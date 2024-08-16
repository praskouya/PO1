#ifndef __Complex_H__
#define __Complex_H__
#include <iostream>
#include <math.h>

using namespace std;

class Complex {
  private:
	double Real, Imag;

  public:
	Complex(double co = 0, double imaginary = 0) : Real(co), Imag(imaginary){};

	Complex& operator=(const Complex& s)
	{
		Real = s.Real;
		Imag = s.Imag;
		return *this;
	};

	Complex operator-() const
	{
		return Complex(-Real, -Imag);
	};

	Complex& operator=(double co)
	{
		Real = co;
		Imag = 0;
		return *this;
	};

	Complex operator+(const Complex& co) const
	{
		Complex n;
		n.Real = this->Real + co.Real;
		n.Imag = this->Imag + co.Imag;
		return n;
	};

	Complex& operator-=(Complex co)
	{
		Real -= co.Real;
		Imag -= co.Imag;
		return *this;
	};

	Complex& operator/=(Complex co)
	{
		double denominator = co.Real * co.Real + co.Imag * co.Imag;
		double Real_result =
			(this->Real * co.Real + this->Imag * co.Imag) / denominator;
		double Imag_result =
			(this->Imag * co.Real - this->Real * co.Imag) / denominator;
		this->Real = Real_result;
		this->Imag = Imag_result;
		return *this;
	};

	double abs()
	{
		return sqrt(this->Real * this->Real + this->Imag * this->Imag);
	}

	double phase()
	{
		double absolute_value;
		absolute_value = abs();
		if (absolute_value == 0) {
			cout << "Argument jest nieokreslony";
			exit(1);
		}
		double angle = atan(this->Imag / this->Real);
		if (this->Real > 0) {
			return angle;
		}
		else if (this->Real < 0) {
			return angle + M_PI;
		}
		else {
			if (this->Imag < 0) {
				return (-1 * M_PI_2);
			}
			return M_PI_2;
		}
		
	}

	Complex conj()
	{
		Complex conjugate;
		conjugate.Real = this->Real;
		conjugate.Imag = this->Imag * (-1);
		return conjugate;
	}

	friend Complex operator-(Complex, Complex);
	friend Complex operator/(Complex, Complex);
	friend ostream& operator<<(ostream& s, const Complex& c)
	{
		s << "(" << c.Real << "," << c.Imag << ")";
		return s;
	};
};

inline Complex operator-(Complex s1, Complex s2)
{
	Complex n(s1);
	return n -= s2;
}

Complex operator/(Complex quotient, Complex divisor)
{
	Complex answer;
	if (divisor.Real == 0 && divisor.Imag == 0) {
		printf("Division by zero");
		exit(1);
	}
	double denominator =
		divisor.Real * divisor.Real + divisor.Imag * divisor.Imag;
	answer.Real =
		(quotient.Real * divisor.Real + quotient.Imag * divisor.Imag) /
		denominator;
	answer.Imag =
		(quotient.Imag * divisor.Real - quotient.Real * divisor.Imag) /
		denominator;
	return answer;
}

#endif /* __Complex_H__ */
