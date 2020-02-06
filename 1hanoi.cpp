#include <iostream>


void hanoi(char src, char temp, char dest, int n)
{
    if(n != 1) hanoi(src, dest, temp, n-1);
    std::cout << "Move disc " << n << " from " << src << " to " << dest << std::endl;
    if (n!= 1) hanoi(temp, src, dest, n-1);
}


int main()
{
    int n;
    std::cout << "The three towers are A, B, and C\nEnter the number of discs initially on A:    ";
    std::cin >> n;
    char a = 'A', b = 'B', c = 'C';
    hanoi(a, b, c, n);
}



