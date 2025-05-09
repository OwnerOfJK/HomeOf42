#include "../include/PmergeMe.hpp"

PmergeMe::PmergeMe() {
    tree = NULL;
    std::cout << "Default Constructor Called" << std::endl;
}

PmergeMe::PmergeMe(int *unsorted_arr, int size) {
    this->tree = create_node(size);
    std::copy(unsorted_arr, unsorted_arr + size, tree->arr.begin());
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
    // print_tree(tree);
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

PmergeMe::node* PmergeMe::create_node(int size) {
    node* new_node = new node;
    new_node->arr.resize(size);
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

void PmergeMe::destroy_tree(node *tree) {
    if (!tree) return;
    destroy_tree(tree->left);
    destroy_tree(tree->right);
    tree->arr.clear();
    delete tree;
}

void PmergeMe::print_vector(std::vector<int> &vector){
    for (size_t i = 0; i < vector.size(); i++)
        std::cout << "Vector at index: " << i << " is valued: " << vector[i] << std::endl;
}

void PmergeMe::print_tree(node *tree) {
    if (!tree) return;

    // Recursively print left and right subtrees
    print_tree(tree->left);
    print_tree(tree->right);

    print_vector(tree->arr);
}

void PmergeMe::sort_tree() {
    mergeSort(this->tree);
}

void PmergeMe::mergeSort(node *tree) {
    if (!tree) return;
    int size = tree->arr.size();
    if (size <= 1) return;

    // Correctly split the array
    int left_size = size / 2;
    int right_size = size - left_size;

    // Allocate child nodes
    tree->left = create_node(left_size);
    print_vector(tree->left->arr);
    tree->right = create_node(right_size);

    // Correct copy ranges
    std::copy(tree->arr.begin(), tree->arr.begin() + left_size, tree->left->arr.begin());
    print_vector(tree->left->arr);
    std::copy(tree->arr.begin() + left_size, tree->arr.end(), tree->right->arr.begin());

    // Recurse
    mergeSort(tree->left);
    mergeSort(tree->right);

    // Merge sorted halves
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
