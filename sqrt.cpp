#include <iostream>
#include <string>

int isqrt(int n)
{
    int i = 1;
    while (i * i < n)
    {
        ++i;
    }
    if (i * i > n)
    {
        --i;
    }
    return i;
}

int main()
{
    int n;
    std::cin >> n;
    int j = isqrt(n);
    std::cout << j;
}