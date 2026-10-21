#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <windows.h> // Необходимо для настройки кодировки консоли Windows

using namespace std;

int main() {
    // ПРИНУДИТЕЛЬНОЕ ВКЛЮЧЕНИЕ UTF-8 В КОНСОЛИ (убирает кракозябры)
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int n;
    cout << "Введите N: ";
    cin >> n;

    // Генератор случайных чисел
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 100);

    vector<int> numbers(n);
    for (int &x : numbers) {
        x = dist(gen);
    }

    cout << "Исходный список: ";
    for (int x : numbers) cout << x << " ";
    cout << "\n";

    // Проверка на пустой ввод
    if (n > 0) {
        // 1. Сумма
        int sum = accumulate(numbers.begin(), numbers.end(), 0);

        // 2. Среднее арифметическое
        double average = static_cast<double>(sum) / numbers.size();

        // 3. Минимум и максимум (ИСПРАВЛЕНА 39 СТРОКА)
        int minimum = *min_element(numbers.begin(), numbers.end());
        int maximum = *max_element(numbers.begin(), numbers.end());

        // Вывод результатов
        cout << "Сумма: " << sum << endl;
        cout << fixed << setprecision(2); // 2 знака после запятой
        cout << "Среднее: " << average << endl;
        cout << "Минимум: " << minimum << endl;
        cout << "Максимум: " << maximum << endl;

        // 4. Сортировка
        sort(numbers.begin(), numbers.end());
        cout << "Отсортированный: ";
        for (int x : numbers) cout << x << " ";
        cout << "\n";

        // 5. Удаление дубликатов
        auto last = unique(numbers.begin(), numbers.end());
        numbers.erase(last, numbers.end());

        cout << "Без дубликатов: ";
        for (int x : numbers) cout << x << " ";
        cout << "\n";
    } else {
        cout << "Список пуст.\n";
    }

    return 0;
}
