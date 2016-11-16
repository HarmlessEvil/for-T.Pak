#include "includes/Matrix.hpp"

int main() {
	vector<double> b;
	Matrix A(10);
	Matrix AT;

	ifstream fin("input.txt");
	fin >> A;

	b = A.quadratize();
	AT = A.transpose();


}
