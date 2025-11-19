#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int game(char you, char computer){
    //Если и пользователь, и компьютер выбрали одно и то же
    if(you == computer){
        return -1;
    }
    //если пользователь выбрал камень , а компьютер выбрал бумагу
    if(you == 's' && computer == 'p'){
        return 0;
    }else if (you == 'p' && computer == 's'){
        return 1;
    }
    //если пользователь выбрал камень , а компьютер выбрал ножницы
    if(you == 's' && computer == 'z'){
        return 1;
    }else if(you == 'z' && computer == 's'){
        return 0;
    }
    //если пользователь выбрал бумагу, а компьютер выбрал ножницы
    if(you == 'p' && computer == 'z'){
        return 0;
    }else if(you == 'z' && computer == 'p'){
        return 1;
    }
}

int main(){
    //сохраняем случайное число
    int n;
    char you, computer, result;
    //выбирает случайное число каждый раз
    srand(time(NULL));
    //сделаем случайное число меньше 100, разделив его на 100
    n = rand() % 100;
    //Используя простую вероятность, 100 примерно делиться между камнем, бумагой и ножницами
    if(n < 33){
        computer = 's';
    }else if(n > 33 && n < 66){
        computer = 'p';
    }else{
        computer = 'z';
    }
    printf("\n\n\n\n\t\t\t\t Нажмите s для Камень, p для Бумаги и z для Ножницы\n\t\t\t\t\t\t\t");
    scanf("%c", &you);
    //вызов функции для запуска игры
    result = game(you, computer);

    if(result == -1){
        printf("\n\n\t\t\t\t Ничья!\n");
    }else if(result == 1){
        printf("\n\n\t\t\t\t Ух ты! Ты выиграл!\n");
    }else{
        printf("\n\n\t\t\t\t О, ты проиграл!\n");
    }
    printf("\t\t\t\tТы выбрал : %c, а компьютер выбрал : %c\n", you, computer);
    return 0;
}