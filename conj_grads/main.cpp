#include "includes/Matrix.hpp"

int main() {
	vector<double> b;
	Matrix A(10);

	ifstream fin("input.txt");
	fin >> A;

	b = A.quadratize();
}