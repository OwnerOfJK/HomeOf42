#include "../include/PmergeMe.hpp"

PmergeMe::PmergeMe() {
    // std::cout << "Default Constructor Called" << std::endl;
}

PmergeMe::PmergeMe(int *unsorted_arr, int size) {
    mainChain.assign(unsorted_arr, unsorted_arr + size);
    std::cout << "\nMerge Insertion Sort:" << std::endl;
    // std::cout << "Input Constructor Called" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &src) : mainChain(src.mainChain) {
    // std::cout << "Copy Constructor Called" << std::endl;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &src) {
    if (this != &src) {
        mainChain = src.mainChain;
    }
    // std::cout << "Assignment Operator Called" << std::endl;
    return *this;
}

PmergeMe::~PmergeMe() {
    std::cout << "Sorted Output:\n";
    print_vector(mainChain);
    std::cout << "Time taken to sort the array: " << timeToSort << " milliseconds" << std::endl;
    // std::cout << "Destructor Called" << std::endl;
}

void PmergeMe::mergeInsertionSort() {
    clock_t start = clock();
    mainChain = recursiveMergeInsertion(mainChain);
    clock_t end = clock();
    timeToSort = static_cast<double>(end - start) * 100 / CLOCKS_PER_SEC;
}

std::vector<int> PmergeMe::recursiveMergeInsertion(std::vector<int> input) {
    if (input.size() <= 1)
        return input;

    std::vector<int> pendChain;
    std::vector<int> mainChain;

    // Split into pairs and sort each
    for (size_t i = 0; i + 1 < input.size(); i += 2) {
        if (input[i] < input[i + 1]) {
            pendChain.push_back(input[i]);
            mainChain.push_back(input[i + 1]);
        } else {
            pendChain.push_back(input[i + 1]);
            mainChain.push_back(input[i]);
        }
    }

    // If odd number of elements, add the last to main
    if (input.size() % 2 == 1)
        mainChain.push_back(input.back());

    // Recursively sort the main chain
    mainChain = recursiveMergeInsertion(mainChain);

    // Insert pending values into main chain
    for (size_t i = 0; i < pendChain.size(); ++i) {
        auto pos = std::upper_bound(mainChain.begin(), mainChain.end(), pendChain[i]);
        mainChain.insert(pos, pendChain[i]);
    }

    return mainChain;
}
