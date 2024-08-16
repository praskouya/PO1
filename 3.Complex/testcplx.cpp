#include <iostream>
using namespace std;
#include "complex.h"

void TestSubstraction(const Complex& Co1, const Complex& Co2);

void TestPhase(const Complex Co);

int main()
{
	Complex a(0.0, 15), b(0, 13), c, second_quarter(-8, 13),
		third_quarter(-6, -2), fourth_quarter(16, -15);

	c = 10;

	cout << "C: " << c << endl;
	c = -a;
	cout << "A: " << a << "-A: " << c << endl;
	c = a + b;
	c = c - Complex(10);
	cout << "A + B - C:" << c << endl;
	c = 10 - a;
	(c -= b) -= 10;
	cout << c << endl;

	TestSubstraction(a, b);
	a /= b;
	cout << "Division result (/= ) : " << a << endl;

	TestPhase(a);
	TestPhase(second_quarter);
	TestPhase(third_quarter);
	TestPhase(fourth_quarter);

	Complex conj_a = a.conj();
	cout << "The complex conjugate of a: " << conj_a << endl;

	return 0;
}

void TestSubstraction(const Complex& Co1, const Complex& Co2)
{
	Complex division_complex = Co1 / Co2;
	cout << "Division result (two complex numbers a = " << Co1 << " b =" << Co2
		 << ") : " << division_complex << endl;
	Complex division_double = 2 / Co1;
	cout << "Division result (a double and a complex number d = 2  a = " << Co1
		 << " ) : " << division_double << endl;
}

void TestPhase(Complex Co)
{
	double phase = Co.phase();
	cout << "The phase of  " << Co << " is " << phase << endl;
}
