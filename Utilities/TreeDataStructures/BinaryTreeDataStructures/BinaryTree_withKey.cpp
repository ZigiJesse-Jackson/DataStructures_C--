#include "BinaryNode_withKey.cpp"
#include <algorithm>
#include <vector>
#include <iostream>

template<typename T>
class BinaryTree{
    BinaryNode<T>* root; 

    // Helper function for BinaryTree destructor
    void deleteBinaryTree(BinaryNode<T>* node){
            if(node==nullptr){
                return;
            }
            deleteBinaryTree(node->left);
            deleteBinaryTree(node->right);
            delete node;
        }

    // Prints tree inorder fashion     
    void printTree(BinaryNode<T>* node){
        // node with no children
        if(node->left==nullptr && node->right==nullptr){
            std::cout << node->data;
            return;
        }

        // initializing current node as root
        BinaryNode<T>* curr = node;
        std::vector<BinaryNode<T>*> stack;
        // traversing inorder iterative
        while (curr!=nullptr || stack.empty()==false){
            // using stack to keep track of Depth
            while(curr!=nullptr){
                stack.push_back(curr);
                curr = curr->left;
            }

            // printing tree inorder
            curr = stack.back();
            std::cout << curr->data << " ";
            stack.pop_back();
            curr = curr->right;
        }
    }

    public:
        // 0-paramter constructor
        BinaryTree(){
            root = new BinaryNode<T>();
        }

        // parameter constructor
        BinaryTree(BinaryNode<T>* node){
            root = node;
        }

        // copy constructor
        BinaryTree(BinaryTree & tree){
            root = new BinaryNode<T>(tree.root->data);
        }

        // move constructor 
        BinaryTree(BinaryTree && tree):root{std::move(tree.root)}{
            tree.root = nullptr;
        }

        // copy assignment
        BinaryTree& operator=(BinaryTree& other){
            root = other.root;
        }

        // move assignment
        BinaryTree& operator=(BinaryTree&& other){
            std::swap(root, other.root);
            other.root = nullptr;
            
        }

        void insert(BinaryNode<T>* inserted_node){

            // Tree is empty
            if(root == nullptr)return;

            // Node to be inserted has the same key as root
            if(root->key == inserted_node->key){
                inserted_node->left = root->left;
                inserted_node->right = root->right;
                std::swap(inserted_node,root);
                delete inserted_node;
                return;
            }
            BinaryNode<T>* parent = root;
            bool notFound = true;
            while(notFound){
                // Node to be inserted should be on right side of parent
                if(parent->key>inserted_node->key){
                    // Spot found for node to be inserted as leaf
                    if(parent->right==nullptr){
                        parent->right = inserted_node;
                        break;
                    }
                    parent = parent->right;
                    continue;
                    }
                // Node to be inserted should be on left side of parent
                if(parent->key<inserted_node->key){
                    // Spot found for node to be inserted as leaf
                    if(parent->left==nullptr){
                        parent->left = inserted_node;
                        break;
                    }
                    parent = parent->left;
                    continue;
                }
                // Node to be inserted should be inserted as parent
                if(parent->key==inserted_node->key){
                    inserted_node->left = parent->left;
                    inserted_node->right = parent->right;
                    std::swap(parent->data, inserted_node->data);
                    delete inserted_node;
                    break;
                }
            }
            return;    
        }

        // print content of tree inorder
        void printTree(){
            printTree(root);
        }

        // BinaryTree destructor
        ~BinaryTree(){
            deleteBinaryTree(root);
            return;
        }
};

