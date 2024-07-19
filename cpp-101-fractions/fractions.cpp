/* This project aims to define classes for fractional numbers and mixed numbers.
 *
 * There are some steps:
 * Defineing Fraction class with Print method. DONE
 * Defining methods for add, subtract, multiply, and division for Fraction class. TODO
 * Adding operator overloading feature for the methods. TODO
 * Defining class Mixed that derived from Fraction class with inheritance. TODO
 */

#include <iostream>
using namespace std;


class Fraction{
	int num;	//numerator
	int denom;	//denominator
public:
	Fraction(); // coinstructor - default
	Fraction(int n, int d);	//constructor - with args
	~Fraction();		//destructor
	void Print();
private:
	void simplify();
	void fix_sign();
	void reduction();
	int gcd(int x,int y);
};


Fraction::Fraction() {
	num = 0;
	denom = 1;
}

Fraction::Fraction(int n, int d) {
	if (d!=0){ //it is an exception. in the future I'll handle it in a standard manner!
		num = n;
		denom = d;
	}
	else{
		cout<<"Exception!"<<endl;
		num = n;
		denom = 1;
	}
	simplify();
}

Fraction::~Fraction() {}

void Fraction::simplify() {
	reduction();
	fix_sign();
}

void Fraction::fix_sign() {
	if (denom < 0) {
		denom = -denom;
		num = -num;
	}
}

void Fraction::reduction() {
	int common = gcd(num, denom);
	num /= common;
	denom /=common;
}

int Fraction::gcd(int x, int y) {
	return y == 0 ? x : gcd(y, x%y); // it is recursive function that do gcd algorithm.
}

void Fraction::Print() {
	cout<<num<<"/"<<denom<<endl;
}


int main()
{

	Fraction x;
	x.Print();

	Fraction y(2,4);
	y.Print();
	return 0;
}
