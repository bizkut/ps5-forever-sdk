/* SPDX-License-Identifier: GPL-3.0-or-later */
#include <errno.h>
#include "rtld_prefix.h"

static char source_prefix[PS5_RTLD_PATH_MAX];
static char replacement_prefix[PS5_RTLD_PATH_MAX];
static unsigned long source_length, replacement_length;

static unsigned long bounded_length(const char *text)
{
    unsigned long length;
    for (length = 0; length < PS5_RTLD_PATH_MAX && text[length]; length++);
    return length;
}

static int equal(const char *left, const char *right, unsigned long length)
{
    unsigned long i;
    for (i = 0; i < length; i++) if (left[i] != right[i]) return 0;
    return 1;
}

int ps5_rtld_register_prefix(const char *source, const char *replacement)
{
    unsigned long from, to, i;
    if (!source || !replacement || source[0] != '/' || replacement[0] != '/') return EINVAL;
    from = bounded_length(source);
    to = bounded_length(replacement);
    if (from == PS5_RTLD_PATH_MAX || to == PS5_RTLD_PATH_MAX) return ENAMETOOLONG;
    if (source_length)
        return from == source_length && to == replacement_length &&
               equal(source, source_prefix, from) && equal(replacement, replacement_prefix, to) ? 0 : EEXIST;
    for (i = 0; i <= from; i++) source_prefix[i] = source[i];
    for (i = 0; i <= to; i++) replacement_prefix[i] = replacement[i];
    replacement_length = to;
    source_length = from;
    return 0;
}

int __rtld_remap_path(const char *name, char *path, unsigned long capacity)
{
    unsigned long length, suffix = 0, output_length, i;
    int remap;
    if (!name || !path) return EINVAL;
    length = bounded_length(name);
    if (length == PS5_RTLD_PATH_MAX) return ENAMETOOLONG;
    remap = source_length && length >= source_length && equal(name, source_prefix, source_length) &&
            (name[source_length] == 0 || name[source_length] == '/');
    if (remap) suffix = source_length;
    output_length = remap ? replacement_length + length - suffix : length;
    if (output_length >= capacity) return ENAMETOOLONG;
    if (remap)
    {
        for (i = 0; i < replacement_length; i++) path[i] = replacement_prefix[i];
        for (; i <= output_length; i++) path[i] = name[suffix + i - replacement_length];
    }
    else for (i = 0; i <= length; i++) path[i] = name[i];
    return 0;
}
