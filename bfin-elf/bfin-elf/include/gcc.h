/************************************************************************
 *
 * gcc.h
 *
 * Copyright (C) 2007 Analog Devices, Inc.
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License. See the file COPYING.LIB for more details.
 *
 * Non-LGPL License is also available as part of VisualDSP++
 * from Analog Devices, Inc.
 *
 ************************************************************************/

/* gcc definitions */

#ifndef _GCC_H
#define _GCC_H

#ifdef __cplusplus
extern "C" {
#endif

#define __builtin_bfin_max(a,b)		((a)>=(b)?(a):(b))
#define __builtin_bfin_min(a,b)		((a)<=(b)?(a):(b))
#define __builtin_bfin_lmax(a,b)	((a)>=(b)?(a):(b))
#define __builtin_bfin_lmin(a,b)	((a)<=(b)?(a):(b))
#define __builtin_bfin_max_fr1x32(a,b)	((a)>=(b)?(a):(b))
#define __builtin_bfin_min_fr1x32(a,b)	((a)<=(b)?(a):(b))
#define __builtin_bfin_cmplx_add	__builtin_bfin_add_fr2x16
#define __builtin_bfin_cmplx_sub	__builtin_bfin_sub_fr2x16
#define __builtin_bfin_shr_fr1x16(a,b)	__builtin_bfin_shl_fr1x16(a,-(b))
#define __builtin_bfin_shr_fr2x16(a,b)	__builtin_bfin_shl_fr2x16(a,-(b))
#define __builtin_bfin_lshr_fr1x16(a,b)	__builtin_bfin_lshl_fr1x16(a,-(b))
#define __builtin_bfin_lshr_fr2x16(a,b)	__builtin_bfin_lshl_fr2x16(a,-(b))
#define __builtin_bfin_shr_fr1x32(a,b)	__builtin_bfin_shl_fr1x32(a,-(b))

#ifndef __NO_BUILTIN

#define ssync() __builtin_bfin_ssync()
#define csync() __builtin_bfin_csync()

#endif /* !__NO_BUILTIN */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif  /* _GCC_H */
