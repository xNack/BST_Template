//
// Created by Gianmarco  Caruso on 14/09/22.
//

#ifndef BST_PRO_GIANMARCO_BST_H
#define BST_PRO_GIANMARCO_BST_H
#include "Node.h"
#include <iostream>
#include <climits>
#include <typeinfo>

template<typename T>
class BST {

private:
    int size;
    Node<T>* root;

    /**
     * @brief Searching of minimum inside the BST
     * @param r
     * @return Node<T>*
     */
    Node<T>* _min(Node<T>* r);

    /**
     * @brief Seraching of the maximum inside the BST
     * @param r
     * @return Node<T>*
     */
    Node<T>* _max(Node<T>* r);

    /**
     * @brief Support function for searching a specific value inside a Node in the BST
     * @param val
     * @param r
     * @return
     */
    Node<T>* _search(T val, Node<T>* r);

    /**
     * Support function for deleting a value inside a Node<T> in BST
     * @param r
     * @param val
     * @return
     */
    bool _delete(Node<T>* r, T val);

public:

    /**
     * @brief Constructor for empty BST
     */
    BST();

    /**
     * @brief Constructor with inizialization of the root
     * @param x
     */
    BST(T x);

    /**
     * @brief Inserting of a new Node
     * @param x
     * @return BST*
     */
    BST* insert(T x);

    /**
     * @brief Searching a specific value inside the BST
     * @param val
     * @param r
     * @return bool
     */
    bool searching(T val); //TODO Da implementare

    /**
     * @brief Inorder Visiting of BST
     * @param r
     * @param os
     * @return std::ostream
     */
    std::ostream& inorder(Node<T>* r, std::ostream& os); //TODO Chiedere perchè private da Luigi

    /**
     * @brief Preorder Visiting of BST
     * @param r
     * @param os
     * @return std::ostream
     */
    std::ostream& preorder(Node<T>* r, std::ostream& os);

    /**
     * @brief Postorder Visiting of BST
     * @param r
     * @param os
     * @return
     */
    std::ostream& postorder(Node<T>* r, std::ostream& os);

    /**
     * Return root
     * @return Node<T>*
     */
    Node<T>* getRoot();

    /**
     * @brief Return min
     * @return T
     */
    T min();

    /**
     * Return max
     * @return T
     */
    T max();

    /**
     * @brief Searching of a value inside the BST
     * @param val
     * @return
     */
    bool search(T x);


    bool deleting(T x) { return _delete(root,x);}

    /**
     * Overloading operator << for printing BST
     * @param os
     * @param obj
     * @return std::ostream
     */
     std::ostream& put(std::ostream& os);
    //friend std::ostream& operator<<(std::ostream& os, BST<T>& obj);
};



#include "BST.tpp"
#endif //BST_PRO_GIANMARCO_BST_H
