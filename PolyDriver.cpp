// Poly.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Poly.h"

int main()
{
	Poly A(6,-4);	// creating Poly A with -ve exponent should be converted to +ve
	int x = A.getCoeff(4); // testing get coefficient of 4 after -4 was convereted to 4 so x =6
	cout << "coeff of power 4 of A is: " << x << endl;
	A.setCoeff(7,3);
	A.setCoeff(6,2);
	A.setCoeff(5,2);
	Poly B(2,0); //testing second constructor of 0 exponent 
	cout << "Printing B of constructor of 0 exponent" << endl;
	cout << B << endl;
	B.setCoeff(8,-3); // trying -ve exponenet 
	B.setCoeff(8,4);
	Poly C; // testing empty constructor
	Poly D(A); // testing copy constructor

	cout << "Testing A and D(copy of A) equality" << endl;

	if (D == A) { // check if A and D are equal .. D is coming by copy constructor of A so they should be equal
		cout << "Polynomials are equal" << endl;
	}
	else {
		cout << "Polynomials are NOT equal" << endl;
	}

	A.setCoeff(6, 8); // changing polynomial A
	
	cout << "testing get coefficient method" << endl;
	x = A.getCoeff(1);
	cout << "coeff of power 1 of A is: " << x << endl;
	x=A.getCoeff(19);
	cout << "coeff of power 19 of A is: " << x << endl;
	x=A.getCoeff(-2);
	cout << "coeff of power -2 of A is: " << x << endl;
	x= A.getCoeff(2);
	cout << "coeff of power 2 of A is: " << x << endl;

	cout << A << endl; // printing A
	cout << B << endl; // printing B
	cout << C << endl; // printing C should be 0 
	cout << D << endl; // printing D


	cout << "Testing A and D(copy of A) equality after changing A" << endl;
	
	if (D == A) { // testing again if A and D are equal .. now they are NOT
		cout << "Polynomials are equal" << endl;
	}
	else {
		cout << "Polynomials are NOT equal" << endl;
	}


	Poly E = A+B; //testing addition
	cout << "A+B" << endl;
	cout << E << endl;
	
	Poly F = B+A;
	cout << "B+A" << endl;
	cout << F << endl;
	
	cout << "A again" << endl;
	cout << A << endl;
	
	cout << "B again" << endl;
	cout << B << endl;
	
	Poly G = B-A;	// testing subtraction
	cout << "B-A" << endl;
	cout << G << endl;
	
	Poly GG = A - B;
	cout << "A-B" << endl;
	cout << GG << endl;

	Poly H = B * A; //testing multiplication
	cout << "B*A" << endl;
	cout << H << endl;	
	
	Poly HH = A * B;	
	cout << "A*B" << endl;
	cout << HH << endl;
	
	cout << endl;

	if (B == A) { // polys are not equal
		cout << "Polynomials are equal" << endl;
	}
	else {
		cout << "Polynomials are NOT equal" << endl;
	}

	A = B; // testing the operator assignment overlaod

	cout << "A again" << endl; // printing A to see if now it is equal to B
	cout << A << endl;

	cout << "B again" << endl;
	cout << B << endl;

	if (B == A) { // testing their equality, they should be equal now
		cout << "Polynomials are equal" << endl;
	}
	else {
		cout << "Polynomials are NOT equal" << endl;
	}

	cout << "testing != operator" << endl; 
	if (B != A) { // test != operator overload, polys are still equal
		cout << "Polynomials NOT are equal" << endl;
	}
	else {
		cout << "Polynomials are equal" << endl;
	}

	A.setCoeff(9, 5); //setting coeffiencient to alter A

	cout << "A again" << endl;
	cout << A << endl; 


	cout << "testing != operator after changing A" << endl;
	if (B != A) { // test != operator overload now they should not be equal
		cout << "Polynomials are NOT equal" << endl;
	}
	else {
		cout << "Polynomials are equal" << endl;
	}

	Poly L;
	L.setCoeff(0, 10); // adding fake term 0^10 to test if L and M are equal or not based on size
	L.setCoeff(1, 4);
	L.setCoeff(5, 9);

	Poly M;
	M.setCoeff(1, 4);
	M.setCoeff(5, 9);

	cout << "Printing L" << endl;
	cout << L << endl;

	cout << "Printing M" << endl;
	cout << M << endl;

	cout << "testing == operator for same equal polynomials but one of them is different size" << endl;
	if (L == M) { // test != operator overload
		cout << "Polynomials are equal" << endl; // both polynomials should be equal even if the sizes are different
	}
	else {
		cout << "Polynomials are NOT equal" << endl;
	}

	//Poly I; // testing start with an empty polynomial
	//cin >> I;

	//cout << "Printing I" << endl;
	//cout << I << endl;

	//Poly J(2, 0); // testing starting with a non-empty polynomial
	//cin >> J;
	//cout << "Printing J" << endl;
	//cout << J << endl;

	//cout << "testing == operator" << endl;
	//if (I == J) { // test != operator overload
	//	cout << "Polynomials are equal" << endl;
	//}
	//else {
	//	cout << "Polynomials are NOT equal" << endl;
	//}	
	////Poly K(7, 1); // testing starting with a non-empty polynomial
	////cin >> K;
	////cout << K << endl;

	//J += I;
	//cout << "Printing J after" << endl;
	//cout << J << endl;
	//cout << "Printing I again" << endl;
	//cout << I << endl;

	//J *= I;
	//cout << "Printing J after" << endl;
	//cout << J << endl;
	//cout << "Printing I again" << endl;
	//cout << I << endl;

	return 0;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Poly A(5, 7), B(3, 4), C(2), D(A), X, Y;
//Poly A2, B2, Z1, Z2;
//
//// set polynomials A and B to desired values
//// A = +5x^7 -4x^3 +10x -2
//// B = +3x^4 +1x^3 
//cout << "Enter terms for polynomial A.  Enter a coefficient " << endl
//<< "then exponent for each term. Enter -1 -1 to terminate." << endl;
//cin >> A;                                     // or use a bunch of setCoeff
//cout << "Enter terms for polynomial B.  Enter a coefficient " << endl
//<< "then exponent for each term. Enter -1 -1 to terminate." << endl;
//cin >> B;                                     // or use a bunch of setCoeff
//
//// outputs exactly what is in quotes: "A = +5x^7 -4x^3 +10x -2"
//cout << "A =" << A << endl;
//// outputs exactly what is in quotes: "B = +3x^4 +1x^3"
//cout << "B =" << B << endl << endl;
//
//
//A2 = A;
//B2 = B;
//C = A + B;
//cout << "Compute C = A + B: " << C << endl << endl;
//
//cout << ((A == B) ? "A == B" : "A is not == B") << endl;
//cout << ((A != B) ? "A is not == B" : "A == B") << endl << endl;
//
//Z1 = A2 - B2;
//cout << "Compute  Z1 = A2 - B2: " << Z1 << endl;
//Z2 = B2 - A2;
//cout << "Compute  Z2 = B2 - A2: " << Z2 << endl << endl;
//
//cout << "Compute  D = A * B - 15" << endl;
//cout << "Before: D =" << D << endl;
//D = A * B - 15;
//cout << "After:  D =" << D << endl << endl;
//
//cout << "Test assignment operators" << endl;
//X = C = D = D;
//Y += A -= B *= A;
//cout << "X =" << X << endl;
//cout << "Y =" << Y << endl << endl;
//
//cout << "Get and Set coefficient" << endl;
//int coeff = D.getCoeff(0);
//cout << "coeff of subscript 0 of D is: " << coeff << endl;
//cout << "Doing getCoeff for term -20000" << endl;
//coeff = D.getCoeff(-20000);              // handle value out of range
//D.setCoeff(50, 0);                        // set x^0 coeff to 50
//D.setCoeff(50, 20000);                    // set x^20000 coeff to 50
//cout << "D =" << D << endl << endl;
//
//return 0;




	//test increaseing the array size by assigning a larger exponenet
	// test by try and catch giving a poly with -ve exponent
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
