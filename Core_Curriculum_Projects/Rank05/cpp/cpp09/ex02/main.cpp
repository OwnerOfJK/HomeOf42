#include "include/PmergeMe.hpp"
#include <stdlib.h>

int main(int argc, char **argv) {
    if (argc < 2)
        std::cout << "Not enough arguments" << std::endl;
    int arr[1000];
    for (int i = 1; i < argc; i++) {
        arr[i - 1] = atoi(argv[i]);
    }
    PmergeMe mergeInsertion(arr, argc - 1);

    mergeInsertion.sort_tree();
    return 0;
}