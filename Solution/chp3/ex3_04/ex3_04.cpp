#include <iostream>

using namespace std;

class Node
{
private:
    int val;
    Node* next;

public:
    Node(int value) : val(value), next(nullptr) {}

    //Getters
    int getValue() const { return val; }
    Node* getNext()const { return next; }

    //Setters
    void setNext(Node* node) { next = node; }

    void print()const
    {
        const Node* current = this;
        while (current != nullptr)
        {
            cout << current->val;
           if (current->next != nullptr)
            {
                cout << "->";
            }
            current = current->next;
        }
        cout << "->NULL";
        cout << endl;
    }
};

class LinkedList
{
private:
    Node* head;

public:
    //Constructors
    LinkedList() : head(nullptr) {}
    LinkedList(Node* node) : head(node) {}

    //Destructor
    ~LinkedList()
    {
        Node* current = head;
        while (current != nullptr)
        {
            Node* next = current->getNext();
            delete current;
            current = next;
        }
    }

    //Metodo para agregar un nodo al final
    void append(int value)
    {
        Node* newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->getNext() != nullptr)
        {
            current = current->getNext();
        }
        current->setNext(newNode);
    }

    void print()const
    {
        if (head != nullptr)
        {
            head->print();
        }
        else
        {
            cout << "Empty list" << endl;
        }
    }

    Node* getNode()
    {
        return head;
    }

    void setNode(Node* n)
    {
        head = n;
    }

    static Node *mergeSortedList2(Node* listHead1, Node* listHead2)
    {
        if (listHead1 == nullptr) return listHead2;
        if (listHead2 == nullptr) return listHead1;

        Node* mergeHead = nullptr;
        Node* mergeTail = nullptr;

        while (listHead1 != nullptr && listHead2 != nullptr)
        {
            int ValueToInsert = 0;

            if (listHead1->getValue() <= listHead2->getValue())
            {
                ValueToInsert = listHead1->getValue();
                listHead1 = listHead1->getNext();
            }
            else
            {
                ValueToInsert = listHead2->getValue();
                listHead2 = listHead2->getNext();
            }

            Node* newNode = new Node(ValueToInsert);

            if (mergeHead == nullptr)
            {
                mergeHead = newNode;
                mergeTail = newNode;
            }
            else
            {
                mergeTail->setNext(newNode);
                mergeTail = newNode;
            }
            
        }


    }

    static Node* mergeSortedList(Node *listHead1, Node* listHead2)
    {
        if (listHead1 == nullptr) return listHead2;
        if (listHead2 == nullptr) return listHead1;

        Node* mergeHead = nullptr;
        Node* mergeTail = nullptr;

        if (listHead1->getValue() <= listHead2->getValue())
        {
            mergeHead = listHead1;
            mergeTail = listHead1;
            listHead1 = listHead1->getNext();
        }
        else
        {
            mergeHead = listHead2;
            mergeTail = listHead2;
            listHead2 = listHead2->getNext();
        }

        while (listHead1 != nullptr && listHead2 != nullptr)
        {
            if (listHead1->getValue() <= listHead2->getValue())
            {
                mergeTail->setNext(listHead1);
                mergeTail = listHead1;
                listHead1 = listHead1->getNext();
            }
            else
            {
                mergeTail->setNext(listHead2);
                mergeTail = listHead2;
                listHead2 = listHead2->getNext();
            }
        }

        if (listHead1 != nullptr)
        {
            mergeTail->setNext(listHead1);
        }
        else
        {
            mergeTail->setNext(listHead2);
        }

    }

};


int main()
{

    LinkedList list1;
    LinkedList list2;

    list1.print();

    list1.append(1);
    list1.append(4);
    list1.append(6);

    list1.print();

    list2.append(2);
    list2.append(3);
    list2.append(5);

    list2.print();

    //Merged both list
    Node* mergeList = LinkedList::mergeSortedList2(list1.getNode(), list2.getNode());
    return 0;
}