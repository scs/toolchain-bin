/************************************************************************
 *
 * matrix.h
 *
 * Copyright (C) 1996-2005 Analog Devices, Inc.
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License. See the file COPYING.LIB for more details.
 *
 * Non-LGPL License is also available as part of VisualDSP++
 * from Analog Devices, Inc.
 *
 ************************************************************************/

#pragma once
#ifndef __NO_BUILTIN
#pragma system_header /* matrix.h */
#endif

#ifndef __MATRIX_DEFINED
#define __MATRIX_DEFINED

#include <fract_typedef.h>
#include <complex_bf.h>
#include <vector.h>

#ifdef _MISRA_RULES
#pragma diag(push)
#pragma diag(suppress:misra_rule_6_3)
#pragma diag(suppress:misra_rule_8_1)
#pragma diag(suppress:misra_rule_8_5)
#endif /* _MISRA_RULES */


#ifdef __cplusplus
 extern "C" {
#endif 


/* * * *        matsadd      * * * *
 *
 *    real matrix + real scalar addition
 * 
 */

__inline__
      static void matsaddf (const float _matrix[], 
                                     float _scalar, 
                                     int _rows, int _columns, 
                                     float _sum[])
            {vecsaddf (_matrix, _scalar, _sum, _rows*_columns);}

__inline__
      static void matsadd (const double _matrix[], 
                                    double _scalar, 
                                    int _rows, int _columns, 
                                    double _sum[])
            {vecsadd (_matrix, _scalar, _sum, _rows*_columns);}

__inline__
      static void matsaddd (const long double _matrix[], 
                                     long double _scalar,
                                     int _rows, int _columns, 
                                     long double _sum[])
            {vecsaddd (_matrix, _scalar, _sum, _rows*_columns);}

__inline__
      static void matsadd_fr16 (const fract16 _matrix[], 
                                         fract16 _scalar, 
                                         int _rows, int _columns, 
                                         fract16 _sum[])
            {vecsadd_fr16 (_matrix, _scalar, _sum, _rows*_columns);}




/* * * *        matssub      * * * *
 *
 *    real matrix - real scalar subtraction
 * 
 */

__inline__
      static void matssubf (const float _matrix[], 
                                     float _scalar,
                                     int _rows, int _columns, 
                                     float _difference[])
            {vecssubf (_matrix, _scalar, _difference, _rows*_columns);}

__inline__
      static void matssub (const double _matrix[], 
                                    double _scalar, 
                                    int _rows, int _columns,
                                    double _difference[])
            {vecssub (_matrix, _scalar, _difference, _rows*_columns);}

__inline__
      static void matssubd (const long double _matrix[], 
                                     long double _scalar,
                                     int _rows, int _columns,
                                     long double _difference[])
            {vecssubd (_matrix, _scalar, _difference, _rows*_columns);}

__inline__
      static void matssub_fr16 (const fract16 _matrix[], 
                                         fract16 _scalar, 
                                         int _rows, int _columns,
                                         fract16 _difference[])
            {vecssub_fr16 (_matrix, _scalar, _difference, _rows*_columns);}




/* * * *        matsmlt      * * * *
 *
 *    real matrix * real scalar multiplication
 * 
 */

__inline__
      static void matsmltf (const float _matrix[], 
                                     float _scalar, 
                                     int _rows, int _columns, 
                                     float _product[])
            {vecsmltf (_matrix, _scalar, _product, _rows*_columns);}

__inline__
      static void matsmlt (const double _matrix[], 
                                    double _scalar, 
                                    int _rows, int _columns, 
                                    double _product[])
            {vecsmlt (_matrix, _scalar, _product, _rows*_columns);}

__inline__
      static void matsmltd (const long double _matrix[], 
                                     long double _scalar,
                                     int _rows, int _columns, 
                                     long double _product[])
            {vecsmltd (_matrix, _scalar, _product, _rows*_columns);}

__inline__
      static void matsmlt_fr16 (const fract16 _matrix[], 
                                         fract16 _scalar, 
                                         int _rows, int _columns, 
                                         fract16 _product[])
            {vecsmlt_fr16 (_matrix, _scalar, _product, _rows*_columns);}

      void MatrixMultVec3x1Frac28_4(fract32 A[][3], fract32 B[], fract32 Res[]);                          

      void MatrixMultVec3x1Frac24_8(fract32 A[][3], fract32 B[], fract32 Res[]);

      void MatrixMultVec4x1Frac24_8(fract32 A[][4], fract32 B[], fract32 Res[]);



/* * * *        matmadd      * * * *
 *
 *    real matrix + real matrix addition
 * 
 */

__inline__
      static void matmaddf (const float _matrix_x[], 
                                     const float _matrix_y[], 
                                     int _rows, int _columns, 
                                     float _sum[])
            {vecvaddf (_matrix_x, _matrix_y, _sum, _rows*_columns);}

__inline__
      static void matmadd (const double _matrix_x[], 
                                    const double _matrix_y[], 
                                    int _rows, int _columns, 
                                    double _sum[])
            {vecvadd (_matrix_x, _matrix_y, _sum, _rows*_columns);}

__inline__
      static void matmaddd (const long double _matrix_x[], 
                                     const long double _matrix_y[],
                                     int _rows, int _columns, 
                                     long double _sum[])
            {vecvaddd (_matrix_x, _matrix_y, _sum, _rows*_columns);}

__inline__
      static void matmadd_fr16 (const fract16 _matrix_x[], 
                                         const fract16 _matrix_y[], 
                                         int _rows, int _columns, 
                                         fract16 _sum[])
            {vecvadd_fr16 (_matrix_x, _matrix_y, _sum, _rows*_columns);}




/* * * *        matmsub      * * * *
 *
 *    real matrix - real matrix subtraction
 * 
 */

__inline__
      static void matmsubf (const float _matrix_x[], 
                                     const float _matrix_y[], 
                                     int _rows, int _columns, 
                                     float _difference[])
            {vecvsubf (_matrix_x, _matrix_y, _difference, _rows*_columns);}

__inline__
      static void matmsub (const double _matrix_x[], 
                                    const double _matrix_y[], 
                                    int _rows, int _columns, 
                                    double _difference[])
            {vecvsub (_matrix_x, _matrix_y, _difference, _rows*_columns);}

__inline__
      static void matmsubd (const long double _matrix_x[], 
                                     const long double _matrix_y[],
                                     int _rows, int _columns, 
                                     long double _difference[])
            {vecvsubd (_matrix_x, _matrix_y, _difference, _rows*_columns);}

__inline__
      static void matmsub_fr16 (const fract16 _matrix_x[], 
                                         const fract16 _matrix_y[], 
                                         int _rows, int _columns, 
                                         fract16 _difference[])
            {vecvsub_fr16 (_matrix_x, _matrix_y, _difference, _rows*_columns);}




/* * * *        matmmlt      * * * *
 *
 *    real matrix * real matrix multiplication
 *
 */

        void matmmltf (const float _matrix_x[], 
                       int _rows_x, int _columns_x, 
                       const float _matrix_y[], 
                       int _columns_y, 
                       float _product[]) asm ("__matmmltf");

        void matmmltd (const long double _matrix_x[], 
                       int _rows_x, int _columns_x,
                       const long double _matrix_y[], 
                       int _columns_y, 
                       long double _product[]) asm ("__matmmltd");

#ifdef __DOUBLES_ARE_FLOATS__
        void matmmlt (const double _matrix_x[],
                      int _rows_x, int _columns_x,
                      const double _matrix_y[],
                      int _columns_y,
                      double _product[]) asm ("__matmmltf");
#else
        void matmmlt (const double _matrix_x[],
                      int _rows_x, int _columns_x,
                      const double _matrix_y[],
                      int _columns_y,
                      double _product[]) asm ("__matmmltd");
#endif 

        void matmmlt_fr16 (const fract16 _matrix_x[], 
                           int _rows_x, int _columns_x, 
                           const fract16 _matrix_y[], 
                           int _columns_y,
                           fract16 _product[]) asm ("__matmmlt_fr16");





/* * * *        cmatsadd      * * * *
 *
 *    complex matrix + complex scalar addition
 * 
 */

__inline__
      static void cmatsaddf (const complex_float _matrix[], 
                                      complex_float _scalar, 
                                      int _rows, int _columns, 
                                      complex_float _sum[])
            {cvecsaddf (_matrix, _scalar, _sum, _rows*_columns);}

__inline__
      static void cmatsadd (const complex_double _matrix[], 
                                     complex_double _scalar, 
                                     int _rows, int _columns, 
                                     complex_double _sum[])
            {cvecsadd (_matrix, _scalar, _sum, _rows*_columns);}

__inline__
      static void cmatsaddd (const complex_long_double _matrix[],
                                      complex_long_double _scalar, 
                                      int _rows, int _columns,
                                      complex_long_double _sum[])
            {cvecsaddd (_matrix, _scalar, _sum, _rows*_columns);}


__inline__
      static void cmatsadd_fr16 (const complex_fract16 _matrix[], 
                                          complex_fract16 _scalar, 
                                          int _rows, int _columns, 
                                          complex_fract16 _sum[])
            {cvecsadd_fr16 (_matrix, _scalar, _sum, _rows*_columns);}




/* * * *        cmatssub      * * * *
 *
 *    complex matrix - complex scalar 
 * 
 */

__inline__
      static void cmatssubf (const complex_float _matrix[], 
                                      complex_float _scalar, 
                                      int _rows, int _columns, 
                                      complex_float _difference[])
            {cvecssubf (_matrix, _scalar, _difference, _rows*_columns);}

__inline__
      static void cmatssub (const complex_double _matrix[], 
                                     complex_double _scalar, 
                                     int _rows, int _columns, 
                                     complex_double _difference[])
            {cvecssub (_matrix, _scalar, _difference, _rows*_columns);}

__inline__
      static void cmatssubd (const complex_long_double _matrix[],
                                      complex_long_double _scalar, 
                                      int _rows, int _columns,
                                      complex_long_double _difference[])
            {cvecssubd (_matrix, _scalar, _difference, _rows*_columns);}

__inline__
      static void cmatssub_fr16 (const complex_fract16 _matrix[], 
                                          complex_fract16 _scalar, 
                                          int _rows, int _columns, 
                                          complex_fract16 _difference[])
            {cvecssub_fr16 (_matrix, _scalar, _difference, _rows*_columns);}




/* * * *        cmatsmlt      * * * *
 *
 *    complex matrix * complex scalar multiplication
 * 
 */

__inline__
      static void cmatsmltf (const complex_float _matrix[], 
                                      complex_float _scalar, 
                                      int _rows, int _columns, 
                                      complex_float _product[])
            {cvecsmltf (_matrix, _scalar, _product, _rows*_columns);}

__inline__
      static void cmatsmlt (const complex_double _matrix[], 
                                     complex_double _scalar, 
                                     int _rows, int _columns, 
                                     complex_double _product[])
            {cvecsmlt (_matrix, _scalar, _product, _rows*_columns);}

__inline__
      static void cmatsmltd (const complex_long_double _matrix[],
                                      complex_long_double _scalar, 
                                      int _rows, int _columns,
                                      complex_long_double _product[])
            {cvecsmltd (_matrix, _scalar, _product, _rows*_columns);}

__inline__
      static void cmatsmlt_fr16 (const complex_fract16 _matrix[], 
                                          complex_fract16 _scalar, 
                                          int _rows, int _columns, 
                                          complex_fract16 _product[])
            {cvecsmlt_fr16 (_matrix, _scalar, _product, _rows*_columns);}




/* * * *        cmatmadd      * * * *
 *
 *    complex matrix + complex matrix addition
 * 
 */

__inline__
      static  void cmatmaddf (const complex_float _matrix_a[], 
                                      const complex_float _matrix_b[], 
                                      int _rows, int _columns, 
                                      complex_float _sum[])
            {cvecvaddf (_matrix_a, _matrix_b, _sum, _rows*_columns);}

__inline__
      static void cmatmadd (const complex_double _matrix_a[], 
                                     const complex_double _matrix_b[], 
                                     int _rows, int _columns, 
                                     complex_double _sum[])
            {cvecvadd (_matrix_a, _matrix_b, _sum, _rows*_columns);}

__inline__
      static void cmatmaddd (const complex_long_double _matrix_a[],
                                      const complex_long_double _matrix_b[],
                                      int _rows, int _columns, 
                                      complex_long_double _sum[])
            {cvecvaddd (_matrix_a, _matrix_b, _sum, _rows*_columns);}

__inline__
      static void cmatmadd_fr16 (const complex_fract16 _matrix_a[], 
                                          const complex_fract16 _matrix_b[], 
                                          int _rows, int _columns, 
                                          complex_fract16 _sum[])
            {cvecvadd_fr16 (_matrix_a, _matrix_b, _sum, _rows*_columns);}




/* * * *        cmatmsub      * * * *
 *
 *    complex matrix - complex matrix subtraction
 * 
 */

__inline__
      static void cmatmsubf (const complex_float _matrix_a[], 
                                      const complex_float _matrix_b[], 
                                      int _rows, int _columns, 
                                      complex_float _difference[])
            {cvecvsubf (_matrix_a, _matrix_b, _difference, _rows*_columns);}

__inline__
      static void cmatmsub (const complex_double _matrix_a[], 
                                     const complex_double _matrix_b[], 
                                     int _rows, int _columns, 
                                     complex_double _difference[])
            {cvecvsub (_matrix_a, _matrix_b, _difference, _rows*_columns);}

__inline__
      static void cmatmsubd (const complex_long_double _matrix_a[],
                                      const complex_long_double _matrix_b[],
                                      int _rows, int _columns, 
                                      complex_long_double _difference[])
            {cvecvsubd (_matrix_a, _matrix_b, _difference, _rows*_columns);}

__inline__
      static void cmatmsub_fr16 (const complex_fract16 _matrix_a[], 
                                          const complex_fract16 _matrix_b[], 
                                          int _rows, int _columns, 
                                          complex_fract16 _difference[])
           {cvecvsub_fr16 (_matrix_a, _matrix_b, _difference, _rows*_columns);}




/* * * *        cmatmmlt      * * * *
 *
 *    complex matrix multiplication
 * 
 */

        void cmatmmltf (const complex_float _matrix_a[], 
                        int _rows_a, int _columns_a, 
                        const complex_float _matrix_b[], 
                        int _columns_b, 
                        complex_float _product[]) asm ("__cmatmmltf");

        void cmatmmltd (const complex_long_double _matrix_a[], 
                        int _rows_a, int _columns_a,
                        const complex_long_double _matrix_b[], 
                        int _columns_b,
                        complex_long_double _product[]) asm ("__cmatmmltd");

#ifdef __DOUBLES_ARE_FLOATS__
        void cmatmmlt (const complex_double _matrix_a[], 
                       int _rows_a, int _columns_a, 
                       const complex_double _matrix_b[], 
                       int _columns_b, 
                       complex_double _product[]) asm ("__cmatmmltf");
#else
        void cmatmmlt (const complex_double _matrix_a[], 
                       int _rows_a, int _columns_a, 
                       const complex_double _matrix_b[], 
                       int _columns_b, 
                       complex_double _product[]) asm ("__cmatmmltd");
#endif


        void cmatmmlt_fr16 (const complex_fract16 _matrix_a[], 
                            int _rows_a, int _columns_a, 
                            const complex_fract16 _matrix_b[], 
                            int _columns_b, 
                            complex_fract16 _product[]) asm ("__cmatmmlt_fr16");




/* * * *        transpm      * * * *
 *
 *    Transpose Matrix
 * 
 */

        void transpmf (const float _matrix[], 
                       int _rows, int _columns, 
                       float _transpose[]) asm ("__transpmf");

        void transpmd (const long double _matrix[], 
                       int _rows, int _columns, 
                       long double _transpose[]) asm ("__transpmd");

#ifdef __DOUBLES_ARE_FLOATS__
        void transpm (const double _matrix[], 
                      int _rows, int _columns, 
                      double _transpose[]) asm ("__transpmf");
#else
        void transpm (const double _matrix[], 
                      int _rows, int _columns, 
                      double _transpose[]) asm ("__transpmd");
#endif


        void transpm_fr16 (const fract16 _matrix[], 
                           int _rows, int _columns, 
                           fract16 _transpose[]) asm ("__transpm_fr16");



#ifdef __cplusplus
 }    /* end extern "C" */
#endif 

#ifdef _MISRA_RULES
#pragma diag(pop)
#endif /* _MISRA_RULES */

#endif   /* __MATRIX_DEFINED  (include guard) */
