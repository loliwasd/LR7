#include <cmath>
#include <iostream>

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

int task5() {
  std::cout << "Задание 5. Введите номер отравленной бочки. Программа составит таблицу истинности по следующему принципу:" << '\n';
  std::cout << "Рабы будут пить из бочек в уникальных комбинациях так, что количество подозрительных бочек" << '\n';
  std::cout << "всегда возможно будет однозначно проверить. 1 - раб испил из бочки, 0 - не испил" << '\n';
  Barrel barrels[240];
  int slaves[5] = {0};

  int poisoned = 0;
  scanf("%d", &poisoned);
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