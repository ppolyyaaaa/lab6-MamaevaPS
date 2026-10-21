#include <iostream>
#include <vector>
#include <windows.h> // Для настройки кодировки консоли

using namespace std;

int main() {
    // Включаем UTF-8 для корректного вывода кириллицы в Windows
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // Исходная матрица 3x3
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Определяем размеры исходной матрицы
    int rows = matrix.size();
    int cols = matrix[0].size();

    // Создаем новую матрицу для результата. 
    // Было rows x cols, стало cols x rows.
    // Изначально она заполнена нулями.
    vector<vector<int>> transposed(cols, vector<int>(rows));

    // Заполняем транспонированную матрицу
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            // Меняем индексы местами: элемент [i][j] становится [j][i]
            transposed[j][i] = matrix[i][j];
        }
    }

    // Вывод результатов

    cout << "Исходная матрица:\n";
    for (const auto& row : matrix) {
        for (int x : row) {
            cout << x << " ";
        }
        cout << "\n";
    }

    cout << "\nТранспонированная матрица:\n";
    for (const auto& row : transposed) {
        for (int x : row) {
            cout << x << " ";
        }
        cout << "\n";
    }

    return 0;
}