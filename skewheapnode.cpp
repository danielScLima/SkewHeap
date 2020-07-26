#include "skewheapnode.h"

SkewHeapNode::SkewHeapNode(int data, SkewHeapNode* father):
    data(data), left(nullptr), right(nullptr), father(father)
{}

bool SkewHeapNode::search(int data)
{
    if (this->data == data)
        return true;
    if (left != nullptr)
    {
        bool leftret = left->search(data);
        if (leftret)
            return true;
    }
    if (right != nullptr)
    {
        bool rightret = right->search(data);
        if (rightret)
            return true;
    }
    return false;
}
