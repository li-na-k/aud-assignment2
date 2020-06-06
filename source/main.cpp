#include "node.hpp"
#include "bst.hpp"

int main(){
    BST example1 {};
    Node* x = new Node{};
    x->key=3;
    Node* y = new Node{};
    y->key=6;
    Node* xy = new Node{};
    xy->key=10;
    Node* c = new Node{};
    c->key=2;
    example1.insert(x, x);
    example1.insert(y, y);
    example1.insert(xy, xy);
    example1.insert(c, c);
    Node* result = new Node{};
    result = example1.search(6);
    std::cout << (example1.minimum())->key << std::endl;
    std::cout << (example1.maximum())->key << std::endl;
    //example1.PrintBST(x);
    return 0;
}
