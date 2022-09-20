//
// Created by Gianmarco  Caruso on 14/09/22.
//

#include "BST.h"

template<typename T>
BST<T>::BST() {
    root = nullptr;
    size = 0;
    //TODO domanda perchè non inizializziamo inizialmente anche root->right a null e root->left a nullptr
}

template<typename T>
BST<T>::BST(T x) {
    root = new Node<T>();
    root->val = x;
    size = 1;
}

template<typename T>
BST<T>* BST<T>::insert(T x) {
    //At first making a new Node<T>
    Node<T>* n = new Node<T>();
    n->val = x;

    //Base case
    if(root == nullptr) root = n;
    else{
        //Caso in cui la root non è nulla e L'albero contiene dei valori
        Node<T>* tmp = root;
        while(true) {
            //Controllo se il valore che devo inserire è più piccolo del valore del nodo corrente
            if(x < tmp->val){
                //Se posso andare a sinistra cambio Nodo
                if(tmp->left) tmp = tmp->left;
                //Se non posso andare a sinistra creo un nuovo Nodo
                else{
                    tmp->left = new Node<T>();
                    tmp->left->val = x;
                    tmp->left->parent = tmp;
                    break;
                }
            }
            //Controllo se il valore che devo inserire è maggiore o uguale del valore nel Nodo corrente
            else if(x >= tmp->val) {
                //Se posso andare a destra cambio Nodo
                if(tmp->right) tmp = tmp->right;
                //Se non posso andare a destra creo un nuovo Nodo
                else{
                    tmp->right = new Node<T>();
                    tmp->right->val = x;
                    tmp->right->parent = tmp;
                    break;
                }
            }
        }
    }
    size++;
    return this;
}

template<typename T>
std::ostream& BST<T>::inorder(Node<T> *r, std::ostream &os) {
    if(!r) return os;
    inorder(r->left,os);
    os << r->val << " ";
    inorder(r->right,os);
    return os;
}

template<typename T>
std::ostream& BST<T>::preorder(Node<T> *r, std::ostream &os) {
    if(!r) return os;
    os << r->val << " ";
    preorder(r->left,os);
    preorder(r->right,os);
    return os;
}

template<typename T>
std::ostream& BST<T>::postorder(Node<T> *r, std::ostream &os) {
    if(!r) return os;
    postorder(r->left,os);
    postorder(r->right,os);
    os << r->val << " ";
    return os;
}

template<typename T>
Node<T>* BST<T>::_min(Node<T> *r) {
    while(r->left) r = r->left;
    return r;
}

template<typename T>
T BST<T>::min() {
    Node<T>* n = _min(root);
    T r;
    if(!n) {
        if(typeid(T) == typeid(std::string)) {
            return r;
        }
        else {
            return r = INT_MIN;
        }
    }
    return n->val;
}

template<typename T>
Node<T>* BST<T>::_max(Node<T> *r) {
    while(r->right) r = r->right;
    return r;
}

template<typename T>
T BST<T>::max() {
    Node<T>* n = _max(root);
    T r;
    if(!n) {
        if(typeid(T) == typeid(std::string)) {
            return r;
        }
        else {
            return r = INT_MAX;
        }
    }
    return n->val;
}

template<typename T>
Node<T>* BST<T>::_search(T x, Node<T> *r) {
    if(r == nullptr) return nullptr;
    if(r->val == x) return r;
    if(x < r->val) return _search(x,r->left);
    return _search(x,r->right);
}

template<typename T>
bool BST<T>::searching(T x) {
    Node<T>* tmp = _search(x, root);
    std::cout << "[Il booleano è settato a 1 se il valore è stato trovato, altrimenti è settato a 0]: ";
    return (tmp != nullptr);
}


template<typename T>
bool BST<T>::_delete(Node<T>* r, T val) {
    r = _search(val, r);
    if(!r) return false;

    //CASO 1
    /**
     * Se il nodo è una foglia senza figli, basta cancellarlo.
     *
     * Quello che bisogna fare è aggiornare il parent dicendogli che il
     * figlio non esiste più.
    */
    if(!r->left && !r->right) {
        std::cout << "DELETE CASO 1 - NODO " << val;
        if(r != root) {
            Node<T>* p = r->parent;
            /**
             * ERRORE ERA QUI:
             * ANDAVAMO A CONTROLLARE I VALORI
             * INVECE BISOGNAVA CONFRONTARE I PUNTATORI
             *
             * VECCHIO CODICE:
             * Potrebbe capitare che valori minori si trovano a sinistra
             * nonostante l'inserimento venga fatto a destra. Quindi
             * il codice sotto non poteva funzionare.
             *
             * if(r->val < p->val) p->left = nullptr;
             * else p->right = nullptr;
            */
            if(r == p->left) p->left = nullptr;
            else p->right = nullptr;
        }
        else root = nullptr;
        delete r;
    }

        //CASO 3
        /**
         * Se il nodo ha due figli, si ricerca il suo successore (massimo a sinistra),
         * si copia il valore del successore sul nodo che volevo cancellare e infine si
         * elimina il successore, che ricadrà in un caso 1 o 2.
         *
        */
    else if(r->left && r->right) {
        std::cout << "DELETE CASO 3 - NODO " << val << ": ";
        Node<T>* succ = _max(r->left);
        r->val = succ->val;
        std::cout << "SUCC: " << r->val << " -> ";
        return _delete(succ, r->val); //Questa passa al CASO 1 o 2
    }

        //CASO 2
        /**
         * Se il nodo ha un unico figlio, si elimina sostituendolo con il suo
         * unico figlio.
         *
         * Per fare questo bisogna considerare se il nodo che stiamo elminando è
         * la root, se così fosse dobbiamo aggiornarla.
         * Altrimenti dobbiamo aggiornare i figli del parent del nodo che
         * si vuole eliminare.
        */
    else {
        std::cout << "DELETE CASO 2 - NODO " << val;
        Node<T>* son = nullptr;
        if(r->left) {
            son = r->left;
        }
        else {
            son = r->right;
        }
        son->parent = r->parent;
        if(!son->parent) {
            root = son;
        }
        else {
            if(r->parent->left) r->parent->left = son;
            else r->parent->right = son;
        }
        delete r;
    }

    //Decrementiamo il numero di nodi
    size--;

    //Restituisce vero se tutto è andato a buon fine.
    std::cout << std::endl;
    return true;
}

template<typename T>
std::ostream& BST<T>::put(std::ostream &os) {
    int scleta;

    os << "Selezionare 1 per visita inorder, 2 per visita preorder, 3 per visita postorder: ";
    std::cin >> scleta;

    if(scleta == 1) {
        inorder(root,os);
        os << std::endl;
        os << "Hai selezionato visita inorder!" << std::endl;
    }
    if(scleta == 2) {
        preorder(root,os);
        os << std::endl;
        os << "Hai selezionato visita preorder!" << std::endl;
    }
    if(scleta == 3) {
        postorder(root,os);
        os << std::endl;
        os << "Hai selezionato visita postorder!" << std::endl;
    }
    os << std::endl;
    return os;
    //TODO Coprire caso con un while quand utente inserisce numeri sbagliati
}

template<typename T>
Node<T>* BST<T>::getRoot() {
    return root;
}

/*
template<typename T>
std::ostream& operator<<(std::ostream& os, BST<T>& obj) {
    obj.inorder(obj.root, os);
    os << std::endl;
    return os;
}
*/