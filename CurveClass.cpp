#include <string.h>
#include <string>
#include "CurveClass.h"
using namespace std;

void Curve::GNUPlot(double x) {
	string equation = format();
	string x0 = to_string(x);
	string y0 = to_string(evaluate(x));
	string command = "start gnuplot -persist -e \"plot " + equation + ", (" + to_string(derive(x)) + ") * (x - " + x0 + ") + " + y0 + ", '+' using (" + x0 + ") : (" + y0 + ")\"";
	system(command.c_str());
}
double Curve::derive(double x) { //used strings for the sake of number/decimal accuracy to reduce chances of derivative function returining a slope of 0
	string derivative = "0";
	string derivChange = "1";
	string holdDeriv = "0";
	double delta = 0.0001;
	for (delta; fabs(stod(derivChange)) > 0.001; delta /= 10) {
		derivative = to_string((evaluate(x + delta) - evaluate(x)) / delta);
		derivChange = to_string(stod(derivative) - stod(holdDeriv));
		holdDeriv = derivative;
	}
	return stod(derivative);
}