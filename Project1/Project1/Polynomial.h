#pragma once
#include <iostream>
using namespace std;

class Polynomial {

private:
	int _degree;
	double* _polynom;
	static int _max_degree;

public:
	Polynomial();
	Polynomial(int);
	Polynomial(const double* c, int);
	Polynomial(const Polynomial& a);
	~Polynomial();
	static int getMaxDegree();
	void print() const;
	void setCoeff(int a, double b);
	double getDegree(bool what) const;
	double getCoeff(int index) const;
	void verifymaxdegree() const;
};
