/************************************************************************
 *
 * math_bf.h
 *
 * Copyright (C) 2002-2006 Analog Devices, Inc.
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License. See the file COPYING.LIB for more details.
 *
 * Non-LGPL License is also available as part of VisualDSP++
 * from Analog Devices, Inc.
 *
 ************************************************************************/

#pragma once
#ifndef __NO_BUILTIN
#pragma system_header /* math_bf.h */
#endif

/*
   This header file contains all ADSP Blackfin specific
   Analog extensions to the ANSI header file math.h.
 */
   
#ifndef  _MATH_BF_H
#define  _MATH_BF_H

#include <fract_typedef.h>
#include <fract_math.h>
#include <gcc.h>

#ifdef _MISRA_RULES
#pragma diag(push)
#pragma diag(suppress:misra_rule_5_7)
#pragma diag(suppress:misra_rule_6_3)
#pragma diag(suppress:misra_rule_8_1)
#pragma diag(suppress:misra_rule_8_5)
#pragma diag(suppress:misra_rule_18_4)
#pragma diag(suppress:misra_rule_19_4)
#endif /* _MISRA_RULES */


#ifdef __cplusplus
extern "C" {
#endif

/* * * *        acos     * * * *
 *    Arc cosine
 */
        fract16 acos_fr16 (fract16 _x) asm ("__acos_fr16");


/* * * *        asin     * * * *
 *    Arc sine
 */
        fract16 asin_fr16 (fract16 _x) asm ("__asin_fr16");


/* * * *        atan     * * * *
 *    Arc tangent
 */
        fract16 atan_fr16 (fract16 _x) asm ("__atan_fr16");


/* * * *        atan2    * * * *
 *    Arc tangent of quotient
 */
        fract16 atan2_fr16 (fract16 _x, fract16 _y) asm ("__atan2_fr16");


/* * * *        cos      * * * *
 *    Cosine
 */
        fract16 cos_fr16 (fract16 _x) asm ("__cos_fr16");


/* * * *        rsqrt    * * * *
 *    Inverse Square Root
 */
        float rsqrtf (float _x) asm ("__rsqrtf");

        long double rsqrtd (long double _x) asm ("__rsqrtd");


#ifdef __DOUBLES_ARE_FLOATS__
        double rsqrt (double _x) asm ("__rsqrtf");
#else
        double rsqrt (double _x) asm ("__rsqrtd");
#endif


/* * * *        sin      * * * *
 *    Sine
 */
        fract16 sin_fr16 (fract16 _x) asm ("__sin_fr16");


/* * * *        sqrt     * * * *
 *    Square Root
 */
        fract16 sqrt_fr16 (fract16 _x) asm ("__sqrt_fr16");


/* * * *        tan      * * * *
 *    Tangent
 */
        fract16 tan_fr16 (fract16 _x) asm ("__tan_fr16");


/* * * *        max      * * * *
 *    Maximum value
 */

#if !defined(__NO_BUILTIN) 
__inline__
__attribute__ ((always_inline))
        static int max(int _x, int _y) 
                { return __builtin_bfin_max(_x,_y); }

__inline__
__attribute__ ((always_inline))
        static long lmax(long _x, long _y)
          { return __builtin_bfin_lmax(_x, _y); }
#else
        int max (int _x, int _y) asm ("__max");

        long lmax (long _x, long _y) asm ("__max");

#endif /* NO_BUILTIN */

        long long  llmax (long long  _x, long long  _y) asm ("__llmax");


/* * * *        min      * * * *
 *    Minimum value
 */

#if !defined(__NO_BUILTIN)
__inline__
__attribute__ ((always_inline))
        static int min(int _x, int _y) 
                { return __builtin_bfin_min(_x,_y); }

__inline__
__attribute__ ((always_inline))
        static long lmin(long _x, long _y)
                { return __builtin_bfin_lmin(_x,_y); }
#else
        int min (int _x, int _y) asm ("__min");

        long lmin (long _x, long _y) asm ("__min");
#endif

        long long  llmin (long long  _x, long long  _y) asm ("__llmin");


/* * * *        clip     * * * *
 *    Clip value to limit
 *
 */
        float fclipf (float _value, float _limit) asm ("__fclipf");

        long double fclipd (long double _value, long double _limit) asm ("__fclipd");


#ifdef __DOUBLES_ARE_FLOATS__
        double fclip (double _value, double _limit) asm ("__fclipf");
#else
        double fclip (double _value, double _limit) asm ("__fclipd");
#endif


        fract16 clip_fr16 (fract16 _value, fract16 _limit) asm ("__clip_fr16");


        int clip (int _value, int _limit) asm ("__clip");

        long lclip (long _value, long _limit);

        long long  llclip (long long  _value, long long  _limit) asm ("__llclip");


/* * * *        copysign   * * * *
 *    Copy Sign of y (=reference) to x (=value)
 */
        float copysignf (float _x, float _y) asm ("__copysignf");

        long double copysignd (long double _x, long double _y) asm ("__copysignd");


#ifdef __DOUBLES_ARE_FLOATS__
        double copysign (double _x, double _y) asm ("__copysignf");
#else
        double copysign (double _x, double _y) asm ("__copysignd");
#endif


        fract16 copysign_fr16 (fract16 _x, fract16 _y) asm ("__copysign_fr16");


/* * * *        countones  * * * *
 *    Count number of 1 bits (parity)
 */
#if !defined(__NO_BUILTIN)
__inline__
__attribute__ ((always_inline))
        static int countones (int _x) 
                { return (int)__builtin_bfin_ones(_x); }
__inline__
__attribute__ ((always_inline))
        static int lcountones (long _x) 
                { return (int)__builtin_bfin_ones((int)_x); }
#else
        int countones (int _x) asm ("__countones");

        int lcountones (long _x) asm ("__lcountones");
#endif /* __NO_BUILTIN */

        int  llcountones (long long  _x) asm ("__llcountones");





#ifdef __cplusplus
}
#endif

#ifdef _MISRA_RULES
#pragma diag(pop)
#endif /* _MISRA_RULES */

#endif   /* _MATH_BF_H */
