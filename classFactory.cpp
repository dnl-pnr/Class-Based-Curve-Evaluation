#include "FunctionClasses.h"
#include <iostream>
using namespace std;

Curve* ClassFactory(int power, vector<double> a) {
	Curve* object;
	if (power == 2) {
		object = new powPoly(a, 2);
	}
	else if (power == 3) {
		object = new powPoly(a, 3);
	}
	else if (power == 4) {
		object = new powPoly(a, 4);
	}
	else if (power == 100) {
		object = new sinWave(a[3], a[2], a[1], a[0]);
	}
	else {
		cout << "\nClass Error." << endl;
		exit(1);
	}
	return object;
}