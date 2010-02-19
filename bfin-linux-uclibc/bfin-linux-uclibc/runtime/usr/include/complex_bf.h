/************************************************************************
 *
 * complex_bf.h
 *
 * Copyright (C) 1996-2007 Analog Devices, Inc.
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License. See the file COPYING.LIB for more details.
 *
 * Non-LGPL License is also available as part of VisualDSP++
 * from Analog Devices, Inc.
 *
 ************************************************************************/

#pragma once
#ifndef __NO_BUILTIN
#pragma system_header /* complex_fns.h */
#endif

#ifndef __COMPLEX_BF_DEFINED
#define __COMPLEX_BF_DEFINED

#include <complex_typedef.h>
#include <fract_complex.h>

#ifdef _MISRA_RULES
#pragma diag(push)
#pragma diag(suppress:misra_rule_6_3)
#pragma diag(suppress:misra_rule_8_1)
#pragma diag(suppress:misra_rule_8_5)
#pragma diag(suppress:misra_rule_19_4)
#pragma diag(suppress:misra_rule_19_6)
#pragma diag(suppress:misra_rule_19_7)
#endif /* _MISRA_RULES */


#ifdef __cplusplus
  extern "C" {
#endif






/* * * *        cadd      * * * *
 *
 *    Complex addition
 *
 */

__inline__
__attribute__ ((always_inline))
        static complex_float caddf (complex_float _a,
                                    complex_float _b)
        {
           complex_float _c;
           _c.re = _a.re + _b.re;
           _c.im = _a.im + _b.im;
           return _c;
        }

        complex_long_double caddd (complex_long_double _a,
                                   complex_long_double _b) asm ("__caddd");


#ifdef __DOUBLES_ARE_FLOATS__
__inline__
__attribute__ ((always_inline))
        static complex_double cadd (complex_double _a,
                                    complex_double _b)
        {
           complex_double _c;
           _c.re = _a.re + _b.re;
           _c.im = _a.im + _b.im;
           return _c;
        }
#else
        complex_double cadd (complex_double _a, complex_double _b) asm ("__caddd");
#endif






/* * * *        csub      * * * *
 *
 *    Complex subtraction
 *
 */

__inline__
__attribute__ ((always_inline))
        static complex_float csubf (complex_float _a,
                                    complex_float _b)
        {
           complex_float _c;
           _c.re = _a.re - _b.re;
           _c.im = _a.im - _b.im;
           return _c;
        }

        complex_long_double csubd (complex_long_double _a,
                                   complex_long_double _b) asm ("__csubd");

#ifdef __DOUBLES_ARE_FLOATS__
__inline__
__attribute__ ((always_inline))
        static complex_double csub (complex_double _a,
                                    complex_double _b)
        {
           complex_double _c;
           _c.re = _a.re - _b.re;
           _c.im = _a.im - _b.im;
           return _c;
        }
#else
        complex_double csub (complex_double _a, complex_double _b) asm ("__csubd");
#endif





/* * * *        cmlt      * * * *
 *
 *    Complex multiplication
 *
 */

__inline__
__attribute__ ((always_inline))
        static complex_float cmltf (complex_float _a,
                                    complex_float _b)
        {
           complex_float _c;
           _c.re = (_a.re * _b.re) - (_a.im* + _b.im);
           _c.im = (_a.re * _b.im) + (_a.im* + _b.re);
           return _c;
        }

        complex_long_double cmltd (complex_long_double _a,
                                   complex_long_double _b) asm ("__cmltd");


#ifdef __DOUBLES_ARE_FLOATS__
__inline__
__attribute__ ((always_inline))
        static complex_double cmlt (complex_double _a,
                                    complex_double _b)
        {
           complex_double _c;
           _c.re = (_a.re * _b.re) - (_a.im* + _b.im);
           _c.im = (_a.re * _b.im) + (_a.im* + _b.re);
           return _c;
        }
#else
        complex_double cmlt (complex_double _a,
                             complex_double _b) asm ("__cmltd");
#endif






/* * * *        cdiv      * * * *
 *
 *    Complex division
 *
 */

        complex_float cdivf (complex_float _a, complex_float _b) asm ("__cdivf");

        complex_long_double cdivd (complex_long_double _a,
                                   complex_long_double _b) asm ("__cdivd");

#ifdef __DOUBLES_ARE_FLOATS__

        complex_double cdiv (complex_double _a, complex_double _b) asm ("__cdivf");
#else
        complex_double cdiv (complex_double _a, complex_double _b) asm ("__cdivd");
#endif






/* * * *        norm      * * * *
 *
 *    Normalize complex number
 *
 */

        complex_float normf (complex_float _a) asm ("__normf");

        complex_long_double normd (complex_long_double _a) asm ("__normd");


#ifdef __DOUBLES_ARE_FLOATS__
        complex_double norm (complex_double _a) asm ("__normf");
#else
        complex_double norm (complex_double _a) asm ("__normd");
#endif








/* * * *        polar      * * * *
 *
 *    Convert polar coordinates to cartesian notation
 *
 */

        complex_float polarf (float _magnitude, float _phase) asm ("__polarf");

        complex_long_double polard (long double _magnitude,
                                    long double _phase) asm ("__polard");

#ifdef __DOUBLES_ARE_FLOATS__
        complex_double polar (double _magnitude, double _phase) asm ("__polarf");
#else
        complex_double polar (double _magnitude, double _phase) asm ("__polard");
#endif





/* * * *        cartesian  * * * *
 *
 *    Convert cartesian coordinates to polar notation
 *    (Return value == magnitude)
 *
 */

        float cartesianf (complex_float _a, float* _phase) asm ("__cartesianf");

        long double cartesiand (complex_long_double _a, long double* _phase) asm ("__cartesiand");


#ifdef __DOUBLES_ARE_FLOATS__
        double cartesian (complex_double _a, double* _phase) asm ("__cartesianf");
#else
        double cartesian (complex_double _a, double* _phase) asm ("__cartesiand");
#endif



#ifdef __cplusplus
}       /* end extern "C" */
#endif


#ifdef _MISRA_RULES
#pragma diag(pop)
#endif /* _MISRA_RULES */


#endif   /* __COMPLEX_BF_DEFINED  (include guard) */
