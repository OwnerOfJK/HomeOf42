#include "include/Array.hpp"

int main() {
    try {
        Array<int> arrayObj(3);
        arrayObj[0] = 1;
        arrayObj[1] = 2;
        arrayObj[2] = 3;
        arrayObj[-1] = 1;
        arrayObj.display();
    
        Array<int> emptyArrayObj(arrayObj);
        emptyArrayObj[0] = 42;
        emptyArrayObj.display();
        arrayObj.display();
    
        Array<int> newArray;
        newArray = arrayObj;
        newArray.display();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }
