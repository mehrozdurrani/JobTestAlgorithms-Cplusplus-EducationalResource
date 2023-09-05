#include <iostream>

int Factorial(int number)
{
    int factorial;
    if (number <= 1)
        return 1;
    else
        factorial = number * Factorial(number - 1);
    return factorial;
}

int main()
{
    int fac = Factorial(5);
    std::cout << fac;
    return 0;
}