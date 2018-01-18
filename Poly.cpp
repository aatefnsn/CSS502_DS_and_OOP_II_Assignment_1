// ------------------------------------------------ Poly.cpp -------------------------------------------------------
//-
// Programmer Name: Ahmed Nada 
//Course Section Number: CSS-502
// Creation Date: 01/15/2018
// Date of Last Modification: 01/19/2018
// --------------------------------------------------------------------------------------------------------------------
// Purpose - a brief statement of the program's function
//
// This file is the cpp source file of the class Poly which defines a Polynomial and overrides a few operators. the cpp file has the implementation of the required  
// constructor, destructor, methods and operators overlad required 
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// the constructor of only coeffiecient will assume an exponent of 0.
// --------------------------------------------------------------------------------------------------------------------

#include "pch.h"
#include "Poly.h"


// ------------------------------------Poly(int coefficient, int largest_exponent)-----------------------------------------------
// Description: constructor
// ---------------------------------------------------------------------------------------------------

Poly::Poly(int coefficient, int largest_exponent)
{ // largest component must be +ve value 
	this->largest_exponent = abs(largest_exponent); // taking the abs of the exponent to make sure the Poly only deals with +ve exponents
	this->coefficient = coefficient;
	this->array = new int[abs(largest_exponent) + 1]; // creating the dynamic array of size exponent +1 since exponents start at 0
	for (int i = 0; i <= abs(largest_exponent); i++) {
		this->array[i] = 0;    // Initialize all elements to zero.
	}
	this->array[abs(largest_exponent)] = coefficient; // setting the polynomial term with the desired coeffiecient at the exponent array index
}

// ------------------------------------Poly(int coefficient)-----------------------------------------------
// Description: constructor
// ---------------------------------------------------------------------------------------------------

Poly::Poly(int coefficient) 
{ // assume the exponent or power is 0
	this->largest_exponent = 0; // again setting exponennt to 0 if only coeffeicient is given to create the polynomial
	this->coefficient = coefficient; // initial coeffiecient of the polynomial

	this->array = new int[1]; // create array of size 1
	for (int i = 0; i <= 0; i++) {
		this->array[i] = 0;    // Initialize all elements to zero.
	}
	this->array[0] = coefficient; // setting coeffeicinet 
}

// ------------------------------------Poly()-----------------------------------------------
// Description: empty constructor
// ---------------------------------------------------------------------------------------------------


Poly::Poly() 
{ // empty constructor 0 coeffecient and 0 exponent
	this->coefficient = 0;
	this->largest_exponent = 0;
	this->array = new int[1]; // array of size 1 to hold a polynomial 0 
	//this->array = new int[2];
	for (int i = 0; i <= 0; i++) {
		this->array[i] = 0;    // Initialize all elements to zero.
	}	
}


// ------------------------------------Poly(const Poly& pol)-----------------------------------------------
// Description: copy constructor
// ---------------------------------------------------------------------------------------------------


Poly::Poly(const Poly& poly) 
{ //copy constructor
	this->coefficient = poly.coefficient; // copy member variable
	this->largest_exponent = poly.largest_exponent;  // copy member variable
	this->array = new int[poly.largest_exponent+1]; // create a new array
	for (int i = 0; i <= poly.largest_exponent; i++) {
		this->array[i] = poly.array[i];    // copy elements from input polynomial array to the new copy polynoial array
	}
}


// ------------------------------------~Poly()-----------------------------------------------
// Description: destructor
// ---------------------------------------------------------------------------------------------------


Poly::~Poly() 
{
	//cout << "deleting Polynomial array" << endl;
	delete[] array; //delete array
	array = nullptr; //or delete array to delete the array pointer or to let it point to null;
}

// ------------------------------------getCoeff(int num)-----------------------------------------------
// Description: Method to return the coeffecient of a given exponent
// ---------------------------------------------------------------------------------------------------


int Poly::getCoeff(int num) 
{ // method to get the coeffieicient of exponent as input
	if (num >= 0 && num <= this->largest_exponent) { // check if the exponent is within the range of polynomial or not 
		int coeff = this->array[num]; // if it is range, set the coeff to the number in the array in the index of that exponent 
		if (coeff > -33686019 && coeff !=0) {
			return this->array[num]; // return the coefficient 
		}
		else { // if it is in the range of the polynomial but maybe the coeffeicient is zero
			cout << "this Exponent does not exist in the polynomial" << endl;
			return 0; // return 0
		}
	}
	else { // outside the range of the polynomial
		cout << "this Exponent does not exist in the polynomial, out of range" << endl;
		return 0;
	}
}

// ------------------------------------setCoeff(int coeff, int exp)-----------------------------------------------
// Description: Method to set a polyomial pair coeffiencient and exponennt
// ---------------------------------------------------------------------------------------------------


void Poly::setCoeff(int coeff, int exp) 
{ // method to set a coeff with a given exponent 
	if ((abs(exp)) > this->largest_exponent) { // if input exponent is larger than the polynomial current largest exponent then we need to extend the array
		int* newarray = new int[(abs(exp)) + 1]; // create a new extended array to fit the new coeffeicient 
		for (int i = 0; i <= (abs(exp));i++) {
			newarray[i] = 0; // intitialize the array to 0s
		}
		for (int i = 0; i <= this->largest_exponent;i++) {
			newarray[i] = this->array[i]; // copy the old values fro mthe old array to the new array
		}
		newarray[(abs(exp))] = coeff; // set the new coeffeicnt with the new exponent
		int * temp = this->array; // set a temp pointer to old array to be bale to delete it 
		this->array = newarray; // set Polynomial array to the new array
		delete[] temp; // delete old array
		temp = nullptr; // delete pointer
		this->largest_exponent = (abs(exp)); // update the largest exponent
	}
	else {
		this->array[abs(exp)] = coeff; // if exponent is within the range of the current polynomial just set the coeffeicient in its place
	}	
}

// ------------------------------------operator>> overload-----------------------------------------------
// Description: Method to overload the cin
// ---------------------------------------------------------------------------------------------------


istream& operator>>(istream &is, Poly &poly) 
{ // cin overload
	bool flag = true;
	int coeff;
	int exp;
	do { // dp-while loop to get the input
		cout << "Enter terms for polynomial.  Enter a coefficient and positive exponent in pairs per line, hit enter to commit or enter -1 -1 to terminate. the Entered polynomial so far is " << poly << endl;
		if (std::cin >> coeff >> exp) { // the input takes a pair of two numbers 
			if (flag = true && coeff) { // if flag is true and coeff is not zero
				if (exp >= 0) { // if exponent is greater than 0
					poly.setCoeff(coeff, exp); // set the coeff using the setcoeff method
				}

				else if (coeff == -1 && exp == -1) { // if -1 -1 pair then terminate the cin
					cout << " End of Input " << endl;
					flag = false;
					break;
				}
				else {
					cout << "exponenet can't be negative, please re-enter your pair only with a positive Exponent" << endl; // if user enter a negative number then display a message and re-try the input
					continue;
				}
			}
		}
	} while (flag = true); // keep it going until the loop breaks using the -1 -1 pair
	return is;
}

// ------------------------------------operator<< overload-----------------------------------------------
// Description: Method to overload the cout
// ---------------------------------------------------------------------------------------------------


ostream& operator<<(ostream &os, const Poly &poly)  // cout overload
{
	bool flag = false;

	for (int i = poly.largest_exponent; i >= 0; i--) { // loop to go over the poly
			if (poly.array[i] > 0 && i > 1) { // if exp greater than 1 and coeff is greater than zero
				os << " +" << poly.array[i] << "x^" << i; // display the power with + sign
				flag = true;
			}
			else if (poly.array[i] < 0 && i > 1) { // if exp greater than 1 and coeff is less than zero
				os << " " << poly.array[i] << "x^" << i; // display with no sign since the coeff will provide its own - sign
				flag = true;
			}
			else if (poly.array[i] > 0 && i == 1) { // if exponnen is one don't display power
				os << " +" << poly.array[i] << "x";
				flag = true;
			}
			else if (poly.array[i] < 0 && i == 1) { // if exponnen is one don't display power
				os << " " << poly.array[i] << "x";
				flag = true;
			}
			else if (poly.array[i] > 0 && i == 0) { // if exponnen is zero display only coeffieicnet 
				os << " +" << poly.array[i];
				flag = true;
			}
			else if (poly.array[i] < 0 && i == 0) { // if exponnen is zero display only coeffieicnet, - ve sign from coeffient if -ve coeffienct 
				os << " " << poly.array[i];
				flag = true;
			}
	}
	if (flag == false) { // if poly is zeros display 0
		os << " 0";
	}
	return os;
}


// ------------------------------------operator+ overload-----------------------------------------------
// Description: Method to overload the addition
// ---------------------------------------------------------------------------------------------------


Poly Poly::operator+(const Poly &poly) const // + overload using the the +=
{
	Poly result = *this;
	result += poly;
	return result;
}

// ------------------------------------operator+= overload-----------------------------------------------
// Description: Method to overload the addition
// ---------------------------------------------------------------------------------------------------


Poly Poly::operator+=(const Poly &poly) // += overload containing the poly addition
{	
	int smallest_exponent;
	if (this->largest_exponent >= poly.largest_exponent) { // if exponnet of poly is bigger than the input poly just add the coeffiecients together in the original array
		smallest_exponent = poly.largest_exponent;
		for (int i = 0; i <= smallest_exponent; i++) {
			this->array[i] = poly.array[i] + this->array[i];
		}
	}
	else {
		smallest_exponent = this->largest_exponent; // if original array is smaller than the inpout then create new array
		int * temparray = new int[poly.largest_exponent+1];
		for (int i = 0; i <= poly.largest_exponent; i++) {
			temparray[i] = 0; // intialize to 0s
		}
		for (int i = 0; i <= smallest_exponent; i++) { // copy the old orignal array into the new resultant array
			temparray[i] = this->array[i];
		}
		int * toBeDeletedArray = this->array; // delete the old array
		this->array = temparray;	// assign the original poly array to the new one
		delete[] toBeDeletedArray;
		for (int i = 0; i <= poly.largest_exponent; i++) {

			this->array[i] = poly.array[i] + this->array[i]; // adding coeffecients
		}
		this->largest_exponent = poly.largest_exponent; // updating the new exponent of the original poly
	}
	return *this; // return the original poly with its array as a resultant
}

// ------------------------------------operator- overload-----------------------------------------------
// Description: Method to overload the subtraction
// ---------------------------------------------------------------------------------------------------


Poly Poly::operator-(const Poly &poly) const
{
	Poly result = *this;
	result -= poly;
	return result;
}

// ------------------------------------operator-= overload-----------------------------------------------
// Description: Method to overload the subtraction
// ---------------------------------------------------------------------------------------------------


Poly Poly::operator-=(const Poly &poly) 
{ // same procedure as addition exceppt that we are subtracting instead of adding the two polynomials
	int smallest_exponent;
	if (this->largest_exponent >= poly.largest_exponent) {
		smallest_exponent = poly.largest_exponent;
		for (int i = 0; i <= smallest_exponent; i++) {
			this->array[i] = this->array[i] - poly.array[i];
		}
	}
	else {
		smallest_exponent = this->largest_exponent;
		int * temparray = new int[poly.largest_exponent + 1];
		for (int i = 0; i <= poly.largest_exponent; i++) {
			temparray[i] = 0;
		}
		for (int i = 0; i <= smallest_exponent; i++) {
			temparray[i] = this->array[i];
		}
		int * toBeDeletedArray = this->array;
		this->array = temparray;
		delete[] toBeDeletedArray;
		for (int i = 0; i <= poly.largest_exponent; i++) {

			this->array[i] = this->array[i] - poly.array[i] ;
		}
		this->largest_exponent = poly.largest_exponent;
	}
	return *this;
}

// ------------------------------------operator* overload-----------------------------------------------
// Description: Method to overload the multiplication
// ---------------------------------------------------------------------------------------------------


Poly Poly::operator*(const Poly &poly) const
{ // * uses the *= overload
	Poly result = *this;
	result *= poly;
	return result;
}


// ------------------------------------operator*= overload-----------------------------------------------
// Description: Method to overload the multiplication
// ---------------------------------------------------------------------------------------------------


Poly Poly::operator*=(const Poly &poly) 
{ // multiplication overload
	int * temparray = new int[poly.largest_exponent + this->largest_exponent + 1]; // two polynomials result is a polynomial of size equal 
	//the sum of the two input polynomials so creating a new array with size equal to the sum of the 2 input polynomials

	for (int k = 0; k <= (poly.largest_exponent + this->largest_exponent); k++) {
		temparray[k] = 0;    // Initialize all elements to zero.
	}

	for (int i = 0; i <= this->largest_exponent; i++) {
		for (int j = 0; j <= poly.largest_exponent; j++) {
			temparray[i + j] += (this->array[i] * poly.array[j]); // do the multiplication of all elements using a nested loop
		}
	}

	int * toBeDeletedArray = this->array;
	this->array = temparray;
	delete[] toBeDeletedArray; // delete old array
	this->largest_exponent = poly.largest_exponent + this->largest_exponent; //updating the largest exponent of the origianl poly
	return *this;
}


// ------------------------------------operator= overload-----------------------------------------------
// Description: Method to overload the assignment operator
// ---------------------------------------------------------------------------------------------------


Poly& Poly::operator=(const Poly &poly) 
{ // operator assignment overload
	if (this == &poly) {
		return *this;  // make sure if both polynomials are the same
	}
	int * newarray = new int[poly.largest_exponent + 1];
	for (int i = 0; i <= poly.largest_exponent; i++) {
		newarray[i] = poly.array[i]; //copy elemnets from input array
	}
	int * temp = this->array;
	this->array = newarray; // assign original array to the newly copied array
	delete[] temp; // delete old array
	this->coefficient = poly.coefficient; //update coeff
	this->largest_exponent = poly.largest_exponent;  // update largest exponent	 
	return *this;
}


// ------------------------------------operator== overload-----------------------------------------------
// Description: Method to overload the equality check
// ---------------------------------------------------------------------------------------------------


bool Poly::operator==(const Poly &poly) const 
{ // equality overload
	if (this->largest_exponent == poly.largest_exponent) { // if sizes are same then compare coef by coeff
		for (int i = 0; i <= this->largest_exponent;i++) {
			if (this->array[i] != poly.array[i]) {
				return false; // if any coeff is not a match return false
			}
		}
	}

	else if (this->largest_exponent < poly.largest_exponent) { // if sizes are different 
		for (int i = 0; i <= this->largest_exponent;i++) {
			if (this->array[i] != poly.array[i]) { // compare value by value till the smallest exponen of both
				return false;
			}
		}
		for (int i = this->largest_exponent+1; i <= poly.largest_exponent;i++) {
			if (poly.array[i] != 0) { // if all match, check the remiaing value of the bigger poly, if the remaining are not zeros then return false .. if remaining are zeros the polys are equal
				return false;
			}
		}
	}

	else if (this->largest_exponent > poly.largest_exponent) { // same as for previos case but swapping the case for which has the larger exponent 
		for (int i = 0; i <= poly.largest_exponent;i++) {
			if (this->array[i] != poly.array[i]) {
				return false;
			}
		}
		for (int i = poly.largest_exponent + 1; i <= this->largest_exponent;i++) {
			if (this->array[i] != 0) {
				return false;
			}
		}
	}

	else { // if anything else
		return false;
	}
	return true;
}

// ------------------------------------operator!= overload-----------------------------------------------
// Description: Method to overload the non-equality check
// ---------------------------------------------------------------------------------------------------



bool Poly::operator!=(const Poly &poly) const 
{ // inequality operator overload
	if (this->largest_exponent != poly.largest_exponent) {
		return true;
	}
	else {
		for (int i = 0; i <= this->largest_exponent;i++) {
			if (this->array[i] != poly.array[i]) {
				return true;
			}
		}
	}
	return false;
}
