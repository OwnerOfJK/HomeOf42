#include "../include/PmergeMe.hpp"

PmergeMe::PmergeMe() {
    // std::cout << "Default Constructor Called" << std::endl;
}

PmergeMe::PmergeMe(int *unsorted_arr, int size) {
    mainChainVector.assign(unsorted_arr, unsorted_arr + size);
    mainChainList.assign(unsorted_arr, unsorted_arr + size);
    // std::cout << "Input Constructor Called" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &src) : mainChainVector(src.mainChainVector) {
    // std::cout << "Copy Constructor Called" << std::endl;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &src) {
    if (this != &src)
        mainChainVector = src.mainChainVector;
    // std::cout << "Assignment Operator Called" << std::endl;
    return *this;
}

PmergeMe::~PmergeMe() {
    std::cout << "\nMergeInsertion(Ford Johnson) Sort (Vector):\n";
    printVec(mainChainVector);
    std::cout << "Time: " << timeToSortVector << " ms\n";
    std::cout << "Result: " << isSortedV(mainChainVector) << std::endl;

    std::cout << "\nMergeInsertion(Ford Johnson) Sort (List):\n";
    printList(mainChainList);
    std::cout << "Time: " << timeToSortList << " ms\n";
    std::cout << "Result: " << isSortedL(mainChainList) << std::endl;
    // std::cout << "Destructor Called" << std::endl;
}

void PmergeMe::mergeInsertionSortVector() {
    clock_t start = clock();
    mainChainVector = recursiveMergeInsertionVector(mainChainVector);
    clock_t end = clock();
    timeToSortVector = static_cast<double>(end - start) * 1000 / CLOCKS_PER_SEC;
}

std::vector<int> PmergeMe::recursiveMergeInsertionVector(std::vector<int> input) {
    if (input.size() <= 1)
        return input;

    std::vector<std::pair<int, int> > pairs;
    std::vector<int> pendChain;
    std::vector<int> mainChainVector;

    bool hasOdd = (input.size() % 2 == 1);
    size_t pairCount = hasOdd ? input.size() - 1 : input.size();

    for (size_t i = 0; i < pairCount; i += 2) {
        int a = input[i];
        int b = input[i + 1];
        if (a < b)
            pairs.push_back(std::make_pair(a, b));
        else
            pairs.push_back(std::make_pair(b, a));
    }

    for (size_t i = 0; i < pairs.size(); ++i) {
        pendChain.push_back(pairs[i].first);
        mainChainVector.push_back(pairs[i].second);
    }

    // Recursively sort main chain
    mainChainVector = recursiveMergeInsertionVector(mainChainVector);

    // Insert first pend element at the beginning
    if (!pendChain.empty())
        mainChainVector.insert(mainChainVector.begin(), pendChain[0]);

    // Insert rest using Jacobsthal order
    std::vector<size_t> jacobIndices = initJacobsVector(pendChain.size());
    for (size_t j = 0; j < jacobIndices.size(); ++j) {
        size_t idx = jacobIndices[j];
        if (idx == 0) continue;

        int y = pendChain[idx];
        int bound = pairs[idx].second;

        // Find position to insert y before bound
        std::vector<int>::iterator it = mainChainVector.begin();
        while (it != mainChainVector.end() && *it != bound)
            ++it;

        std::vector<int>::iterator insertPos = mainChainVector.begin();
        while (insertPos != it && *insertPos < y)
            ++insertPos;

        mainChainVector.insert(insertPos, y);
    }

    // If odd, insert last unpaired element
    if (hasOdd) {
        int last = input.back();
        std::vector<int>::iterator it = mainChainVector.begin();
        while (it != mainChainVector.end() && *it < last)
            ++it;
        mainChainVector.insert(it, last);
    }

    return mainChainVector;
}

std::vector<size_t> PmergeMe::initJacobsVector(size_t size) {
    std::vector<size_t> jacob;
    jacob.push_back(1);
    jacob.push_back(1);
    while (jacob.back() < size) {
        size_t next = jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2];
        jacob.push_back(next);
        // std::cout << "next: " << next << std::endl;
    }

    std::vector<bool> used(size, false);
    std::vector<size_t> result;

    // Convert Jacobsthal numbers to insertion indices
    for (int k = (int)jacob.size() - 1; k >= 2; --k) {
        size_t blockSize = jacob[k] - jacob[k - 1];
        size_t startIdx = jacob[k - 1] - 1;

        for (size_t j = 0; j < blockSize && startIdx + j < size; ++j) {
            size_t idx = startIdx + j;
            if (!used[idx]) {
                used[idx] = true;
                result.push_back(idx);
            }
        }
    }

    // Fill in remaining indices not covered by Jacobsthal pattern
    for (size_t i = 1; i < size; ++i) {
        if (!used[i])
            result.push_back(i);
    }

    return result;
}

void PmergeMe::mergeInsertionSortList() {
    clock_t start = clock();
    mainChainList = recursiveMergeInsertionList(mainChainList);
    clock_t end = clock();
    timeToSortList = static_cast<double>(end - start) * 1000 / CLOCKS_PER_SEC;
}

std::list<int> PmergeMe::recursiveMergeInsertionList(std::list<int> input) {
    if (input.size() <= 1)
        return input;

    std::list<std::pair<int, int> > pairs;
    std::list<int> pendChain;
    std::list<int> mainChain;

    bool hasOdd = (input.size() % 2 == 1);
    int oddElement = 0;
    if (hasOdd) {
        std::list<int>::iterator last = input.end();
        --last;
        oddElement = *last;
        input.erase(last);
    }

    std::list<int>::iterator it = input.begin();
    while (it != input.end()) {
        int a = *it++;
        int b = *it++;
        if (a < b)
            pairs.push_back(std::make_pair(a, b));
        else
            pairs.push_back(std::make_pair(b, a));
    }

    for (std::list<std::pair<int, int> >::iterator p = pairs.begin(); p != pairs.end(); ++p) {
        pendChain.push_back(p->first);
        mainChain.push_back(p->second);
    }

    mainChain = recursiveMergeInsertionList(mainChain);

    if (!pendChain.empty())
        mainChain.push_front(pendChain.front());

    std::list<size_t> jacobIndices = initJacobsList(pendChain.size());
    for (std::list<size_t>::iterator idxIt = jacobIndices.begin(); idxIt != jacobIndices.end(); ++idxIt) {
        size_t idx = *idxIt;
        if (idx == 0 || idx >= pendChain.size())
            continue;

        std::list<int>::iterator pend = pendChain.begin();
        std::advance(pend, idx);
        int y = *pend;

        std::list<std::pair<int, int> >::iterator pair = pairs.begin();
        std::advance(pair, idx);
        int bound = pair->second;

        std::list<int>::iterator boundIt = std::find(mainChain.begin(), mainChain.end(), bound);
        std::list<int>::iterator insertPos = mainChain.begin();
        while (insertPos != boundIt && *insertPos < y)
            ++insertPos;

        mainChain.insert(insertPos, y);
    }

    if (hasOdd) {
        std::list<int>::iterator it = mainChain.begin();
        while (it != mainChain.end() && *it < oddElement)
            ++it;
        mainChain.insert(it, oddElement);
    }

    return mainChain;
}

std::list<size_t> PmergeMe::initJacobsList(size_t size) {
    std::vector<size_t> jacob;
    jacob.push_back(1);
    jacob.push_back(1);

    while (jacob.back() < size) {
        size_t n = jacob.size();
        size_t next = jacob[n - 1] + 2 * jacob[n - 2];
        jacob.push_back(next);
    }

    std::vector<bool> used(size, false);
    std::list<size_t> result;

    for (int k = jacob.size() - 1; k >= 2; --k) {
        size_t blockSize = jacob[k] - jacob[k - 1];
        size_t startIdx = jacob[k - 1] - 1;

        for (size_t j = 0; j < blockSize && (startIdx + j) < size; ++j) {
            size_t idx = startIdx + j;
            if (!used[idx]) {
                used[idx] = true;
                result.push_back(idx);
            }
        }
    }

    for (size_t i = 1; i < size; ++i) {
        if (!used[i])
            result.push_back(i);
    }

    return result;
}
