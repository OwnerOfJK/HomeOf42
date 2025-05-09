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

node* PmergeMe::copy_tree(node *tree) {
    if (tree == nullptr) {
        return nullptr;
    }

    node* new_node = new node;
    new_node->size = tree->size;
    new_node->arr = new int[tree->size];
    std::copy(tree->arr, tree->arr + tree->size, new_node->arr);

    // Recursively copy left and right subtrees
    new_node->left = copy_tree(tree->left);
    new_node->right = copy_tree(tree->right);

    return new_node;
}

void PmergeMe::destroy_tree(node *tree) {
    if (!tree) return;
    destroy_tree(tree->left);
    destroy_tree(tree->right);
    delete[] tree->arr;
    delete tree;
}