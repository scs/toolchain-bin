#pragma once
#ifndef __NO_BUILTIN
#pragma system_header /* i2x16_base.h */
#endif
/************************************************************************
 *
 * i2x16_base.h
 *
 * Copyright (C) 2000-2006 Analog Devices, Inc.
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License. See the file COPYING.LIB for more details.
 *
 * Non-LGPL License is also available as part of VisualDSP++
 * from Analog Devices, Inc.
 *
 ************************************************************************/

/* Basic operations on packed 16-bit integers. */

#ifndef _I2x16_BASE_H
#define _I2x16_BASE_H

#include <i2x16_typedef.h>
#include <r2x16_base.h>

#ifdef _MISRA_RULES
#pragma diag(push)
#pragma diag(suppress:misra_rule_2_4)
#pragma diag(suppress:misra_rule_6_3)
#pragma diag(suppress:misra_rule_8_1)
#pragma diag(suppress:misra_rule_8_5)
#endif /* _MISRA_RULES */

#ifdef __cplusplus
extern "C" {
#endif
/*
 * Composition and extraction
 */

__inline__
__attribute__ ((always_inline))
static int2x16 compose_i2x16(short _x, short _y) {
	return compose_2x16(_x, _y);
}
__inline__
__attribute__ ((always_inline))
static short high_of_i2x16(int2x16 _x) {
	return high_of_2x16(_x);
}
__inline__
__attribute__ ((always_inline))
static short low_of_i2x16(int2x16 _x) {
	return low_of_2x16(_x);
}

/*
 * Arithmetic operations
 * add({a,b},{c,d})	=> {a+c, b+d}
 * sub({a,b},{c,d})	=> {a-c, b-d}
 * mult({a,b},{c,d})	=> {a*c, b*d}
 */

#if (defined(__ADSPBLACKFIN__) || defined(__ADSPTS__)) && !defined(__NO_BUILTIN)

__inline__
__attribute__ ((always_inline))
static int2x16 add_i2x16(int2x16 _x, int2x16 _y) {
	return __builtin_bfin_add_i2x16(_x, _y);
}
__inline__
__attribute__ ((always_inline))
static int2x16 sub_i2x16(int2x16 _x, int2x16 _y) {
	return __builtin_bfin_sub_i2x16(_x, _y);
}
__inline__
__attribute__ ((always_inline))
static int2x16 mult_i2x16(int2x16 _x, int2x16 _y) {
	return __builtin_bfin_mult_i2x16(_x, _y);
}

#else
int2x16 add_i2x16(int2x16, int2x16);
int2x16 sub_i2x16(int2x16, int2x16);
int2x16 mult_i2x16(int2x16, int2x16);
#endif


/*
 * Sideways addition:
 * sum({a,b})	=> a+b
 */

#ifdef __ADSPTS__
__inline__
__attribute__ ((always_inline))
static int sum_i2x16(int2x16 _x) {
	return __builtin_bfin_sum_i2x16(_x);
}
#else

__inline__
__attribute__ ((always_inline))
static int sum_i2x16(int2x16 _x) {
	return (int)high_of_i2x16(_x)+low_of_i2x16(_x);
}

#endif /* __ADSPTS_ */

#ifdef __cplusplus
 } /* extern "C" */
#endif

#ifdef _MISRA_RULES
#pragma diag(pop)
#endif /* _MISRA_RULES */

#endif /* _I2x16_BASE_H */
