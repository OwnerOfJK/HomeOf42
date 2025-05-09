#ifndef pmergeme_hpp
#define pmergeme_hpp

#include <iostream>
#include <algorithm>
#include <vector>

class PmergeMe {
    private:
        struct node {
            std::vector<int> arr;
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

        // Core
        void sort_tree();
        //this function recursively splits the parameter array into two.
        //returns the head of the tree
        //recursive until the size of the arr is 1
        void mergeSort(node *tree);
        //will operater on subarrays with size 1
        //look at value in each subarray, order them and put them back into the head
        //called inside the mergeSort
        //compare most left element of each subarray and put them one by one into the head
        void merge(node *left_node, node *right_node, node *parent);


        // Utils
        node *copy_tree(node *tree);
        void destroy_tree(node *tree);
};

#endif