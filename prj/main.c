#include <stdio.h>
#include <math.h> // Для использования функции sqrt() и pow()

// Функция для сложения
double add(double a, double b) {
    return a + b;
}

// Функция для вычитания
double subtract(double a, double b) {
    return a - b;
}

// Функция для умножения
double multiply(double a, double b) {
    return a * b;
}

// Функция для деления
double divide(double a, double b) {
    if (b != 0) {
        return a / b;
    } else {
        printf("Ошибка: деление на ноль!\n");
        return 0;
    }
}

// Функция для возведения в степень
double power(double a, double b) {
    return pow(a, b);
}

// Функция для вычисления квадратного корня
double sqrt_calc(double a) {
    if (a < 0) {
        printf("Ошибка: нельзя извлечь квадратный корень из отрицательного числа!\n");
        return -1; // Возвращаем ошибочное значение
    }
    return sqrt(a);
}

int main() {
    double num1, num2, result;
    int choice;

    // Меню калькулятора
    printf("Калькулятор:\n");
    printf("1. Сложение\n");
    printf("2. Вычитание\n");
    printf("3. Умножение\n");
    printf("4. Деление\n");
    printf("5. Возведение в степень\n");
    printf("6. Квадратный корень\n");
    printf("Выберите операцию (1-6): ");
    scanf("%d", &choice);

    // Ввод чисел
    if (choice != 6) {
        printf("Введите первое число: ");
        scanf("%lf", &num1);
        printf("Введите второе число: ");
        scanf("%lf", &num2);
    } else {
        printf("Введите число для вычисления квадратного корня: ");
        scanf("%lf", &num1);
    }

    // Выполнение выбранной операции
    switch (choice) {
        case 1:
            result = add(num1, num2);
            printf("Результат: %.2lf\n", result);
            break;
        case 2:
            result = subtract(num1, num2);
            printf("Результат: %.2lf\n", result);
            break;
        case 3:
            result = multiply(num1, num2);
            printf("Результат: %.2lf\n", result);
            break;
        case 4:
            result = divide(num1, num2);
            if (num2 != 0) {
                printf("Результат: %.2lf\n", result);
            }
            break;
        case 5:
            result = power(num1, num2);
            printf("Результат: %.2lf\n", result);
            break;
        case 6:
            result = sqrt_calc(num1);
            if (result != -1) {
                printf("Результат: %.2lf\n", result);
            }
            break;
        default:
            printf("Неверный выбор операции.\n");
            break;
    }

    return 0;
}
