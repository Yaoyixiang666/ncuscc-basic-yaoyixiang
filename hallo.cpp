#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <fstream>

// √∞≈›≈≈–Ú
void bubbleSort(std::vector<double>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// øÏÀŸ≈≈–Ú
void quickSort(std::vector<double>& arr, int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                std::swap(arr[i], arr[j]);
            }
        }

        std::swap(arr[i + 1], arr[high]);

        int p = i + 1;

        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

int main() {
    std::vector<int> data_sizes = {10000000 };

    std::ofstream csv_file("sorting_performance.csv");
    csv_file << "Data Size, Bubble Sort Time (ms), Quick Sort Time (ms)\n";

    for (int size : data_sizes) {
        std::vector<double> data(size);
        std::default_random_engine generator;
        std::uniform_real_distribution<double> distribution(0.0, 1000.0);

        for (int i = 0; i < size; i++) {
            data[i] = distribution(generator);
        }

        std::vector<double> data_copy = data;

        auto start = std::chrono::high_resolution_clock::now();
        bubbleSort(data);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> bubble_sort_time = end - start;

        start = std::chrono::high_resolution_clock::now();
        quickSort(data_copy, 0, size - 1);
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> quick_sort_time = end - start;

        csv_file << size << ", " << bubble_sort_time.count() << ", " << quick_sort_time.count() << "\n";
    }

    csv_file.close();

    return 0;
}