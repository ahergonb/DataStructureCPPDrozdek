#include <iostream>
#include "LinkedList.h"

int main()
{
    LinkedList myList;

    myList.addToHead(10);
    myList.addToTail(20);
    myList.addToTail(30);
    myList.addToTail(40);
    myList.addToTail(50);

    myList.printList();

    std::cout << "\n--- Test 1: Delete 3th node (30) ---" << std::endl;
    myList.deleteIthNode(3);
    myList.printList();

    std::cout << "\n--- Test 2: Delete 1st node (10) ---" << std::endl;
    myList.deleteIthNode(1);
    myList.printList();

    std::cout << "\n--- Test 3: Delete Tail node (50) ---" << std::endl;
    myList.deleteIthNode(3);
    myList.printList();

    std::cout << "\n--- Test 4: Delete not exist node (50) ---" << std::endl;
    myList.deleteIthNode(5);
    myList.printList();

    return 0;
}