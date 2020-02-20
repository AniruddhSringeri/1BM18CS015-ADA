//Write an efficient program for printing k largest elements in an array. Elements in the array can be in any order. 
//It is given that all array elements are distinct.

#include <iostream>
#include <algorithm>

int main()
{
    int n, k;

    std::cout << "Enter the size of array:   ";
    std::cin >> n;
    int arr[n];
    std::cout << "Enter an array with distinct elements:    ";

    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    std::sort(arr, arr+n);

    std::cout << "Enter k:   ";
    std::cin >> k;

    std::cout << "These are the " << k << " largest elements in the array:   ";

    for(int i = 0; i < k; i++)
    {
        std::cout << arr[n-1-i] << std::endl;
    }

    return 0;
}