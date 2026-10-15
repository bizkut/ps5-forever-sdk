/* SPDX-License-Identifier: GPL-3.0-or-later */
#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include "../rtld_prefix.h"

int main(void)
{
    char path[PS5_RTLD_PATH_MAX], long_prefix[PS5_RTLD_PATH_MAX + 1];
    char source[] = "/data/homebrew/PPSA99030/wine";
    char replacement[] = "/app0/wine";
    assert(!__rtld_remap_path(source, path, sizeof(path)));
    assert(!strcmp(path, source));
    assert(ps5_rtld_register_prefix(NULL, replacement) == EINVAL);
    assert(ps5_rtld_register_prefix("", replacement) == EINVAL);
    assert(ps5_rtld_register_prefix("relative", replacement) == EINVAL);
    assert(ps5_rtld_register_prefix(source, "") == EINVAL);
    assert(ps5_rtld_register_prefix(source, "relative") == EINVAL);
    memset(long_prefix, 'a', sizeof(long_prefix));
    long_prefix[0] = '/';
    long_prefix[sizeof(long_prefix) - 1] = 0;
    assert(ps5_rtld_register_prefix(long_prefix, replacement) == ENAMETOOLONG);
    assert(ps5_rtld_register_prefix(source, long_prefix) == ENAMETOOLONG);
    assert(!__rtld_remap_path(source, path, sizeof(path)) && !strcmp(path, source));
    assert(!ps5_rtld_register_prefix(source, replacement));
    source[1] = 'x'; replacement[1] = 'x'; /* Registered strings are owned copies. */
    assert(!__rtld_remap_path("/data/homebrew/PPSA99030/wine", path, sizeof(path)));
    assert(!strcmp(path, "/app0/wine"));
    assert(!__rtld_remap_path("/data/homebrew/PPSA99030/wine/lib/ntdll.so", path, sizeof(path)));
    assert(!strcmp(path, "/app0/wine/lib/ntdll.so"));
    assert(!__rtld_remap_path("/data/homebrew/PPSA99030/wine-other/lib", path, sizeof(path)));
    assert(!strcmp(path, "/data/homebrew/PPSA99030/wine-other/lib"));
    assert(!__rtld_remap_path("libkernel.sprx", path, sizeof(path)));
    assert(!strcmp(path, "libkernel.sprx"));
    strcpy(path, "unchanged");
    assert(__rtld_remap_path("/data/homebrew/PPSA99030/wine/lib", path, 5) == ENAMETOOLONG);
    assert(!strcmp(path, "unchanged"));
    assert(__rtld_remap_path(long_prefix, path, sizeof(path)) == ENAMETOOLONG);
    assert(!ps5_rtld_register_prefix("/data/homebrew/PPSA99030/wine", "/app0/wine"));
    assert(ps5_rtld_register_prefix("/data/other", "/app0/wine") == EEXIST);
    assert(ps5_rtld_register_prefix("/data/homebrew/PPSA99030/wine", "/app0/other") == EEXIST);
    assert(!__rtld_remap_path("/data/homebrew/PPSA99030/wine", path, sizeof(path)));
    assert(!strcmp(path, "/app0/wine"));
    puts("rtld prefix: disabled, exact, child, boundary, ownership, overflow and registration tests passed");
    return 0;
}
