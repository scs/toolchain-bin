/************************************************************************
 *
 * complex_typedef.h
 *
 * Copyright (C) 2001-2006 Analog Devices, Inc.
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License. See the file COPYING.LIB for more details.
 *
 * Non-LGPL License is also available as part of VisualDSP++
 * from Analog Devices, Inc.
 *
 ************************************************************************/

#pragma once
#ifndef __NO_BUILTIN
#pragma system_header /* complex_typedef.h */
#endif

/* Define complex data types (fractional and float) */

#ifndef _COMPLEX_TYPEDEF_H
#define _COMPLEX_TYPEDEF_H

#include <fract_typedef.h>

#ifdef _MISRA_RULES
#pragma diag(push)
#pragma diag(suppress:misra_rule_5_6)
#pragma diag(suppress:misra_rule_6_3)
#pragma diag(suppress:misra_rule_5_7)
#pragma diag(suppress:misra_rule_18_4)
#endif /* _MISRA_RULES */


typedef struct complex_fract16 {
#pragma align 4
    fract16 re;
    fract16 im;
} __attribute__((aligned(4))) complex_fract16;

/* Composite type used by builtins */
typedef union composite_complex_fract16 {
    struct complex_fract16 x;
    long raw;
} composite_complex_fract16;

#define CFR16_RE(X) (X).x.re
#define CFR16_IM(X) (X).x.im
#define CFR16_RAW(X) (X).raw


typedef struct complex_fract32 {
    fract32 re;
    fract32 im;
} complex_fract32;

/* Composite type used by builtins */
typedef union composite_complex_fract32 {
    struct complex_fract32  x;
    long long raw;
} composite_complex_fract32;

#define CFR32_RE(X) (X).x.re
#define CFR32_IM(X) (X).x.im
#define CFR32_RAW(X) (X).raw

/* C++ Template class variant declared in complex */
typedef struct complex_float {
    float re;
    float im;
} complex_float;

typedef struct complex_long_double {
    long double re;
    long double im;
} complex_long_double;

#ifdef __DOUBLES_ARE_FLOATS__          /* 32-bit doubles */
  typedef complex_float          complex_double;
#else                                  /* 64-bit doubles */
  typedef complex_long_double    complex_double;
#endif

#ifdef _MISRA_RULES
#pragma diag(pop)
#endif /* _MISRA_RULES */
#endif /* _COMPLEX_TYPEDEF_H */
