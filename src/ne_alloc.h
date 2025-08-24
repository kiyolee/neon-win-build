/* 
   Replacement memory allocation handling etc.
   Copyright (C) 1999-2021, Joe Orton <joe@manyfish.co.uk>

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.
   
   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public
   License along with this library; if not, write to the Free
   Software Foundation, Inc., 59 Temple Place - Suite 330, Boston,
   MA 02111-1307, USA

*/

#ifndef NE_ALLOC_H
#define NE_ALLOC_H

#include <stdlib.h>

#ifndef WIN32
#include <sys/types.h>
#endif

#include "ne_defs.h"

NE_BEGIN_DECLS

typedef void (*ne_oom_callback_fn)(void);

/* Set callback which is called if malloc() returns NULL. */
NE_API void ne_oom_callback(ne_oom_callback_fn callback);

#ifndef NEON_MEMLEAK
/* Replacements for standard C library memory allocation functions,
 * which never return NULL. If the C library malloc() returns NULL,
 * neon will abort(); calling an OOM callback beforehand if one is
 * registered.  The C library will only ever return NULL if the
 * operating system does not use optimistic memory allocation. */
NE_API void *ne_malloc(size_t size) ne_attribute_alloc_size(1) ne_attribute_malloc;
NE_API void *ne_calloc(size_t size) ne_attribute_alloc_size(1) ne_attribute_malloc;
NE_API void *ne_realloc(void *ptr, size_t s) ne_attribute_alloc_size(2);
NE_API char *ne_strdup(const char *s) ne_attribute_malloc;
NE_API char *ne_strndup(const char *s, size_t n) ne_attribute_malloc;
#ifdef WIN32
NE_API void ne_free(void *ptr);
#else
#define ne_free free
#endif
#endif

NE_END_DECLS

#endif /* NE_ALLOC_H */
