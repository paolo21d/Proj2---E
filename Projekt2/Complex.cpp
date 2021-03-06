//
// Created by Ewa on 06.03.2018.
//

#include "Complex.h"
#include <cmath>

using namespace std;
template <typename Tre, typename Tim>
Complex<Tre, Tim>::Complex(Tre r, Tim i) {
	//cout<<"Konstruktor inicjujacy"<<endl;
	re = r;
	im = i;
}
template <typename Tre, typename Tim>
Complex<Tre, Tim>::Complex() {
	re = 0;
	im = 0;
}
template <typename Tre, typename Tim>
Complex<Tre, Tim>::Complex(Tre r) {
	re = r;
	im = 0;
}
template <typename Tre, typename Tim>
Complex<Tre, Tim>::Complex(const Complex &com) {
	re = com.re;
	im = com.im;
}
template <typename Tre, typename Tim>
Complex<Tre, Tim>::~Complex() {
	//cout << "Destruktor " << this << endl;
}

/////////Metody
template <typename Tre, typename Tim>
double Complex<Tre, Tim>::modul() {
	return sqrt(re * re + im * im);
}

template <typename Tre, typename Tim>
double Complex<Tre, Tim>::argument() {
	if (this->modul() == 0) {
		cout << "Modul=0, brak argumentu" << endl;
		return 0;
	}
	return asin(im / this->modul());
}

template <typename Tre, typename Tim>
void Complex<Tre, Tim>::ustaw(double r, double i) {
	re = r;
	im = i;
}

template <typename Tre, typename Tim>
double Complex<Tre, Tim>::getIm() const {
	return this->im;
}

template <typename Tre, typename Tim>
double Complex<Tre, Tim>::getRe() const {
	return this->re;
}

//przeciazenia operatorow
template <typename Tre, typename Tim>
Complex<Tre, Tim> operator+(const Complex &z1, const Complex &z2) {
	//Complex z (z1.getRe()+z2.getRe(), z1.getIm()+z2.getIm());
	//return  z;
	//return  Complex (z1.getRe()+z2.getRe(), z1.getIm()+z2.getIm())
	return Complex<Tre, Tim> (z1.re + z2.re, z1.im + z2.im);
}

Complex operator-(const Complex &z1, const Complex &z2) {
	return Complex(z1.re - z2.re, z1.im - z2.im);
}

Complex operator*(const Complex &z1, const Complex &z2) {
	double r = z1.re * z2.re - z1.im * z2.im;
	double i = z1.re * z2.im + z1.im * z2.re;
	//double r = z1.getRe() * z2.getRe() - z1.getIm() * z2.getIm();
	//double i = z1.getRe() * z2.getIm() + z1.getIm() * z2.getRe();
	return Complex(r, i);
}

/*Complex &operator+=(Complex &z1, Complex &z2) {
Complex z(z1.getRe() + z2.getRe(), z1.getIm() + z2.getIm());
return z;
}

Complex &operator+=(Complex &z1, double r) {
Complex z(z1.getRe() + r, z1.getIm());
return z;
}

Complex &operator+=(double r, Complex &z1) {
Complex z(z1.getRe() + r, z1.getIm());
return z;
}*/
template <typename Tre, typename Tim>
Complex &Complex<Tre, Tim>::operator+=(const Complex &z) {
	this->re += z.re;
	this->im += z.im;
	return *this;
}

template <typename Tre, typename Tim>
Complex &Complex<Tre, Tim>::operator-=(const Complex &z) {
	this->re -= z.re;
	this->im -= z.im;
	return *this;
}

template <typename Tre, typename Tim>
Complex &Complex<Tre, Tim>::operator*=(const Complex &z) {
	this->re = this->re * z.re - this->im * z.im;
	this->im = this->re * z.im + this->im * z.re;
	return *this;
}

ostream &operator<<(ostream &wyjscie, const Complex &z) {
	if (z.getIm() > 0)
		return wyjscie << z.getRe() << "+" << z.getIm() << "i";
	else if (z.getIm() < 0)
		return wyjscie << z.getRe() << "" << z.getIm() << "i";
	else
		return wyjscie << z.getRe();
}