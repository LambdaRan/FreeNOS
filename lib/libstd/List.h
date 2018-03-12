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

    // insert an item an the start of the list
    void prepend(T t)
    {
        assertRead(t);

        // create a new node with the item
        Node *node = new Node(t);
        // connect the item to the list head, if set
        if (m_head)
        {
            m_head->prev = node;
            node->next = m_head;
        }
        // make the new node head of the list
        m_head = node;

        // also make it the tail, if not yet set
        if (!m_tail)
            m_tail = node;
        // update node count
        ++m_count;
    }

    // insert an item at the end of the list
    void append(T t)
    {
        assertRead(t);

        Node *node = new Node(t);
        node->prev = m_tail;

        // connect the item with the tail, if any
        if (m_tail)
            m_tail->next = node;
        // make the new Node the tail of the list
        m_tail = node;
        // also make the item the head, if none
        if (!m_head)
            m_head = node;
        // update the count
        ++m_count;
    }

    // remove all items which are equal to the given item
    // P527 基类中虚函数开头的关键字virtual在派生类内可写可不写。
    // C++11新标准允许派生类显示注明他将使用那个成员函数改写基类中的虚函数
    // 在形参列表后加 override
    // P530 派生类经常（但不总是）覆盖它继承的虚函数
    virtual int remove(T t)
    {
        assertRead(t);

        Node *node = m_head;
        Node *next;
        int num = 0;

        while (node)
        {
            next = node->next;
            if (node->data == t)
            {
                remove(t);
                ++num;
            }
            node = next;
        }
        return num;
    }

    // removes the given node from the list
    virtual int remove(Node *node)
    {
        if (node->prev)
            node->prev->next = node->next;

        if (node == head)
            m_head = node->next;
        
        if (node->next)
            node->next->prev = node->prev;
        
        if (node == m_tail)
            m_tail = node->prev;
        
        --m_count;
        delete node;
        return true;
    }

    // check whether an element is no the List
    virtual bool constains(const T t) const
    {
        assertRead(t);

        for (Node *i = m_head; i; i = i->next)
            if (i->data == t)
                return true;
        
        return false;
    }

    // clear the entire list
    virtual void clear()
    {
        Node *node = m_head, *next = ZERO;

        // delete all node and optionally(可选，随意的) items too
        while (node)
        {
            next = node->next;
            delete node;
            node = next;
        }
        // clear administration
        m_head = ZERO;
        m_tail = ZERO;
        m_count = 0;
    }

    // get the first node on the list
    Node * head()
    {
        return m_head;
    }

    // get the first node on the list (read-only)
    const Node * head() const
    {
        return m_head;
    }

    // get the last node on the list
    Node * tail() 
    {
        return m_tail;
    }

    // get the last node on the list (read-only)
    const Node * tail() const 
    {
        return m_tail;
    }

    // get the first the value in the list
    // assumes that the list is not empty
    T first()
    {
        return m_head->data;
    }

    // get the first value as constant
    // assumes that the list is not empty
    const T first() const 
    {
        return m_head->data;
    }

    // get the last value on the list
    // assumes the last value is not empty
    T last()
    {
        return m_tail->data;
    }
    
    // get the last value on the list as constant
    // assumes the last value is not empty 
    const T tail() const 
    {
        return m_tail->data;
    }

    // get the pointer to the item at the given position
    virtual const T * get(Size position) const 
    {
        Size num = 0;
        Node *node = m_head;

        // is the index within bounds of the list?
        if (position >= m_count)
            return ZERO;

        // find the item and return it
        while (num++ < position)
            node = node->next;

        return &node->data;
    }
    
    // get a reference to the item at the given position
    // assumes that the item is available
    virtual const T & at(Size position) const 
    {
        Size num = 0;
        Node *node = m_head;

        // is the index within bounds of the list?
        if (position >= m_count)
            return ZERO;

        // find the item and return it
        while (num++ < position)
            node = node->next;

        return node->data;
    }

    // check if the list is empty
    virtual bool isEmpty() const 
    {
        return !m_head;
    }

    // get the size of the list
    Size size() const 
    {
        return m_count;
    }

    // get the number of items on the list
    Size count() const 
    {
        return m_count;
    }

    // append operator
    List & operator << (T t)
    {
        append(t);
        return (*this);
    }

    // comparsion operator
    bool operator == (const List<T> &lst) const
    {
        if (lst.count() != m_count)
            return false;
        
        for (Node *n = m_head; n; n = n->next)
            if (!lst.constains(n->data))
                return false;
        
        return true;
    }

    // inequality operator
    bool operator != (const List<T> &lst) const 
    {
        if (lst.count() != m_count)
            return true;
        
        for (Node *n = m_head; n; n = n->next)
            if (!lst.constains(n->data))
                return true;
        
        return false;        
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
