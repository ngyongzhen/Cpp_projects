#include "Tree.h"

Tree::Tree(int *arr){
    buildTree(arr);
}

void buildTree(int *arr){
    if(arr.size == 1){
        return arr[0];
    }
}
