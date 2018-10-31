/*=============================================================================
#     FileName: Complex.h
#         Desc: Header for libcomplex library
#       Author: Abdul Wasay
#        Email: wasaya@acm.org
#     HomePage: https://knightturing.github.io/
#      Version: 1.0
#   LastChange: 2018-10-30 14:39:43
#      History:
=============================================================================*/

#ifndef COMPLEX_H
#define COMPLEX_H

class Complex
{
	private:
		int real;
		int imag;
		friend bool operator==(const Complex& a, const Complex &b);
	public:
		Complex();
		Complex(int,int);
		Complex add(Complex, Complex);
		int getReal();
		int getImag();

};
#endif
