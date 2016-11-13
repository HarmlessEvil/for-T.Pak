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
    ~Matrix();
    vector<double>& operator[](int i);
    friend istream& operator>>(istream& is, Matrix& x);
    friend ostream& operator<<(ostream& os, Matrix& x);
	friend ifstream& operator>>(ifstream& is, Matrix& x);
    unsigned int size();
protected:
    vector<vector<double>> tab;
};

vector<double> solve(Matrix a);

#endif //NM_DIVSUB_MATRIX_HPP
