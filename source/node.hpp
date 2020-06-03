#ifndef NODE_HPP 
#define NODE_HPP       
       
struct Node {
    int key = 0; //stored value
    Node* left = nullptr; //left child
    Node* right = nullptr; //right child
    Node* p = nullptr; //parent
}       

#endif
