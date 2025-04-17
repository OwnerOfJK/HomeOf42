#include "include/Span.hpp"

int main()
{
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "Shortest Span is: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span is: " << sp.longestSpan() << std::endl;
        for (size_t* it = sp.begin(); it != sp.end(); ++it) {
            std::cout << "Value at address " << it << " is: " << *it << std::endl;
        }
    }

    {   try {
            Span emptySp(2);
            emptySp.addNumber(42);
            emptySp.addNumber(42);
            emptySp.addNumber(42);
        } catch (std::exception &e)
        {
            std::cerr << std::endl << e.what() << std::endl;
        }
    }

    {
        std::vector<size_t> numbers;
        for (size_t i = 0; i < 50000; ++i)
            numbers.push_back(i);
        Span span(50000);
        std::cout << "There are " << span.getCount() << " numbers in the Span of length: " << span.getMax() << std::endl;
        span.addNumbers(numbers.begin(), numbers.end());
        std::cout << "There are " << span.getCount() << " numbers in the Span of length: " << span.getMax() << std::endl;
        std::cout << "The number at index 200 is: " << span.getNumber(200) << std::endl;
    }
    
    return (0);
}