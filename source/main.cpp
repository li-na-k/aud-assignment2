#include "node.hpp"
#include "bst.hpp"

int main(){
    BST example1 {};
    Node* x = new Node{};
    x->key=3;
    Node* y = new Node{};
    y->key=6;
    example1.insert(x, x);
    example1.insert(y, y);
    Node* result = new Node{};
    result = example1.search(6);
   
    
    example1.PrintBST(x);
    return 0;
}
