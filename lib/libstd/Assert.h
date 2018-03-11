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

#ifndef __ASSERT_H
#define __ASSERT_H

#if defined(__ASSERT__) && !defined(__HOST__)

#include "Macros.h"
#include "Types.h"

#ifdef __SERVER__
#include <LogMessage.h>
#include <stdlib.h>
#endif // __SERVER__

// runtime function

// function which prints a message, and then terminates itself
extern C void __assertFailure(const char *fmt, ...);

// verify that the given address is radable
extern C int __assertRead(Address addr);

// verify that the given address is writeable
extern C int __assertWrite(Address addr);

// preprocessor macros

// invoke __assertFailure for applications, and log() + exit() for servers
#ifdef __SERVER__
#define raiseFailure(fmt, ...) \
    log(fmt, ##__VA_ARGS__); \
    exit(1);
#else
#define raiseFailure(fmt, ...) \
    __assertFailure(fmt, ##__VA_ARGS__);
#endif // __SERVER__

// verify that a given expression evaluates to true
#define assert(exp) \
    if (!(exp)) \
    { \
        raiseFailure("[%s:%d]: ***Assertion '%s' failed ***\n", \
                        __FILE__, __LINE__, #exp); \
    }

// presume that the given address is readable
#define assertRead(addr) \
    assert(__assertRead((Address)addr))

// presume that the given address is writeable
#define assertWrite(addr) \
    assert(__assertWrite((Address)addr))

#else
// Dummy preprocessor macros

// Dummy assertion function which does not perform any check.
#define assert(exp)

// Dummy assertion function for checking read access on an address.
#define assertRead(addr)

// Dummy assertion function for checking read access on an address.
#define assertWrite(addr)
    
#endif
#endif
