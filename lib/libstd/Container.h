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

#ifndef __LIBSTD_CONTAINER_H
#define __LIBSTD_CONTAINER_H

#include "Types.h"
#include "Macros.h"

// containers provide access to stored items.
class Container
{
public:
    Container();
    virtual ~Container();

    // returns the maxinum size of this container
    virtual Size size() const = 0;

    //returns the number of items inside the container
    virtual Size count() const = 0;

    // removes all items from the container
    virtual void clear() = 0;

    // check if the container is empty
    virtual bool isEmpty() const;

    // ensure that at least the given size is avilable
    virtual bool reserve(Size size);

    // shrink the container size by the given amount of items
    virtual bool shrink(Size size);

    // try to minimize the memory required in the container
    virtual Size squeeze();

    // change the size of the container
    virtual bool resize(Size size);
};


#endif