#include <iostream>
#include "LinkedList.h"

void LinkedList::addToHead(int val)
{
    Head = new Node(val, Head);
    if (Tail == nullptr)
    {
        Tail = Head;
    }
}

void LinkedList::addToTail(int val)
{
    if (Head == nullptr)
    {
        Head = new Node(val);
    }
    else
    {
        Tail->next = new Node(val);
        Tail = Tail->next;

    }
}

int LinkedList::deleteFromHead()
{
    int value = 0;
    if (Head != nullptr)
    {
        value = Head->info;
        Node *tmp = Head;

        if (Head == Tail)
        {
            Head = nullptr;
            Tail = nullptr;
        }
        else
        {
            Head = Head->next;
            delete tmp;
        }
    }
    else
    {
        std::cout << "There is not Nodes in the list" << std::endl;
    }

    return value;
}

int LinkedList::deleteFromTail()
{
    if (Head != nullptr)
    {
        if (Head == Tail)
        {
            Tail = nullptr;
            delete Head;
        }
        else
        {
            Node* tmp;
            for (tmp = Head; tmp->next != Tail; tmp = tmp->next);

            delete Tail;
            Tail = tmp;
            Tail->next = nullptr;
        }
    }
    else
    {
        std::cout << "There is not Nodes in the list" << std::endl;
    }

    return 0;
}

void LinkedList::printList()const
{
    Node* current = Head;
    while (current != nullptr) {
        std::cout << current->info << " -> ";
        current = current->next;
    }
    std::cout << "NULL" << std::endl;
}

int LinkedList::deleteIthNode(int index)
{
    int counter = 0;
    Node* current = nullptr;
    Node* prev = nullptr;

    if (index <= 0 && Head == nullptr)
    {
        std::cout << "La lista esta vacia o el indice es menor o igual a 0" << std::endl;
        return 1;
    }
    else
    {
        // If we have to delete head
        if (index == 1)
        {
            Node* deleteNode = nullptr;
            deleteNode = Head;
            Head = Head->next;

            if (Head == nullptr)
            {
                Tail = nullptr;
            }

            delete deleteNode;
            return 0;
        }
        //If we are higher than 1, we iterate the List
        counter = 1;
        prev = Head;
        while (prev != nullptr && counter < index - 1)
        {
            prev = prev->next;
            counter++;
        }

        if (prev == nullptr || prev->next == nullptr)
        {
            std::cout << "Error: the node position " << index << " not exist" << std::endl;
            return 1;
        }

        Node* nodeToDelete = prev->next;
        prev->next = nodeToDelete->next;

        // Update the Tail, if we need to delete the last node
        if (nodeToDelete == Tail)
        {
            Tail = prev;
        }

        delete nodeToDelete;
        std::cout << "Node in the position " << index << "deleted susessfully" << std::endl;
        return 0;
    }
}

int LinkedList::deleteNode(int val)
{
    int rc = 0;
    if (Head != nullptr)
    {
        if (Head == Tail && val == Head->info)
        {
            delete Head;
            Head = Tail = nullptr;
        }
        else if (Head->info)
        {
            Node* temp = Head;
            Head = temp->next;
            delete temp;
        }
        else 
        {
            Node* tmp;
            Node* pred;

            for (pred = Head, tmp = Head->next;
                tmp != nullptr && !(tmp->info == val);
                pred = pred->next, tmp = tmp->next);
            
            if (tmp != nullptr)
            {
                pred->next = tmp->next;
                if (tmp == Tail)
                {
                    Tail = tmp;
                }
                delete tmp;
            }
        }
    }

    return rc;
}

LinkedList::~LinkedList()
{
    for (Node* p; !isEmpty(); )
    {
        p = Head->next;
        delete Head;
        Head = p;
    }
}