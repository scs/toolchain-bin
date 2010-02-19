/************************************************************************
 *
 * util.h 
 *
 * Copyright (C) 2002-2004 Analog Devices, Inc.
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License. See the file COPYING.LIB for more details.
 *
 * Non-LGPL License is also available as part of VisualDSP++
 * from Analog Devices, Inc.
 *
 ************************************************************************/

/* This file contains function declarations and  macros used in the 
** standard C and DSP libraries.
*/

#pragma once
#ifndef __NO_BUILTIN
#pragma system_header /* util.h */
#endif

#ifndef _UTIL_H
#define _UTIL_H

#ifdef __ADSPTS__
#include "_divide.h"
#endif

#ifdef _MISRA_RULES
#pragma diag(push)
#pragma diag(suppress:misra_rule_5_7)
#pragma diag(suppress:misra_rule_6_3)
#pragma diag(suppress:misra_rule_18_4)
#pragma diag(suppress:misra_rule_19_4)
#endif /* _MISRA_RULES */

#define DOUBLE  long double
#define FLOAT   float
#define INT     int
#define LONG    long int

#define MPY(x, y)   ((float)(x) * (float)(y))
#define MPYD(x, y)  ((long double)(x) * (long double)(y))

#ifdef  __ADSPTS__
#define DIV(x, y)   (_divide40((float)(x),(float)(y)))
#else
#define DIV(x, y)   ((float)(x) / (float)(y))
#endif
#define DIVD(x, y)  ((long double)(x) / (long double)(y))

#define ADD(x, y)   ((float)(x) + (float)(y))
#define ADDD(x, y)  ((long double)(x) + (long double)(y))

#define SUB(x, y)   ((float)(x) - (float)(y))
#define SUBD(x, y)  ((long double)(x) - (long double)(y))

#define TO_FLOAT(x)    ((float)(x))
#define TO_DOUBLE(x)   ((long double)(x))
#define TO_LONG(x)     ((long)(x))

typedef union 
{
   FLOAT f;
   LONG i;
} FLOAT_BIT_MANIPULATOR;


typedef union 
{
   DOUBLE f;
   LONG i[2];
} DOUBLE_BIT_MANIPULATOR;

#ifdef _MISRA_RULES
#pragma diag(pop)
#endif /* _MISRA_RULES */

#endif /* _UTIL_H */
