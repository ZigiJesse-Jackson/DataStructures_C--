#include <array>
#include <algorithm>

// explanation in Notion notebook under Google Interview Questions
template<size_t n>
int Find_Swaps(const int target, const std::array<int, n> &A, const std::array<int, n> &B){
    int num_swaps = 0;

    for(int i = 0; i<A.size();i++){
        if(A[i] != target && B[i] != target){
            return INT_MAX;
        }else if(A[i] != target){
            num_swaps+=1;
        }
    }
    return num_swaps;
}

template<size_t n>
int Min_Dom_Rot(const std::array<int, n> &A, const std::array<int, n> &B){
    // check that arrays are not empty and are of equal size
    if(A.size()<1 && (A.size() != B.size())){
        return -1;
    }

    int target_A = A[0];
    int target_B = B[0];

    int min1 = std::min(Find_Swaps(target_A, A, B),Find_Swaps(target_A, B, A));
    int min2 = std::min(Find_Swaps(target_B, A, B), Find_Swaps(target_B, B, A));

    int num_rotations = std::min(min1, min2) == INT_MAX ? -1 : std::min(min1, min2);

    return num_rotations;
}