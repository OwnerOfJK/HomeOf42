#include "../include/MergeSort.hpp"
#include <ctime>

MergeSort::MergeSort() {
    tree = NULL;
    // std::cout << "Default Constructor Called" << std::endl;
}

MergeSort::MergeSort(int *unsorted_arr, int size) {
    // std::cout << "Input Constructor Called" << std::endl;
    this->tree = create_node(size);
    std::copy(unsorted_arr, unsorted_arr + size, tree->arr.begin());
}

MergeSort::MergeSort(const MergeSort &src) {
    tree = copy_tree(src.tree);
    std::cout << "Copy Constructor Called" << std::endl;
}

MergeSort &MergeSort::operator=(const MergeSort &src) {
    if (this != &src) {
        destroy_tree(tree);
        tree = copy_tree(src.tree);
    }
    // std::cout << "Assignment Operator Called" << std::endl;
    return *this;
}

MergeSort::~MergeSort() {
    std::cout << "\nMerge Sort:" << std::endl;
    std::cout << "Ordered number array:" << std::endl;
    print_vector(tree->arr);
    std::cout << "Time taken to sort the array: " << timeToSort << " milliseconds" << std::endl;
    destroy_tree(tree);
    // std::cout << "Destructor Called" << std::endl;
}

MergeSort::node* MergeSort::copy_tree(MergeSort::node *tree) {
    if (!tree) return NULL;

    node* new_node = new node;
    new_node->arr = std::vector<int>(tree->arr);
    new_node->left = copy_tree(tree->left);
    new_node->right = copy_tree(tree->right);

    return new_node;
}

MergeSort::node* MergeSort::create_node(int size) {
    node* new_node = new node;
    new_node->arr.resize(size);
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

void MergeSort::destroy_tree(node *tree) {
    if (!tree) return;
    destroy_tree(tree->left);
    destroy_tree(tree->right);
    tree->arr.clear();
    delete tree;
}

void MergeSort::print_tree(node *tree) {
    if (!tree) return;

    print_tree(tree->left);
    print_tree(tree->right);

    print_vector(tree->arr);
}

void MergeSort::sortNumbers() {
    clock_t start = clock();
    mergeSort(this->tree);
    clock_t end = clock();
    timeToSort = static_cast<double>(end - start) * 100 / CLOCKS_PER_SEC;
}

void MergeSort::mergeSort(node *tree) {
    if (!tree) return;
    int size = tree->arr.size();
    if (size <= 1) return;

    int left_size = size / 2;
    int right_size = size - left_size;

    tree->left = create_node(left_size);
    tree->right = create_node(right_size);
    
    std::copy(tree->arr.begin(), tree->arr.begin() + left_size, tree->left->arr.begin());
    std::copy(tree->arr.begin() + left_size, tree->arr.end(), tree->right->arr.begin());

    mergeSort(tree->left);
    mergeSort(tree->right);

    // Merge sorted halves
    merge(tree->left, tree->right, tree);
}

void MergeSort::merge(node *left_node, node *right_node, node *parent) {
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