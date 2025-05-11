#include "include/PmergeMe.hpp"
#include "include/MergeSort.hpp"
#include <stdlib.h>
#include <ctime>
#include <algorithm>

#include "include/Utils.hpp"

void testSort(int *arr, int size) {
    
    std::cout << "\nstd::sort (Vector):\n";
    std::vector<int> vecArray(arr, arr + size);
    clock_t startV = clock();
    std::sort(vecArray.begin(), vecArray.end());
    clock_t endV = clock();
    double sortDurationV = static_cast<double>(endV - startV) * 1000 / CLOCKS_PER_SEC;
    printVec(vecArray);
    std::cout << "Time: " << sortDurationV << " ms\n";
    std::cout << "Result: " << isSortedV(vecArray) << std::endl;


    std::cout << "\nstd::sort (List):\n";
    std::list<int> listArray(arr, arr + size);
    clock_t startL = clock();
    listArray.sort();
    clock_t endL = clock();
    double sortDurationL = static_cast<double>(endL - startL) * 1000 / CLOCKS_PER_SEC;
    printList(listArray);
    std::cout << "Time: " << sortDurationL << " ms\n";
    std::cout << "Result: " << isSortedL(listArray) << std::endl;
}

//to test use ./PmergeMe $(shuf -i 0-10000 -n 100)
int main(int argc, char **argv) {
    if (argc < 2) {
        std::cout << "Not enough arguments" << std::endl;
        return 0;
    }
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
    mergeSort.sortVector();
    mergeSort.sortList();

    // MergeInsertionSort
    PmergeMe mergeInsertion(arr, argc - 1);
    mergeInsertion.mergeInsertionSortVector();
    mergeInsertion.mergeInsertionSortList();
    return 0;
}


