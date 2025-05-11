#ifndef MergeSort_hpp
#define MergeSort_hpp

#include <iostream>
#include <algorithm>
#include <vector>

class MergeSort {
    private:
        struct node {
            std::vector<int> arr;
            node *left;
            node *right;
        };
        node *tree;
        double timeToSort;
    public:
        // Constructing / Destructing
        MergeSort();
        MergeSort(int *unsorted_arr, int size);
        MergeSort(const MergeSort &src);
        MergeSort &operator=(const MergeSort &src);
        ~MergeSort();

        // Core
        void sortNumbers();
        void mergeSort(node *tree);
        void merge(node *left_node, node *right_node, node *parent);

        // Utils
        node *copy_tree(node *tree);
        void destroy_tree(node *tree);
        void print_tree(node *tree);
        void print_vector(std::vector<int> &vector);
        node *create_node(int size);
};

#endif