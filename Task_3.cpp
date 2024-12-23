#include <iostream>
#include <string>

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

std::string add_zeros(std::string str, long long max)
{
    long long length = str.length();
    for(long long i = length; i < max; ++i)
    {
        str = "0" + str;
    }
    return str;
}

int get_base()
{
    int base = 0;
    while(true)
    {
        std::cin >> base;
        if(base < 2 || base > 36)
        {
            std::cin.ignore(32767,'\n');
            std::cout << "Недопустимое значение" << '\n';
        }
        else 
        {
            break;
        }
    }
    return base;
}

long long max_length(std:: string a, std::string b)
{
    long long max = a.length();
    if(b.length() > max)
    {
        return b.size();
    }
    return max;
}

std::string sum(std::string a, std::string b, long long max_length, int base)
{
    std::string res;
    int ost = 0, val = 0;
    int A = 0, B = 0;
    for(long long i = 0; i < max_length; ++i)
    {
        if(isalpha(a[i]) != 0)
        {
            A = a[i] - 'A' + 10;
        }
        else
        {
            A = a[i] - '0';
        }
        if(isalpha(b[i]) != 0)
        {
            B = b[i] - 'A' + 10;
        }
        else
        {
            B = b[i] - '0';
        }
        val = ost + A + B;
        ost = 0;
        if(val >= base)
        {
            ++ost;
            val = val - base;
        }
        if(val > 9)
        {
            res += 'A' + val - 10;
        }
        else {
            res += (val + '0');
        }
        if(i == max_length - 1 && ost == 1)
        {
            res += "1";
            break;
        }
    }
    return res;
}

std::string substract(std::string a, std::string b, long long max_length, int base)
{
    std::string res;
    int ost = 0, val = 0;
    int A = 0, B = 0;
    for(long long i = 0; i < max_length; ++i)
    {
        A = a[i];
        if(isalpha(a[i]) != 0)
        {
            A = a[i] - 'A' + 10;
        }
        else
        {
            A = a[i] - '0';
        }
        if(isalpha(b[i]) != 0)
        {
            B = b[i] - 'A' + 10;
        }
        else
        {
            B = b[i] - '0';
        }
        val = ost + A + B;
        ost = 0;
        if(val >= base)
        {
            ++ost;
            val = val - base;
        }
        if(val > 9)
        {
            res += 'A' + val - 10;
        }
        else {
            res += (val + '0');
        }
        if(i == max_length - 1 && ost == 1)
        {
            res += "1";
            break;
        }
    }
    return res;
}

int oper(std::string sign)
{
    if(sign == "+")
    {
        return 1;
    }
    else if(sign == "-")
    {
        return 2;
    }
}

void task3()
{
    int base;
    long long max;
    base = get_base();
    std::string str;
    std::cin >> str;
    std::string str2;
    std::cin >> str2;
    max = max_length(str, str2);
    str = add_zeros(str, max);
    str2 = add_zeros(str2, max);
    str = reverse(str);
    str2 = reverse(str2);
    str = sum(str, str2, max, base);
    str = reverse(str);
    std::cout << str << '\n';
}

int main() {
    task3();
    return 0;
}