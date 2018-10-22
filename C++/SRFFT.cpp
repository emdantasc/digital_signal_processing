/*
 * SRFFTM.cpp
 *
 *  Created on: 4 de out de 2018
 *      Author: emdan
 */
#include<cstring>
#include<iostream>
#include"Complex.h"

using namespace std;

void Butterfly1(Complex A[], int begin, int end, int depth);
void Butterfly2(Complex A[], int begin, int end, int depth);

int main(void) {

}

void Butterfly1(Complex A[], int begin, int end, int depth) {
	int middle = (begin - end) / 2;
	for (int i = begin; i <= begin + middle; i++) {
		A[i] = A[i] + A[i + middle + 1];
		if (i < (begin + middle) / 2) {
			A[i + middle + 1] = A[i] - A[i + middle + 1];
		} else {
			A[i + middle + 1] = (A[i] - A[i + middle + 1]).jmul();
		}
	}
}

void Butterfly2(Complex A[], int begin, int end, int depth) {
	int middle = (begin - end) / 2;
	for (int i = begin; i <= begin + middle; i++) {
		A[i] = A[i] + A[i + middle + 1];
		if (i < (begin + middle) / 2) {
			A[i + middle + 1] = A[i] - A[i + middle + 1];
		} else {
			A[i + middle + 1] = (A[i] - A[i + middle + 1]).jmul();
		}
	}
}
;
