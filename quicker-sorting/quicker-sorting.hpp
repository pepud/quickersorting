#ifndef QUICK_SORT_HPP
#define QUICK_SORT_HPP

#include <vector>
#include <thread>
#include <algorithm>
#include <functional>

template <typename T>
class MergeSort {
public:
     /**
	 * @brief Sorts the std::vector using Merge Sort algorithm
	 * @param The std::vector to be sorted
	 * @param Determines whether to use multi-threading or not
	 * @param Lambda function used to compare two elements of the std::vector
	 **/
    static void sort(std::vector<T>& arr, bool is_multi_thread, const std::function<bool(const T&, const T&)>& comp) {
        merge_sort(arr, 0, arr.size() - 1, comp, is_multi_thread);
    }

private:
    static void merge(std::vector<T>& arr, int left, int mid, int right, const std::function<bool(const T&, const T&)>& comp) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        std::vector<T> left_half(n1);
        std::vector<T> right_half(n2);

        for (int i = 0; i < n1; ++i)
            left_half[i] = arr[left + i];
        for (int j = 0; j < n2; ++j)
            right_half[j] = arr[mid + 1 + j];

        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (comp(left_half[i], right_half[j])) {
                arr[k] = left_half[i];
                i++;
            }
            else {
                arr[k] = right_half[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            arr[k] = left_half[i];
            i++;
            k++;
        }

        while (j < n2) {
            arr[k] = right_half[j];
            j++;
            k++;
        }
    }

    static void merge_sort(std::vector<T>& arr, int left, int right, const std::function<bool(const T&, const T&)>& comp, bool is_multi_thread, int depth = 0) {
        const int MAX_DEPTH = 4; // 4 threads are optimal for most of the cases, but you can change it though
        if (left < right) {
            int mid = left + (right - left) / 2;

            if (depth < MAX_DEPTH && is_multi_thread) {
                std::thread left_thread(merge_sort, std::ref(arr), left, mid, std::ref(comp), is_multi_thread, depth + 1);
                std::thread right_thread(merge_sort, std::ref(arr), mid + 1, right, std::ref(comp), is_multi_thread, depth + 1);

                left_thread.detach();
                right_thread.detach();
            }
            else {
                merge_sort(arr, left, mid, comp, is_multi_thread, depth + 1);
                merge_sort(arr, mid + 1, right, comp, is_multi_thread, depth + 1);
            }

            merge(arr, left, mid, right, comp);
        }
    }
};


#endif // QUICK_SORT_HPP
