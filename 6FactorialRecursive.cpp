#include <iostream>

int factorial(int n)
{
    if(n == 0)
        return 1;
    else
        return n * factorial(n-1);
}

int main()
{
    std::cout << "FACTORIAL PROGRAM\nEnter n: ";
    int n;
    std::cin >> n;

    std::cout << "Factorial of " << n << " is " << factorial(n) << "\n";
    return 1;
}