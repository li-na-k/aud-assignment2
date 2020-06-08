#ifndef BST_HPP 
#define BST_HPP
#include <iostream>
#include <fstream>

int i = 0; //counter for drawing nullptr, used in printBST-method

class BST{
    public:
        //constructor for initializing list
        BST ():
        root_ {nullptr}
        {}

        
        /*Search: Search, that returns either a pointer to the node that has a given key value 
        or NIL if the Tree doesn’t contain such a node. 
        Searching has complexity O(h) where h is the height of a Tree.*/
        Node* search(int key) const{
            Node* it = new Node{};
            it = root_;
            bool found = false;
            while(found == false){
                if(it == nullptr || it->key == key){ 
                    return it;
                    found = true;
                }
                else if(it->key < key){
                    it = it->right;
                }
                else{
                    it = it->left;
                }
            }
        }

        /* given a tree's root, return a pointer to the node with the maximum and the minimum key,
        respectively the rightmost and the leftmost in the Tree. They both have complexity O(h).*/
        Node* minimum (Node* root) const {
            Node* min = new Node{};
            min = root;
            while (min->left != nullptr) {
                min = min->left;
            }
            return min;
        }
    
        Node* maximum(Node* root) const {
            Node* max = new Node{};
            max = root;
            while (max->right != nullptr) {
                max = max->right;
            }
            return max;
        }
        /* Predecessor (complexity O(h)) of a node x returns the node with the maximum smaller key in the Tree (NIL if x is the minimum node).
        The predecessor of x is defined as the Maximum(x.left) if x.left 6= NIL or as the first ancestor reached from its right sub-tree.*/
        Node* predecessor(Node* const x){
            if(x->key == minimum(root_)->key){
                return nullptr;
            }
            else{
            return maximum(x->left);
            }
        }

        /* Successor (complexity O(h)) of a node x returns the node with the minimum bigger key in the Tree (NIL if x is the maximum node).
        The successor of x is defined as the Minimum(x.right) if x.right 6= NIL or as the first ancestor reached from its left sub-tree.*/
        Node* successor(Node* x){
            if(x->key == maximum(root_)->key){
                return nullptr;
            }
            else{
                return minimum(x->right);
            }
        }

        //inserts a node into tree. If node with the same key is already in the tree the new node is inserted left to the already existing node
        void insert (Node* new_node) {
            Node* it = new Node{};
            it = root_; 

            bool is_inserted = false;
            bool found_place = false;

            if (it == nullptr) { //if tree is empty
                root_ = new_node;
            } else {
                while (!is_inserted) {
                //find right place for new node
                    while(!found_place){
                        if (new_node->key <= it->key && it->left != nullptr) {
                            it = it->left;
                        } else if (new_node->key > it->key && it->right != nullptr) {
                            it = it->right;
                        }
                        else{
                            found_place=true;
                        }
                    }
                //insert node as left or right child of it
                if (new_node->key <= it->key) {
                    it->left = new_node;
                    new_node->p = it;
                    is_inserted = true;
                } else if (new_node->key > it->key) {
                    it->right = new_node;
                    new_node->p = it;
                    is_inserted = true;
                }
                }
            }
        }

        /*removes Node out of tree and deletes it*/
        void remove (Node* it) {
            //Case 1: if it is a leaf
            if (it->left == nullptr && it->right == nullptr) { 
                if(it == root_){ //if it is only node in the tree
                    root_ = nullptr;
                }
                else{ 
                    if (it->p->left == it){ //check whether it is the right or left child and kill connection to parent
				        it->p->left = nullptr;
                    } else {
				        it->p->right = nullptr;
                    }
                }
                it = nullptr;
                delete it;
            //Case 2: If x has only one child
            } else if ((it->left == nullptr && it->right != nullptr) || (it->right == nullptr && it->left != nullptr)) {
                //find child Node
                Node* child;
                if(it->left == nullptr && it->right != nullptr){
                    child = (it->right);
                }
                else{
                    child = (it->left);
                }

                if (it == root_){ //check if it is root
                    root_ = child;
                }
                else{
                    if (it == it->p->left){ //again, check whether it is a left or right child
                        child->p = it->p;
                        it->p->left = child;
                    } 
                    else {
                        child->p = it->p;
				        it->p->right = child;
                    }
                }
                it = nullptr;
                delete it;
            //Case 3: If it has two children and its right child doesn’t have a left child
            } else if (it->left != nullptr && it->right != nullptr && it->right->left == nullptr) {
                //it can be substituted with right child
                Node* right_child = it->right;
                right_child->p = it->p;
                right_child->left = it->left;
                if(it != root_){
                    if (it == it->p->left){ //again, check whether it is a left or right child (to set parent of it to right_child)
                        it->p->left = right_child;
                    } else {
                        it->p->right = right_child;
                    }
                } else{
                    root_ = right_child;
                }
                it = nullptr;
                delete it;
            //Case 4
            } else if (it->right != nullptr && it->right->right != nullptr && it->right->left != nullptr && successor(it)->left == nullptr) {
                Node* z = successor(it);
                //set right child of z
                z->right = it->right;
                it->right->p = z;
                z->right->left = nullptr;

                //set parent of z
                z->p = it->p;
                if(it != root_){
                    if (it == it->p->left){ //again, check whether it is a left or right child (to set parent of it to right_child)
                    it->p->left = z;
                    } else {
				        it->p->right = z;
                    }
                } else {
                    root_ = z;
                }
                
                //set left child of z
                z->left = it->left;
                it->left->p = z;

                it = nullptr;
                delete it;
            }
        }

        void printBST () {
            const char *path="../../myfile.gv";
            std::ofstream myfile(path);
            myfile << "digraph SampleBST{" << std::endl;

            printBST_aux(root_, myfile);

            myfile << "}" << std::endl;
            myfile.close();
        }

        void printBST_aux (Node* it, std::ofstream& stream) { //auxiliary method for printBST()
             if (it->left != nullptr) {
                stream << it->key << "->" << it->left->key << ";" << std::endl; 
                printBST_aux(it->left, stream); //recursively draw left path until nullptr is reached
                }
            else{
                //draw nullptr
                stream << "nil" << i << "[shape=point];" << std::endl;
                stream << it->key << "->" << "nil" << i << ";" << std::endl; 
                i++; //i is a global variable
                }
            if(it->right != nullptr) {
                stream << it->key << "->" << it->right->key << ";" << std::endl;
                printBST_aux(it->right, stream); //recursively draw right path until nullptr is reached
            }
            else{
                //draw nullptr
                stream << "nil" << i << "[shape=point];" << std::endl;
                stream << it->key << "->" << "nil" << i << ";" << std::endl; 
                i++;
            }

        }      


                          

    private:
        Node* root_;


};

#endif
