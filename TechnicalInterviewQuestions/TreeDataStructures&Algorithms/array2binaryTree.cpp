#include "../.././Utilities/TreeDataStructures/BinaryTreeDataStructures/BinaryTree_withKey.cpp"
#include <array>
#include <vector>
#include <iostream>

// helper function to Binary Tree order of array by array indices
template<typename T, size_t n>
void arr_ind_2_binary(std::array<T, n>& arr, std::vector<int>& queue, int l, int r){
    // base case
    if(l==r || l>r){
        queue.push_back(l);
        return;
    }

    // binary traversal of array
    int mid = (r+l)/2;
    queue.push_back(mid);

    arr_ind_2_binary(arr, queue, l, mid-1);
    arr_ind_2_binary(arr, queue, mid+1, r);
}


template<typename T, size_t n>
BinaryTree<T>* array_to_BST(std::array<T, n>& arr){
    // vector to hold order of insertions into BinaryTree
    std::vector<int> indices_bin_tree_order;
    arr_ind_2_binary(arr, indices_bin_tree_order, 0,arr.size()-1);

    // position of root of resultant binary tree in parameter array
    int root = indices_bin_tree_order[0];
    // constructing root node and creating binary tree
    BinaryNode<T>* new_node =  new BinaryNode<T>(arr[root], arr[root]);
    BinaryTree<T>* bst = new BinaryTree<T>(new_node);

    // inserting nodes by pre-order traversal of array for height-balanced tree
    // the BinaryNode key is assumed to be the same as the BinaryNode data
    for( int i=0;i<indices_bin_tree_order.size();i++){
        // accessing index of array by order of pre-order traversal
        int pos = indices_bin_tree_order[i];
        new_node =  new BinaryNode<T>(arr[pos], arr[pos]);
        
        // std::cout << pos <<" "<<arr[pos]<<"\n";
        bst->insert(new_node);
    }

    return bst;
}

