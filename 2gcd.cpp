#include <iostream>

int gcd(int m, int n)
{
    int rem = 0;
    do
    {
        rem = m % n;
        if(rem == 0) break;
        m = n;
        n = rem;
    }
    while(rem != 0);

    return n;
}

int main()
{
    int m, n;
    std::cout << "Enter the larger number:   ";
    std::cin >> m;
    std::cout << "Enter smaller number:   ";
    std::cin >> n;

    if(n > m)
    {
        std::cout << "Invalid input!\n";
        exit(0);
    }

    std::cout << "gcd is " << gcd(m,n) << "\n";

}