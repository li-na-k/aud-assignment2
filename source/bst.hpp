#ifndef BST_HPP 
#define BST_HPP

class BST{
    public:
        //constructor for initializing list
        List ():
        root_ {nullptr}
        {}
        //Search: Search, that returns either a pointer to the node that has a given key value or NIL if the Tree doesn’t contain such a node. Searching has complexity O(h) where h is the height of a Tree.
        Node* search(int key) const;

        //given a Tree or its Root, return a pointer to the node with the maximum and the minimum key, respectively the rightmost and the leftmost in the Tree. They both have complexity O(h).
        Node* minimum() const;
        Node* maximum() const;

        /* Predecessor (complexity O(h)) of a node x returns the node with the maximum smaller key in the Tree (NIL if x is the minimum node).
        The predecessor of x is defined as the Maximum(x.left) if x.left 6= NIL or as the first ancestor reached from its right sub-tree.*/
        Node* predecessor(Node const& it);

        /* Successor (complexity O(h)) of a node x returns the node with the minimum bigger key in the Tree (NIL if x is the maximum node).
        The successor of x is defined as the Minimum(x.right) if x.right 6= NIL or as the first ancestor reached from its left sub-tree.*/
        Node* successor(Node const& it);

        //TODO: Insert and Delete (node = root when function is called)
        void insert (Node& node, Node& it) {
            if (root_ == nullptr) {
                root_ = it;
            } else {
                while (node->leftchild != nullptr && node->rightchild != nullptr) {
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
        void remove (Node& it) {
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
            if (root_ == nullptr) {
                return 0;
            }
            while (root_->left != nullptr) {
                printf("%i -> %i", root_, root_->left);
                PrintBST(root_->left);
            }
            printf("nili[shape=point];");
            printf("%i -> %i", root_, nili);
            while (root_->right != nullptr) {
                PrintBST(root_->right);
                printf("%i -> %i", root_, root_->right);
            }
        }

    private:
        Node* root_;


}

#endif
