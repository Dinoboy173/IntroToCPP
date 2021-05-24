#include <iostream>
#include "RecursivePower.h"

int main(int argc, char** argv)
{
    int num = 2;
    int power = 5;

    std::cout << "RecursivePower1" << std::endl;
    std::cout << RecursivePower1(num, power) << std::endl;
    std::cout << std::endl;

    std::cout << "RecursivePower2" << std::endl;
    std::cout << RecursivePower2(num, power) << std::endl;
    std::cout << std::endl;

    std::cout << "RecursivePower3" << std::endl;
    std::cout << RecursivePower3(num, power) << std::endl;
    std::cout << std::endl;

    return 0;
}