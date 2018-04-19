//
// Created by Ewa on 06.03.2018.
//

#ifndef PROJEKT1_COMPLEX_H
#define PROJEKT1_COMPLEX_H

#include <iostream>
template <typename Tre, typename Tim>
class Complex {
private:
	Tre re;
	Tim 
public:
	Complex();
	Complex(Tre r, Tim i);
	Complex(const Complex &com); //konstruktor kopiujacy
	Complex(Tre r);
	~Complex();

	Tre getRe() const;
	Tim getIm() const;
	void ustaw(Tre r, Tim i);
	double modul();
	double argument();

	friend std::ostream &operator<<(std::ostream &wyjscie, const Complex &z);
	friend Complex operator+(const Complex &z1, const Complex &z2);

	friend Complex operator-(const Complex &z1, const Complex &z2);

	friend Complex operator*(const Complex &z1, const Complex &z2);

	//_zwracany_typ_ & operator +=( const _typ_ & );
	Complex &operator+=(const Complex &z);

	Complex &operator-=(const Complex &z);

	Complex &operator*=(const Complex &z);
};

#endif //PROJEKT1_COMPLEX_H