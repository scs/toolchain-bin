#pragma once
#ifndef __NO_BUILTIN
#pragma system_header /* fr2x16_math.h */
#endif
/************************************************************************
 *
 * fr2x16_math.h
 *
 * Copyright (C) 2000-2006 Analog Devices, Inc.
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License. See the file COPYING.LIB for more details.
 *
 * Non-LGPL License is also available as part of VisualDSP++
 * from Analog Devices, Inc.
 *
 ************************************************************************/

/* Standard library functions for two packed fractional values. */

#ifndef _FR2x16_MATH_H
#define _FR2x16_MATH_H

#include <fract_typedef.h>  /* get definitions for fract16 and fract32 */
#include <fr2x16_base.h>
#include <fr2x16_typedef.h>

#ifdef _MISRA_RULES
#pragma diag(push)
#pragma diag(suppress:misra_rule_2_4)
#pragma diag(suppress:misra_rule_5_3)
#pragma diag(suppress:misra_rule_5_7)
#pragma diag(suppress:misra_rule_6_3)
#pragma diag(suppress:misra_rule_8_1)
#pragma diag(suppress:misra_rule_8_5)
#endif /* _MISRA_RULES */



/*
 * Standard functions:
 * abs({a,b})		=> {abs(a), abs(b)}
 * min({a,b},{c,d})	=> {min(a,c),min(b,d)}
 * max({a,b},{c,d})	=> {max(a,c),max(b,d)}
 */

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __NO_BUILTIN
__inline__
__attribute__ ((always_inline))
static fract2x16 abs_fr2x16(fract2x16 _x) {
	return __builtin_bfin_abs_fr2x16(_x);
}
__inline__
__attribute__ ((always_inline))
static fract2x16 min_fr2x16(fract2x16 _x, fract2x16 _y) {
	return __builtin_bfin_min_fr2x16(_x, _y);
}
__inline__
__attribute__ ((always_inline))
static fract2x16 max_fr2x16(fract2x16 _x, fract2x16 _y) {
	return __builtin_bfin_max_fr2x16(_x, _y);
}

/*
extern fract2x16 __builtin_bfin_dspaddsubsat(fract2x16, fract2x16);
extern fract2x16 __builtin_bfin_dspsubaddsat(fract2x16, fract2x16);
extern fract16 __builtin_bfin_diff_hl_fr2x16(fr2x16);
extern fract16 __builtin_bfin_diff_lh_fr2x16(fr2x16); */

__inline__
__attribute__ ((always_inline))
static fract2x16 add_as_fr2x16(fract2x16 x,fract2x16 y) {
        return __builtin_bfin_dspaddsubsat(x,y);
        }

__inline__
__attribute__ ((always_inline))
static fract2x16 add_sa_fr2x16(fract2x16 x,fract2x16 y) {
        return __builtin_bfin_dspsubaddsat(x,y);
        }

__inline__
__attribute__ ((always_inline))
static fract16 diff_hl_fr2x16(fr2x16 x) {
        return __builtin_bfin_diff_hl_fr2x16(x);
        }

__inline__
__attribute__ ((always_inline))
static fract16 diff_lh_fr2x16(fr2x16 x) {
        return __builtin_bfin_diff_lh_fr2x16(x);
        }

#endif /* __NO_BUILTIN */

/*
 * Cross-over multiplication:
 * ll({a,b}, {c,d})	=> a*c
 * lh({a,b}, {c,d})	=> a*d
 * hl({a,b}, {c,d})	=> b*c
 * hh({a,b}, {c,d})	=> b*d
 */

__inline__
__attribute__ ((always_inline))
static fract32 mult_ll_fr2x16(fract2x16 _x, fract2x16 _y) {
        return (fract32)low_of_fr2x16(_x)*(fract32)low_of_fr2x16(_y);
}
__inline__
__attribute__ ((always_inline))
static fract32 mult_hl_fr2x16(fract2x16 _x, fract2x16 _y) {
	return (fract32)high_of_fr2x16(_x)*(fract32)low_of_fr2x16(_y);
}
__inline__
__attribute__ ((always_inline))
static fract32 mult_lh_fr2x16(fract2x16 _x, fract2x16 _y) {
	return (fract32)low_of_fr2x16(_x)*(fract32)high_of_fr2x16(_y);
}
__inline__
__attribute__ ((always_inline))
static fract32 mult_hh_fr2x16(fract2x16 _x, fract2x16 _y) {
	return (fract32)high_of_fr2x16(_x)*(fract32)high_of_fr2x16(_y);
}

#ifdef __cplusplus
}
#endif

#ifdef _MISRA_RULES
#pragma diag(pop)
#endif /* _MISRA_RULES */

#endif /* _FR2x16_MATH_H */
