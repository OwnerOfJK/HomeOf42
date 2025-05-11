#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <vector>
#include <list>

void printVec(const std::vector<int> &vector);
void printList(const std::list<int> &lst);
std::string isSortedV(const std::vector<int> &vector);
std::string isSortedL(const std::list<int> &lst);

#endif