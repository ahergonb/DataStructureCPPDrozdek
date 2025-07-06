#pragma once

template<class T>
class DLLNode
{
public:
    T info;
    DLLNode* next, * prev;

    DLLNode()
    {
        next = prev = nullptr;
    }

    DLLNode(const T& el, DLLNode* n = nullptr, DLLNode* p = nullptr)
    {
        info = el;
        next = n;
        prev = p;
    }
};

template<class T>
class DoublyLinkedList
{
public:
    DoublyLinkedList()
    {
        head = tail = nullptr;
    }
    void addToDLLTail(const T&);
    T deleteFromDLLTail();

protected:
    DLLNode<T>* head, * tail;
};
