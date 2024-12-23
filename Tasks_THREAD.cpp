#include <iostream>
#include <cmath>
#include <string>

//task1
int task1() //O(n)
{
    std::cout << "Введите число. Программа переведёт его в доп. код: " << '\n';
    std::string digits;
    std::cin >> digits;
    std::cout << "Your input: " << digits << '\n';
    digits = invert(digits);
    digits = addOne(digits);
    std::cout << "Output    : " << digits << '\n';
    return 0;
}

//end task1

//task2 
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

std::string sum_bi(std::string a, std::string b, long long max_length)
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

std::string to_sum(std::string digits1, std::string digits2)
{
    digits1 = reverse(digits1);
    digits2 = reverse(digits2);
    digits1 = sum_bi(digits1, digits2, digits1.size());
    digits1 = reverse(digits1);
    return digits1;
}

std::string additional_code(std::string digits)
{
    digits = invert(digits);
    digits = addOne(digits);
    return digits;
}

int task2() //O(n)
{
    std::cout << "Введите последовательно два двоичных числа (в том чичсле в естественной форме). Программа произведёт сложение в доп. коде." << '\n';
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

//end task2

//task3
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
    std::cout << "Введите основание системы от 2 до 36." << '\n';
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
        val = ost + A - B;
        ost = 0;
        if(val < 0)
        {
            --ost;
            val = val + base;
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

void task3() //O(n)
{
    int base;
    long long max;
    base = get_base();
    std::cout << "Введите первое число" << '\n';
    std::string str;
    std::cin >> str;
    std::string str, sign;
    std::cout << "Введите + или -" << '\n';
    std:: cin >> sign;
    std::cout << "Введите второе число" << '\n';
    std::string str2;
    std::cin >> str2;
    max = max_length(str, str2);
    str = add_zeros(str, max);
    str2 = add_zeros(str2, max);
    str = reverse(str);
    str2 = reverse(str2);
    if(sign == "+")
    {
        str = sum(str, str2, max, base);
    }
    else
    {
        str = substract(str, str2, max, base);
    }
    str = reverse(str);
    std::cout << str << '\n';
}

//end task3

//task4
bool divisible(std::string number, long long div) //O(n)
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
void task4(std::string number, int div)
{
    if(divisible(number, div) == 1) 
    {
        std::cout<< number<<" делится на "<< div << '\n';
    }
    else 
    {
        std::cout<< number<<" не делится на "<< div << '\n';
    }
}

void task4()
{
    std::cout << "Введите число, делимость которого хотите на 3, 47, 197 хотите проверить" << '\n';
    std::string number;
    std::cin >> number;
    task4(number, 3);
    task4(number, 47);
    task4(number, 197);
}
//end task 4

//task5
struct Barrel {
  int slaves[5] = {0};
  int isPoisoned = 0;
};

int drink(Barrel barrels[], int slaves[]) {
  int slavesCount = 0;
  for (int i = 0; i < 240; i++) {
    if (barrels[i].isPoisoned) {
      for (int j = 0; j < 5; j++) {
        if (barrels[i].slaves[j]) {
          slaves[j] = 1;
        }
      }
    }
  }
  for (int i = 0; i < 5; i++) {
    if (slaves[i]) {
      std::cout << "Раб " << i+1 << " мёртв" << '\n';
    } else
      slavesCount++;
  }
  return slavesCount;
}

int task5() { //O(n^2)
  std::cout << "Задание 5. Введите номер отравленной бочки. Программа составит таблицу истинности по следующему принципу:" << '\n';
  std::cout << "Рабы будут пить из бочек в уникальных комбинациях так, что количество подозрительных бочек" << '\n';
  std::cout << "всегда возможно будет однозначно проверить. 1 - раб испил из бочки, 0 - не испил" << '\n';
  Barrel barrels[240];
  int slaves[5] = {0};

  int poisoned = 0;
  std::cin >> poisoned;
  barrels[poisoned].isPoisoned = 1;
  int k = 0;
  int t = 0;

  for (int i = 0; i < 240; i++) {
    if (i < 32) {
      continue;

    } else if (i < 112) {

      t = i % 10;
      if (t == 2) {
        k = 1;
      } else if (t == 5) {
        k += 2;
      } else if (t == 3 || t == 7) {
        k++;
      } else if (t == 8) {
        k += 4;
      } else if (t == 0) {
        k += 11;
      } else if (t == 1) {
        k += 3;
      }
      for (int j = 0; j < 5; j++) {
        barrels[i].slaves[j] = ((t + k) >> j) & 1;
      }
    } else if (i < 152) {
      t = i % 10;
      if (t == 2) {
        k = 5;
      } else if (t == 3) {
        k += 3;
      } else if (t == 4 || t == 7 || t == 1) {
        k++;
      } else if (t == 6) {
        k += 4;
      } else if (t == 9) {
        k += 2;
      } else if (t == 0) {
        k += 10;
      }
      for (int j = 0; j < 5; j++) {
        barrels[i].slaves[j] = ((t + k) >> j) & 1;
      }
    } else if (i < 232) {
      t = i % 5;
      if (t == 2) {
        k = 0;
      } else if (t == 3) {
        k++;
      } else if (t == 4) {
        k += 3;
      } else if (t == 0) {
        k += 12;
      } else if (t == 1) {
        k += 16;
      }
      for (int j = 0; j < 5; j++) {
        barrels[i].slaves[j] = ((t + k) >> j) & 1;
      }
    } else {
      t = i % 5;
      if (t == 2) {
        k = 13;
      } else if (t == 3) {
        k += 7;
      } else if (t == 4) {
        k += 3;
      } else if (t == 0) {
        k += 6;
      }
      for (int j = 0; j < 5; j++) {
        barrels[i].slaves[j] = ((t + k) >> j) & 1;
      }
    }
  }

  for (int i = 0; i < 240; i++) {
    std::cout << i << ": { ";
    for (int j = 0; j < 5; j++) {
        std::cout << barrels[i].slaves[j] << " ";
    }
    std::cout << "}\n";
  }

  int slavesCount = drink(barrels, slaves);
  std::cout << "Рабы (1 - мёртвые, 0 - живые): { ";
  for (int i = 0; i < 5; i++) {
  std::cout << slaves[i] << " ";
  }
  std::cout << "}\n";
  std::cout << "Так как умерли только эти рабы, значит: \n";
  int count = 0;
  k = 0;
  for (int i = 0; i < 240; i++) {
    if (barrels[i].slaves[0] == slaves[0] && barrels[i].slaves[1] == slaves[1] && barrels[i].slaves[2] == slaves[2] && barrels[i].slaves[3] == slaves[3] && barrels[i].slaves[4] == slaves[4]) {
      k = i;
      count++;
      std::cout << "Бочка " << i << " вероятно отравлена" << '\n';
    }
  }
  if (count == 1) {
    std::cout << "Бочка " << k << " отравлена" << '\n';
    return 0;
  }

  std::cout << "надо проверить " << count << " бочки(-ек). цифра 1 в новой таблице означает, что из бочки пил раб."<< '\n';

  for (int i = 0; i < 240; i++) {
    for (int j = 0; j < 5; j++) {
      barrels[i].slaves[j] = -1;
    }
  }
t = 0;
  if (slavesCount == 5) {
    for (int i = 0; i < 32; i++) {
      std::cout << i << ": ";
      for (int j = 0; j < 5; j++) {
        barrels[i].slaves[j] = (i >> j) & 1;
        std::cout << barrels[i].slaves[j] << " ";
      }
      std::cout << '\n';
    }
  } else if (slavesCount == 4) {
    slaves[0] = slaves[1] = slaves[2] = slaves[3] = 0;
    slaves[4] = 1;
    for (int i = k; i >= 152; i -= 5) {
      std::cout << i << ": ";
      for (int j = 0; j < 4; j++) {
        barrels[i].slaves[j] = (t >> j) & 1;
        std::cout << barrels[i].slaves[j] << " ";
      }
      barrels[i].slaves[4] = 1;
      std::cout << '\n';
      t++;
    }
    std::cout << k << '\n';
  } else if (slavesCount == 3) {
    slaves[0] = slaves[1] = slaves[2] = 0;
    slaves[3] = slaves[4] = 1;
    for (int i = k; i >= 32; i -= 10) {
      std::cout << i << ": ";
      for (int j = 0; j < 3; j++) {
        barrels[i].slaves[j] = (t >> j) & 1;
        std::cout << barrels[i].slaves[j] << " ";
      }
      barrels[i].slaves[3] = barrels[i].slaves[4] = 1;
      std::cout << '\n';
      t++;
    }
    std::cout << k << '\n';
  } else if (slavesCount == 2) {
    slaves[0] = slaves[1] = 0;
    slaves[2] = slaves[3] = slaves[4] = 1;
    for (int i = k; i >= 112; i -= 10) {
      std::cout << i << ": ";
      for (int j = 0; j < 2; j++) {
        barrels[i].slaves[j] = (t >> j) & 1;
        std::cout << barrels[i].slaves[j] << " ";
      }
      barrels[i].slaves[2] = barrels[i].slaves[3] = barrels[i].slaves[4] = 1;
      std::cout << '\n';
      t++;
    }
    std::cout << k << '\n';
  } else if (slavesCount == 1) {
    slaves[0] = 0;
    slaves[1] = slaves[2] = slaves[3] = slaves[4] = 1;
    for (int i = k; i >= 232; i -= 5) {
      std::cout << i << ": ";
      barrels[i].slaves[0] = 0;
      for (int j = 0; j < 1; j++) {
        barrels[i].slaves[j] = (t >> j) & 1;
        std::cout << barrels[i].slaves[j] << " ";
      }
      barrels[i].slaves[1] = barrels[i].slaves[2] = barrels[i].slaves[3] = barrels[i].slaves[4] = 1;
      std::cout << '\n';
      t++;
    }
    std::cout << k << '\n';
  }

  drink(barrels, slaves);

  for (int i = 0; i < 240; i++) {
    if (barrels[i].slaves[0] == slaves[0] &&
        barrels[i].slaves[1] == slaves[1] &&
        barrels[i].slaves[2] == slaves[2] &&
        barrels[i].slaves[3] == slaves[3] &&
        barrels[i].slaves[4] == slaves[4]) {
      std::cout << "Бочка " << i << " отравлена" << '\n';
    }
  }

  return 0;
}

//end task5

int main()
{
    int num;
    std::cout << "Выполнил Мурашко Андрей Николаевич, 453001 группа." << '\n';
    std::cout << "Введите номер задания от 1 до 5: " << '\n';
    std::cin >> num;
    switch (num)
    {
    case 1:
        task1();
        break;
    case 2:
        task2();
        break;
    case 3:
        task3();
        break;
    case 4:
        task4();
        break;
    case 5:
        task5();
        break;
    }
    return 0;
}