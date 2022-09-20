#include <iostream>
#include "BST.h"

using namespace std;

template<typename T>
ostream& operator<<(ostream& os, BST<T>& obj) {
    return obj.put(os);
}


int main() {

    BST<string>* tree_1 = new BST<string>("Antonio");
    BST<double>* tree_2 = new BST<double>();
    BST<int>* tree_3 = new BST<int>();
    BST<unsigned short>* tree_4 = new BST<unsigned short>();

    tree_1->insert("Gianmarco")->insert("Francesco")->insert("Alessia")->insert("Giulia")->insert("Zante");
    tree_2->insert(4.502)->insert(7.204)->insert(20.531)->insert(98.0092);
    tree_3->insert(20)->insert(10)->insert(15)->insert(25)->insert(23)->insert(39)->insert(35)->insert(42);
    tree_4->insert(2)->insert(1)->insert(3);


    //TODO Domanda su stampa più piccolo e non come vengono inseriti

    cout << "[tree_1]: "<< *tree_1 << endl;
    cout << "[tree_2]: "<< *tree_2 << endl;
    cout << "[tree_3]: "<< *tree_3 << endl;

    cout << "La root di [tree_3] è: " << tree_3->getRoot()->val << " !" << endl;
    cout << "La root di [tree_2] è: " << tree_2->getRoot()->val << " !" << endl;
    cout << "La root di [tree_1] è: " << tree_1->getRoot()->val << " !" << endl << endl;

    cout << "Il minimo di [tree_3] è: " << tree_3->min() << endl;
    cout << "Il minimo di [tree_2] è: " << tree_2->min() << endl << endl;
    cout << "Il minimo di [tree_1] è: " << tree_1->min() << endl; //TODO Sistemare problema INT_MIN con le stringhe

    cout << "Il massimo di [tree_3] è: " << tree_3->max() << endl;
    cout << "Il massimo di [tree_2] è: " << tree_2->max() << endl << endl;
    cout << "Il massimo di [tree_1] è: " << tree_1->max() << endl; //TODO Sistemare problema INT_MAX con le stringhe

    cout << tree_1->searching("Francesco") << endl;
    cout << tree_2->searching(20.531) << endl;
    cout << tree_3->searching(48) << endl << endl;

    cout << "[tree_1]: "<< *tree_1 << endl;
    tree_1->deleting("Gianmarco");
    cout << "[tree_1]: "<< *tree_1 << endl;

    return 0;
}
