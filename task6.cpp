#include <iostream>
#include <vector>
#include <algorithm> // Для std::sort и std::unique
#include <windows.h> // Для SetConsoleOutputCP (только для Windows)

int main() {
    // Включаем поддержку UTF-8 в консоли Windows
    #ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8);
    #endif

    std::vector<int> numbers = {10, 5, 20, 8, 20, 15};

    // 1. Сортируем по убыванию
    std::sort(numbers.begin(), numbers.end(), std::greater<int>());

    // (Удаляем дубликаты, чтобы 20 и 20 не считались за первое и второе место)
    numbers.erase(std::unique(numbers.begin(), numbers.end()), numbers.end());

    // 3. Выводим второй элемент (индекс 1)
    if (numbers.size() >= 2) {
        std::cout << "Второй по величине элемент: " << numbers[1] << "\n";
    } else {
        std::cout << "Недостаточно уникальных элементов.\n";
    }

    return 0;
}