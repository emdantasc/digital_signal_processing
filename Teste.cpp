/*
 * Teste.cpp
 *
 *  Created on: 3 de out de 2018
 *      Author: emdan
 */
#include "Complex.h"
#include <iostream>

using namespace std;

int main(void){
	Complex A, B, C, D, E, F;

	A.set(1,2);
	B.set(3,4);
	C.set(1,1);

	D=A+B;
	E=B*C;
	F=C-C;

	D.print();
	E.print();
	F.print();

	return 0;
}
