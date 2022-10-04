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
	cout << "        Area.........................................." << fixed << showpoint << setprecision(2) << tArea << endl;
	cout << "        Perimeter....................................." << fixed << showpoint << setprecision(2) << tPerimeter << endl;
	cout << "Rectangle" << endl;
	cout << "        Area.........................................." << fixed << showpoint << setprecision(2) << rArea << endl;
	cout << "        Perimeter....................................." << fixed << showpoint << setprecision(2) << rPerimeter << endl;
}

// Q2
float x1, x2, four =4.0, negone = -1.0, temp, d, e, f;
void askRealRoots() {
	cout << "To see the two real roots of aX^2+bX+c=0, enter the a,b, and c values: ";
	cin >> d >> e >> f;
	cout << endl;
}
void displayRealRoots() {
	cout << "X1 = " << fixed << showpoint << setprecision(2) << x1 
		 << " X2 = " << fixed << showpoint << setprecision(2) << x2 << endl;
}

// Q3
char drinkType;
int sandwichType;
float tenInch = 3.45, twelveInch = 5.25, sodaPrice = 2.25, waterPrice = 1.75, total, numSandwiches, numDrinks;
void displayCustomerTotal() {
	cout << "Your total bill: " << fixed << showpoint << setprecision(2) << total;
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
		fld e;		// st[0] = e
		fld negone;	// st[0] = -1, st[1] = e
		fmul;		// st[0] = -b
		fld e;		// st[0] = e st[1] = -e
		fld e;		// st[0] = e, st[1] = e, st[2] = -e
		fmul;		// st[0] = e^2, st[1] = -e
		fld four;	// st[0] = 4, st[1] = e^2, st[2] = -e
		fld d;		// st[0] = d, st[1] = 4, st[2] = e^2, st[3] = -e
		fmul;		// st[0] = 4d, st[1] = e^2, st[2] = -e
		fld f;		// st[0] = f, st[1] = 4d, st[2] = e^2, st[3] = -e
		fmul;		// st[0] = 4df, st[1] = e^2 st[2] = -e
		fsub;		// st[0] = e^2 - 4df
		fsqrt;		// st[0] = sqrt(e^2 - 4df), st[1] = -e
		fadd;		// st[0] = -e + sqrt(e^2 - 4df)
		fld d;		// st[0] = d, st[1] = -e + sqrt(e^2 - 4df)
		fld two;	// st[0] = 2, st[1] = d, st[2] = -e + sqrt(e^2 - 4df)
		fmul;		// st[0] = 2d, st[1] = -e + sqrt(e^2 - 4df)
		fdiv;		// st[0] = (-e + sqrt(e^2 - 4df)) / 2d
		fstp x1;

		// find x2
		fld e;		// st[0] = e
		fld negone;	// st[0] = -1, st[1] = e
		fmul;		// st[0] = -b
		fld e;		// st[0] = e st[1] = -e
		fld e;		// st[0] = e, st[1] = e, st[2] = -e
		fmul;		// st[0] = e^2, st[1] = -e
		fld four;	// st[0] = 4, st[1] = e^2, st[2] = -e
		fld d;		// st[0] = d, st[1] = 4, st[2] = e^2, st[3] = -e
		fmul;		// st[0] = 4d, st[1] = e^2, st[2] = -e
		fld f;		// st[0] = f, st[1] = 4d, st[2] = e^2, st[3] = -e
		fmul;		// st[0] = 4df, st[1] = e^2 st[2] = -e
		fsub;		// st[0] = e^2 - 4df
		fsqrt;		// st[0] = sqrt(e^2 - 4df), st[1] = -e
		fsub;		// st[0] = -e - sqrt(e^2 - 4df)
		fld d;		// st[0] = d, st[1] = -e - sqrt(e^2 - 4df)
		fld two;	// st[0] = 2, st[1] = d, st[2] = -e - sqrt(e^2 - 4df)
		fmul;		// st[0] = 2d, st[1] = -e - sqrt(e^2 - 4df)
		fdiv;		// st[0] = (-e - sqrt(e^2 - 4df)) / 2d
		fstp x2;


		call displayRealRoots;
	}

	// Q3

	cout << endl << endl;

	cout << "----------------7-11 Convenient Store---------------" << endl;
	cout << "   Drinks" << endl;
	cout << "      Soda(s)..................................$2.25" << endl;
	cout << "      Water(w).................................$1.75" << endl;
	cout << "   Sandwiches" << endl;
	cout << "      10 inches................................$3.45" << endl;
	cout << "      12 inches................................$5.25" << endl;
	cout << "How many drinks?";
	cin >> numDrinks;
	cout << "    What kind of drink(s = soda, w = water)?";
	cin >> drinkType;
	cout << "How many Sandwiches?";
	cin >> numSandwiches;
	cout << "    What size of sandwich(10/12 inches)?";
	cin >> sandwichType;
	_asm {
		cmp drinkType, 's';
		Je trueSoda;			// if customer input s jump to soda
		fld numDrinks;			// st[0] = numDrinks
		fld waterPrice;			// st[0] = waterPrice, st[1] = numDrinks
		fmul;					// st[0] = waterPrice * numDrinks
		fstp total;				// total = waterPrice * numDrinks
		Jmp sandwichStart;
	trueSoda:
		fld numDrinks;			// st[0] = numDrinks
		fld sodaPrice;			// st[0] = sodaPrice, st[1] = numDrinks
		fmul;					// st[0] = sodaPrice * numDrinks
		fstp total;				// total = sodaPrice * numDrinks
	sandwichStart:
		cmp sandwichType, 10;
		Je tenSandwich;
		fld numSandwiches;		// st[0] = numSandwiches
		fld twelveInch;			// st[0] = twelveInch, st[1] = numSandwiches
		fmul;					// st[0] = twelveInch * numSandwiches
		fld total;				// st[0] = drinkPrice * numDrinks, st[1] = twelveInch * numSandwiches
		fadd;					// st[0] = (drinkPrice * numDrinks) + (twelveInch * numSandwiches)
		fstp total;				// total = (drinkPrice * numDrinks) + (twelveInch * numSandwiches)
		Jmp displayQ3;
	tenSandwich:
		fld numSandwiches;		// st[0] = numSandwiches
		fld tenInch;			// st[0] = tenInch, st[1] = numSandwiches
		fmul;					// st[0] = tenInch * numSandwiches
		fld total;				// st[0] = drinkPrice * numDrinks, st[1] = tenInch * numSandwiches
		fadd;					// st[0] = (drinkPrice * numDrinks) + (tenInch * numSandwiches)
		fstp total;				// total = (drinkPrice * numDrinks) + (tenInch * numSandwiches)
		Jmp displayQ3;
	displayQ3:
		call displayCustomerTotal;
	}

}


