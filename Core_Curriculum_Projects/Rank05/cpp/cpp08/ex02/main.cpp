#include "include/MutantStack.hpp"

void testMutantStack() {
    std::cout << "🧪 Testing MutantStack" << std::endl;

    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << "Top: " << mstack.top() << std::endl; // Should print 17
    mstack.pop();

    std::cout << "Size after pop: " << mstack.size() << std::endl; // Should print 1

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << "Contents:" << std::endl;
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
        std::cout << *it << std::endl;
    }

    std::stack<int> s(mstack); // Copy construction should work fine
}

void testList() {
    std::cout << "\n🧪 Testing std::list" << std::endl;

    std::list<int> lstack;

    lstack.push_back(5);
    lstack.push_back(17);
    lstack.pop_back();

    std::cout << "Size after pop: " << lstack.size() << std::endl; // Should print 1

    lstack.push_back(3);
    lstack.push_back(5);
    lstack.push_back(737);
    lstack.push_back(0);

    std::cout << "Contents:" << std::endl;
    for (std::list<int>::iterator it = lstack.begin(); it != lstack.end(); ++it) {
        std::cout << *it << std::endl;
    }
}

int main() {
    testMutantStack();
    testList();
    return 0;
}