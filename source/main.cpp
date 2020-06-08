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
    example1.insert(x);
    example1.insert(y);
    example1.insert(xy);
    example1.insert(c);
    example1.insert(d);
    example1.insert(e);
    example1.insert(f);
    example1.insert(g);

    
    //Node* result = new Node{};
    //result = example1.search(6);
    //std::cout << (example1.minimum())->key << std::endl; Das wieder rein
    //std::cout << (example1.maximum())->key << std::endl;
    //example1.PrintBST();
/*
    Node* z = new Node{};
    z->key=7;
    Node* a = new Node{};
    a->key=10;
    Node* b = new Node{};
    b->key=22;
    Node* c = new Node{};
    c->key=99;
    example1.insert(x, x);
    example1.insert(y, y);
    example1.insert(z, z);
    example1.insert(a, a);
    example1.insert(b, b);
    example1.insert(c, c);
    //Node* result = new Node{};
    //result = example1.search(6);*/
   
    
    std::cout<< example1.predecessor(x)->key << std::endl;
    std::cout<< example1.successor(y)->key << std::endl;
    //example1.remove(d);
    //example1.remove(f);
    example1.remove(y);
    example1.PrintBST4();

    return 0;
}
