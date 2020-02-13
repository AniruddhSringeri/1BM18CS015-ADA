#include <iostream>

int fibonacci(int n)
{
    if(n == 0)
        return 0;
    else if(n == 1)
        return 1;
    else    
        return fibonacci(n-1) + fibonacci(n-2);
}

int main()
{
    std::cout << "Program to find nth fibonacci number\nEnter n:  ";
    int n;
    std::cin >> n;

    std::cout << "Number " << n << " in Fibonacci series is " << fibonacci(n) << "\n";
    return 1;
}