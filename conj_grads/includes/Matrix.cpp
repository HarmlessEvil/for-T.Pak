//
// Created by Alexander on 06.10.2016.
//

#include "Matrix.hpp"

Matrix :: Matrix (unsigned  n) {
    tab = vector<vector<double>>(n, vector<double>(n + 1, 0));
}

Matrix Matrix :: operator*(Matrix & x)
{
	unsigned s = size();
	Matrix result = Matrix(s + 1);
	result.quadratize();

	for (unsigned i = 0; i <= s; i++) {
		for (unsigned j = 0; j <= s; j++) {
			for (unsigned k = 0; k <= s; k++) {
				result[i][j] += tab[i][k] * x[k][j];
			}
		}
	}

	return result;
}

vector<double> Matrix :: operator*(vector<double>& x)
{
	unsigned s = size();
	vector<double> result(s + 1, 0);

	for (unsigned i = 0; i <= s; i++) {
		for (unsigned j = 0; j <= s; j++) {
			result[i] += tab[i][j] * x[j];
		}
	}

	return result;
}

Matrix Matrix :: operator*(double x)
{
	unsigned s = size();
	Matrix result(s + 1);
	result.quadratize();

	for (unsigned i = 0; i <= s; i++) {
		for (unsigned j = 0; j <= s; j++) {
			result[i][j] = tab[i][j] * x;
		}
	}

	return result;
}

vector<double> Matrix :: quadratize()
{
	vector<double> result;
	unsigned int s = size();
	if (tab.size() != tab[0].size()) {
		for (unsigned int i = 0; i < s; i++) {
			result.push_back(tab[i][s]);
			tab[i].resize(s);
		}
	}

	return result;
}

Matrix Matrix :: transpose()
{
	unsigned int s = size();
	Matrix result = Matrix(s + 1);
	result.quadratize();
	
	for (unsigned int i = 0; i < s; i++) {
		for (unsigned int j = 0; j < s; j++) {
			result[j][i] = tab[i][j];
		}
	}

	return result;
}

unsigned int Matrix :: size() {
    return tab[0].size() - 1;
}

Matrix :: ~Matrix() {
    for (unsigned i = 0; i < size() + 1; i++) {
        tab[i].clear();
    }
    tab.clear();
}

vector<double>& Matrix :: operator[](int i) {
    return tab[i];
}

vector<double> Matrix :: operator()(unsigned j)
{
	unsigned s = size();
	vector<double> result(s + 1, 0);

	for (unsigned i = 0; i <= s; i++) {
		result[i] = tab[i][j];
	}

	return result;
}

istream& operator>> (istream& is, Matrix& x) {
    unsigned int s = x.size();

    for (unsigned int i = 0; i < s; i++) {
        for (unsigned int j = 0; j < s + 1; j++) {
            if (j == s) {
                cout << "Enter the free member of the string " << i << " ";
            } else {
                cout << "Enter element (" << i << ',' << j << ") ";
            }
            is >> x[i][j];
        }
    }
    return is;
}

ostream& operator<< (ostream& os, Matrix& x) {
    unsigned int s = x.size();

    for (unsigned int i = 0; i < s; i++) {
        for (unsigned int j = 0; j < s + 1; j++) { os << x[i][j] << ' '; }
        os << endl;
    }
    return os;
}

ifstream& operator>>(ifstream& is, Matrix& x)
{
	unsigned int s = x.size();

	for (unsigned int i = 0; i < s; i++) {
		for (unsigned int j = 0; j < s; j++) {
			is >> x[i][j];
			x[i][s] += x[i][j];
		}
	}
	return is;
}

vector<double> solve(Matrix a) {
    int size = (int)a.size();

    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            if ((a[j][i] == 0) || (a[j][i] == 1))
                continue;
            if (i == j) {
                for (int k = size; k >= i; k--) {
                    a[j][k] /= a[j][i];
                }
            } else {
				for (int k = size; k >= i; k--) {
                    a[j][k] = a[j][k] / a[j][i] - a[i][k];
                }
            }
        }
    }

	for (int i = size - 1; i > 0; i--) {
		for (int j = i - 1; j >= 0; j--) {
			a[j][size] -= a[i][size] * a[j][i];
			a[j][i] = 0;
		}
	}

	std::vector<double> res;

	for (int i = 0; i < size; res.push_back(a[i++][size]));

	return res;
}

vector<double> vsMul(vector<double>& lhs, double rhs)
{
	vector<double> result(lhs);

	for (unsigned i = 0; i < lhs.size(); i++) {
		result[i] *= rhs;
	}

	return result;
}

double scalarMul(vector<double>& lhs, vector<double>& rhs)
{
	double result = 0;

	for (unsigned i = 0; i < lhs.size(); i++) {
		result += lhs[i] * rhs[i];
	}

	return result;
}
