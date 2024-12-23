#include <iostream>
#include <string>

std::string invert(std::string str)
{
    for(int i = 0; i < str.size(); ++i)
    {
        if(str[i] == '0')
        {
            str[i] = '1';
        }
        else if(str[i] == '1')
        {
            str[i] = '0';
        }
    }
    std::cout << "inverted: " << str << '\n';
    return str;
}

std::string addOne(std::string str)
{
    for(int i = str.size(); i > -1; --i)
    {
        if(str[i] == '1')
        {
            str[i] = '0';
        }
        else if(str[i] == '0')
        {
            str[i] = '1';
            break;
        }
    }
    return str;
}

int main ()
{
    std::string digits;
    std::cin >> digits;
    std::cout << "Your input: " << digits << '\n';
    digits = invert(digits);
    digits = addOne(digits);
    std::cout << "Output    : " << digits << '\n';
    return 0;
}