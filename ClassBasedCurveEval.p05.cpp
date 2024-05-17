#include <iostream>
#include <vector>
#include "CurveClass.h"
#include "classFactory.h"
using namespace std;

int main()
{
	vector<double> coef;
	int power = 0;
	double val = 0;
	string which = "0";
	bool run = true;
	bool poly = false;
	bool sin = false;
	bool doContinue = true;

	while (run == true) {
		cout << "Would you like to use a sin wave or a simple polynomial? (Enter 1 or 2)" << endl;
		cin >> which;
		if (which == "1") {
			sin = true;
		}
		else if (which == "2") {
			poly = true;
		}
		else {
			cout << "Please enter 1 or 2";
			break;
		}
		if (poly == true) {
			cout << "What is the power of your simple polynomial? Acceptable Answers: (2, 3, 4)" << endl;
			cin >> power;

			if (power == 2) {
				coef.resize(3);
				cout << "Enter the coefficients (axx + bx + c):" << endl << "a: ";
				cin >> coef[2];
				cout << "b: ";
				cin >> coef[1];
				cout << "c: ";
				cin >> coef[0];
			}
			else if (power == 3) {
				coef.resize(4);
				cout << "Enter the coefficients (axxx + bxx + cx + d):" << endl << "a: ";
				cin >> coef[3];
				cout << "b: ";
				cin >> coef[2];
				cout << "c: ";
				cin >> coef[1];
				cout << "d: ";
				cin >> coef[0];
			}
			else if (power == 4) {
				coef.resize(5);
				cout << "Enter the coefficients (axxxx + bxxx + cxx + dx + e):" << endl << "a: ";
				cin >> coef[4];
				cout << "b: ";
				cin >> coef[3];
				cout << "c: ";
				cin >> coef[2];
				cout << "d: ";
				cin >> coef[1];
				cout << "e: ";
				cin >> coef[0];
			}
			else {
				cout << "\nUnsupported power.\n";
				doContinue = false;
			}

			if (doContinue == true) {
				cout << "\nWhat x do you want to make a tangent line to?" << endl;
				cin >> val;

				Curve* function = ClassFactory(power, coef);
				function->GNUPlot(val);
			}
		}
		if (sin == true) {
			coef.resize(4);
			cout << "Enter the assorted values of your equation. (a * sin(bx - c) + d)" << endl;
			cout << "a: ";
			cin >> coef[3];
			cout << "b: ";
			cin >> coef[2];
			cout << "c: ";
			cin >> coef[1];
			cout << "d: ";
			cin >> coef[0];

			cout << "\nWhat x do you want to make a tangent line to?" << endl;
			cin >> val;

			power = 100; //cuz i no have power 100 polynomial
			Curve* function = ClassFactory(power, coef);
			function->GNUPlot(val);
		}
		
		//check if user wants to run code again
		string response;
		cout << "Enter 1 to run again.\n";
		cin >> response;
		if (response == "1") {
			run = true;
		}
		else {
			run = false;
		}
	}
}