#include<iostream>
#include<ctime>
#include<algorithm>


int main()
{
    clock_t t;
    int *a, n, temp;
    std::cout << "Enter the number of elements\n";
    std::cin >> n;
    a = new int[n];
    
    for(int i = 0; i < n; i++)
    {
        a[i] = rand() / 10;
    }


    t = clock();
    for(int i = 1; i < n; i++)
    {
        int j = i - 1;
        temp = a[i];
        while(j >= 0 && a[j] > temp)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = temp;
    }
    t = clock()- t;


    std::cout << "The sorted array is\n";
    for(int i = 0; i < n; i++)
    {
        std::cout << a[i] << " ";
    }

    std::cout << "\nSorting time is: " << t << "\n";
    return 0;
}
