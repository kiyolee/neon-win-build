/* 
   Global interfaces private to neon.
   Copyright (C) 2005-2021, Joe Orton <joe@manyfish.co.uk>

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

/* NOTE WELL: The interfaces defined in this file are internal to neon
 * and MUST NOT be used by neon-based applications. */

#ifndef NE_INTERNAL_H
#define NE_INTERNAL_H 1

#include "config.h"

#ifdef HAVE_SYS_LIMITS_H
#include <sys/limits.h>
#endif
#ifdef HAVE_LIMITS_H
#include <limits.h> /* for UINT_MAX etc */
#endif

#include "ne_defs.h"

#undef _
#ifdef NE_HAVE_I18N
#include <libintl.h>
#define _(str) dgettext(PACKAGE_NAME, str)
#else
#define _(str) (str)
#endif /* NE_ENABLE_NLS */
#define N_(str) (str)

#if !defined(LONG_LONG_MAX) && defined(LLONG_MAX)
#define LONG_LONG_MAX LLONG_MAX
#elif !defined(LONG_LONG_MAX) && defined(LONGLONG_MAX)
#define LONG_LONG_MAX LONGLONG_MAX
#endif

#if defined(NE_LFS)

#define ne_lseek lseek64
#define FMT_NE_OFF_T NE_FMT_OFF64_T
#define NE_OFFT_MAX LONG_LONG_MAX
#ifdef HAVE_STRTOLL
#define ne_strtoff strtoll
#else
#define ne_strtoff strtoq
#endif

#else /* !NE_LFS */

#if defined(_MSC_VER) && _MSC_VER >= 1400
#define ne_lseek _lseek
#else
#define ne_lseek lseek
#endif
#define FMT_NE_OFF_T NE_FMT_OFF_T

#if defined(SIZEOF_LONG_LONG) && defined(LONG_LONG_MAX) \
    && SIZEOF_OFF_T == SIZEOF_LONG_LONG
#define NE_OFFT_MAX LONG_LONG_MAX
#else
#define NE_OFFT_MAX LONG_MAX
#endif

#if SIZEOF_OFF_T > SIZEOF_LONG && defined(HAVE_STRTOLL)
#define ne_strtoff strtoll
#elif SIZEOF_OFF_T > SIZEOF_LONG && defined(HAVE_STRTOQ)
#define ne_strtoff strtoq
#else
#define ne_strtoff strtol
#endif
#endif /* NE_LFS */

#define NE_HASH_ALGMASK (0x000f)

/* Return malloc-allocated ASCII hexadecimal representation of
 * input. */
NE_PRIVATE char *ne__strhash2hex(const unsigned char *digest, size_t len, unsigned int flags);

#ifdef HAVE_EXPLICIT_BZERO
#define ne__strzero(s, n) explicit_bzero(s, n)
#else
#define ne__strzero(s, n) memset(s, 0, n)
#endif

#endif /* NE_INTERNAL_H */
