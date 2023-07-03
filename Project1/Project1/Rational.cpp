#include <iostream>
#include "Rational.h"

using namespace std;


void Rational::print() const {

	if (_nom.getDegree(true) == 0 && _denom.getDegree(true) == 0) {

		cout << "polynomial = 0" << endl;
		cout << "--------------------------" << endl;
		cout << "polynomial = 1" << endl;
		return;
	}

	getNom().print();
	cout << "--------------------------" << endl;
	getDenom().print();
}

Rational::Rational() {}


Rational::Rational(const Polynomial& a, const Polynomial& b) : _nom(a) , _denom(b) {
	if (_denom.getDegree(true) < 0)
	{
		_nom = 0;
		_denom = 0;
	}
	
}

const Polynomial& Rational::getNom() const {
	return _nom;
}

const Polynomial& Rational::getDenom() const {
	return _denom;
}
