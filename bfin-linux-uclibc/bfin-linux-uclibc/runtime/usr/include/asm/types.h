#ifndef _BFIN_TYPES_H
#define _BFIN_TYPES_H

/*
 * This file is never included by application software unless
 * explicitly requested (e.g., via linux/types.h) in which case the
 * application is Linux specific so (user-) name space pollution is
 * not a major issue.  However, for interoperability, libraries still
 * need to be careful to avoid a name clashes.
 */
#include <asm-generic/int-ll64.h>

#ifndef __ASSEMBLY__

typedef unsigned short umode_t;

#endif				/* __ASSEMBLY__ */
/*
 * These aren't exported outside the kernel to avoid name space clashes
 */

#endif				/* _BFIN_TYPES_H */
