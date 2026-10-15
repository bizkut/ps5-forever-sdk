/* SPDX-License-Identifier: GPL-3.0-or-later */
#pragma once
#include <ps5/rtld.h>

/* No allocation or system calls. Input/output must not alias. On error the
 * output is unchanged. A disabled/nonmatching map copies the original path. */
int __rtld_remap_path(const char *name, char *path, unsigned long capacity);
