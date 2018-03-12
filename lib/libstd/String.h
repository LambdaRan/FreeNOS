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

#ifndef __LIBSTD_STRING_H
#define __LIBSTD_STRING_H

#include "Types.h"
#include "Macros.h"
#include "Assert.h"
#include "Sequence.h"
#include "List.h"

// default maximum length of a Strig's value
#define STRING_DEFAULT_SIZE 64

// abstraction of strings
class String : public Sequence<char>
{
public:
    // default constructor
    // P237  
    //String() = default;
    String();

    // copy constructor
    String(const String &str);

    // constructor
    String(char *s, bool copy = true);

    // constant constructor
    String(const char *s, bool copy = false);

    // signed integer constructor
    // creates a string with the textual representation
    // of the given signed integer
    String(int number);

    // destructor
    virtual ~String();

    // caculates the length of the string
    virtual Size size() const;

    // number of characters int the string
    virtual Size count() const;

    // same as count
    Size length() const;

    // get the length of the given character string
    static Size length(char *str);

    // get the length of a constant character string
    static Size length(const char *str);

    // change the size of the string buffer
    virtual bool resize(Size size);

    // make sure at least given number of bytes available
    virtual bool reserve(Size count);

    // return the item at the given position
    virtual const char * get(Size position) const;

    // return a reference to the item at the given position
    // note that this function does not perform bounds checking
    // position must be a valid index
    virtual const char & at(Size position) const;

    // return value at the given position
    // if positon is not within bounds of this array
    // this function will return a default constructed T
    virtual const char value(Size position) const;

    // check if the given character occurs in the string
    virtual bool constains(char character) const;

    // test if this string starts with the specified prefix
    bool startsWith(String &prefix) const;

    // test if this string starts with the specified prefix
    bool startsWith(const char *prefix) const;

    // test if this string ends with the specified suffix
    bool endsWith(String *suffix) const;

    // test if this string ends with the specified suffix
    bool endsWith(const char *suffix) const;

    // compares this string to the given string
    virtual int compareTo(const String &str) const;

    // compare with another string
    virtual int compareTo(const String &str,
                            bool caseSensitive = true) const;

    // compare with a character string
    virtual int compareTo(const char *str,
                            bool caseSensitive = true,
                            Size count = 0) const;
    
    // alias for compareTo()
    virtual bool equals(const String &str) const;

    // matches the string against a mask
    // mask Pattern to match against.
    bool match(const char *mask) const;

    // return a new string that constains a copy of this string
    // starting from index (includsive), and copies at most size charaters
    String substring(Size index, Size size = 0);

    // split the string into parts sepetated by a delimiter
    List<String> split(char delimiter);

    // split the string into parts separated by a delimiter
    List<String> split(const String &delimiter);

    // convert the string to a signed long integer
    long toLong(Number::Base base = Number::Dec);

    // pad line with trailing whitespace
    // 用尾随空格填充行。
    // This function ensures the last line inside the String
    // is at least the given length in characters, by appending
    // extra whitespace at the end of the line.    
    String & pad(Size length);

    // remove leading and trailing whitespace from the string
    String & trim();

    // convert all characters to lower case
    String & lower();

    // convert all characters to upper case
    String & upper();

    // set text-representation of a signed number
    Size set(long number, Number::Base base = Number::Dec, char *string = ZERO);

    // set text-representation of an unsigned number
    Size setUnsigned(ulong number,
                    Number::Base base = Number::Dec,
                    char *string = ZERO,
                    bool sign = false);
    
    // assignment operator
    void operator = (const char *str);

    // assignment operator
    void operator = (const String &str);

    // ocomparision operator
    bool operator == (const String & str) const;

    // inequal operator
    bool operator != (const String & str) const;

    // dereference operator (read-only)
    const char * operator * () const;

    // dereference operator
    char * operator * ();

    // append characters string to the string
    String & operator << (const char *str);

    // append string to another string
    String & operator << (const String &str);

    // append the given number as text to the string
    String & operator << (long number);

    // change the default number format representation
    String & operator << (Number::Base format);

private:
    // current value of the string
    char *m_string;
    // size of the strig buffer, include any NULL byte(s) at the end
    Size m_size;
    // length of the string text, excluding NULL byte(s) at the end
    Size m_count;
    // true if the string buffer is a deep copy, false otherwise
    bool m_allocated;
    // number format to use for convertions
    Number::Base m_base;
};

#endif