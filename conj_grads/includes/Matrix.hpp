//
// Created by Alexander on 06.10.2016.
//

#ifndef NM_DIVSUB_MATRIX_HPP
#define NM_DIVSUB_MATRIX_HPP

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Matrix {
public:
    Matrix (unsigned n);
	Matrix() = default;
    ~Matrix();

    vector<double>&  operator[](int i);
	vector<double>   operator()(unsigned  i);
    friend istream&  operator>>(istream& is, Matrix& x);
    friend ostream&  operator<<(ostream& os, Matrix& x);
	friend ifstream& operator>>(ifstream& is, Matrix& x);

	Matrix			 operator*(Matrix& x);
	vector<double>	 operator*(vector<double>& x);
	Matrix			 operator*(double x);

	vector<double>	 quadratize();
	Matrix		     transpose();
    unsigned int     size();
protected:
    vector<vector<double>> tab;
};

vector<double> solve(Matrix a);

vector<double> vsMul(vector<double>& lhs, double rhs);
double scalarMul(vector<double>& lhs, vector<double>& rhs);

#endif //NM_DIVSUB_MATRIX_HPP
