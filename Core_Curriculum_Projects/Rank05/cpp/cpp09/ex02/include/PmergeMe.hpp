#ifndef pmergeme_hpp
#define pmergeme_hpp

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

#include "Utils.hpp"

class PmergeMe {
    private:
        std::vector<int>    mainChainVector;
        double              timeToSortVector;
        
        std::list<int>      mainChainList;
        double              timeToSortList;

    public:
        // Constructing / Destructing
        PmergeMe();
        PmergeMe(int *unsorted_arr, int size);
        PmergeMe(const PmergeMe &src);
        PmergeMe &operator=(const PmergeMe &src);
        ~PmergeMe();
        
        // Core - Vector
        void mergeInsertionSortVector();
        std::vector<int> recursiveMergeInsertionVector(std::vector<int> input);
        std::vector<size_t> initJacobsVector(size_t size);

        // Core - List
        void mergeInsertionSortList();
        std::list<int> recursiveMergeInsertionList(std::list<int> input);
        std::list<size_t> initJacobsList(size_t size);
};
    

#endif