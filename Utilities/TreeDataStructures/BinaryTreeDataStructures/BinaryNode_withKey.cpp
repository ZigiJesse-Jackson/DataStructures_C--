#include <utility>
template<typename T>
struct BinaryNode{
    unsigned int key;
    T data;
    BinaryNode* left;
    BinaryNode* right;

    // Copy constructor with optional defaults
    BinaryNode(const unsigned int other_key=0,const T & other_data = T{}, BinaryNode * other_left = nullptr, BinaryNode * other_right = nullptr )
    :key{other_key}, data{other_data}, left{other_left}, right{other_right}, key{}{}

    // Move constructor with rvalue ref and optional defaults
    BinaryNode(unsigned int other_key, T && other_data, BinaryNode * other_left = nullptr, BinaryNode * other_right = nullptr ):key{other_key}, data{std::move(other_data)},
        left{other_left}, right{other_right} {
        }
};