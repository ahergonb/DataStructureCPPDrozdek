#ifndef INT_LINKED_LIST
#define INT_LINKED_LIST

class IntSLLNODE
{
public:
    IntSLLNODE()
    {
        next = nullptr;
    }

    IntSLLNODE(int el, IntSLLNODE *ptr = nullptr)
    {
        info = el;
        next = ptr;
    }

    IntSLLNODE *next;
    int info;
};

class IntSLList
{
public:
    IntSLList()
    {
        head = tail = nullptr;
    }
    ~IntSLList();

    int isEmpty()
    {
        return head == nullptr;
    }

    void addToHead(int);
    void addToTail(int);
    int deleteFromHead();
    int deleteFromTail();
    int deleteNode(int);
    void printList();
    bool isInList(int) const;

private:
    IntSLLNODE *head;
    IntSLLNODE *tail;

};



#endif //INT_LINKED_LIST