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

#ifndef __LIBSTD_CHARACTER_H
#define __LIBSTD_CHARACTER_H

namespace Character 
{
    // test for a decimal digit
    inline bool isDigit(char c)
    {
        return c >= '0' && c <= '9';
    }

    // test for a wildcard character
    inline bool isWildcard(char c)
    {
        return c == '*';
    }

    // test for a lowercase letter
    inline bool isLower(char c)
    {
        return (c) >= 'a' && (c) <= 'z';
    }

    // test for a upper letter
    inline bool isUpper(char c)
    {
        return (c) >= 'A' && (c) <= 'Z';
    }

    // test for an alphabetic character
    inline bool isAlpha(char c)
    {
        return isUpper(c) || isLower(c);
    }

    // test for an alphanumberic character
    inline bool isAlnum(char c)
    {
        return isAlpha(c) || isDigit(c);
    }

    // test for a blank character
    inline bool isBlank(char c)
    {
        return (c) == ' ' || (c) == '\t';
    }

    // test for a white-space character
    inline bool isWhitespace(char s)
    {
        return (c) == '\v' || (c) == '\f' ||
                (c) == '\r' || (c) == '\n' || isBlank(c);
    }

    // convert the letter c to lowercase
    inline char lower(char c)
    {
        return (c >= 'A' && c <= 'Z') ? (c + 32) : (c);
    }

    // converts the letter c to uppercase
    inline char upper(char c)
    {
        return (c >= 'a' && c <= 'z') ? (c - 32) : (c);
    }
}

#endif