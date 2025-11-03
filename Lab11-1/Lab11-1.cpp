#include <iostream>
#include <iomanip> // для форматованого виведення
#include <cmath>   // для pow()
using namespace std;

// Константи для розміру масиву
const int ROWS = 3;
const int COLS = 4;

// 🔹 Функція введення елементів двовимірного масиву
void inputMatrix(int a[ROWS][COLS]) {
    cout << "Введіть елементи матриці " << ROWS << "x" << COLS << ":" << endl;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
    }
}

// 🔹 Функція для виведення матриці
void printMatrix(int a[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << setw(5) << a[i][j];
        }
        cout << endl;
    }
}

// 🔹 Функція для обчислення суми квадратів усіх елементів
int sumOfSquares(int a[ROWS][COLS]) {
    int sum = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            sum += a[i][j] * a[i][j];
        }
    }
    return sum;
}

// 🔹 Функція сортування парних стовпців за спаданням
void sortEvenColumnsDescending(int a[ROWS][COLS]) {
    // j = 1 означає другий стовпець, j = 3 — четвертий (нумерація з 0)
    for (int j = 1; j < COLS; j += 2) {
        for (int i = 0; i < ROWS - 1; i++) {
            for (int k = i + 1; k < ROWS; k++) {
                if (a[i][j] < a[k][j]) {
                    int temp = a[i][j];
                    a[i][j] = a[k][j];
                    a[k][j] = temp;
                }
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "Ukrainian");

    int matrix1[ROWS][COLS];
    int matrix2[ROWS][COLS];

    cout << "=== Введення першої матриці ===" << endl;
    inputMatrix(matrix1);
    cout << "\n=== Введення другої матриці ===" << endl;
    inputMatrix(matrix2);

    cout << "\nПерша матриця:" << endl;
    printMatrix(matrix1);
    cout << "\nДруга матриця:" << endl;
    printMatrix(matrix2);

    int sum1 = sumOfSquares(matrix1);
    int sum2 = sumOfSquares(matrix2);

    cout << "\nСума квадратів елементів першої матриці: " << sum1 << endl;
    cout << "Сума квадратів елементів другої матриці: " << sum2 << endl;

    sortEvenColumnsDescending(matrix1);
    sortEvenColumnsDescending(matrix2);

    cout << "\nПерша матриця після сортування парних стовпців за спаданням:" << endl;
    printMatrix(matrix1);
    cout << "\nДруга матриця після сортування парних стовпців за спаданням:" << endl;
    printMatrix(matrix2);

    return 0;
}