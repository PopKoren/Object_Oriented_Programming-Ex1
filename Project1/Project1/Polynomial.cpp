#include <iostream>
#include "Polynomial.h"

using namespace std;

int Polynomial::_max_degree = 0;

Polynomial::Polynomial() {

	_degree = 0;
	_polynom = new (nothrow) double[1] {0};


	this->verifymaxdegree();

}	


Polynomial::Polynomial(int degree) {

	_degree = degree;
	_polynom = new (nothrow) double[_degree + 1] {0};


	this->verifymaxdegree();

}

Polynomial::Polynomial(const double* c, int a) {

	_degree = a;
	_polynom = new (nothrow) double[_degree + 1] {0};
	

	for (int i = 0; i <= a; i++) {
		_polynom[i] = c[i];
	}

	this->verifymaxdegree();


}

Polynomial::Polynomial(const Polynomial& a) {
	this->_degree = a._degree;
	this->_polynom = new (nothrow) double[_degree + 1];

	for (int i = 0; i <= _degree; i++) {
		_polynom[i] = a._polynom[i];
	}
}


int Polynomial::getMaxDegree() {
	return _max_degree;
}

void Polynomial::print() const {

	if (_degree <= 1) {
		cout << "polynomial = 0" << endl;
		return;
	}

	int revCount = _degree;

	for (int i = _degree; i > 0; i--) {
		if (_polynom[i] == 0) {
			revCount--;
		}
		else {
			break;
		}
	}

	if (revCount == 0) {
		cout << "polynomial = 0" << endl;	
		return;
	}

	cout << "polynomial = " << _polynom[0];

	for (int i = 1; i <= revCount; i++) {

		cout << "+" << _polynom[i] << "X^" << i;

	}

	cout << endl;

}


void Polynomial::setCoeff(int a, double b) {
	_polynom[a] = b;
	this->verifymaxdegree();

}

double Polynomial::getDegree(bool what) const {
	if (what == false) {
		return _degree;
	}
	else {
		int count = 0;
		for (int i = 0; i < _degree; i++) {
			if (_polynom[i] != 0) {
				count++;
			}
		}

		return count;
	}
}

double Polynomial::getCoeff(int index) const {
	if (index < 0 || index > _degree) {
		return -12345.5;
	}
	return _polynom[index];
}

void Polynomial::verifymaxdegree() const {

	int revCount = getDegree(true) + 1;

	for (int i = revCount; i > 0; i--) {
		if (_polynom[i] != 0) {
			break;
		}
		else
		{
			revCount--;
		}
	}
	if (revCount > _max_degree) {
		_max_degree = revCount;
	}
}

Polynomial::~Polynomial() {
	delete[] _polynom;
}
