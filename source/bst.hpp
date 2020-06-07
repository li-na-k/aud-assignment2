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
        void insert (Node* new_node) {
            Node* it = new Node{};
            it = root_;

            bool is_inserted = false;
            bool found_place = false;
            //was passiert wennx.key = y.key??
            if (it == nullptr) {
                root_ = new_node;
            } else {
                while (!is_inserted) {
                    while(!found_place){
                        if (new_node->key < it->key && it->left != nullptr) {
                            it = it->left;
                        } else if (new_node->key > it->key && it->right != nullptr) {
                            it = it->right;
                        }
                        else{
                            found_place=true;
                        }
                    }
                if (new_node->key < it->key) {
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
        void PrintBST () {
            int i = 0;
            const char *path="/Users/klara/myfile.gv";
            std::ofstream myfile(path);
            Node* it = new Node{};
            it = root_;
            
            myfile << "digraph SampleBST{" << std::endl;
            
            if (it == nullptr) {
                myfile << "nil0[shape=point];" << std::endl;
            }
            
            while (it->left != nullptr) {
                myfile << it->key << "->" << it->left->key << std::endl;
                it = it->left;
            }
            myfile << "nil" << i << "[shape=point];" << std::endl;
            myfile << it->key << "-> nil" << i << std::endl;
            i++;
            it = root_;
            while (it->right != nullptr) {
                myfile << it->key << "->" << it->right->key << std::endl;
                it = it->right;
            }
            myfile << "nil" << i << "[shape=point];" << std::endl;
            myfile << it->key << "-> nil" << i << std::endl;
            i++;
            myfile << "}" << std::endl;
            myfile.close();
        }

        //Print (outputs a .gv file in dot language) siehe Folien (auch leere Knoten zeichnen!)
        void PrintBST2 () {
            const char *path="/Users/linaklass/myfile.gv";
            std::ofstream myfile(path);

            myfile << "digraph SampleBST{" << std::endl;

            Node* it = root_;
            int i = 0;
            while(it->key <= maximum()->key){
                while(it->left != nullptr){
                    myfile << it->key << "->" << it->left->key << ";" << std::endl;
                    it = it->left;
                }

                //draw nullptr
                myfile << "nil" << i << "[shape=point];" << std::endl;
                myfile << it->key << "->" << "nil" << i << ";" << std::endl; 
                i++;

                if(it->right != nullptr){
                    myfile << it->key << "->" << it->right->key << ";" << std::endl;
                    it = it->right;
                } else {
                    //draw nullptr
                    myfile << "nil" << i << "[shape=point];" << std::endl;
                    myfile << it->key << "->" << "nil" << i << ";" << std::endl; 
                    i++;
                    if (it->key != maximum()->key) {
                        it = it->p->p->right;   
                    }else{
                        break;
                    }
                } 
                 
            } 
            myfile << "}" << std::endl;
            myfile.close();
        }          


                          

    private:
        Node* root_;


};

#endif
