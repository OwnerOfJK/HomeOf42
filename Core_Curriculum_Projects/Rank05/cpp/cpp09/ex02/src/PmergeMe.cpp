#include "../include/PmergeMe.hpp"

PmergeMe::PmergeMe() {
    tree = NULL;
    std::cout << "Default Constructor Called" << std::endl;
}

PmergeMe::PmergeMe(int *unsorted_arr, int size) {
    node* new_tree = new node;
    new_tree->arr.resize(size);
    std::copy(unsorted_arr, unsorted_arr + size, new_tree->arr.begin());
    this->tree = new_tree;
    tree->left = NULL;
    tree->right = NULL;
    std::cout << "Input Constructor Called" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &src) {
    tree = copy_tree(src.tree);
    std::cout << "Copy Constructor Called" << std::endl;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &src) {
    if (this != &src) {
        destroy_tree(tree);
        tree = copy_tree(src.tree);
    }
    std::cout << "Assignment Operator Called" << std::endl;
    return *this;
}

PmergeMe::~PmergeMe() {
    destroy_tree(tree);
    std::cout << "Destructor Called" << std::endl;
}

PmergeMe::node* PmergeMe::copy_tree(PmergeMe::node *tree) {
    if (!tree) return NULL;

    node* new_node = new node;
    new_node->arr = std::vector<int>(tree->arr);
    new_node->left = copy_tree(tree->left);
    new_node->right = copy_tree(tree->right);

    return new_node;
}

void PmergeMe::destroy_tree(node *tree) {
    if (!tree) return;
    destroy_tree(tree->left);
    destroy_tree(tree->right);
    tree->arr.clear();
    delete tree;
}


void PmergeMe::sort_tree() {
    mergeSort(this->tree);
}

void PmergeMe::mergeSort(node *tree) {
    if (!tree) return;
    int size = tree->arr.size();
    if (size <= 1) return;
    tree->left->arr.resize(size / 2);
    tree->right->arr.resize(size - size / 2);
    std::copy(tree->arr.begin(), tree->arr.begin() + size / 2, tree->left->arr.begin());
    std::copy(tree->arr.begin() + size / 2 + 1, tree->arr.end() + size / 2, tree->right->arr.begin());
    mergeSort(tree->left);
    mergeSort(tree->right);
    merge(tree->left, tree->right, tree);
}

void PmergeMe::merge(node *left_node, node *right_node, node *parent) {
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
