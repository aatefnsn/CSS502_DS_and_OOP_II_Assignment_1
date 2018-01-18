// ------------------------------------------------ Poly.h -------------------------------------------------------
//-
// Programmer Name: Ahmed Nada 
//Course Section Number: CSS-502
// Creation Date: 01/15/2018
// Date of Last Modification: 01/19/2018
// --------------------------------------------------------------------------------------------------------------------
// Purpose - a brief statement of the program's function
//
// This file is the header file of the class Poly which defines a Polynomial and overrides a few operators.  
//
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// the constructor of only coeffiecient will assume an exponent of 0.
// --------------------------------------------------------------------------------------------------------------------

#pragma once
#include <stdio.h>
#include <iostream>
using namespace std; 

class Poly 
{
private:
	int coefficient=0; // memeber variable for creating a poly instance
	int largest_exponent=0; // size of the polynomial which resembles the size of the array hoding the polynomial
	int* array = nullptr; // dynamic array to hold the polyomial terms together
public:
	//constructor
	Poly(int coefficient, int largest_exponent); // regular constructor
	Poly(int coefficient); // assume the exponent or power is 0
	Poly(); // empty constructor 0 coeffecient and 0 exponent
	Poly(const Poly& poly); //copy constructor
	
	//destructoer
	~Poly();

	//getters
	int getCoeff(int num); // get coeffeicient of a certain exponenet

	//setters
	void setCoeff(int coeff, int exp); // set a polynomial coeff of a certain exponent

	//Overload	
	Poly operator*(const Poly &poly) const; // multiplication overload
	Poly operator+(const Poly &poly) const; // addition overload
	Poly operator-(const Poly &poly) const; // subtraction overload
	Poly operator*=(const Poly &poly);
	Poly operator+=(const Poly &poly);
	Poly operator-=(const Poly &poly);
	Poly& operator=(const Poly &poly); // operator assignment overload
	bool operator==(const Poly &poly) const; // equality check overload
	bool operator!=(const Poly &poly) const; // non-equality check overload

	friend ostream& operator<<(ostream &os, const Poly &poly); // overloading the cout
	friend istream& operator>>(istream &is, Poly &poly); // overloading the cin
};