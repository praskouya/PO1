#include <iostream>
#pragma once
using namespace std;

class Poly {
  private:
    int degree;
    float* coefficients;

  public:
    Poly(float scalar_number = 0);
    Poly(const Poly& p1);
    ~Poly();

    friend Poly operator-(const Poly& p1, const Poly& p2);
    friend Poly operator+(const Poly& p1, const Poly& p2);
    friend Poly operator*(const Poly& p1, const Poly& p2);
    friend ostream& operator<<(ostream& os, const Poly& p1);

    float operator()(float x) const;
    Poly& operator=(const Poly& p1);

    float& operator[](int x);
    float operator[](int x) const;
};
