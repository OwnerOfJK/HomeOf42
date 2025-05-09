#include "include/PmergeMe.hpp"
#include <stdlib.h>

int main(int argc, char **argv) {
    if (argc < 2)
        std::cout << "Not enough arguments" << std::endl;
    int arr[argc - 1];
    for (int i = 0; i < argc; i++) {
        arr[i] = atoi(argv[i]);
    }
    PmergeMe mergeInsertion(arr, argc -1);
    mergeInsertion.sort_tree();
    return 0;
}