/* 
* Implement Recursive Binary search and Linear search and determine the time required to search an element. 
* Repeat the experiment for different values of N and plot a graph of the time taken versus N.
*/

//This program calculates the worst time required to search an element. Therefore, the key is always the last element.
//and all the elements are distinct to prevent the algorithm from finding a copy of the last element.

#include <iostream>
#include <chrono>

int linearSearch(int arr[], int start, int size, int key)
{
    if(start == size)
        return -1;
    else if(arr[start] == key)
        return start;
    else
        return linearSearch(arr, start + 1, size, key);
}

int main()
{
    int size, key;
    std::cout << "Enter size of array:   ";
    std::cin >> size;

    int arr[size];
    /*
    std::cout << "Enter the elements of the array:   ";
    for(int i = 0; i < size; i++)
    {
        std::cin >> arr[i];
    }
    */

    for(int i = 0; i < size; i++)
    {
        arr[i] = i;
    }

    /*
    std::cout << "Enter element to be searched:   ";
    std::cin >> key;
    int result = linearSearch(arr, 0, size, key);
    */

    key = arr[size - 1];
    auto start = std::chrono::high_resolution_clock::now();
    int result = linearSearch(arr, 0, size, key);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Time taken (in microseconds) to search last element is:  " << duration.count() << "\n"; 


    /*
    if(result != -1)
        std::cout << "The element has been found at position " << result << "\n";
    else
        std::cout << "Element not found!\n";
    
    */

    return 0;
}