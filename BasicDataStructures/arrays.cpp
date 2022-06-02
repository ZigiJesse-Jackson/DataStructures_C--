#include <iostream>

int main()
{
    int Array[] = {2, 3, 4, 3, 5, 90, 120, 395, 80};

    std::cout << sizeof(Array) << std::endl;
    std::cout << Array[6] << std::endl;
    std::printf("%d\n", Array[4]);
    return 0;
}