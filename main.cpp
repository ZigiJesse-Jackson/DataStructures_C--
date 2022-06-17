#include <iostream>
#include <array>    
// #include "./Utilities/TreeDataStructures/BinaryTreeDataStructures/BinaryTree_withKey.cpp"
#include "./TechnicalInterviewQuestions/TreeDataStructures&Algorithms/array2binaryTree.cpp"

int main()
{   
    std::array<int, 5> arr = {-10,-3,0,5,9}; 
    BinaryTree<int>* tree;
    tree = array_to_BST(arr);   
    tree->printTree(1);
    
    return 0;
}