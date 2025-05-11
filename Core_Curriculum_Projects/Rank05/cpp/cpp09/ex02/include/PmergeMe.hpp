#ifndef pmergeme_hpp
#define pmergeme_hpp

#include <iostream>
#include <algorithm>
#include <vector>

class PmergeMe {
    private:
        std::vector<int>    mainChain;
        double              timeToSort;
    
    public:
        // Constructing / Destructing
        PmergeMe();
        PmergeMe(int *unsorted_arr, int size);
        PmergeMe(const PmergeMe &src);
        PmergeMe &operator=(const PmergeMe &src);
        ~PmergeMe();
        
        // Core
        void mergeInsertionSort();
        std::vector<int> recursiveMergeInsertion(std::vector<int> input);
    
        // Utils
        void print_vector(const std::vector<int> &vec);
    };
    

#endif