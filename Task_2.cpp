#include <iostream>
#include <string>
#include <cmath>

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
///
std::string convertToBinary(long long dec)
{
    std::string binar;
    while (dec != 0)
    {
        if(dec%2 == 0)
        {
            binar = "0" + binar;
        }
        else if(dec%2 == 1)
        {
            binar = "1" + binar;
        }
        dec = dec/2;
    }
    return binar;
}

long long convertToDec(std::string bin)
{
    int size = bin.size();
    long long dec = 0;
    for( int i = 0; i < size; ++i)
    {
        if(bin[i] == '1')
        {
            dec += pow(2, size - i - 1);
        }
    }
    return dec;
}
///
void sizeEquality(std::string &str1, std::string &str2)
{
    int max_size = 0;
    int size1 = str1.size();
    int size2 = str2.size();
    max_size = str1.size();
    if(size1 <= size2)
    {
        max_size = size2;
        for (int i = 0; i < size2 - size1; ++i)
        {
            str1 = "0" + str1;
        }
    }
    else
    {
        for (int i = 0; i < size1 - size2; ++i)
        {
            str2 = "0" + str2;
        }
    }
}

std::string reverse(std::string str)
{
    std::string new_str;
    long long length = str.length();
    for(long long i = length - 1; i > -1; --i)
    {
        new_str += str[i];
    }
    return new_str;
}

std::string sum(std::string a, std::string b, long long max_length)
{
    int base = 2;
    std::string res;
    int ost = 0, val = 0;
    int A = 0, B = 0;
    for(long long i = 0; i < max_length; ++i)
    {
        A = a[i] - '0';
        B = b[i] - '0';
        val = ost + A + B;
        ost = 0;
        if(val >= base)
        {
            ++ost;
            val = val - base;
        }
        else {
            res += (val + '0');
        }
        /*if(i == max_length - 1 && ost == 1)
        {
            res += "1";
            break;
        }*/
    }
    return res;
}

/*std::string convertToDirect(std::string nat_code)
{

}*/

std::string to_sum(std::string digits1, std::string digits2)
{
    digits1 = reverse(digits1);
    digits2 = reverse(digits2);
    digits1 = sum(digits1, digits2, digits1.size());
    digits1 = reverse(digits1);
    return digits1;
}

std::string additional_code(std::string digits)
{
    digits = invert(digits);
    digits = addOne(digits);
    return digits;
}

int main ()
{
    std::string str1, str2;
    std::cin >> str1 >> str2;
    std::cout << str1 << '\n';
    std::cout << str2 << '\n';
    if(str1[0] == '-')
    {
        str1.erase(0, 1); 
        str1 = additional_code(str1);   
    }
    if(str2[0] == '-')
    {
        str2.erase(0, 1); 
        str2 = additional_code(str2);   
    }
    sizeEquality(str1, str2);
    std::cout << str1 << '\n';
    std::cout << str2 << '\n';
    str1 = to_sum(str1, str2);
    std::cout << "Output: " << str1 << '\n';
    return 0;
}