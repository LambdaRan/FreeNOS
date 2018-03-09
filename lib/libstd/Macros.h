/*
 * Copyright (C) 2009 Niek Linnenbank
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __MACROS_H
#define __MACROS_H

#include "Types.h"

#define TRUE    1
#define FALSE   0

#ifndef NULL
#define NULL    (void *)0
#endif 

#define ZERO    0
// Stringfies the given input
#define QUOTE(x) \
    #x
// Indirect quoting.
#define IQUOTE(x) \
    QUOTE(x)

// convert kilobyte to bytes
#define KiloByte(v) ((v) * 1024)
// convert megabytes to bytes
#define MegaByte(v) ((v) * 1024 * 1024)
// convert gigabytes to bytes
#define GigaByte(v) ((v) * 1024 * 1024 * 1024)

// TODO: #warning Integer range depends on the architecture. Move to libarch.
#define LONG_MIN -2147483647L
#define LONG_MAX  2147483647L
#define ULONG_MIN 0LU
#define ULONG_MAX 4294967295LU
#define INT_MIN -2147483647
#define INT_MAX  2147483647
#define UINT_MIN 0U
#define UINT_MAX 4294967295U

// Calculate a division, and round to up any remaining.
#define CEIL(number,divisor) \
    ((number) % (divisor) ? \
    ((number) / (divisor)) + 1 : (number) / (divisor))

#ifdef __cplusplus

// absolute value of a double
inline double doubleAbsolute(double number)
{
    return number < 0 ? -number : number;
}

// Compare two doubles using a epsilon number as precision indicator.
inline bool doubleEquals(double a, double b, double epsilon)
{
    return doubleAbsolute(a - b) < epsilon;
}

#endif // __cplusplus

// calculates offsets in data structures
#define offsetof(TYPE, MEMBER) \
    ((Size) &((TYPE *)0)->MEMBER)

// Used to define external C functions. 
#ifdef __cplusplus
#define C "C"
#define CPP
#else
#define C
#endif // __plusplus 

// Can be used to link a symbol inside a specific section.
#define SECTION(s) \
    __attribute__((__section__(s)))

// Declares an symbol to be forcibly "used".
#define USED \
    __attribute__((__used__))

// Ensures strict minimum memory requirements.
// This option effectively disabled extra padding by the compiler.
#define PACKED \
    __attribute__((__packed__))

// Aligns a symbol at the given boundary.
#define ALIGN(n) \
    __attribute__((aligned(n)))

#endif // !__MACROS_H 