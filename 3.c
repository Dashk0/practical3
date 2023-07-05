#include <stdio.h>

// Рекурсивна функція для підрахунку кількості чисел
int countNumbers(int r, int prevDigit, int prevPrevDigit) {
    if (r == 0) {
        return 1;  // Досягли кінця розрядів, повертаємо 1
    }

    int count = 0;
    for (int digit = 5; digit <= 9; digit += 4) {
        // Перевірка умови, що три однакові цифри не стоять поруч
        if (digit != prevDigit || digit != prevPrevDigit) {
            count += countNumbers(r - 1, digit, prevDigit);  // Рекурсивний виклик для наступного розряду
        }
    }

    return count;
}

int main() {
    int r;
    int count;

    // Зчитування вхідних даних
    printf("Введіть кількість розрядів (р): ");
    scanf("%d", &r);

    // Підрахунок кількості чисел
    count = countNumbers(r, -1, -1);

    // Виведення результату
    printf("Кількість чисел із %d розрядів: %d\n", r, count);

    return 0;
}