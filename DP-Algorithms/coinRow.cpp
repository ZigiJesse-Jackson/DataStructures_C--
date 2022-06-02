#include <iostream>
#include <array>
#include <algorithm>

// takes an array coins of positive integers in no particular order
template <std::size_t n>
int coinRow(std::array<int, n> coins)
{
    if (n < 1) // check that number of coins in array
    {
        return -1; // no coins in array, return -1
    }
    std::array<int, coins.size() + 1> F; // create array for optimal solution
    std::array<int, coins.size() + 1> C; // create array for traversal

    for (int i = 0; i < coins.size(); i++)
    {
        C[i + 1] = coins[i]; // copy coins into array C with offset 1
    }

    F[0] = 0;        // F[0] = 0 by problem definition
    F[1] = coins[0]; // F[1] = first coin by problem definition
    for (int i = 2; i <= coins.size(); i++)
    {
        F[i] = std::max(C[i] + F[i - 2], F[i - 1]); // optimal solution for i coins is max of optimal solution
                                                    // C[i] + optimal solution of n-2 coins and optimal solution
                                                    // of n-1 coins
    }
    return F[coins.size()]; // return optimal solution
}