#   Copyright (C) 2023 John Törnblom
#
# This file is free software; you can redistribute it and/or modify it
# under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; see the file COPYING. If not see
# <http://www.gnu.org/licenses/>.

include ../Makefile.inc

CFLAGS += -ffreestanding -fno-builtin -nostdlib -fPIC
CFLAGS += -target x86_64-sie-ps5 -fno-plt -fno-stack-protector
CFLAGS += -fvisibility-nodllstorageclass=default -Wall -Werror
CFLAGS += -fms-extensions -Wno-microsoft-anon-tag
CFLAGS += -O1
CFLAGS += -isystem ../include/freebsd -I../include

HOST_CC ?= cc
HOST_CFLAGS := -std=c11 -O1 -Wall -Wextra -Werror -I../include

OBJ := crt.o syscall.o klog.o nid.o kernel.o rtld.o rtld_so.o rtld_sprx.o \
       rtld_payload.o rtld_dlfcn.o rtld_prefix.o mdbg.o patch.o kernel_procio.o _start.o

.PHONY: all clean install test

all: crt1.o crti.o crtn.o crtbegin.o crtend.o crtbeginS.o crtendS.o

test: tests/rtld_prefix
	tests/rtld_prefix

tests/rtld_prefix: rtld_prefix.c rtld_prefix.h tests/rtld_prefix.c ../include/ps5/rtld.h
	$(HOST_CC) $(HOST_CFLAGS) rtld_prefix.c tests/rtld_prefix.c -o $@

crtbeginS.o:
	$(AR) -rsc $@

crtendS.o:
	$(AR) -rsc $@

crtbegin.o:
	$(AR) -rsc $@

crtend.o:
	$(AR) -rsc $@

crti.o:
	$(AR) -rsc $@

crtn.o:
	$(AR) -rsc $@

crt1.o: $(OBJ)
	$(LD) -m elf_x86_64 -r -o $@ $^

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

rtld.o rtld_prefix.o: rtld_prefix.h ../include/ps5/rtld.h

%.o: %.S
	$(CC) -c $(CFLAGS) -masm=intel -o $@ $^

clean:
	rm -f *.o *.a
	rm -f tests/rtld_prefix

install: crt1.o crti.o crtn.o crtbegin.o crtend.o crtbeginS.o crtendS.o
	install -d $(DESTDIR)/target/lib
	install $^ $(DESTDIR)/target/lib
