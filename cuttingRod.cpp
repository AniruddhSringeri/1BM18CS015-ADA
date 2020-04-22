#include<limits.h>
#include<iostream>
  
int maximum(int a, int b){
    if(a > b) return a;
    else return b;
}
  

int cutRod(int price[], int n) 
{ 
    if (n <= 0) 
       return 0; 
    int max = INT_MIN; 

    for (int i = 0; i<n; i++) 
        max = maximum(max, price[i] + cutRod(price, n-i-1)); 
  
   return max; 
} 

int main() 
{ 
    int n;
    std::cout << "Enter the size of the rod:  ";
    std::cin >> n;
    int arr[n];
    std::cout << "Enter the prices of rod of length 1, 2, 3 ... "<<n<<std::endl;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    std::cout<<"Maximum Obtainable Value is "<<cutRod(arr, n)<<std::endl;  
    return 0; 
}
