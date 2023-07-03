#pragma once
#include "Polynomial.h"
#include <iostream>
using namespace std;

class Rational {
private:
	Polynomial _nom;
	Polynomial _denom;
public:
	void print() const;
	Rational(const Polynomial& a,const Polynomial& b);
	Rational();
	const Polynomial& getNom() const;
	const Polynomial& getDenom() const;

};




