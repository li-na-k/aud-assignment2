#ifndef BST_HPP 
#define BST_HPP
#include <iostream>
#include <fstream>

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

        /* given a Tree or its Root, return a pointer to the node with the maximum and the minimum key,
        respectively the rightmost and the leftmost in the Tree. They both have complexity O(h).*/
        Node* minimum () const {
            Node* min = new Node{};
            min = root_;
            while (min->left != nullptr) {
                min = min->left;
            }
            return min;
        }
    
        Node* maximum() const {
            Node* max = new Node{};
            max = root_;
            while (max->right != nullptr) {
                max = max->right;
            }
            return max;
        }
        /* Predecessor (complexity O(h)) of a node x returns the node with the maximum smaller key in the Tree (NIL if x is the minimum node).
        The predecessor of x is defined as the Maximum(x.left) if x.left 6= NIL or as the first ancestor reached from its right sub-tree.*/
        Node* predecessor(Node const& it);

        /* Successor (complexity O(h)) of a node x returns the node with the minimum bigger key in the Tree (NIL if x is the maximum node).
        The successor of x is defined as the Minimum(x.right) if x.right 6= NIL or as the first ancestor reached from its left sub-tree.*/
        Node* successor(Node* it);

        //TODO: Insert and Delete (node = root when function is called)
        void insert (Node* node, Node* it) {
            if (root_ == nullptr) {
                root_ = it;
            } else {
                node = root_;
                while (node->left != nullptr && node->right != nullptr) {
                    if (it->key < node->key) {
                        return insert (node->left, it);
                    }
                    if (it->key > node->key) {
                        return insert (node->right, it);
                    }
                }
                if (it->key < node->key) {
                    node->left = it;
                } else if (it -> key > node->key) {
                    node->right = it;
                }
            }
        }

        void remove (Node* it) {
            if (it->left == nullptr && it->right == nullptr) {
                //1st case
            } else if ((it->left == nullptr && it->right != nullptr) || (it->right == nullptr && it->left != nullptr)) {
                //2nd case
            } else if (it->left != nullptr && it->right != nullptr && it->right->left == nullptr) {
                //3rd case
            } else if (it->right != nullptr && it->right->right != nullptr && it->right->left != nullptr && successor(it)->left == nullptr) {
                //4th case
            }
        }

        //Print (outputs a .gv file in dot language) siehe Folien (auch leere Knoten zeichnen!)
        void PrintBST (Node* it) {
            int i = 0;
            const char *path="/Users/klara/myfile.gv";
            std::ofstream myfile(path);
           
            if (root_ == nullptr) {
                //return 0;
            }
            while (root_->left != nullptr) {
                myfile << root_ << "->" << root_->left << std::endl;
                PrintBST(root_->left);
            }
            //printf("nili[shape=point];");
            myfile << "nil" << i << "[shape=point];" << std::endl;
            myfile << root_ << "-> nil" << i << std::endl;
            i++;
            while (root_->right != nullptr) {
                PrintBST(root_->right);
                myfile << root_ << "->" << root_->right << std::endl;
            }
            myfile.close();
        }

    private:
        Node* root_;


};

#endif
