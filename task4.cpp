#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <windows.h> // Для настройки кодировки консоли

using namespace std;

int main() {
    // Включаем UTF-8 для корректного вывода кириллицы в Windows
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // Создаем тип кортежа: (Имя, Возраст, Средний балл)
    // string - имя, int - возраст, double - балл
    using Student = tuple<string, int, double>;

    // Исходный список студентов
    vector<Student> students = {
        {"Иван", 25, 4.5},
        {"Мария", 22, 4.8},
        {"Петр", 30, 4.2},
        {"Анна", 20, 4.9}
    };

    // 1. Самый старший (максимальный возраст)

    // Ищем итератор на элемент с максимальным возрастом (индекс 1 в кортеже)
    auto oldest_it = max_element(students.begin(), students.end(), 
        [](const Student& a, const Student& b) {
            return get<1>(a) < get<1>(b);
        });

    // Выводим имя и возраст самого старшего
    cout << "Самый старший: " << get<0>(*oldest_it) 
         << ", " << get<1>(*oldest_it) << " лет\n";

    // 2. С самым высоким баллом
    
    // Ищем элемент с максимальным баллом (индекс 2 в кортеже)
    auto best_it = max_element(students.begin(), students.end(), 
        [](const Student& a, const Student& b) {
            return get<2>(a) < get<2>(b);
        });

    // Выводим имя и балл лучшего студента
    cout << "Лучший студент: " << get<0>(*best_it) 
         << ", балл " << get<2>(*best_it) << "\n";

    // 3. Средний возраст

    // Суммируем возрасты
    int total_age = 0;
    for (const auto& student : students) {
        total_age += get<1>(student);
    }
    // Считаем среднее
    double avg_age = static_cast<double>(total_age) / students.size();
    
    // Выводим с одним знаком после запятой
    cout << fixed << setprecision(1);
    cout << "Средний возраст: " << avg_age << "\n";
    cout << defaultfloat; // Возвращаем обычный формат вывода для следующих строк

    // 4. Сортировка по баллу (убывание) - бонус из Питона
    cout << "\n--- Сортировка по баллу ---\n";
    
    // Сортируем вектор с помощью лямбда-функции (по убыванию балла)
    sort(students.begin(), students.end(), 
        [](const Student& a, const Student& b) {
            return get<2>(a) > get<2>(b); // Знак '>' для сортировки по убыванию
        });

    // Выводим отсортированный список
    for (const auto& student : students) {
        cout << get<0>(student) << ": " << get<2>(student) << "\n";
    }

    return 0;
}