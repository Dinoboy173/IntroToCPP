#include <iostream>

// Note

void RecursiveFibonacci(int num1, int num2, int count)
{
    if (count <= 0) return;

    std::cout << num1 << std::endl;

    RecursiveFibonacci(num2, num1 + num2, count - 1);
}

int main(int argc, char** argv)
{
    RecursiveFibonacci(0, 1, 15);

    return 0;
}