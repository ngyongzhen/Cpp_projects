#ifndef TREE_H
#define TREE_H

template<class Value>
struct Node{
    Value value;
    Node *left;
    Node *right;

    bool isGreater(Node node){
        if(this.value > node.value){
            return true;
        }else{
            return false;
        }
    }
};
class Tree
{

};

#endif // TREE_H
