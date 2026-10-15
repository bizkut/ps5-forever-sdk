/* Copyright (C) 2024 John Törnblom

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
#include <sys/types.h>


/* The kernel reports a failure with the carry flag set and the error number
 * in rax. Every stub below jumps here then, so that it returns -1 with errno
 * set, as the C library does on FreeBSD, rather than the error number. */
__attribute__((visibility("hidden"))) long
__libc_syscall_error(int err) {
  errno = err;
  return -1;
}


void
syscall() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, rdi\n"
    "  mov rdi, rsi\n"
    "  mov rsi, rdx\n"
    "  mov rdx, rcx\n"
    "  mov r10, r8\n"
    "  mov r8,  r9\n"
    "  mov r9,  qword ptr [rsp + 8]\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
__syscall() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, rdi\n"
    "  mov rdi, rsi\n"
    "  mov rsi, rdx\n"
    "  mov rdx, rcx\n"
    "  mov r10, r8\n"
    "  mov r8,  r9\n"
    "  mov r9,  qword ptr [rsp + 8]\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
fork() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 2\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
wait4() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 7\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
link() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 9\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
fchdir() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 13\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
mknod() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 14\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
chown() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 16\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}


void
ptrace() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 26\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
dup() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 41\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
ktrace() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 45\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
setlogin() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 50\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
acct() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 51\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
reboot() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 55\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
revoke() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 56\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
symlink() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 57\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
readlink() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 58\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
umask() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 60\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
chroot() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 61\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
vfork() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 66\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
sbrk() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 69\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
sstk() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 70\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
vadvise() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 72\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
getpgrp() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 81\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
setpgid() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 82\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
swapon() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 85\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
fchown() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 123\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
mkfifo() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 132\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
adjtime() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 140\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
setsid() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 147\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
quotactl() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 148\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
nlm_syscall() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 154\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
nfssvc() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 155\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
lgetfh() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 160\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
getfh() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 161\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
rtprio() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 166\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
semsys() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 169\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
msgsys() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 170\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
shmsys() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 171\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
setfib() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 175\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
ntp_adjtime() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 176\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
setgid() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 181\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
pathconf() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 191\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
fpathconf() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 192\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
undelete() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 205\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
getpgid() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 207\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
semget() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 221\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
semop() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 222\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
msgget() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 225\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
msgsnd() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 226\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
msgrcv() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 227\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
shmat() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 228\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
shmdt() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 230\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
shmget() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 231\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
ffclock_getcounter() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 241\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
ffclock_setestimate() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 242\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
ffclock_getestimate() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 243\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
clock_nanosleep() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 244\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
clock_getcpuclockid2() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 247\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
ntp_gettime() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 248\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
minherit() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 250\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
rfork() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 251\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
lchown() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 254\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
aio_read() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 255\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
aio_write() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 256\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
lio_listio() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 257\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
lchmod() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 274\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
lutimes() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 276\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
nstat() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 278\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
nfstat() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 279\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
nlstat() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 280\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
fhopen() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 298\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
fhstat() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 299\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
modnext() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 300\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
modstat() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 301\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
modfnext() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 302\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
modfind() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 303\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
kldload() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 304\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
kldunload() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 305\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
kldfind() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 306\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
kldnext() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 307\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
kldstat() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 308\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
kldfirstmod() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 309\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
setresuid() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 311\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
setresgid() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 312\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
aio_return() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 314\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
aio_suspend() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 315\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
aio_cancel() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 316\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
aio_error() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 317\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
yield() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 321\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
utrace() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 335\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
kldsym() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 337\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
jail() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 338\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
nnpfs_syscall() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 339\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
__acl_get_file() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 347\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
__acl_set_file() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 348\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
__acl_get_fd() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 349\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
__acl_set_fd() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 350\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
__acl_delete_file() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 351\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
__acl_delete_fd() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 352\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
__acl_aclcheck_file() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 353\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
__acl_aclcheck_fd() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 354\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
extattrctl() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 355\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
extattr_set_file() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 356\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
extattr_get_file() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 357\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
extattr_delete_file() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 358\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
aio_waitcomplete() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 359\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
getresuid() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 360\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
getresgid() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 361\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
extattr_set_fd() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 371\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
extattr_get_fd() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 372\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
extattr_delete_fd() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 373\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
__setugid() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 374\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
eaccess() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 376\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
afs3_syscall() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 377\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}


void
__mac_get_proc() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 384\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
__mac_set_proc() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 385\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
__mac_get_fd() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 386\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
__mac_get_file() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 387\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
__mac_set_fd() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 388\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
__mac_set_file() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 389\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
kenv() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 390\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
lchflags() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 391\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
mac_syscall() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 394\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
getfsstat() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 395\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
statfs() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 396\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
fstatfs() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 397\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
fhstatfs() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 398\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
__mac_get_pid() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 409\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
__mac_get_link() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 410\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
__mac_set_link() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 411\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
extattr_set_link() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 412\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
extattr_get_link() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 413\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
extattr_delete_link() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 414\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
__mac_execve() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 415\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
swapoff() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 424\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
__acl_get_link() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 425\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
__acl_set_link() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 426\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
__acl_delete_link() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 427\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
__acl_aclcheck_link() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 428\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
thr_create() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 430\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
thr_exit() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 431\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
thr_self() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 432\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
thr_kill() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 433\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
jail_attach() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 436\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
extattr_list_fd() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 437\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
extattr_list_file() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 438\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
extattr_list_link() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 439\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
thr_suspend() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 442\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
thr_wake() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 443\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
kldunloadf() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 444\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
audit() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 445\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
auditon() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 446\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
getauid() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 447\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
setauid() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 448\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
getaudit() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 449\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
setaudit() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 450\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
getaudit_addr() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 451\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
setaudit_addr() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 452\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
auditctl() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 453\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
thr_new() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 455\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
kmq_open() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 457\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
kmq_setattr() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 458\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
kmq_timedreceive() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 459\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
kmq_timedsend() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 460\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
kmq_notify() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 461\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
kmq_unlink() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 462\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
abort2() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 463\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
thr_set_name() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 464\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
aio_fsync() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 465\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
sctp_peeloff() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 471\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
sctp_generic_sendmsg() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 472\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
sctp_generic_sendmsg_iov() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 473\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
sctp_generic_recvmsg() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 474\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
thr_kill2() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 481\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
cpuset() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 484\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
cpuset_setid() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 485\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
faccessat() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 489\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
fchmodat() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 490\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
fchownat() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 491\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
fexecve() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 492\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
fstatat() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 493\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
futimesat() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 494\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
linkat() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 495\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
mkdirat() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 496\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
mkfifoat() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 497\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
mknodat() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 498\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
openat() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 499\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
readlinkat() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 500\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
renameat() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 501\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
symlinkat() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 502\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
unlinkat() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 503\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
posix_openpt() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 504\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
gssd_syscall() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 505\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
jail_get() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 506\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
jail_set() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 507\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
jail_remove() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 508\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
closefrom() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 509\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
semctl() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 510\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
msgctl() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 511\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
shmctl() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 512\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
lpathconf() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 513\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
__cap_rights_get() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 515\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
cap_enter() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 516\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
cap_getmode() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 517\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
pdfork() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 518\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
pdkill() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 519\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
pdgetpid() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 520\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
getloginclass() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 523\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
setloginclass() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 524\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
rctl_get_racct() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 525\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
rctl_get_rules() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 526\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
rctl_get_limits() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 527\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
rctl_add_rule() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 528\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
rctl_remove_rule() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 529\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

/* The console has no posix_fallocate or posix_fadvise: FreeBSD's numbers 530
 * and 531 are obsolete slots in its system call table (the 5.50 kernel's
 * syscallnames; Relapse-Exploit's src/utils/syscalls.js agrees). Both
 * return an error number instead of setting errno, as POSIX specifies, so
 * callers such as Wine take their fallback. */
int
posix_fallocate(int fd, off_t offset, off_t len) {
  (void)fd;
  (void)offset;
  (void)len;
  return EOPNOTSUPP;
}

int
posix_fadvise(int fd, off_t offset, off_t len, int advice) {
  (void)fd;
  (void)offset;
  (void)len;
  (void)advice;
  return 0;  /* advice only */
}

/* FreeBSD 10/11 placed the calls below at 532-549. The console keeps those
 * numbers for its own calls (regmgr_call, jitshm_*, dl_*, evf_*,
 * query_memory_protection, batch_map, osem_create) and has these at 677-694
 * (the 5.50 kernel's syscallnames table; Relapse-Exploit's syscalls.js has
 * the same numbers). FreeBSD's numbers made futimens call evf_cancel with a
 * file descriptor as the event flag, failing with ESRCH (Wine, 2026-10-03). */

void
wait6() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 677\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
cap_rights_limit() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 678\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
cap_ioctls_limit() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 679\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
cap_ioctls_get() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 680\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
cap_fcntls_limit() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 681\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
cap_fcntls_get() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 682\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
bindat() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 683\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
connectat() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 684\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
chflagsat() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 685\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
aio_mlock() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 688\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
procctl() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 689\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
ppoll() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 690\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
futimens() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 691\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
utimensat() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 692\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
numa_getaffinity() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 693\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

void
numa_setaffinity() {
  asm(".intel_syntax noprefix\n"
    "  mov rax, 694\n"
    "  mov r10, rcx\n"
    "  syscall\n"
    "  jb 1f\n"
    "  ret\n"
    "1:\n"
    "  mov edi, eax\n"
    "  jmp __libc_syscall_error\n"
    );
}

