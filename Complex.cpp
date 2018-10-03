/*
 * Complex.cpp
 *
 *  Created on: 3 de out de 2018
 *      Author: emdan
 */

#include "Complex.h"
#include <cmath>
#include <iostream>

using namespace std;

Complex::Complex(double re, double im){
	this->real=re;
	this->imaginary=im;
	cout<<"Set constructor"<<endl;
}

Complex::Complex(const Complex& A){
	this->real=A.real;
	this->imaginary=A.imaginary;
}

void Complex::set(double re, double im){
	this->real=re;
	this->imaginary=im;
}

Complex Complex::operator +(const Complex& A){
	double re=this->real+A.real;
	double im=this->imaginary+A.imaginary;
	Complex B(re, im);
	return B;
}

Complex Complex::operator-(const Complex& A){
	return Complex(this->real-A.real,this->imaginary-A.imaginary);
}

Complex Complex::operator*(const Complex& A){
	return Complex(this->real*(A.real) - this->imaginary*(A.imaginary),this->real*(A.imaginary) + this->imaginary*(A.real));
}

void Complex::print(){
	cout<<"Real= "<<this->real<<" Imaginary= "<<this->imaginary<<endl;
}

Complex::~Complex() {}

