#pragma once

class DLLNode
{
    DLLNode()
    {
        next = prev = nullptr;
    }

    DLLNode(const int &el, DLLNode *n = 0, DLLNode *p = 0)
    {
        info = el;
        next = n;
        prev = p;
    }

    int info;
    DLLNode* prev, * next;
};