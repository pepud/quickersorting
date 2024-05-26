#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include "quicker-sorting/quicker-sorting.hpp"

template <typename T>
std::vector<T> generate_large_array(size_t size) {
    std::vector<int> arr(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 1000000);

    for (size_t i = 0; i < size; ++i) {
        arr[i] = dis(gen);
    }

    return arr;
}

int main(int argc, char* argv[]) {
    size_t size = 1000000;
    std::vector<int> large_array = generate_large_array<int>(size);
    
    auto time_1 = std::chrono::high_resolution_clock::now();
    MergeSort<int>::sort(large_array, false, [](int a, int b) -> bool {
        return a > b;
    });
    auto duration_1 = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - time_1).count();
	std::cout << "[>] MergeSort (Without Multi-Threading): " << duration_1 << "ms" << std::endl;

    std::vector<double> large_array_2 = generate_large_array<double>(size);
    auto time_2 = std::chrono::high_resolution_clock::now();
    MergeSort<double>::sort(large_array_2, true, [](int a, int b) -> bool {
        return a > b;
    });
    auto duration_2 = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - time_2).count();
    std::cout << "[>] MergeSort (Multi-Threading): " << duration_2 << "ms" << std::endl;

    return 0;
}
