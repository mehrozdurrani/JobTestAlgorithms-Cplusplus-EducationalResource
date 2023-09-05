#include <iostream>
#include <vector>

std::vector<int> FebonacciSeries(int value)
{
    int number = 0;
    std::vector<int> febonacciSeries;
    febonacciSeries.push_back(0);
    febonacciSeries.push_back(1);
    int index = 2;
    for (int i = 0; i < value - 2; i++)
    {
        febonacciSeries.push_back(febonacciSeries[index - 1] + febonacciSeries[index - 2]);
        index++;
    }
    return febonacciSeries;
}

int main()
{
    FebonacciSeries(8);
    FebonacciSeries(19);
    return 0;
}