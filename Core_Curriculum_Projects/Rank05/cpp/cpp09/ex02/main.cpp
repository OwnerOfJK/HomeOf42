#include "include/PmergeMe.hpp"
#include "include/MergeSort.hpp"
#include <stdlib.h>
#include <array>
#include <ctime>

void testSort(int *arr, int size) {
    std::cout << "\nstd::sort:" << std::endl;
    std::vector<int> vecArray(arr, arr + size);

    clock_t start = clock();
    std::sort(vecArray.begin(), vecArray.end());
    clock_t end = clock();
    double sortDuration = static_cast<double>(end - start) * 100 / CLOCKS_PER_SEC;

    if (size > 100) {
        std::cout << "Array is too large to display." << std::endl;
    } else {
        std::cout << "Sorted number array:" << std::endl;
        std::cout << "{";
        for (int i = 0; i < size; i++) {
            std::cout << " " << vecArray[i];
        }
        std::cout << " }";
        std::cout << std::endl;
    }
    std::cout << "Time taken to sort the array: " << sortDuration << " milliseconds" << std::endl;
}


int main(int argc, char **argv) {
    if (argc < 2)
        std::cout << "Not enough arguments" << std::endl;
    int arr[argc + 1];
    for (int i = 1; i < argc; i++) {
        arr[i - 1] = atoi(argv[i]);
    }

    std::cout << "Unordered number array:" << std::endl;
    std::cout << "{";
    for (int i = 0; i < argc - 1; i++) {
        std::cout << " " << arr[i];
    }
    std::cout << " }";
    std::cout << std::endl;

    // std::sort
    testSort(arr, argc - 1);

    // MergeSort
    MergeSort mergeSort(arr, argc - 1);
    mergeSort.sortNumbers();

    // MergeInsertionSort
    PmergeMe mergeInsertion(arr, argc - 1);
    mergeInsertion.mergeInsertionSort();
    return 0;
}


