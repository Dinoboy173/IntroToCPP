#include <iostream>

// Note

int RecursivePower1(int num, int power)
{
    if (power <= 1) return num;
    else return RecursivePower1(num + num, power - 1);

    return num;
}

int RecursivePower2(int num, int power)
{
    while (power > 1)
    {
        num = num * 2;

        power--;
    }

    return num;
}

int RecursivePower3(int num, int power)
{
    do ((num = num * 2) && power--);
    while (power > 1);

    if (power <= 1) return num;

    return num;
}