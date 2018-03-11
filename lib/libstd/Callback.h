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

#ifndef __LIBSTD_CALLBACK_H
#define __LIBSTD_CALLBACK_H

#include "Types.h"

class CallbackFunction
{
public:
    virtual void execute(void *parameter) = 0;
};

// abstrction for prividing a callback function to a object instance
template <typename Base, typename ParamType>
class Callback : public CallbackFunction
{
private: 
    // callback function prototype
    typedef void (Base::*Function)(ParamType *param);
public: 
    // constructor
    Callback(Base *object, Function func)
    {
        m_object = object;
        m_function = func;
    }

    virtual void execute(void *parameter)
    {
        executeOnObject((ParamType *)parameter);
    }

private: 
    // execute the callback
    // parameter one parameter which is passed to the callback function
    virtual void executeOnObject(ParamType *parameter)
    {
        (m_object->*m_function)(parameter);
    }

    // object instance
    Base *m_object;
    // Function pointer
    Function m_function;
};



#endif