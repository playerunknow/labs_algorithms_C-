#pragma once


#include <iostream>
#include <vector>
#include <algorithm>  // для swap
#include <ctime>      // для вимірювання часу
#include <random>     // для генерації випадкових чисел

using namespace std;

// Функція для вимірювання часу виконання
#define TIMEIT(func) \
    { \
        clock_t start_time = clock(); \
        func; \
        clock_t end_time = clock(); \
        double execution_time = double(end_time - start_time) / CLOCKS_PER_SEC; \
        cout << "execution_time " #func ": " << execution_time << " секунд\n\n"; \
    }

// Функція для генерації випадкового масиву
vector<int> generate_random_array(int n, int lower_bound = 0, int upper_bound = 100) {
    vector<int> array(n);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(lower_bound, upper_bound);

    for (int i = 0; i < n; ++i) {
        array[i] = dis(gen);
    }
    return array;
}

// Сортування бульбашкою (BubbleSort)
void BubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Сортування вставками (InsertionSort)
void InsertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int current_value = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > current_value) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = current_value;
    }
}

// Швидке сортування (QuickSort)
vector<int> quicksort(const vector<int>& arr) {
    if (arr.size() <= 1) return arr;

    int pivot = arr[arr.size() / 2];
    vector<int> left, middle, right;

    for (int x : arr) {
        if (x < pivot) left.push_back(x);
        else if (x == pivot) middle.push_back(x);
        else right.push_back(x);
    }

    left = quicksort(left);
    right = quicksort(right);

    left.insert(left.end(), middle.begin(), middle.end());
    left.insert(left.end(), right.begin(), right.end());
    return left;
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[(low + high) / 2];
    int i = low - 1;
    int j = high + 1;

    while (true) {
        do {
            ++i;
        } while (arr[i] < pivot);

        do {
            --j;
        } while (arr[j] > pivot);

        if (i >= j) return j;

        swap(arr[i], arr[j]);
    }
}

// Швидке сортування Хоара (Hoare's QuickSort)
void quicksortHoare(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksortHoare(arr, low, pi);
        quicksortHoare(arr, pi + 1, high);
    }
}

// Функція для виконання сортувань та вимірювання часу
void calculation(const vector<int>& random_array) {
    vector<int> main_array = random_array;

    TIMEIT(BubbleSort(main_array));

    main_array = random_array;
    TIMEIT(InsertionSort(main_array));

    main_array = random_array;
    TIMEIT(quicksort(main_array));

    main_array = random_array;
    TIMEIT(quicksortHoare(main_array, 0, main_array.size() - 1));

    cout << "\n\n\n\n\n\n\n";
}

void hub_lab_1() {
    vector<int> random_array1 = generate_random_array(1000, 0, 10000);
    vector<int> random_array2 = generate_random_array(2000, 0, 10000);
    vector<int> random_array3 = generate_random_array(3000, 0, 10000);
    vector<int> random_array4 = generate_random_array(4000, 0, 10000);
    vector<int> random_array5 = generate_random_array(5000, 0, 10000);
    vector<int> random_array6 = generate_random_array(6000, 0, 10000);

    calculation(random_array1);
    calculation(random_array2);
    calculation(random_array3);
    calculation(random_array4);
    calculation(random_array5);
    calculation(random_array6);
}
