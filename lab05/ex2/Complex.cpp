#include "Complex.h"
#include <cmath>


Complex::Complex() : Complex(0, 0) {}

Complex::Complex(double real, double imag) {
    real_data = real;
    imag_data = imag;
}

bool Complex::is_real() const {
    return imag() == 0;
}

double Complex::real() const {
    return real_data;
}

double Complex::imag() const {
    return imag_data;
}

double Complex::abs() const {
    return sqrt(real() * real() + imag() * imag());
}

Complex Complex::conjugate() const {
    return { real(), -imag() };
}



//de  mine
Complex operator+(const Complex& l, const Complex& r) {
    
    return Complex(l.real() + r.real(), l.imag() + r.imag());
}

Complex operator+(const Complex& l, double r) {
    return Complex(l.real() + r, l.imag());
}

Complex operator+(double l, const Complex& r) {
    return Complex(l + r.real(), r.imag());
}



Complex operator-(const Complex& l, const Complex& r) {
     return Complex(l.real() - r.real(), l.imag() - r.imag());
}

Complex operator-(const Complex& l, double r) {
    return Complex(l.real() - r, l.imag());
}

Complex operator-(double l, const Complex& r) {
    return Complex(l - r.real(), r.imag());
}


Complex operator*(const Complex& l, const Complex& r) {
    return Complex(l.real() * r.real(), l.imag() * r.imag());
}

Complex operator*(const Complex& l, double r) {
    return Complex(l.real() * r, l.imag());
}

Complex operator*(double l, const Complex& r) {
    return Complex(l * r.real(), r.imag());
}

//gata cele  9


//op unar
Complex operator-(const Complex& obj) {
    return Complex(-obj.real(), -obj.imag());
}


bool operator== (const Complex& l, const Complex& r){
    printf("Operatorul ==\n");
    if ((l.real() == r.real()) && (l.imag() == r.imag()))
        return true;
    else
        return false;

}

bool operator== (const Complex& l, const Complex& r) {
    printf("Operatorul !=\n");
    if ((l.real() != r.real()) && (l.imag() != r.imag()))
        return true;
    else
        return false;

}
