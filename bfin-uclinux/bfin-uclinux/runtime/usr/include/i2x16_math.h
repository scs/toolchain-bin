#pragma once
#ifndef __NO_BUILTIN
#pragma system_header /* i2x16_math.h */
#endif
/************************************************************************
 *
 * i2x16_math.h 
 *
 * Copyright (C) 2000-2006 Analog Devices, Inc.
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License. See the file COPYING.LIB for more details.
 *
 * Non-LGPL License is also available as part of VisualDSP++
 * from Analog Devices, Inc.
 *
 ************************************************************************/

/* Additional operations on packed 16-bit integers */

#ifndef _I2x16_MATH_H
#define _I2x16_MATH_H

#include <i2x16_typedef.h>
#include <i2x16_base.h>
#include <stdlib.h>
#include <math_bf.h>

#ifdef _MISRA_RULES
#pragma diag(push)
#pragma diag(suppress:misra_rule_2_4)
#pragma diag(suppress:misra_rule_6_3)
#pragma diag(suppress:misra_rule_8_1)
#pragma diag(suppress:misra_rule_8_5)
#pragma diag(suppress:misra_rule_19_4)
#endif /* _MISRA_RULES */

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Standard functions
 * abs({a,b})		=> { abs(a), abs(b) }
 * min({a,b},{c,d})	=> { min(a,c), min(b,d) }
 * max({a,b},{c,d})	=> { max(a,c), max(b,d) }
 */

__inline__
__attribute__ ((always_inline))
static int2x16 abs_i2x16(int2x16 _x) {
	return compose_2x16((short)abs((int)high_of_i2x16(_x)), (short)abs((int)low_of_i2x16(_x)));
}
__inline__
__attribute__ ((always_inline))
static int2x16 min_i2x16(int2x16 _x, int2x16 _y) {
	return compose_2x16((short)min((int)high_of_i2x16(_x), (int)high_of_i2x16(_y)),
                       (short)min((int)low_of_i2x16(_x), (int)low_of_i2x16(_y)));
}
__inline__
__attribute__ ((always_inline))
static int2x16 max_i2x16(int2x16 _x, int2x16 _y) {
	return compose_2x16((short)max((int)high_of_i2x16(_x), (int)high_of_i2x16(_y)),
                       (short)max((int)low_of_i2x16(_x), (int)low_of_i2x16(_y)));
}

/*
 * Cross-wise multiplication
 * ll({a,b},{c,d})	=> a*c
 * lh({a,b},{c,d})	=> a*d
 * hl({a,b},{c,d})	=> b*c
 * hh({a,b},{c,d})	=> b*d
 */

__inline__
__attribute__ ((always_inline))
static long int mult_ll_i2x16(int2x16 _x, int2x16 _y) {
	return (long int)low_of_i2x16(_x)*(long int)low_of_i2x16(_y);
}
__inline__
__attribute__ ((always_inline))
static long int mult_hl_i2x16(int2x16 _x, int2x16 _y) {
	return (long int)high_of_i2x16(_x)*(long int)low_of_i2x16(_y);
}
__inline__
__attribute__ ((always_inline))
static long int mult_lh_i2x16(int2x16 _x, int2x16 _y) {
	return (long int)low_of_i2x16(_x)*(long int)high_of_i2x16(_y);
}
__inline__
__attribute__ ((always_inline))
static long int mult_hh_i2x16(int2x16 _x, int2x16 _y) {
	return (long int)high_of_i2x16(_x)*(long int)high_of_i2x16(_y);
}

#ifdef __cplusplus
  } /* extern "C" */
#endif

#ifdef _MISRA_RULES
#pragma diag(pop)
#endif /* _MISRA_RULES */

#endif /* _I2x16_MATH_H */
