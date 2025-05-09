#ifndef pmergeme_hpp
#define pmergeme_hpp

#include <iostream>
#include <algorithm>

class PmergeMe {
    private:
        struct node {
            int  size;
            int *arr;
            node *left;
            node *right;
        };
        node *tree;
    public:
        // Constructing / Destructing
        PmergeMe();
        PmergeMe(int *unsorted_arr, int size);
        PmergeMe(const PmergeMe &src);
        PmergeMe &operator=(const PmergeMe &src);
        ~PmergeMe();

        // Utils
        node *copy_tree(node *tree);
        void destroy_tree(node *tree);
};

#endif