#pragma once
#ifndef __NO_BUILTIN
#pragma system_header /* r2x16_base.h */
#endif
/************************************************************************
 *
 * r2x16.h
 *
 * Copyright (C) 2000-2006 Analog Devices, Inc.
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License. See the file COPYING.LIB for more details.
 *
 * Non-LGPL License is also available as part of VisualDSP++
 * from Analog Devices, Inc.
 *
 ************************************************************************/

/* Basic operations on 2x16-base types. */

#ifndef _R2x16_BASE_H
#define _R2x16_BASE_H

#if defined(__ADSPBLACKFIN__) 

#include <r2x16_typedef.h>

#ifdef _MISRA_RULES
#pragma diag(push)
#pragma diag(suppress:misra_rule_6_3)
#pragma diag(suppress:misra_rule_8_1)
#pragma diag(suppress:misra_rule_8_5)
#endif /* _MISRA_RULES */


#if defined(__cplusplus)
extern "C" {
#endif

#if !defined(__NO_BUILTIN)

__inline__
__attribute__ ((always_inline))
static raw2x16 compose_2x16(_raw16 _x, _raw16 _y) {
	return __builtin_bfin_compose_2x16(_x, _y);
}
__inline__
__attribute__ ((always_inline))
static  _raw16 high_of_2x16(raw2x16 _x) {
	return __builtin_bfin_extract_hi(_x);
}
__inline__
__attribute__ ((always_inline))
static  _raw16 low_of_2x16(raw2x16 _x) {
	return __builtin_bfin_extract_lo(_x);
}

#else

__inline__
__attribute__ ((always_inline))
static raw2x16 compose_2x16(_raw16 _x, _raw16 _y) {
/* Casting and variable u required for MISRA compliance */
        unsigned int u = (((unsigned int)_x << 16) | ((unsigned int)_y & 0xFFFFU));
	return (raw2x16)u;
}
__inline__
__attribute__ ((always_inline))
static  _raw16 high_of_2x16(raw2x16 _x) {
        unsigned int u = ((unsigned int)_x >> 16);
	return (_raw16)u;
}
__inline__
__attribute__ ((always_inline))
static _raw16 low_of_2x16(raw2x16 _x) {
	unsigned u = ((unsigned int)_x & 0xFFFFU);
	return (_raw16)u;
}

#endif /* __NO_BUILTIN */

#if defined(__cplusplus)
} /* extern "C" */
#endif

#ifdef _MISRA_RULES
#pragma diag(pop)
#endif /* _MISRA_RULES */

#endif /* __ADSPBLACKFIN__ */

#endif /* _R2x16_BASE_H */
