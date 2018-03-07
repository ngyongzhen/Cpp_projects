#include <iostream>

#include <vector>
#include "BinaryTree.h"

using namespace std;

BinaryTree::BinaryTree(vector<int> vec)
{
    this->root = NULL;
    constructTree(vec);
}

BinaryTree::~BinaryTree()
{
    traverse(this->root, true);
}

// Public
void BinaryTree::insertData(int data){
    insertData(&(this->root), data);
}

void BinaryTree::traverse(){
    traverse(this->root, false);
}

bool BinaryTree::isExist(int data){
    cout << "Searching for " << data << endl;
    return searchTree(this->root, data) != NULL;
}

// Private
void BinaryTree::constructTree(vector<int> vec){
    for(int v : vec){
        insertData(&(this->root), v);
    }
}

void BinaryTree::insertData(Node** node, int data){
    if(*node == NULL){
        *node = getNewNode(data);
    }else if(data <= (*node)->data){
        insertData(&((*node)->left), data);
    }else{
        insertData(&((*node)->right), data);
    }
}

Node* BinaryTree::getNewNode(int data){
    Node* node = new Node();
    node->data = data;
    return node;
}

void BinaryTree::traverse(Node* node, bool isDestroy){
    if(node == NULL)return;
    traverse(node->left, isDestroy);
    if(!isDestroy){
        cout << node->data << endl; // Sorted printout
    }
    traverse(node->right, isDestroy);
    if(isDestroy){
        delete[] node;
    }
}

Node* BinaryTree::searchTree(Node* node, int data){
    if(node == NULL) return NULL;
    if(data == node->data){
        return node;
    }
    return searchTree(node->left, data);
    return searchTree(node->right, data);
}
