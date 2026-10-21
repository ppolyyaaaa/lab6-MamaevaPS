#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <windows.h> // Для настройки кодировки UTF-8

using namespace std;

int main() {
    // Включаем UTF-8 для корректного вывода русского текста в консоли
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // Исходный вектор с числами (как на слайде)
    vector<int> numbers = {1, 2, 3, 2, 4, 5, 1, 6, 3, 7};

    cout << "Исходный список: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << "\n\n";

    // ==========================================
    // Способ 1: Через std::map (подсчет количества)
    // ==========================================
    cout << "--- Способ 1 (через map) ---\n";
    map<int, int> counts;
    
    // Считаем, сколько раз встречается каждое число
    for (int num : numbers) {
        counts[num]++;
    }

    cout << "Дубликаты: ";
    // Проходим по map (он автоматически отсортирован по ключам)
    for (const auto& pair : counts) {
        // Если число встретилось больше 1 раза — это дубликат
        if (pair.second > 1) {
            cout << pair.first << " ";
        }
    }
    cout << "\n\n";

    // ==========================================
    // Способ 2: Через std::set (множества)
    // ==========================================
    cout << "--- Способ 2 (через set) ---\n";
    set<int> seen;       // Здесь храним числа, которые уже видели
    set<int> duplicates; // Здесь храним найденные дубликаты

    for (int num : numbers) {
        // Если число уже есть в seen, значит мы встретили его повторно
        if (seen.count(num)) {
            duplicates.insert(num);
        }
        // Добавляем число в "увиденные" (если оно там уже есть, set просто проигнорирует это)
        seen.insert(num);
    }

    cout << "Дубликаты: ";
    for (int num : duplicates) {
        cout << num << " ";
    }
    cout << "\n";

    return 0;
}