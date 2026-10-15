/* Copyright (C) 2025 John Törnblom

This program is free software; you can redistribute it and/or modify it
under the terms of the GNU General Public License as published by the
Free Software Foundation; either version 3, or (at your option) any
later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; see the file COPYING. If not, see
<http://www.gnu.org/licenses/>.  */

#include <errno.h>
#include <unistd.h>

#include <sys/mman.h>
#include <sys/syscall.h>


/**
 * shared objects do not link with crt1.o, declare deps as weak.
 **/
__attribute__((weak)) int kernel_mprotect(pid_t, intptr_t, size_t, int);


static long
__syscall6(long n, long a1, long a2, long a3, long a4, long a5, long a6) {
  unsigned long ret;
  char iserror;

  register long r10 __asm__("r10") = a4;
  register long r8 __asm__("r8") = a5;
  register long r9 __asm__("r9") = a6;

  __asm__ __volatile__(
     "syscall" : "=a"(ret), "=@ccc"(iserror), "+r"(r10), "+r"(r8), "+r"(r9) :
     "a"(n), "D"(a1), "S"(a2), "d"(a3) :
     "rcx", "r11", "memory"
     );

  return iserror ? -ret : ret;
}


static void*
sys_mmap(void* addr, size_t size, int prot, int flags, int fd, off_t offset) {
  long ret;

  if((ret=__syscall6(SYS_mmap, (long)addr, size, prot, flags, fd, offset)) < 0) {
    errno = -ret;
    return (void*)-1;
  }

  return (void*)ret;
}


static int
sys_mprotect(const void* addr, size_t size, int prot) {
  long ret;

  if((ret=__syscall6(SYS_mprotect, (long)addr, size, prot, 0, 0, 0)) < 0) {
    errno = -ret;
    return -1;
  }

  return (int)ret;
}


int
mprotect(const void* addr, size_t size, int prot) {
  if(!(prot & PROT_EXEC)) {
    return sys_mprotect(addr, size, prot);
  }

  if(!kernel_mprotect(-1, (intptr_t)addr, size, prot)) {
    return 0;
  }

  errno = EPERM;
  return -1;
}


/**
 * Two cases are mapped in two steps, then given the requested protection:
 * executable memory, whose PROT_EXEC only kernel_mprotect grants; and a
 * private file mapping with write access. The console's kernel writes the
 * latter's changes through to the file when it is writable from the start,
 * while one mapped read-only and then made writable is copy-on-write
 * (ps5-proton-ge-custom ps5/probes/mapcow, firmware 5.50: Wine's DLL
 * relocations reached the installed files).
 **/
void*
mmap(void* addr, size_t size, int prot, int flags, int fd, off_t offset) {
  int map_prot = prot & ~PROT_EXEC;
  void *map_addr;

  if((flags & MAP_PRIVATE) && !(flags & MAP_ANON)) {
    map_prot &= ~PROT_WRITE;
  }
  if(map_prot == prot) {
    return sys_mmap(addr, size, prot, flags, fd, offset);
  }

  if((map_addr=sys_mmap(addr, size, map_prot, flags, fd, offset)) == MAP_FAILED) {
    return map_addr;
  }

  if(prot & PROT_EXEC) {
    if(kernel_mprotect(-1, (intptr_t)map_addr, size, prot)) {
      munmap(map_addr, size);
      errno = EPERM;
      return MAP_FAILED;
    }
  } else if(sys_mprotect(map_addr, size, prot)) {
    int error = errno;
    munmap(map_addr, size);
    errno = error;
    return MAP_FAILED;
  }

  return map_addr;
}
