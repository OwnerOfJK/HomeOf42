#ifndef MergeSort_hpp
#define MergeSort_hpp

#include <iostream>
#include <algorithm>
#include <vector>

#include "Utils.hpp"

class MergeSort {
    private:
        struct nodeVec {
            std::vector<int> arr;
            nodeVec *left;
            nodeVec *right;
        };
        struct nodeList {
            std::list<int> arr;
            nodeList *left;
            nodeList *right;
        };

        nodeVec *treeVec;
        nodeList *treeList;
        double timeVec;
        double timeList;

    public:
        // Constructors / Destructors
        MergeSort();
        MergeSort(int *unsorted_arr, int size);
        MergeSort(const MergeSort &src);
        MergeSort &operator=(const MergeSort &src);
        ~MergeSort();

        // Core
        void sortVector();
        void sortList();

    private:
        // Vector
        void mergeSortVector(nodeVec *tree);
        void mergeVector(nodeVec *left_node, nodeVec *right_node, nodeVec *parent);

        // List
        void mergeSortList(nodeList *tree);
        void mergeList(nodeList *left_node, nodeList *right_node, nodeList *parent);

        // Utils
        nodeVec *createNodeVec(int size);
        nodeList *createNodeList();

        nodeVec *copyVec(nodeVec *tree);
        nodeList *copyList(nodeList *tree);

        void destroyVec(nodeVec *tree);
        void destroyList(nodeList *tree);
};

#endif