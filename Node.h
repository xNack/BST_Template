//
// Created by Gianmarco  Caruso on 14/09/22.
//

#ifndef BST_PRO_GIANMARCO_NODE_H
#define BST_PRO_GIANMARCO_NODE_H

template<typename T>
class Node {

public:
    Node<T>* parent;
    Node<T>* right;
    Node<T>* left;
    T val;
};


#endif //BST_PRO_GIANMARCO_NODE_H
