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
	this->real=new double;
	this->imaginary=new double;
	*this->real=re;
	*this->imaginary=im;
}

Complex::Complex(const Complex& A){
	this->real=new double;
	this->imaginary=new double;
	*this->real=*A.real;
	*this->imaginary=*A.imaginary;
}

void Complex::set(double re, double im){
	*this->real=re;
	*this->imaginary=im;
}

void Complex::operator =(const Complex& A){
	*this->real=*A.real;
	*this->imaginary=*A.imaginary;
}

Complex Complex::operator +(const Complex& A){
	return Complex(*this->real+*A.real,*this->imaginary+*A.imaginary);
}

Complex Complex::operator-(const Complex& A){
	return Complex(*this->real-*A.real,*this->imaginary-*A.imaginary);
}

Complex Complex::operator*(const Complex& A){
	return Complex(*this->real*(*A.real) - *this->imaginary*(*A.imaginary),*this->real*(*A.imaginary) + *this->imaginary*(*A.real));
}

Complex Complex::operator*(const Complex* A){
	return Complex(*this->real*(*A->real) - *this->imaginary*(*A->imaginary),*this->real*(*A->imaginary) + *this->imaginary*(*A->real));
}

Complex Complex::twiddle(int n, int k, int N){
	if(n==0){return Complex(0,1)*this;}
	else{return Complex(cos((double)(2*M_PI*n*k/N)),-sin((double)(2*M_PI*n*k/N)))*this;}
}

void Complex::jmul(void){
	double aux=*this->real;
	*this->real=-(*this->imaginary);
	*this->imaginary=aux;
}

void Complex::print(){
	cout<<"Real address= "<<this->real<<" Imaginary address= "<<this->imaginary<<endl;
	cout<<"Real value= "<<*this->real<<" Imaginary value= "<<*this->imaginary<<endl;
}

Complex::~Complex() {
	delete this->real;
	delete this->imaginary;
}

