#include <iostream>

std::string ReverseString(std::string const &str)
{
    std::string reversedString = "";
    for (int i = str.length() - 1; i >= 0; i--)
    {
        reversedString.push_back(str[i]);
    }
    return reversedString;
}

int main()
{
    std::string str = "Hello World!";
    std::cout << ReverseString(str);
    return 0;
}