#pragma once
#ifndef __NO_BUILTIN
#pragma system_header /* r2x16_typedef.h */
#endif
/************************************************************************
 *
 * r2x16_typedef.h
 *
 * Copyright (C) 2000-2003 Analog Devices, Inc.
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License. See the file COPYING.LIB for more details.
 *
 * Non-LGPL License is also available as part of VisualDSP++
 * from Analog Devices, Inc.
 *
 ************************************************************************/

/* Defines two 16-bit values packed into a single 32-bit word.  */

#ifndef _R2x16_TYPEDEF_H
#define _R2x16_TYPEDEF_H

#if defined(__ADSPBLACKFIN__) || defined(__ADSPTS__)

#include <raw_typedef.h>

#if !defined(__NO_BUILTIN)
typedef __v2hi	raw2x16;
#else
typedef _raw32	raw2x16;
#endif

#endif

#endif /* _R2x16_TYPEDEF_H */
