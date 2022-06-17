#include <utility>
template<typename T>
struct BinaryNode{
    int key;
    T data;
    BinaryNode<T>* left;
    BinaryNode<T>* right;

    // Copy constructor with optional defaults
    BinaryNode(int other_key=0,const T & other_data = T{}, BinaryNode* other_left = nullptr, BinaryNode * other_right = nullptr )
    :key{other_key}, data{other_data}, left{other_left}, right{other_right} {}

    // Move constructor with rvalue ref and optional defaults
    BinaryNode(int other_key, T && other_data, BinaryNode * other_left = nullptr, BinaryNode * other_right = nullptr ):key{other_key}, data{std::move(other_data)},
        left{other_left}, right{other_right} {}
};