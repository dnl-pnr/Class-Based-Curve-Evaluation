#include <vector>
#include <string.h>
#include "FunctionClasses.h"
using namespace std;

//polyClass methods
powPoly::powPoly(vector<double> a, int b) {
	coefficients = a;
	power = b;
}
double powPoly::evaluate(double x) {                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
	double value = 0;
	for (int i = 0; i < power + 1; ++i) {
		value += coefficients[i] * pow(x, i);
	}
	return value;
}
string powPoly::format() {
	string GNUPlotString;
	for (int i = 0; i < power + 1; ++i) {
		if (i > 0) {
			GNUPlotString += " + ";
		}
		GNUPlotString += "(";
		GNUPlotString += to_string(coefficients[i]);
		GNUPlotString += ") * x**";
		GNUPlotString += to_string(i);
	}
	return GNUPlotString;
}

//sin class methods
sinWave::sinWave(double a, double b, double c, double d) {
	coefficient1 = a;
	coefficient2 = b;
	trailingVal = c;
	insideMinus = d;
}
double sinWave::evaluate(double x) {
	double value = (coefficient1 * sin((coefficient2 * x) - insideMinus)) + trailingVal;
	return value;
}
string sinWave::format() {
	string GNUPlotString = "(" + to_string(coefficient1) + ") * sin((" + to_string(coefficient2) + ") * x - " + to_string(insideMinus) + ") + " + to_string(trailingVal);
	return GNUPlotString;
}

