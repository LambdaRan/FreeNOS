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

#ifndef __LIBSTD_LIST_H
#define __LIBSTD_LIST_H

#include "Macros.h"
#include "Assert.h"
#include "Sequence.h"

// Simple linked list template class.
template <typename T>
class List : public Sequence<T>
{
public:
    // represents an item on the list
    class Node 
    {
    public:
        // constructor
        Node(T t) : data(t), prev(ZERO), next(ZERO)
        {
        }

        // item of this node
        T data;
        // previous node
        Node *prev;
        // next node
        Node *next;
    };

    // class constructor
    List() 
        : m_head(ZERO), m_tail(ZERO), m_count(0)
    {
    }

    // copy constructor
    // P440 如果一个构造函数的第一个参数是自身类型的引用，且任何额外参数都有默认值，则此构造函数为拷贝构造函数
    // 总是一个const引用
    List(const List<T> &lst)
        : m_head(ZERO), m_tail(ZERO), m_count(0)
    {
        for (Node *node = lst.m_head; node; node->m_next)
            append(node->data);
    }

    // class destructor
    ~List()
    {
        Node *node = m_head;
        while (node)
        {
            Node *tmp = node;
            node = node->next;
            delete tmp;
        }
    }
private:
    // head of the list
    Node *m_head;
    //tail of the list
    Node *m_tail;
    // number of items currently in the list
    Size m_count;
};

#endif
