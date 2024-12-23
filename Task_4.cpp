#include <iostream>
#include <string>

bool divisible(std::string number, long long div)
{
    long long ost = 0, a, b;
    long long current_digit, buffer;
    for(long long i = 0; number[i] != '\0'; ++i)
    {
        current_digit = number[i] + (~48 + 1);
        ost = (ost << 1) + (ost << 3) + current_digit;

        while(ost >= div) // O(log(ost / div))
        {
            buffer = div;
            while(2*buffer <= ost) //O(log(ost / buf)
            {
                buffer = buffer << 1;
            }
            ost+=(~buffer+1);
        }
    }
    return ost == 0;
}

void task4()
{
    std::cout << "Введите число, делимость которого хотите, затем простое число, делимость на которое будем проверять" << '\n';
    long long div;
    std::string number;
    std::cin >> number >> div;
    if(divisible(number, div) == 1) 
    {
        std::cout<< number<<" делится на "<< div << '\n';
    }
    else 
    {
        std::cout<< number<<" не делится на "<< div << '\n';
    }
}

int main()
{
    task4();
    return 0;
}