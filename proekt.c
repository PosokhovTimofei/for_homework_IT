#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Инициализация генератора случайных чисел с использованием текущего времени в качестве зерна
    srand(time(NULL));

    // Генерация и вывод 10 случайных чисел в диапазоне от 0 до RAND_MAX
    printf("Random numbers:\n");
    for (int i = 0; i < 10; ++i) {
        printf("%d\n", rand());
    }

    return 0;
}
