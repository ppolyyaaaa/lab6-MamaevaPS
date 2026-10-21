#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>
#include <windows.h> // Для настройки кодировки UTF-8

using namespace std;

int main() {
    // Включаем UTF-8 для корректного вывода кириллицы в Windows
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // Исходные списки
    vector<int> list1 = {1, 2, 3, 4, 5};
    vector<int> list2 = {4, 5, 6, 7, 8};

    // Переводим векторы в множества (set), чтобы убрать дубликаты 
    // и получить доступ к математическим операциям над множествами
    set<int> set1(list1.begin(), list1.end());
    set<int> set2(list2.begin(), list2.end());

    // 1. Объединение (все элементы без дубликатов)
    set<int> unionSet;
    // std::set_union берет два отсортированных диапазона и кладет результат в unionSet
    set_union(set1.begin(), set1.end(), 
              set2.begin(), set2.end(), 
              inserter(unionSet, unionSet.begin()));

    // 2. Пересечение (общие элементы)
    set<int> intersection;
    set_intersection(set1.begin(), set1.end(), 
                     set2.begin(), set2.end(), 
                     inserter(intersection, intersection.begin()));

    // 3. Разность (элементы первого множества, которых нет во втором)
    set<int> difference;
    set_difference(set1.begin(), set1.end(), 
                   set2.begin(), set2.end(), 
                   inserter(difference, difference.begin()));

    // --- Вывод результатов ---
    // Так как мы использовали std::set, элементы автоматически отсортированы по возрастанию

    cout << "Объединение: ";
    for (int x : unionSet) cout << x << " ";
    cout << "\n";

    cout << "Пересечение: ";
    for (int x : intersection) cout << x << " ";
    cout << "\n";

    cout << "Разность: ";
    for (int x : difference) cout << x << " ";
    cout << "\n";

    return 0;
}