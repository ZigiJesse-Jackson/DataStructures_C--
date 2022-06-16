#include <iostream>
#include "./List-Type_Data_Structures/BinaryTree.cpp"

int main()
{   
    BinaryNode<int>* root = new BinaryNode<int>(8, 8);
    BinaryTree<int> tree = BinaryTree<int>(root);
    BinaryNode<int>* n_4 = new BinaryNode<int>(4,4);
    BinaryNode<int>* n_12 = new BinaryNode<int>(12,12);
    BinaryNode<int>* n_2 = new BinaryNode<int>(2,2);
    BinaryNode<int>* n_6 = new BinaryNode<int>(6,6);
    BinaryNode<int>* n_10 = new BinaryNode<int>(10,10);
    BinaryNode<int>* n_14 = new BinaryNode<int>(14,14);
    BinaryNode<int>* n_1 = new BinaryNode<int>(1,1);
    BinaryNode<int>* n_3 = new BinaryNode<int>(3,3);
    BinaryNode<int>* n_5 = new BinaryNode<int>(5,5);
    BinaryNode<int>* n_7 = new BinaryNode<int>(7,7);
    BinaryNode<int>* n_9 = new BinaryNode<int>(9,9);
    BinaryNode<int>* n_11 = new BinaryNode<int>(11,11);
    BinaryNode<int>* n_13 = new BinaryNode<int>(13,13);
    BinaryNode<int>* n_15 = new BinaryNode<int>(15,15);
    BinaryNode<int>* n_17 = new BinaryNode<int>(94,29);

    tree.insert(n_4);
    tree.insert(n_12);
    tree.insert(n_2);
    tree.insert(n_6);
    tree.insert(n_10);
    tree.insert(n_14);
    tree.insert(n_1);
    tree.insert(n_3);
    tree.insert(n_5);
    tree.insert(n_7);
    tree.insert(n_9);
    tree.insert(n_11);
    tree.insert(n_13);
    tree.insert(n_15);
    tree.insert(n_17);  

    tree.printTree();
    
    return 0;
}