#include <iostream>
#include <string>

int Calculate(int num1, int num2, std::string operation)
{
    if (operation == "Add")
        return num1 + num2;
    else if (operation == "Sub")
        return num1 - num2;
    else if (operation == "Mul")
        return num1 * num2;
    else if (operation == "Div")
        return num1 / num2;
}

int main(int argc, char** argv)
{
    int num1 = 0;
    int num2 = 0;
    std::string operation = "";

    std::cout << "Please enter a number: ";
    std::cin >> num1;

    std::cout << "Please enter another number: ";
    std::cin >> num2;

    std::cout << "Please enter an operation (Add, Sub, Mul, Div): ";
    std::cin >> operation;

    std::cout << Calculate(num1, num2, operation);

    return 0;
}