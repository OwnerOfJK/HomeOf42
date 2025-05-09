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
    delete[] tree->arr;
    delete tree;
}