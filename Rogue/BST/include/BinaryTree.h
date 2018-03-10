#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "vector"

using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};
class BinaryTree
{
    public:
        BinaryTree(vector<int>);
        virtual ~BinaryTree();

        void insertData(int);
        void traverse();
        bool isExist(int);

    private:
        Node *root;

        void constructTree(vector<int>);
        void insertData(Node**, int);
        Node* getNewNode(int);
        void traverse(Node*, bool);
        Node* searchTree(Node*, int);
};

#endif // BINARYTREE_H
