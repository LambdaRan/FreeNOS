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

#ifndef __LIBSTD_SEQUENCE_H
#define __LIBSTD_SEQUENCE_H

#include "Container.h"
#include "Comparable.h"
#include "Types.h"
#include "Macros.h"


template <typename T> 
class Sequence : public Container, public Comparable<Sequence<T> >
{
public: 
    // add the given item to the sequence, if possible
    virtual int insert(const T &item)
    {
        return -1;
    }

    // insert the given item at the given position
    // if an item exits at the given position, it will be replaceed by the given item
    virtual bool insert(Size position, const T &item)
    {
        return false;
    }

    // fill the sequence with the given value
    virtual void fill(T value)
    {
        Size s = this->size();

        for (Size i = 0; i < s; ++i)
            insert(i, value);
    }

    // remove all items with the given value
    virtual int remove(T value)
    {
        return 0;
    }

    // removes the item at the given position 
    virtual bool removeAt(Size position)
    {
        return false;
    }

    // remove all items from the sequence
    virtual void clear()
    {
        Size s = this->size();

        for (Size i = 0; i < s; ++i)
            removeAt(i);
    }

    // returns the item at the given position
    virtual const T * get(Size position) const = 0;

    // Returns a reference to the item at the given position.
    // Note that this function does not perform bounds checking.
    // Position must be a valid index.
    virtual const T & at(Size position) const = 0;

    // check if the given item is stored in the sequence
    virtual bool contains(const T value) const 
    {
        Size sz = this->size();
        for (Size i = 0; i < sz; ++i)
            if (at(i) == value)
                return true;
        return false;
    }

    // compara this sequence to another sequence
    virtual int compareTo(const Sequence<T> &s) const
    {
        Size sz = this->size();
        Size cnt = this->count();

        // Size must be equal
        if (s.size() != sz)
            return s.size() - sz;
        // count must be equal
        if (s.count() != cnt)
            return s.count() - cnt;
        // all elements must be equal
        for (Size i = 0; i < cnt; ++i)
        {
            if (at(i) != s.at(i))
            {
                return i + 1;
            }
        }
        return 0;
    }

    // P501 下标运算符重载，必须时成员函数。　最好同时定义下标运算符的常量版本和非常量版本

    // return the item at the given position in the sequence
    const T & operator[](int i) const
    {
        return at(i);
    }

    // return the item at the given position in the sequence
    const T & operator[](Size i) const
    {
        return at(i);
    }

    // Returns the item at the given position in the Sequence.
    T & operator[](int i)
    {
        return (T &) at(i);
    }

    // Returns the item at the given position in the Sequence.
    T & operator[](Size i)
    {
        return (T &) at(i);
    }
};
#endif