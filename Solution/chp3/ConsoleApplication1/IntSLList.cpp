#include <iostream>
#include "IntSLList.h"

using namespace std;


IntSLList::~IntSLList()
{
    for(IntSLLNODE *p; !isEmpty(); )
    {
        p = head->next;
        delete head;
        head = p;
    }
}

void IntSLList::addToHead(int infoHead)
{
    head = new IntSLLNODE(infoHead, head);
    if(tail == nullptr)
    {
        tail = head;
    }
}

void IntSLList::addToTail(int infoTail)
{
    if(head == nullptr)
    {
        head = tail = new IntSLLNODE(infoTail);
    }
    else
    {
        tail->next = new IntSLLNODE(infoTail);
        tail = tail->next;
    }
}

int IntSLList::deleteFromHead()
{
    int el = 0;
    //Check if the SLL is not empty
    if(!isEmpty())
    {
        el = head->info;
        //We need temp to remove the head and do not lost the reference
        IntSLLNODE *tmp = head;

        if(head == tail)
        {
            head = tail = nullptr;
        }
        else
        {
            head = head->next;
            delete tmp;
        }
    }
    else
    {
        cout << "There is not value in the SLL" << endl;
    }

    return el;
}

int IntSLList::deleteFromTail()
{
    int el = 0;
    //Check if the SLL is not empty
    if(!isEmpty())
    {
        el = tail->info;
        if(head == tail)
        {
            delete head;
            head = tail = nullptr;
        }
        else
        {
            //If more than one node in the list
            IntSLLNODE *tmp;
            for(tmp = head; tmp->next != tail; tmp = tmp->next);
            
            delete tail;
            tail = tmp;
            tail->next = nullptr;
        }
    }

    return el;
}

int IntSLList::deleteNode(int el)
{
    //check if the list is empty
    if (!isEmpty())
    {
        if (head == tail && el == head->info)
        {
            delete head;
            head = tail = nullptr;
        }
        else if (el == head->info)
        {
            IntSLLNODE* temp = head;
            head = temp->next;
            delete temp;
        }
        else
        {
            IntSLLNODE* pred, *temp;
            for (pred = head, temp = head->next;
                temp != nullptr && !(temp->info == el);
                pred = pred->next, temp = temp->next);

            if (temp != nullptr)
            {
                pred->next = temp->next;
                if (temp == tail)
                {
                    tail = pred;
                }
                delete temp;
            }
        }
    }
    else
    {
        cout << "The list is empty" << endl;
    }
}

void IntSLList::printList()
{
    if (!isEmpty())
    {
        IntSLLNODE* temp = head;
        while (temp != nullptr)
        {
            cout << temp->info;
            if (temp->next != nullptr)
            {
                cout << "->";
            }
            temp = temp->next;
        }

        cout << "->NULL" << endl;
    }
}

bool IntSLList::isInList(int el) const
{
    IntSLLNODE* temp;
    for (temp = head; temp != nullptr && !(temp->info == el); temp = temp->next);
    return (temp != nullptr);
}