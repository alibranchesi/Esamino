#include <iostream>
#include <cmath>

bool is_prime(int N)
{
    int i = 0;
    int c = 5;
    if (N < 2)
    {
        return false;
    }
    else if(N == 2 || N == 3)
    {
        return true;
    }
    else if(i == (N % 2) ||i == (N % 3))
    {
        return false;
    }
    while (c <= sqrt(N))
    {
        if (i == (N % c))
        {
            return false;
        }
        c += 2;
    }
    return true;   
}

int main()
{
    std::cout << is_prime(1);
    std::cout << is_prime(2);
    std::cout << is_prime(3);
    std::cout << is_prime(4);
    std::cout << is_prime(5);
    std::cout << is_prime(6);
}
