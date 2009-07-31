#pragma once
#ifndef __NO_BUILTIN
#pragma system_header /* fr2x16_base.h */
#endif

/************************************************************************
 *
 * fr2x16_base.h
 *
 * Copyright (C) 2000-2006 Analog Devices, Inc.
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License. See the file COPYING.LIB for more details.
 *
 * Non-LGPL License is also available as part of VisualDSP++
 * from Analog Devices, Inc.
 *
 ************************************************************************/

/* Basic operations on packed fractional types, including composition and
 * extraction
 */

#ifndef _FR2x16_BASE_H
#define _FR2x16_BASE_H

#include <fr2x16_typedef.h>
#include <fract_typedef.h>
#include <r2x16_base.h>

#ifdef _MISRA_RULES
#pragma diag(push)
#pragma diag(suppress:misra_rule_2_4)
#pragma diag(suppress:misra_rule_5_7)
#pragma diag(suppress:misra_rule_8_1)
#pragma diag(suppress:misra_rule_8_5)
#pragma diag(suppress:misra_rule_16_1)
#endif /* _MISRA_RULES */

#ifdef __cplusplus
extern "C" {
#endif

#if !defined(__NO_BUILTIN)

__inline__
static fract16 sum_fr2x16(fract2x16 _x) {
  return __builtin_bfin_sum_fr2x16(_x);
}

#else

fract16 sum_fr2x16(fract2x16 _x);

#endif

/*
 * Composition and extraction
 */

/* Takes two fract16 values, and returns a fract2x16 value.
 * Input: two fract16 values
 * Returns: {_x,_y} */
__inline__
__attribute__ ((always_inline))
static fract2x16 compose_fr2x16(fract16 _x, fract16 _y) {
	return compose_2x16(_x,_y);
}

/* Takes a fract2x16 and returns the 'high half' fract16.
 * Input: _x{a,b}
 * Returns: a.
 */

__inline__
__attribute__ ((always_inline))
static fract16 high_of_fr2x16(fract2x16 _x) {
  return high_of_2x16(_x);
}

/* Takes a fract2x16 and returns the 'low half' fract16
 * Input: _x{a,b}
 * Returns: b
 */

__inline__
__attribute__ ((always_inline))
static fract16 low_of_fr2x16(fract2x16 _x) {
  return low_of_2x16(_x);
}

#ifdef __cplusplus
 }
#endif

#ifdef _MISRA_RULES
#pragma diag(pop)
#endif /* _MISRA_RULES */

#endif /* _FR2x16_BASE_H */
