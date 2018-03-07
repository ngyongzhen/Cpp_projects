#include "Node.h"

template<typename T>
Node<T>::Node()
{
    //ctor
}

template<typename T>
bool Node<T>::isGreater(Node node){
    if(this.value > node.value){
        return true;
    }else{
        return false;
    }
}
