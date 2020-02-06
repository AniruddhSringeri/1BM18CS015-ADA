#include <iostream>
#include <algorithm>


void binarysearch(int arr[], int start, int end, int key)
{
    int mid;

    while(start <= end)
    {
        mid = (start+end)/2;
        if(arr[mid] == key)
        {
            int left = mid;
            int right = mid;
            while(arr[left] == key)
            {
                left--;
            }
            left++;
            while(arr[right] == key)
            {
                right++;
            }
            right--;
            std::cout << "The key is found from index " << left << " to index " << right << "\n";
            std::cout << "The count of the key is " << (right-left+1) << "\n"; 
            return;
        }

        else if(arr[mid] > key)
            binarysearch(arr, start, mid - 1, key);
        
        else    
            binarysearch(arr, mid + 1, end, key);
    }

    if(start > end)
    {
        std::cout << "Key not found!\n";
        return;
    }

}


int main()
{
    int n;
    std::cout << "Enter number of elements of array:   ";
    std::cin >> n;
    int arr[n];
    std::cout << "Enter elements:   ";

    for(int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    std::sort(arr, arr+n);

    std::cout << "The sorted array is:  ";
    
    for(int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";


    std::cout << "Enter key to be searched:   ";
    int key;
    std::cin >> key;

    binarysearch(arr, 0, n - 1, key);
}