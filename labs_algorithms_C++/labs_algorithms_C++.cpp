#include <iostream>
#include <vector>
#include <algorithm>  // для std::swap
#include <cstdlib>    // для std::rand і std::srand
#include <ctime>      // для std::time
#include <chrono>     // для вимірювання часу

using namespace std;
using namespace std::chrono;

// Функція для вимірювання часу виконання
template <typename Func, typename... Args>
void timeit(Func func, const string& name, Args&&... args) 
{
    auto start = high_resolution_clock::now();
    func(forward<Args>(args)...);
    auto end = high_resolution_clock::now();
    duration<double> execution_time = end - start;
    cout << "execution_time " << name << ": " << execution_time.count() << " seconds\n\n";
}

// Функція для генерації випадкового масиву
vector<int> generate_random_array(int n, int lower_bound = 0, int upper_bound = 100) 
{
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) 
    {
        arr[i] = lower_bound + rand() % (upper_bound - lower_bound + 1);
    }
    return arr;
}

// BubbleSort
void BubbleSort(vector<int>& arr) 
{
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) 
    {
        for (int j = 0; j < n - i - 1; ++j) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// InsertionSort
void InsertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) 
    {
        int current_value = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > current_value) 
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = current_value;
    }
}

// QuickSort
vector<int> quicksort(const vector<int>& arr) 
{
    if (arr.size() <= 1) 
    {
        return arr;
    }

    int pivot = arr[arr.size() / 2];
    vector<int> left, middle, right;

    for (int x : arr) 
    {
        if (x < pivot) left.push_back(x);
        else if (x == pivot) middle.push_back(x);
        else right.push_back(x);
    }

    left = quicksort(left);
    right = quicksort(right);

    vector<int> result;
    result.insert(result.end(), left.begin(), left.end());
    result.insert(result.end(), middle.begin(), middle.end());
    result.insert(result.end(), right.begin(), right.end());

    return result;
}

int partition(vector<int>& arr, int low, int high) 
{
    int pivot = arr[(low + high) / 2];
    int i = low - 1;
    int j = high + 1;

    while (true)
    {
        do 
        {
            i++;
        } while (arr[i] < pivot);

        do 
        {
            j--;
        } while (arr[j] > pivot);

        if (i >= j) 
        {
            return j;
        }

        swap(arr[i], arr[j]);
    }
}


// Hoare's QuickSort
void quicksortHoare(vector<int>& arr, int low, int high) 
{
    if (low < high) 
    {
        int pi = partition(arr, low, high);
        quicksortHoare(arr, low, pi);
        quicksortHoare(arr, pi + 1, high);
    }
}


int main() 
{
    srand(time(0));  // Ініціалізація генератора випадкових чисел

    vector<int> random_array = generate_random_array(10000, 0, 10000);
    vector<int> main_array = random_array;

    timeit(BubbleSort, "BubbleSort", main_array);
    main_array = random_array;

    timeit(InsertionSort, "InsertionSort", main_array);
    main_array = random_array;

    auto start = high_resolution_clock::now();
    vector<int> sorted_array = quicksort(main_array);
    auto end = high_resolution_clock::now();
    duration<double> execution_time = end - start;
    cout << "execution_time quicksort: " << execution_time.count() << " seconds\n\n";

    main_array = random_array;

    start = high_resolution_clock::now();
    quicksortHoare(main_array, 0, main_array.size() - 1);
    end = high_resolution_clock::now();
    execution_time = end - start;
    cout << "execution_time quicksortHoare: " << execution_time.count() << " seconds\n\n";

    return 0;
}
