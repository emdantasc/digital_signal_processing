/*
 * Complex.h
 *
 *  Created on: 3 de out de 2018
 *      Author: emdan
 */

#ifndef COMPLEX_H_
#define COMPLEX_H_

class Complex {
private:
	double real, imaginary;
public:
	Complex(double re=0, double im=0);
	Complex(const Complex& A);

	void set(double re, double im);

	Complex inline operator=(const Complex& A){return Complex(A);}
	Complex operator +(const Complex& A);
	Complex operator -(const Complex& A);
	Complex operator *(const Complex& A);
	Complex jmul();
	Complex twiddle(int n, int k, int N);

	void print();

	void test();

	virtual ~Complex();
};

#endif /* COMPLEX_H_ */
