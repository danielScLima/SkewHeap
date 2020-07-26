#ifndef SKEW_HEAP_H
#define SKEW_HEAP_H

#include <iostream>
#include <vector>

#include "skewheapnode.h"

/*!
 * \brief The SkewHeap class
 */
class SkewHeap
{
public:
    /*!
     * \brief SkewHeap
     */
    SkewHeap();

    ~SkewHeap();

    /*!
     * \brief getRoot
     * \return
     */
    SkewHeapNode* getRoot();

    /*!
     * \brief insert
     * \param data
     */
    void insert(int data);
    /*!
     * \brief removeMin
     * \return
     */
    struct SkewHeapNode* removeMin();
    /*!
     * \brief search
     * \param data
     * \return
     */
    bool search(int data);

    /*!
     * \brief gitDotFileMode1
     * \return
     */
    const std::string gitDotFileMode1();
    /*!
     * \brief gitDotFileMode2
     * \return
     */
    const std::string gitDotFileMode2();

    /*!
     * \brief preOrder
     * \return
     */
    const std::string preOrder();
    /*!
     * \brief inOrder
     * \return
     */
    const std::string inOrder();
    /*!
     * \brief posOrder
     * \return
     */
    const std::string posOrder();
    /*!
     * \brief InLevelOrder
     * \return
     */
    const std::string InLevelOrder();

    /*!
     * \brief merge
     * \param heapOne
     * \param heapTwo
     */
    void merge(SkewHeapNode *heapOne, SkewHeapNode *heapTwo);
    /*!
     * \brief setRoot
     * \param node
     */
    void setRoot(SkewHeapNode *node);
private:
    struct SkewHeapNode* root = nullptr;

    /*!
     * \brief exibirSubArvore1
     * \param n
     * \param content
     * \param count
     */
    void exibirSubArvore1(SkewHeapNode *n, std::string &content, int& count);
    /*!
     * \brief exibirSubArvore2
     * \param father
     * \param isLeftSon
     * \param n
     * \param content
     * \param count
     */
    void exibirSubArvore2(SkewHeapNode *father, bool isLeftSon, SkewHeapNode *n, std::string &content, int &count);

    /*!
     * \brief preOrder
     * \param node
     * \param content
     */
    void preOrder(SkewHeapNode *node, std::string &content);
    /*!
     * \brief inOrder
     * \param node
     * \param content
     */
    void inOrder(SkewHeapNode *node, std::string &content);
    /*!
     * \brief posOrder
     * \param node
     * \param content
     */
    void posOrder(SkewHeapNode *node, std::string &content);

    /*!
     * \brief checkAndCorrectIfNeeded
     * \param node
     */
    void checkAndCorrectIfNeeded(SkewHeapNode *node);

    /*!
     * \brief merge
     * \param heapOne
     * \param heapTwo
     * \param stack
     */
    void merge(SkewHeapNode* heapOne, SkewHeapNode* heapTwo, std::vector<SkewHeapNode*>& stack);
    /*!
     * \brief insertInHeapOfMerge
     * \param node
     * \param stack
     * \param insertInStack
     */
    void insertInHeapOfMerge
    (
        SkewHeapNode* node,
        std::vector<SkewHeapNode*> &stack,
        bool insertInStack = true
    );
    /*!
     * \brief checkAndCorrectIfNeededJustThisSkewHeapNode
     * \param node
     */
    void checkAndCorrectIfNeededJustThisSkewHeapNode(SkewHeapNode *node);

    /*!
     * \brief dealockSubTree
     * \param node
     */
    void dealockSubTree(SkewHeapNode *node);
};

#endif // SKEW_HEAP_H
