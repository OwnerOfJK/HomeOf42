#include "include/Iter.hpp"

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    size_t len = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original array: ";
    iter(arr, len, print_element<int>);
    std::cout << std::endl;

    iter(arr, len, add_one);

    std::cout << "After add_one: ";
    iter(arr, len, print_element<int>);
    std::cout << std::endl;

    // Testing with different types
    double d_arr[] = {1.1, 2.2, 3.3, 4.4};
    size_t d_len = sizeof(d_arr) / sizeof(d_arr[0]);

    std::cout << "Double array: ";
    iter(d_arr, d_len, print_element<double>);
    std::cout << std::endl;

    std::string s_arr[] = {"Hello", "World", "C++"};
    size_t s_len = sizeof(s_arr) / sizeof(s_arr[0]);

    std::cout << "String array: ";
    iter(s_arr, s_len, print_element<std::string>);
    std::cout << std::endl;

    return 0;
}