#include "node.hpp"
#include "bst.hpp"

int main(){
    BST example1 {};
    Node* x = new Node{};
    x->key=3;
    Node* y = new Node{};
    y->key=6;
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
    //result = example1.search(6);
   
    example1.PrintBST2(x);
    return 0;
}
