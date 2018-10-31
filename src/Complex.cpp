/*=============================================================================
#     FileName: Complex.cpp
#         Desc: Source code file for the libcomplex library.
#       Author: Abdul Wasay
#        Email: wasaya@acm.org
#     HomePage: https://knightturing.github.io/
#      Version: 1.0
#   LastChange: 2018-10-30 14:40:35
#      History:
=============================================================================*/

#include"../include/Complex.h"
#include<iostream>
using namespace std;

Complex::Complex()
{
	real = 0;

	imag = 0;

}
	
Complex::Complex(int r, int i)
{
	real = r;

	imag = i;
}

Complex Complex::add(Complex c1, Complex c2)
{
	Complex c3(0,0);

	c3.real = c1.real + c2.real;



	c3.imag = c1.imag + c2.imag;
	return c3;
}

int Complex::getReal()
{
	return real;
}

int Complex::getImag()
{
	return imag;
}
bool operator==(const Complex& a, const Complex& b)
{
	if(a.real == b.real)
	{
		if(a.imag == b.imag)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;	
	}
	return true;
}


	
