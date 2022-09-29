#include <iostream>
#include <iomanip>
using namespace std;

// Matthew Sanchez and Alexander Gomez
//
// CPSC 240
//


// Q1
float a, b, c, h, l, w, half = 0.5, tArea, tPerimeter, rArea, rPerimeter, two = 2.0;
void askForTriangle() {
	cout << "Enter the values of a,b,c, and h for the triangle: ";
	cin >> a >> b >> c >> h;
	cout << endl;
}
void askForRectangle() {
	cout << "Enter the length and width of the rectangle: ";
	cin >> l >> w;
	cout << endl;
}
void shapeStats() {
	cout << "Triangle" << endl;
	cout << "        Area.........................................." << tArea << endl;
	cout << "        Perimeter....................................." << tPerimeter << endl;
	cout << "Rectangle" << endl;
	cout << "        Area.........................................." << rArea << endl;
	cout << "        Perimeter....................................." << rPerimeter << endl;
}

// Q2
float x1, x2, four =4.0, negone = -1.0, temp;
void askRealRoots() {
	cout << "To see the two real roots of aX^2+bX+c=0, enter the a,b, and c values: ";
	cin >> a, b, c;
	cout << endl;
}
void displayRealRoots() {
	cout << "X1 = " << x1 << "    X2 = " << x2 << endl;
}


int main() {
	// Q1
	_asm {
		call askForTriangle;
		call askForRectangle;
		// calculate triangle area
		fld c;		// st[0] = c
		fld h;		// st[0] = h, st[1] = c
		fmul;		// st[0] = c * h
		fld half;	// st[0] = 0.5, st[1] = c * h
		fmul;		// st[0] = 0.5(c * h)
		fstp tArea;
		// calculate triangle perimeter
		fld a;		// st[0] = a
		fld b;		// st[0] = b, st[1] = a
		fadd;		// st[0] = b + a
		fld c;		// st[0] = c, st[1] = b + a
		fadd;		// st[0] = c + b + a
		fstp tPerimeter;
		// calculate rectangle area
		fld l;	// st[0] = length
		fld w;	// st[0] = width, st[1] = length
		fmul;		// st[0] = width * length
		fstp rArea;
		// calculate rectangle perimeter
		fld l; // st[0] = length
		fld w;	// st[0] = width, st[1] = length
		fadd;		// st[0] = width + length
		fld two; // st[0] = 2.0, st[1] = width + length
		fmul; // st[0] = 2(width+length)
		fstp rPerimeter;
		call shapeStats;
		mov a, 0;
		mov b, 0;
		mov c, 0;
	}

	// Q2
	_asm {
		call askRealRoots;
		// first find X1
		fld a;		// st[0] = a
		fld c;		// st[0] = c, st[1] = a
		fmul;		// st[0] = 4ac
		fld four;
		fmul;
		fld b;		// st[0] = b, st[1] = 4ac
		fld b;		// st[0] = b, st[1] = b, st[2] = 4ac
		fmul;		// st[0] = b^2, st[1] = 4ac
		fsub;		// st[0] = b^2 - 4ac
		fsqrt;		// st[0] = sqrt(b^2 - 4ac)
		fstp temp;
		fld b;		// st[0] = b, st[1] = sqrt(b^2 - 4ac)
		fld negone;	// st[0] = -1, st[1] = b, st[2] = sqrt(b^2 - 4ac)
		fmul;		// st[0] = -b, st[1] = sqrt(b^2 - 4ac)
		fadd;		// st[0] = -b + sqrt(b^2 -4ac)
		fld a;		// st[0] = a, st[1] = -b + sqrt(b^2 -4ac)
		fld two;	// st[0] = 2, st[1] = a, st[2] = -b + sqrt(b^2 -4ac)
		fmul;		// st[0] = 2a, st[1] = -b + sqrt(b^2 -4ac)
		fdiv;		// st[0] = (-b + sqrt(b^2 - 4ac))/ 2a
		fstp x1; 

		// find X2
		fld a;		// st[0] = a
		fld c;		// st[0] = c, st[1] = a
		fmul;		// st[0] = ac
		fld four;	// st[0] = 4, st[1] = ac
		fmul;		// st[0] = 4ac
		fld b;		// st[0] = b, st[1] = 4ac
		fld b;		// st[0] = b, st[1] = b, st[2] = 4ac
		fmul;		// st[0] = b^2, st[1] = 4ac
		fsub;		// st[0] = b^2 - 4ac
		fsqrt;		// st[0] = sqrt(b^2 - 4ac)
		fld b;		// st[0] = b, st[1] = sqrt(b^2 - 4ac)
		fld negone;	// st[0] = -1, st[1] = b, st[2] = sqrt(b^2 - 4ac)
		fmul;		// st[0] = -b, st[1] = sqrt(b^2 - 4ac)
		fsub;		// st[0] = -b -sqrt(b^2 -4ac)
		fld a;		// st[0] = a, st[1] = -b - sqrt(b^2 -4ac)
		fld two;	// st[0] = 2, st[1] = a, st[2] = -b - sqrt(b^2 -4ac)
		fmul;		// st[0] = 2a, st[1] = -b - sqrt(b^2 -4ac)
		fdiv;		// st[0] = (-b - sqrt(b^2 - 4ac))/ 2a
		fstp x2;
		call displayRealRoots;
	}
}


