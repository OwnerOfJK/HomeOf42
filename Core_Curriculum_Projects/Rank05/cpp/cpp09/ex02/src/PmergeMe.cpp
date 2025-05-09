#include "../include/PmergeMe.hpp"

PmergeMe::PmergeMe() {
    tree = nullptr;
    std::cout << "Default Constructor Called" << std::endl;
}

PmergeMe::PmergeMe(int *unsorted_arr, int size) {
    node* new_tree = new node;
    new_tree->size = size;
    new_tree->arr = new int[size];
    std::copy(unsorted_arr, unsorted_arr + size, new_tree->arr);
    this->tree = new_tree;
    tree->left = nullptr;
    tree->right = nullptr;
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