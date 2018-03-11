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

#ifndef __SINGLETON_H
#define __SINGLETON_H

template <typename T>
class Singleton
{
public: 
    // constructor
    // instance new instance of T
    // P587 在类的代码内简化模板类名的使用， 可以直接使用模板名而不提供实参，但是在类外的成员函数定义必须提供模板实参
    // Note: 在一个类模板的作用域内，我们可以直接使用模板名而不必指定模板实参
    // Singleton(T *obj)
    Singleton<T>(T *obj) : instance(obj)
    {
    }

    // one and only instance 
    static T *instance;
};
// initialize the static member obj
template<typename T>
T *Singleton<T>::instance = 0;

#endif