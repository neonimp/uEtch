/**
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _DGEOM_H_
#define _DGEOM_H_
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#if defined(__linux__)
#include "linux/linux_dgeom.h"
#endif
#if defined(__WIN64) || defined(__WIN32)
#include "nt/dgeom.h"
#endif
struct devgeom {
    size_t blkct;
    size_t iomin;
    size_t pblksiz;
};

size_t uetch_blkcnt(char *path);
size_t uetch_blksiz(char *path);
/**
 * This function abstracts over platform specifics and retrieves information about a drive geometry to dgeom
 * @param dgeom this struct will have it's values set to the relevant values if successful poison otherwise
 * @param path
 * @return
 */
int uetch_dgeom(struct devgeom *dgeom, char *path);

#endif //_DGEOM_H_
