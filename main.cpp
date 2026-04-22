#include <iostream>
#include "generic_array.hpp"

int main() {
    GenericArray<int> arr;

    for (int i = 0; i < 12; i++)
        arr.addElement(i * 2);

    std::cout << "Size: " << arr.size() << std::endl;
    std::cout << "Sum: " << arr.sum() << std::endl;
    std::cout << "Max: " << arr.max() << std::endl;
    std::cout << "Min: " << arr.min() << std::endl;

    int* sliced = arr.slice(5, 10);

    std::cout << "Slice(5,10): ";
    for (int i = 0; i <= 10 - 5; i++)
        std::cout << sliced[i] << " ";
    std::cout << std::endl;

    delete[] sliced;

    return 0;
}
