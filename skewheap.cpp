#include "skewheap.h"
#include <iostream>
#include <queue>
#include <string>

SkewHeap::SkewHeap()
{

}

SkewHeap::~SkewHeap()
{
    if (root != nullptr)
    {
        dealockSubTree(root);
        delete root;
    }
}

void SkewHeap::dealockSubTree(SkewHeapNode *node)
{
    if (node == nullptr)
        return;

    if (node->left != nullptr)
    {
        dealockSubTree(node->left);
        delete node->left;
    }
    if (node->right != nullptr)
    {
        dealockSubTree(node->right);
        delete node->right;
    }
}

SkewHeapNode *SkewHeap::getRoot()
{
    return root;
}

void SkewHeap::insert(int data)
{
    if (root == nullptr)
    {
        SkewHeapNode* toInsert = new SkewHeapNode(data, nullptr);
        root = toInsert;
    }
    else //root not null
    {
        SkewHeapNode* tmp = root;
        while (true)
        {
            if (tmp->data <= data) //Inserir no ramo direito
            {
                //Verifica se a direita é null
                //Se sim, já insere lá
                if (tmp->right == nullptr)
                {
                    SkewHeapNode* toInsert = new SkewHeapNode(data, tmp);
                    tmp->right = toInsert;
                    toInsert->father = tmp;
                    //Começa a checar, a partir de tmp, se ta tudo ok
                    checkAndCorrectIfNeeded(tmp);
                    break;
                }
                else //Se não, mergulha
                {
                    tmp = tmp->right;
                    //não faz break
                }
            }
            else //o dado a ser inserido é menor que este nó
            {
                if (tmp == root)
                {
                    SkewHeapNode* toInsert = new SkewHeapNode(data, nullptr);
                    SkewHeapNode* backupRoot = root;
                    backupRoot->father = toInsert;
                    root = toInsert;

                    //Mesmo sabendo que vai trocar, coloca na direita
                    toInsert->right = backupRoot;
                    backupRoot->father = toInsert;
                    checkAndCorrectIfNeeded(root);
                }
                else
                {
                    SkewHeapNode* backupFather = tmp->father;
                    SkewHeapNode* toInsert = new SkewHeapNode(data, backupFather);
                    tmp->father = toInsert;
                    toInsert->right = tmp; //o tmp sempre é colocado a direita
                    backupFather->right = toInsert;//No pai, sempre desçe para a direita
                    toInsert->father = backupFather;
                    checkAndCorrectIfNeeded(toInsert);
                }
                break; //faz break, independente da situação
            }
        } //end of while loop
    } //end of root not null
}

void SkewHeap::checkAndCorrectIfNeededJustThisSkewHeapNode(SkewHeapNode *node)
{
    if (root == nullptr)
        return;

    //Faz o start do calculo, começando em node
    SkewHeapNode* tmp = node;

    if (tmp->left != nullptr || tmp->right != nullptr)
    {
        SkewHeapNode* swapNode = tmp->left;
        tmp->left = tmp->right;
        tmp->right = swapNode;
    }
}

void SkewHeap::checkAndCorrectIfNeeded(SkewHeapNode *node)
{
    if (root == nullptr)
        return;

    //Faz o start do calculo, começando em node
    SkewHeapNode* tmp = node;
    while (tmp != nullptr)
    {
        if (tmp->left != nullptr || tmp->right != nullptr)
        {
            SkewHeapNode* swapNode = tmp->left;
            tmp->left = tmp->right;
            tmp->right = swapNode;
        }

        tmp = tmp->father;
    }
}

SkewHeapNode *SkewHeap::removeMin()
{
    if (root == nullptr)
        return nullptr;

    SkewHeapNode* backupRoot = root;
    SkewHeapNode* left = root->left;
    SkewHeapNode* right = root->right;

    if (left != nullptr)
    {
        left->father = nullptr;
    }
    if (right != nullptr)
    {
        right->father = nullptr;
    }

    root = nullptr;

    SkewHeap* leftistHeapLeft = new SkewHeap();
    leftistHeapLeft->setRoot(left);

    SkewHeap* leftistHeapRight = new SkewHeap();
    leftistHeapRight->setRoot(right);

    merge(leftistHeapLeft->getRoot(), leftistHeapRight->getRoot());

    leftistHeapLeft->setRoot(nullptr);
    leftistHeapRight->setRoot(nullptr);

    delete leftistHeapLeft;
    delete leftistHeapRight;

    return backupRoot;
}

bool SkewHeap::search(int data)
{
    if (root == nullptr)
        return false;
    else
        return root->search(data);
}

const std::string SkewHeap::gitDotFileMode2()
{
    std::string textToFile = "digraph g{";
    textToFile += "node [shape=record, height=0.1]";

    if (root == nullptr)
    {
        textToFile += "NULL [label = \"<l> | <m> NULL | <r>\"];Root -> NULL;";
    }
    else
    {
        int count = 0;
        exibirSubArvore2(nullptr, true, root, textToFile, count);
    }

    textToFile += "}";

    return textToFile;
}

const std::string SkewHeap::gitDotFileMode1()
{
    std::string textToFile = "digraph g{";
    textToFile += "Root[shape=none fontcolor=blue];";

    if (root == nullptr)
    {
        textToFile += "NULL [ fontcolor=red ];Root -> NULL;";
    }
    else
    {
        int count = 0;
        textToFile += "Root->"+std::to_string(root->data)+";";
        exibirSubArvore1(root, textToFile, count);
    }

    textToFile += "}";

    return textToFile;
}

const std::string SkewHeap::preOrder()
{
    std::string content;
    preOrder(root, content);
    return content;
}

const std::string SkewHeap::inOrder()
{
    std::string content;
    inOrder(root, content);
    return content;
}

const std::string SkewHeap::posOrder()
{
    std::string content;
    posOrder(root, content);
    return content;
}

const std::string SkewHeap::InLevelOrder()
{
    std::string content;

    std::queue<SkewHeapNode*> queue;

    if (root != nullptr)
        queue.push(root);

    SkewHeapNode* node = nullptr;
    while(queue.size() > 0)
    {
        SkewHeapNode* node = queue.front(); //acessa o primeiro
        queue.pop(); //remove o primeiro

        content += std::to_string(node->data)+" ";

        if (node->left != nullptr)
            queue.push(node->left);

        if (node->right != nullptr)
            queue.push(node->right);
    }

    return content;
}

void SkewHeap::preOrder(struct SkewHeapNode* node, std::string& content)
{
    if (node != nullptr)
    {
        content += std::to_string(node->data) + " ";
        preOrder(node->left, content);
        preOrder(node->right, content);
    }
}
void SkewHeap::inOrder(struct SkewHeapNode* node, std::string& content)
{
    if (node != nullptr)
    {
        inOrder(node->left, content);
        content += std::to_string(node->data) + " ";
        inOrder(node->right, content);
    }
}
void SkewHeap::posOrder(struct SkewHeapNode* node, std::string& content)
{
    if (node != nullptr)
    {
        posOrder(node->left, content);
        posOrder(node->right, content);
        content += std::to_string(node->data) + " ";
    }
}

void SkewHeap::exibirSubArvore1
(
    struct SkewHeapNode* n,
    std::string& content,
    int& count
)
{
    //Desenha o dado do nó n
    content += std::to_string(n->data)+";";

    if (n->left == nullptr)
    {
        content += std::to_string(n->data)+"->NULL"+std::to_string(count++)+";";
    }
    else
    {
        content += std::to_string(n->data)+"->"+std::to_string(n->left->data)+";";
        exibirSubArvore1
        (
            n->left,
            content,
            count
        );
    }

    if (n->right == nullptr)
    {
        content += std::to_string(n->data)+"->NULL"+std::to_string(count++)+";";
    }
    else
    {
        content += std::to_string(n->data)+"->"+std::to_string(n->right->data)+";";
        exibirSubArvore1
        (
            n->right,
            content,
            count
        );
    }
}

void SkewHeap::exibirSubArvore2
(
    struct SkewHeapNode *father,
    bool isLeftSon,
    struct SkewHeapNode* n,
    std::string& content,
    int& count
)
{
    //Desenha o dado do nó n
    content += std::to_string(n->data)+" [label = \"<l> | <m> "+std::to_string(n->data)+" | <r>\"]";

    //desenha a ligação entre o pai e ele
    if (father != nullptr)
    {
        if (isLeftSon)
            content += std::to_string(father->data)+":l->"+std::to_string(n->data)+";";
        else
            content += std::to_string(father->data)+":r->"+std::to_string(n->data)+";";
    }
    else
    {
        //é o root
        content += "ROOT[shape=none fontcolor=blue];";
        content += "ROOT->"+std::to_string(n->data)+";";
    }

    if (n->left != nullptr)
    {
        exibirSubArvore2
        (
            n,
            true, //is left
            n->left,
            content,
            count
        );
    }

    if (n->right != nullptr)
    {
        exibirSubArvore2
        (
            n,
            false, //is not left
            n->right,
            content,
            count
        );
    }
}

void SkewHeap::merge(SkewHeapNode *heapOne, SkewHeapNode *heapTwo)
{
    std::vector<SkewHeapNode*> stack;
    merge(heapOne, heapTwo, stack);
}

void SkewHeap::setRoot(SkewHeapNode *node)
{
    this->root = node;
}

void SkewHeap::merge(SkewHeapNode *heapOne, SkewHeapNode *heapTwo, std::vector<SkewHeapNode*>& stack)
{
    if (heapOne == nullptr && heapTwo == nullptr)
        return;
    else if (heapOne != nullptr && heapTwo == nullptr)
    {
        //insertInHeapOfMerge(heapOne, stack);

        //according to https://www.cs.usfca.edu/~galles/visualization/SkewHeap.html
        insertInHeapOfMerge(heapOne, stack, false);

        //And this is the end
    }
    else if(heapOne == nullptr && heapTwo != nullptr)
    {
        //insertInHeapOfMerge(heapTwo, stack);

        //according to https://www.cs.usfca.edu/~galles/visualization/SkewHeap.html
        insertInHeapOfMerge(heapTwo, stack, false);

        //And this is the end
    }
    else
    {
        if (heapOne->data <= heapTwo->data)
        {
            //Deve inserir heapOne
            SkewHeapNode *heapOneBackup = heapOne;
            heapOne = heapOne->right;
            heapOneBackup->right = nullptr;
            insertInHeapOfMerge(heapOneBackup, stack);
            merge(heapOne, heapTwo, stack);
        }
        else
        {
            //Deve inserir heapTwo
            SkewHeapNode *heapTwoBackup = heapTwo;
            heapTwo = heapTwo->right;
            heapTwoBackup->right = nullptr;
            insertInHeapOfMerge(heapTwoBackup, stack);
            merge(heapOne, heapTwo, stack);
        }
    }

    if (stack.size() > 0)
    {
        while (stack.size() > 0)
        {
            SkewHeapNode * back = stack.back();
            stack.pop_back();

            checkAndCorrectIfNeededJustThisSkewHeapNode(back);
        }
    }
}

void SkewHeap::insertInHeapOfMerge
(
    SkewHeapNode *node,
    std::vector<SkewHeapNode*> &stack,
    bool insertInStack
)
{
    node->father = nullptr;

    if (insertInStack)
        stack.push_back(node);

    if (root == nullptr)
    {
        root = node;
    }
    else
    {
        SkewHeapNode *tmp = root;
        while (tmp->right != nullptr)
        {
            tmp = tmp->right;
        }

        tmp->right = node;
        node->father = tmp;
    }
}
