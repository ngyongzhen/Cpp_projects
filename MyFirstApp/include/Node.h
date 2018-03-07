#ifndef NODE_H
#define NODE_H

template<class Value>
class Node
{
    public:
        Node();
        Value value;
        Node *left;
        Node *right;

        bool isGreater(Node node);
};

#endif // NODE_H
