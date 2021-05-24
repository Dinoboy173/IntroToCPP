#include <iostream>

bool BinarySearch(int* arr, int size, int searchValue)
{
    // TODO: write your code here
    int left = 0;
    int right = (size - 1);
    int mid = (right + left) / 2;

    bool found = false;

    while (!found)
    {
        mid = (right + left) / 2; // sets mid value

        if (mid == left && searchValue > arr[mid]) mid = right; // checks if mid gets stuck on second last cell when searchValue is in last cell

        if (arr[mid] == searchValue) found = true; // checks if searchValue is found
        else if (searchValue < arr[mid]) right = mid; // moves mid right
        else if (searchValue > arr[mid]) left = mid; // moves mid left

        if (left == mid && right == mid) break; // checks if searchValue was not found
    }

    if (found == true) return true;
    else return false;
}

int main()
{
    const int ARR_SIZE = 8;
    int arr1[ARR_SIZE] = { 1, 3, 5, 7, 9, 11, 13, 15 };

    std::cout << (BinarySearch(arr1, ARR_SIZE, 9) ? "Found" : "Not Found") << std::endl;
    std::cout << (BinarySearch(arr1, ARR_SIZE, 1) ? "Found" : "Not Found") << std::endl;
    std::cout << (BinarySearch(arr1, ARR_SIZE, 15) ? "Found" : "Not Found") << std::endl;
    std::cout << (BinarySearch(arr1, ARR_SIZE, 0) ? "Found" : "Not Found") << std::endl;

    return 0;
}