#ifndef BST_HPP 
#define BST_HPP

class BST{
    public:
        //Search: Search, that returns either a pointer to the node that has a given key value or NIL if the Tree doesn’t contain such a node. Searching has complexity O(h) where h is the height of a Tree.
        Node* search(int key) const;

        //given a Tree or its Root, return a pointer to the node with the maximum and the minimum key, respectively the rightmost and the leftmost in the Tree. They both have complexity O(h).
        Node* minimum() const;
        Node* maximum() const;

        /*Predecessor (complexity O(h)) of a node x returns the node with the maximum smaller key in the Tree (NIL if x is the minimum node). 
        The predecessor of x is defined as the Maximum(x.left) if x.left 6= NIL or as the first ancestor reached from its right sub-tree.*/
        Node* predecessor(Node const& it);

        /*Successor (complexity O(h)) of a node x returns the node with the minimum bigger key in the Tree (NIL if x is the maximum node). 
        The successor of x is defined as the Minimum(x.right) if x.right 6= NIL or as the first ancestor reached from its left sub-tree.*/
        Node* predecessor(Node const& it);

        //TODO: Insert and Delete
        void insert(Node& it);
        void delete(Node const& it); //const übergabe???

        //Print (outputs a .gv file in dot language) siehe Folien (auch leere Knoten zeichnen!)

    private:
        Node root;


}

#endif