#include<iostream>
#include<chrono>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b; 
    *b = temp;
}

void selectionSort(int *arr, int n)
{
    int i{}, j{}, k{};

    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(arr[i] > arr[j])
            {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

int main()
{
    int n;

    std::cout << "Enter number of elements:   ";
    std::cin >> n;
    /*
    std::cout << "Enter the elements:   ";

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }
    */

    int arr[n];
    for(int i = 0; i < n; i++)
    {
        arr[i] = std::rand() % 1000;
    }

    std::cout << "The unsorted array is:  ";
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << ", ";
    }
    std::cout << "\b\b  \n";

    auto start = std::chrono::high_resolution_clock::now();
    selectionSort(arr, n);
    auto stop = std::chrono::high_resolution_clock::now();

    std::cout << "The sorted array is:  ";
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << ", ";
    }
    std::cout << "\b\b  \n";

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Time taken (in microseconds) is:  " << duration.count() << "\n"; 
}
