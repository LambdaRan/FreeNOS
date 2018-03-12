/*
 * Copyright (C) 2015 Niek Linnenbank
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

#ifndef __MEMORYBLOCK_H
#define __MEMORYBLOCK_H

#include "Types.h"

class MemoryBlock 
{
public:
    // fill memory with a constant byte
    static void * set(void *dest, int ch, unsigned count);

    // copy memory from one place to another
    static Size copy(void *dest, const void *src, Size count);

    // copy a character string
    static Size copy(char *dest, char *src, Size count);

    // compare memory
    static bool compare(void *dest, void *src, Size count);

    // compare memory
    static bool compare(const char *p1, const char *p2, Size count = 0);
    
};

#endif