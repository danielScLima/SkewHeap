#ifndef SKEWHEAPNODE_H
#define SKEWHEAPNODE_H

/*!
 * \brief The SkewHeapNode struct
 */
struct SkewHeapNode
{
    /*!
     * \brief SkewHeapNode
     * \param data
     * \param father
     */
    SkewHeapNode(int data, SkewHeapNode* father);
    /*!
     * \brief search
     * \param data
     * \return
     */
    bool search(int data);

    int data = 0;
    struct SkewHeapNode* left = nullptr;
    struct SkewHeapNode* right = nullptr;
    struct SkewHeapNode* father = nullptr;
};

#endif // SKEWHEAPNODE_H
