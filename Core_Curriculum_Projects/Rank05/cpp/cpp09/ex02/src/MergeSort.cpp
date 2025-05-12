#include "../include/MergeSort.hpp"

// ==== Constructors / Destructor ====

MergeSort::MergeSort() : treeVec(NULL), treeList(NULL), timeVec(0), timeList(0) {}

MergeSort::MergeSort(int *unsorted_arr, int size) {
    treeVec = createNodeVec(size);
    std::copy(unsorted_arr, unsorted_arr + size, treeVec->arr.begin());

    treeList = createNodeList();
    std::copy(unsorted_arr, unsorted_arr + size, std::back_inserter(treeList->arr));
}

MergeSort::MergeSort(const MergeSort &src) {
    treeVec = copyVec(src.treeVec);
    treeList = copyList(src.treeList);
}

MergeSort &MergeSort::operator=(const MergeSort &src) {
    if (this != &src) {
        destroyVec(treeVec);
        destroyList(treeList);
        treeVec = copyVec(src.treeVec);
        treeList = copyList(src.treeList);
    }
    return *this;
}

MergeSort::~MergeSort() {
    std::cout << "\nMerge Sort (Vector):\n";
    printVec(treeVec->arr);
    std::cout << "Time: " << timeVec << " ms\n";
    std::cout << "Result with " <<  treeVec->arr.size() << " numbers: " << isSortedV(treeVec->arr) << std::endl;

    std::cout << "\nMerge Sort (List):\n";
    printList(treeList->arr);
    std::cout << "Time: " << timeList << " ms\n";
    std::cout << "Result with " <<  treeList->arr.size() << " numbers: " << isSortedL(treeList->arr) << std::endl;

    destroyVec(treeVec);
    destroyList(treeList);
}

// ==== Vector Sorting ====

void MergeSort::sortVector() {
    clock_t start = clock();
    mergeSortVector(treeVec);
    clock_t end = clock();
    timeVec = static_cast<double>(end - start) * 1000 / CLOCKS_PER_SEC;
}

void MergeSort::mergeSortVector(nodeVec *tree) {
    if (!tree || tree->arr.size() <= 1) return;

    int size = tree->arr.size();
    int mid = size / 2;

    tree->left = createNodeVec(mid);
    tree->right = createNodeVec(size - mid);

    std::copy(tree->arr.begin(), tree->arr.begin() + mid, tree->left->arr.begin());
    std::copy(tree->arr.begin() + mid, tree->arr.end(), tree->right->arr.begin());

    mergeSortVector(tree->left);
    mergeSortVector(tree->right);

    mergeVector(tree->left, tree->right, tree);
}

void MergeSort::mergeVector(nodeVec *left_node, nodeVec *right_node, nodeVec *parent) {
    int left_size = left_node->arr.size();
    int right_size = right_node->arr.size();
    int i = 0;
    int l = 0;
    int r = 0;

    while (l < left_size && r < right_size)
    {
        if (left_node->arr[l] < right_node->arr[r]) {
            parent->arr[i] = left_node->arr[l];
            i++;
            l++;
        }
        else {
            parent->arr[i] = right_node->arr[r];
            i++;
            r++;
        }
    }
    while(l < left_size) {
        parent->arr[i] = left_node->arr[l];
        i++;
        l++;
    }
    while(r < right_size) {
        parent->arr[i] = right_node->arr[r];
        i++;
        r++;
    }
}

// ==== List Sorting ====

void MergeSort::sortList() {
    clock_t start = clock();
    mergeSortList(treeList);
    clock_t end = clock();
    timeList = static_cast<double>(end - start) * 1000 / CLOCKS_PER_SEC;
}

void MergeSort::mergeSortList(nodeList *tree) {
    if (!tree || tree->arr.size() <= 1) return;

    int size = tree->arr.size();
    int mid = size / 2;

    tree->left = createNodeList();
    tree->right = createNodeList();

    std::list<int>::iterator it = tree->arr.begin();
    for (int i = 0; i < mid; ++i, ++it)
        tree->left->arr.push_back(*it);
    for (; it != tree->arr.end(); ++it)
        tree->right->arr.push_back(*it);

    mergeSortList(tree->left);
    mergeSortList(tree->right);

    mergeList(tree->left, tree->right, tree);
}

void MergeSort::mergeList(nodeList *left, nodeList *right, nodeList *parent) {
    std::list<int>::iterator itL = left->arr.begin();
    std::list<int>::iterator itR = right->arr.begin();
    parent->arr.clear();

    while (itL != left->arr.end() && itR != right->arr.end()) {
        if (*itL < *itR) {
            parent->arr.push_back(*itL++);
        } else {
            parent->arr.push_back(*itR++);
        }
    }

    while (itL != left->arr.end()) {
        parent->arr.push_back(*itL++);
    }

    while (itR != right->arr.end()) {
        parent->arr.push_back(*itR++);
    }
}

// ==== Utility Methods ====

MergeSort::nodeVec* MergeSort::createNodeVec(int size) {
    nodeVec *n = new nodeVec;
    n->arr.resize(size);
    n->left = n->right = NULL;
    return n;
}

MergeSort::nodeList* MergeSort::createNodeList() {
    nodeList *n = new nodeList;
    n->left = n->right = NULL;
    return n;
}

MergeSort::nodeVec* MergeSort::copyVec(nodeVec *tree) {
    if (!tree) return NULL;
    nodeVec *n = new nodeVec;
    n->arr = tree->arr;
    n->left = copyVec(tree->left);
    n->right = copyVec(tree->right);
    return n;
}

MergeSort::nodeList* MergeSort::copyList(nodeList *tree) {
    if (!tree) return NULL;
    nodeList *n = new nodeList;
    n->arr = tree->arr;
    n->left = copyList(tree->left);
    n->right = copyList(tree->right);
    return n;
}

void MergeSort::destroyVec(nodeVec *tree) {
    if (!tree) return;
    destroyVec(tree->left);
    destroyVec(tree->right);
    delete tree;
}

void MergeSort::destroyList(nodeList *tree) {
    if (!tree) return;
    destroyList(tree->left);
    destroyList(tree->right);
    delete tree;
}

