#include "Poly.h"
#include <cmath>

Poly::Poly(float scalar_number)
{
    this->degree = 0;
    this->coefficients = new float[1];
    coefficients[0] = scalar_number;
}

Poly::Poly(const Poly& p1)
{
    degree = p1.degree;
    coefficients = new float[degree + 1];
    for (int i = 0; i <= degree; i++) {
        coefficients[i] = p1.coefficients[i];
    }
}

Poly::~Poly()
{
    delete[] this->coefficients;
}

Poly operator-(const Poly& p1, const Poly& p2)
{
    int bigger_size, smaller_size;
    if (p1.degree >= p2.degree) {
        bigger_size = p1.degree;
        smaller_size = p2.degree;
    }
    else {
        bigger_size = p2.degree;
        smaller_size = p1.degree;
    }

    Poly difference;

    for (int i = 0; i <= smaller_size; i++) {
        difference[i] = p1[i] - p2[i];
    }

    if (p1.degree > p2.degree) {
        for (int i = smaller_size + 1; i <= bigger_size; i++) {
            difference[i] = p1[i];
        }
    }
    else if (p1.degree < p2.degree) {
        for (int i = smaller_size + 1; i <= bigger_size; i++) {
            difference[i] = p2[i];
        }
    }
    return difference;
}

Poly operator+(const Poly& p1, const Poly& p2)
{
    Poly sum;
    if (p1.degree >= p2.degree) {
        for (int i = 0; i <= p1.degree; i++) {
            sum[i] = p1[i];
        }
        for (int i = 0; i <= p2.degree; i++) {
            sum[i] += p2[i];
        }
    }
    else {
        for (int i = 0; i <= p2.degree; i++) {
            sum[i] = p2[i];
        }
        for (int i = 0; i <= p1.degree; i++) {
            sum[i] += p1[i];
        }
    }

    return sum;
}

float& Poly::operator[](int x)
{
    if (x > degree) {
        float* greater_degree = new float[x + 1];
        for (int i = 0; i <= n; i++) {
            greater_degree[i] = coefficients[i];
        }
        for (int i = n + 1; i <= x; i++) {
            greater_degree[i] = 0;
        }
        delete[] coefficients;
        coefficients = greater_degree;
        degree = x;
    }

    return coefficients[x];
}

float Poly::operator[](int x) const
{
    return coefficients[x];
}

Poly operator*(const Poly& p1, const Poly& p2)
{
    Poly product;

    for (int i = 0; i <= p1.degree; i++) {
        for (int j = 0; j <= p2.degree; j++) {
            product[i + j] += p1[i] * p2[j];
        }
    }

    return product;
}

ostream& operator<<(ostream& os, const Poly& p1)
{
    bool printed = false;
    for (int i = p1.degree; i > 0; i--) {
        if (p1[i] != 0) {
            printed = true;

            if (p1[i] != 1) {
                os << abs(p1.coefficients[i]);
            }

            os << "x";

            if (i != 1) {
                os << "^" << i;
            }

            int x = -1;
            for (int j = i - 1; j >= 0; j--) {
                if (p1[j] != 0) {
                    x = j;
                    break;
                }
            }

            if (x != -1) {
                if (p1[x] >= 0) {
                    os << " + ";
                }
                else {
                    os << " - ";
                }
            }
        }
    }

    if (p1.coefficients[0] != 0 || !printed) {
        os << abs(p1.coefficients[0]);
    }

    return os;
}

float Poly::operator()(float x) const
{
    float value = 0;
    for (int i = 0; i <= degree; i++) {
        value += (float)pow(x, i) * coefficients[i];
    }
    return value;
}

Poly& Poly::operator=(const Poly& p1)
{
    if (degree != p1.degree) {
        delete[] coefficients;
        coefficients = new float[p1.degree + 1];
        degree = p1.degree;
    }

    for (int i = 0; i <= p1.degree; i++) {
        coefficients[i] = p1.coefficients[i];
    }

    return *this;
}
