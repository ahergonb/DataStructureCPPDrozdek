#pragma once

class Node
{
public:
    int info;
    Node* next;

    Node()
    {
        info = 0;
        next = nullptr;
    }

    Node(int data, Node* node = nullptr) : info(data), next(node) {}

};

class LinkedList
{
private:
    Node* Head;
    Node* Tail;

public:
    LinkedList()
    {
        Head = nullptr;
        Tail = nullptr;
    }

    ~LinkedList();

    void addToHead(int);
    void addToTail(int);
    int deleteFromHead();
    int deleteFromTail();
    int deleteNode(int);
    int deleteIthNode(int index);
    void printList() const;

    int isEmpty()
    {
        return Head == nullptr;
    }
};