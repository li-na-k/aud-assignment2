#include "node.hpp"
#include "bst.hpp"

int main(){
    BST example1 {};
    Node* x = new Node{};
    x->key=10;
    Node* y = new Node{};
    y->key=6;
    Node* xy = new Node{};
    xy->key=8;
    Node* c = new Node{};
    c->key=2;
    Node* d = new Node{};
    d->key=7;
    Node* e = new Node{};
    e->key=11;
    Node* f = new Node{};
    f->key=9;
    Node* g = new Node{};
    g->key=1;
    /*insert example*/
    example1.insert(x);
    example1.insert(y);
    example1.insert(xy);
    example1.insert(c);
    example1.insert(d);
    example1.insert(e);
    example1.insert(f);
    example1.insert(g);

    /*search example (prints key of the searched node) */
    std::cout<< "the key you searched for is: " << example1.search(6)->key << std::endl;

    /* minimum and maximum */
    std::cout<< "minimum of the tree: " << example1.minimum(x)->key << std::endl;
    std::cout<< "maximum of the tree: " << example1.maximum(x)->key << std::endl;
    
    /*predecessor and successor example*/
    std::cout<< "predecessor of given node: " << example1.predecessor(x)->key << std::endl;
    std::cout<< "sucessor of given node: " << example1.successor(y)->key << std::endl;
    
    /* to test different (border) cases of remove chose a case and un-comment it*/
        /*to test case 1*/
        //example1.remove(e);

        /*to test case 2*/
        //example1.remove(c);

        /*to test case 3*/
        //example1.remove(d);
        //example1.remove(y);

        /*to test case 4*/
        //example1.remove(y);

        /* removing the root*/
        //example1.remove(x);
        //example1.remove(e);
        //example1.remove(y);

        example1.printBST();

    return 0;
}
