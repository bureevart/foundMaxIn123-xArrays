/*
Написать перегруженные функции и проте-
стировать их в основной программе:
■ Нахождения максимального значения в одномерном
массиве; Нахождения максимального значения в двумерном
массиве;
■ Нахождения максимального значения в трёхмерном
массиве;
*/

/*
Input:
13 71 83
16 63 39 27 56 71 48 16 82 31 86 29
13 7 19 5 93 55 30 12 100 36 88 3 25 18 68 98 1 91 2 29 41 79 12 54 9 64 56 58 21 51
 67 14 62 66 96 25 4 82 5 1 88 38 79 5 48 56 19 17 70 29 70 35 71 23 71 88 29 67 51 50
Output:
83
86
100
*/

#include <iostream>

using namespace std;

/**
 * Поиск максимума в одномерном массиве
 *
 * @param arr одномерный массив
 * @param size размер 1 (длина)
 */
int foundMaxInArray (int* arr, int size) {
    int max = *(arr + 0);
    for (int i = 0; i < size; ++i) {
        if (*(arr + i) > max) {
            max = *(arr + i);
        }
    }
    
    return max;
}

/**
 * Поиск максимума в двумерном массиве
 *
 * @param arr двумерный массив
 * @param size1 размер 1 (длина)
 * @param size2 размер 2 (высота)
 */
int foundMaxInArray (int** arr, int size1, int size2) {
    int max = *(*(arr + 0) + 0);
    for (int i = 0; i < size1; ++i) {
        for (int j = 0; j < size2; ++j) {
            if (*(*(arr + i) + j) > max) {
                max = *(*(arr + i) + j);
            }
        }
    }
    
    return max;
}

/**
 * Поиск максимума в трехмерном массиве
 *
 * @param arr трехмерный массив
 * @param size1 размер 1 (длина)
 * @param size2 размер 2 (высота)
 * @param size3 размер 3 (ширина)
 */
int foundMaxInArray (int*** arr, int size1, int size2, int size3) {
    int max = *(*(*(arr + 0) + 0) + 0);
    for (int i = 0; i < size1; ++i) {
        for (int j = 0; j < size2; ++j) {
            for (int k = 0; k < size3; ++k) {
                if (*(*(*(arr + i) + j) + k) > max) {
                    max = *(*(*(arr + i) + j) + k);
                }
            }
        }
    }
    
    return max;
}

/**
 * Ввод одномерного массива
 *
 * @param arr одномерный массив
 * @param size размер 1 (длина)
 */
void inputArray (int* arr, int size) {
    cout << "Введите значения одномерного массива: " << endl;


    for (int i = 0; i < size; ++i) {
        cin >> *(arr + i);
    }
}

/**
 * Ввод двумерного массива
 *
 * @param arr двумерный массив
 * @param size1 размер 1 (длина)
 * @param size2 размер 2 (высота)
 */
void inputArray (int** arr, int size1, int size2) {
    cout << "Введите значения двумерного массива: " << endl;


    for (int i = 0; i < size1; ++i) {
        for (int j = 0; j < size2; ++j) {
            cin >> *(*(arr + i) + j);
        }
    }
}

/**
 * Ввод трехмерного массива
 *
 * @param arr трехмерный массив
 * @param size1 размер 1 (длина)
 * @param size2 размер 2 (высота)
 * @param size3 размер 3 (ширина)
 */
void inputArray (int*** arr, int size1, int size2, int size3) {
    cout << "Введите значения трехмерного массива: " << endl;

    for (int i = 0; i < size1; ++i) {
        for (int j = 0; j < size2; ++j) {
            for (int k = 0; k < size3; ++k) {
                cin >> *(*(*(arr + i) + j) + k);
            }
        }
    }
}


int main() {
    system("chcp 1251>nul");

    int size1 = 3;
    int size2 = 4;
    int size3 = 5;
    int *arr1 = new int[size1];
    int **arr2 = new int*[size1];
    for (int i = 0; i < size1; ++i) {
        *(arr2 + i) = new int[size2];
    }
    int ***arr3 = new int**[size1];
    for (int i = 0; i < size1; ++i) {
        *(arr3 + i) = new int*[size2];
        for (int j = 0; j < size2; ++j) {
            *(*(arr3 + i) + j) = new int[size3];
        }
    }

    inputArray(arr1, size1);
    inputArray(arr2, size1, size2);
    inputArray(arr3, size1, size2, size3);

    cout << "Максимальный в первом массиве" << foundMaxInArray(arr1, size1) << endl;
    cout << "Максимальный во втором массиве"  << foundMaxInArray(arr2, size1, size2) << endl;
    cout << "Максимальный в третьем массиве"  << foundMaxInArray(arr3, size1, size2, size3) << endl;

    //добавить удаление
    return 0;
}
