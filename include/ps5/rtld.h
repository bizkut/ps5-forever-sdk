/* SPDX-License-Identifier: GPL-3.0-or-later */
#pragma once
#include <sys/cdefs.h>

#define PS5_RTLD_PATH_MAX 1024

__BEGIN_DECLS

/* Register one absolute loader-path prefix during single-threaded startup.
 * Disabled by default; there is no environment trigger. Strings are copied
 * into fixed buffers, so caller storage need not survive this call.
 * Only an exact prefix or a prefix followed by '/' is remapped. Returns 0
 * on success (including identical registration), or an errno value for an
 * empty/non-absolute/overlong prefix or a second conflicting registration.
 * Registration must precede library loads and other threads. */
int ps5_rtld_register_prefix(const char *source, const char *replacement);

__END_DECLS
