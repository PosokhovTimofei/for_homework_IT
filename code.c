#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Функция для генерации случайного выбора компьютера (камень, ножницы, бумага)
int computer_choice() {
    return rand() % 3;  // Генерируем случайное число от 0 до 2
}

// Функция для определения победителя раунда
int determine_winner(int player_choice, int computer_choice) {
    if ((player_choice == 0 && computer_choice == 1) || 
        (player_choice == 1 && computer_choice == 2) ||
        (player_choice == 2 && computer_choice == 0)) {
        return 1;  // Игрок победил
    } else if ((player_choice == 0 && computer_choice == 2) || 
               (player_choice == 1 && computer_choice == 0) ||
               (player_choice == 2 && computer_choice == 1)) {
        return -1; // Компьютер победил
    } else {
        return 0;  // Ничья
    }
}

int main() {
    const char* choices[] = {"Камень", "Ножницы", "Бумага"};
    char play_again = 'y';
    srand(time(NULL)); // Инициализируем генератор случайных чисел

    while (play_again == 'y' || play_again == 'Y') {
        printf("Выберите ваш ход:\n");
        printf("0 - Камень\n");
        printf("1 - Ножницы\n");
        printf("2 - Бумага\n");

        int player_choice;
        scanf("%d", &player_choice);

        if (player_choice < 0 || player_choice > 2) {
            printf("Некорректный ввод. Пожалуйста, выберите 0, 1 или 2.\n");
            continue;
        }

        int comp_choice = computer_choice();
        printf("Вы выбрали: %s\n", choices[player_choice]);
        printf("Компьютер выбрал: %s\n", choices[comp_choice]);

        int winner = determine_winner(player_choice, comp_choice);
        if (winner == 1) {
            printf("Вы победили!\n");
        } else if (winner == -1) {
            printf("Компьютер победил.\n");
        } else {
            printf("Ничья!\n");
        }

        printf("Хотите сыграть еще раз? (y/n): ");
        scanf(" %c", &play_again);
    }

    printf("Спасибо за игру!\n");
    return 0;
}

