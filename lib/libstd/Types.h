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

#ifndef __TYPES_H
#define __TYPES_H

#ifndef __ASSEMBLER__

#if 0
#define BITWISE \
    __attribute__((bitwise))
#else
#define BITWISE
#endif

typedef unsigned int uint;
typedef unsigned long ulong;
typedef unsigned long long u64;
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

typedef signed int sint;
typedef signed long slong;
typedef signed long long s64;
typedef signed int s32;
typedef signed short int s16;
typedef signed char s8;

typedef u64 BITWISE le64;
typedef u64 BITWISE be64;
typedef u32 BITWISE le32;
typedef u32 BITWISE be32;
typedef u16 BITWISE le16;
typedef u16 BITWISE be16;
typedef u8  BITWISE le8;
typedef u8  BITWISE be8;

typedef unsigned int Size;
typedef unsigned long Address;
typedef unsigned short UserID;
typedef unsigned short GroupID;
typedef u16 ProcessID;

// Describes a device ID number.                                                                                                                                     
typedef struct DeviceID                                                               
{                                                                                     
    // Major device ID number is a PID.                                            
    ProcessID major;
    // Device specific minor ID number. 
    u16 minor;
}
DeviceID;

// Error code defined in Error.h
typedef slong Error;

#ifdef __cplusplus

namespace Number
{
    // Numeral system base type.
    typedef enum Base
    {
        Dec, // Decimal: 0-10 
        Hex, // Hexadecimal: 0x0-0xf 
    }
    Base;
};

#endif 

#endif 
#endif 