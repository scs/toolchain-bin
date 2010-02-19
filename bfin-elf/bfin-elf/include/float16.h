/************************************************************************
 *
 * float16.h
 *
 * Copyright (C) 1996-2007 Analog Devices, Inc.
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License. See the file COPYING.LIB for more details.
 *
 * Non-LGPL License is also available as part of VisualDSP++
 * from Analog Devices, Inc.
 *
 ************************************************************************/

/*
** C prototype functions for C++ float16 class.
** float16 is a 32-bit type. Exponent is low-half.
** Mantissa is high half:
** s mmm mmmm mmmm mmmm s eee eeee eeee eeee
** Exponent is unbiased, and there is no hidden bit,
** numbers are normalised to 0.x, not 1.x.
*/

#pragma once
#ifndef __NO_BUILTIN
#pragma system_header /* float16.h */
#endif

#ifndef _FLOAT16_H
#define _FLOAT16_H

#ifdef _MISRA_RULES
#pragma diag(push)
#pragma diag(suppress:misra_rule_5_7)
#pragma diag(suppress:misra_rule_6_3)
#pragma diag(suppress:misra_rule_8_1)
#pragma diag(suppress:misra_rule_8_5)
#pragma diag(suppress:misra_rule_12_6)
#pragma diag(suppress:misra_rule_18_4)
#pragma diag(suppress:misra_rule_19_1)
#endif /* _MISRA_RULES */

#ifdef _FLOAT16_NO_INLINE

typedef long float16;

#else

typedef union {
      long l;           /* for simple initialisations  */
      unsigned long u;  /* for conversions             */
      struct {
         short e;       /* low half                    */     
         short m;       /* high half                   */
      } s;
      float f;          /* for conversions             */       
} float16;

#endif /* _FLOAT16_NO_INLINE */

#include <fract.h>

#define PlusInf_fl16  0x7fffffff
#define NegInf_fl16   0x8000ffff
#define NaN_fl16      0x00008000

#ifdef _FLOAT16_NO_INLINE

#ifdef __cplusplus
extern "C" {
#endif

float16 fr16_to_fl16(fract16);
fract16 fl16_to_fr16(float16);
float16 norm_fl16(float16);
float16 add_fl16(float16, float16);
float16 sub_fl16(float16, float16);
float16 mul_fl16(float16, float16);
float16 div_fl16(float16, float16);
float16 negate_fl16(float16);
float16 abs_fl16(float16);
int cmp_fl16(float16, float16);
float16 fl_to_fl16(float);
int fits_in_fl16(float);
float fl16_to_fl(float16);

#ifdef __cplusplus
}
#endif

#else

__inline__
float16 fr16_to_fl16(fract16 fr)
{
   float16 fl = { 0 };
   if (fr != 0) {
      short exponent = (short) norm_fr1x16(fr);
      unsigned int temp;
      fl.s.e = -exponent;
      temp = (unsigned int)fr << exponent;
      fl.s.m = (short)temp;
   }
   return fl;
}

__inline__
fract16 fl16_to_fr16(float16 fl)
{
   fract16 fraction = fl.s.m;
   short exponent = fl.s.e;

   return shl_fr1x16(fraction, (int)exponent);
}

__inline__
static float16 norm_fl16(float16 fl)
{
   if (fl.s.m != 0) {
      short exponent = (short)norm_fr1x16(fl.s.m);
      fl.s.m <<= exponent;
      fl.s.e -= exponent;
   } else {
      fl.s.e = 0;
   }
   return fl;
}

__inline__
float16 add_fl16(float16 x, float16 y)
{
   int d = x.s.e - y.s.e;
   float16 fl = x, a = y;
   int xneg = x.l < 0;
   int yneg = y.l < 0;
   unsigned int misra_temp;
   if (d < 0) {
      fl = y;
      a = x;
   }
   d = abs_fr1x32(d);
   misra_temp = (unsigned int)a.s.m >> d;
   fl.s.m += misra_temp;
   /* check for overflow. Isn't a quick way of doing this in C. */
   if ((xneg == yneg) && (xneg != (fl.l < 0))) {
      unsigned short u;
      u = (unsigned short)fl.s.m >> 1;
      u |= (unsigned short)((unsigned short)xneg << 15);
      fl.s.m = (short)u;
      fl.s.e++;
   } else if (fl.s.m != 0) {
      short exponent = (short)norm_fr1x16(fl.s.m);
      fl.s.m <<= exponent;
      fl.s.e -= exponent;
   } else {
      fl.s.e = 0;
   }
   return fl;
}

__inline__
float16 sub_fl16(float16 x, float16 y)
{
   int d = x.s.e - y.s.e;
   float16 fl = x, a = y;
   int xneg = x.l < 0;
   int yneg = y.l < 0;
   if (d < 0) {
      d = -d;
      fl.s.m >>= d;
      fl.s.e += d;
   } else {
      a.s.m >>= d;
   }
   fl.s.m -= a.s.m;
   /* check for overflow. Isn't a quick way of doing this in C. */
   if ((xneg != yneg) && (yneg == (fl.l < 0))) {
      unsigned short u;
      u = (unsigned short)fl.s.m >> 1;
      u |= (unsigned short)((unsigned short)xneg << 15);
      fl.s.m = (short)u;
      fl.s.e++;
   } else if (fl.s.m != 0) {
      short exponent = (short)norm_fr1x16(fl.s.m);
      fl.s.m <<= exponent;
      fl.s.e -= exponent;
   } else {
      fl.s.e = 0;
   }
   return fl;
}

__inline__
float16 mul_fl16(float16 x, float16 y)
{
   float16 fl;

   fl.s.e  = x.s.e + y.s.e;
   fl.s.m = mult_fr1x16(x.s.m, y.s.m);
   if (fl.s.m != 0) {
      short exponent = (short)norm_fr1x16(fl.s.m);
      fl.s.m <<= exponent;
      fl.s.e -= exponent;
   } else {
      fl.s.e = 0;
   }
   return fl;
}

__inline__
float16 div_fl16(float16 x, float16 y)
{
   int i;
   int niters = 15;
   const long one = 0x40000001;
   float16 fl;
   int xneg = x.l < 0;
   int yneg = y.l < 0;
   unsigned short r = 0u;
   unsigned short d = (unsigned short)x.s.m;
   unsigned short q = (unsigned short)y.s.m;
   signed short tmp;
   if (y.l == 0) {
      fl.l=NaN_fl16;
   } else if (y.l == one) {
      fl = x;
   } else if (x.l == y.l) {
      fl.l = one;
   } else {
     fl.s.e = x.s.e - y.s.e;
     if (xneg != 0) {
        tmp = -(short)d;
        d = (unsigned short)tmp;
     }
     if (yneg != 0) {
        tmp = -(short)q;
        q = (unsigned short)tmp;
     }
     for (i = 0; i < niters; i++) {
        if (q <= d) {
           d -= q;
           r |= 1u;
        }
        d <<= 1;
        r <<= 1;
     }
     d = r;
     if ((d & 0x8000u) != 0) {
        /* overflow */
        d >>= 1;
        fl.s.e++;
     }
     if (xneg != yneg) {
        tmp = -(short)d;
        d = (unsigned short)tmp;
     }
     fl.s.m = (short)d;       /* truncation  */
     if (fl.s.m != 0) {
        short exponent = (short)norm_fr1x16(fl.s.m);
        fl.s.m <<= exponent;
        fl.s.e -= exponent;
     } else {
        fl.s.e = 0;
     }
   }
   return fl;
}

__inline__
float16 negate_fl16(float16 fl)
{
   fl.s.m = -fl.s.m;
   return fl;
}

__inline__
float16 abs_fl16(float16 fl)
{
   fl.s.m = abs_fr1x16(fl.s.m);
   return fl;
}

__inline__
int cmp_fl16(float16 x, float16 y)
{
   /* x < y  => negative
   ** x == y =>  0
   ** x > y  => positive
   */
   int neg = 0;
   int res;
   short resl, resh;
   int xneg = x.l < 0;   /* x.u & 0x80000000 might be faster */
   int yneg = y.l < 0;

   /* If both are negative, compare and negate.
   ** If both positive, just compare.
   ** If signs differ, return 1, with sign of x.
   */
   
   if (xneg == yneg) {
     neg = xneg;

     resh = sub_fr1x16(x.s.m, y.s.m);
     resl = sub_fr1x16(x.s.e, y.s.e);
     if (resl == 0) {
        resl = resh;
     }
     res = resl;
     if (neg != 0) {
      res = -res;
     }
   } else {
     unsigned int temp;
     temp = ((unsigned int)xneg << 31) | 1u;
     res = (int)temp;
   }
   return res;
}

__inline__
float16 fl_to_fl16(float f)
{
   float16 fl;
   unsigned long sign, uexp;
   long exponent;
   fl.f = f;
   if ((fl.u << 1) == 0) {
      /* -0.0 or +0.0 - needs special handling */
      fl.u = 0ul;
   } else {
     sign = (fl.u >> 31) << 31;
     uexp = (fl.u << 1) >> 24;
     uexp = uexp - 127u;
     exponent = (long)uexp;
     exponent += 1;   /* because we have to include the hidden bit */
     fl. u |= (unsigned int)1<<23;   /* add the hidden bit */
     fl.u <<= 8;   /* move 24-bit mantissa to top, to remove exp & sign */
     fl.u >>= 1;   /* back one space, for sign */
#ifdef DEBUG
     if (fl.s.e) {
        printf("Warning: precision lost %08x\n", fl.s.e);
     }
#endif
     fl.s.e = (short)exponent;
     if (sign != 0) {
        fl.s.m = -fl.s.m;
     }
   }
   return fl;
}

__inline__
int fits_in_fl16(float f)
{
   float16 fl;
   fl.f = f;
   return (fl.u & 0xffu) == 0;
}

__inline__
float fl16_to_fl(float16 fl)
{
   unsigned long exponent, sign;
   if (fl.u != 0) {
     short temp;
     sign = (fl.u >> 31) << 31;
     temp = fl.s.e + 127 - 1;   /* remove one, for hidden bit */
     exponent = (unsigned long)temp;   
     if (((unsigned short)fl.s.m & 0xffffu) == 0x8000u) {
        fl.s.m = 0x4000;
        exponent++;
     } else if (sign != 0) {
        fl.s.m = -fl.s.m;
     } else {
        ; /* required by MISRA */
     }
     fl.s.e = 0;
     fl.u <<= 2;   /* remove sign bit and hidden bit*/
     fl.u >>= 9;
     exponent <<= 23;
     fl.u = sign | exponent | fl.u;
   }
   return fl.f;
}

#endif /*  NO_INLINE */

#ifdef _MISRA_RULES
#pragma diag(pop)
#endif /* _MISRA_RULES */

#endif /* _FLOAT16_H */
