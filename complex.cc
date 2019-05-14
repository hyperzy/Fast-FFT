//
// Created by brian on 11/20/18.
//

#include "complex.h"

#include <cmath>

const float PI = 3.14159265358979f;

Complex::Complex() : real(0.0f), imag(0.0f) {}

Complex::Complex(float r) : real(r), imag(0.0f) {}

Complex::Complex(float r, float i) : real(r), imag(i) {}

Complex Complex::operator+(const Complex &b) const {
    Complex c;
    c.real = real + b.real;
    c.imag = imag + b.imag;
    return c;
}

Complex Complex::operator-(const Complex &b) const {
    Complex c;
    c.real = real - b.real;
    c.imag = imag - b.imag;
    return c;
}

Complex Complex::operator*(const Complex &b) const {
    Complex c;
    c.real = real * b.real - imag * b.imag;
    c.imag = imag * b.real + real * b.imag;
    return c;
}

Complex Complex::mag() const {
    Complex c(sqrtf(real * real + imag * imag), 0.0f);
    return c;
}

Complex Complex::angle() const {
    Complex c(atan2f(imag, real), 0.0f);
    return c;
}

Complex Complex::conj() const {
    Complex c(real, -imag);
    return c;
}

std::ostream& operator<< (std::ostream& os, const Complex& rhs) {
    Complex c(rhs);
    if(fabsf(rhs.imag) < 1e-10) c.imag = 0.0f;
    if(fabsf(rhs.real) < 1e-10) c.real = 0.0f;

    if(c.imag == 0) {
        os << c.real;
    }
    else {
        os << "(" << c.real << "," << c.imag << ")";
    }
    return os;
}