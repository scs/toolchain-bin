#pragma once
#ifndef __NO_BUILTIN
#pragma system_header /* raw_typedef.h */
#endif
/************************************************************************
 *
 * raw_typedef.h
 *
 * Copyright (C) 2000-2003 Analog Devices, Inc.
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License. See the file COPYING.LIB for more details.
 *
 * Non-LGPL License is also available as part of VisualDSP++
 * from Analog Devices, Inc.
 *
 ************************************************************************/

/* raw type definitions */

#ifndef _RAW_TYPEDEF_H
#define _RAW_TYPEDEF_H

#if defined(__ADSPBLACKFIN__)

typedef char  _raw8;
typedef short _raw16;
typedef int   _raw32;
#if !defined(__NO_BUILTIN)
typedef short __v2hi __attribute__ ((vector_size (4)));
#endif

#elif defined(__ADSPTS__)

/* All TS types are at least 32 bits, but we pretend with these. */
typedef int    _raw32;
typedef _raw32 _raw8;
typedef _raw32 _raw16;

#endif

#endif /* _RAW_TYPEDEF_H */
