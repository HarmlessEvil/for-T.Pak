#include <iostream>
#include "Matrix.hpp"

int main() {
    unsigned int size;

    std::cout << "Enter the dimension of the matrix: ";
    std::cin >> size;
    std::cout << "Matrix has to be non-singular!\n";
    Matrix a(size);

    std::cin >> a;

    std::vector<double> ans = solve(a);

    return 0;
}