#pragma once
#include <vector>
#include <string>
#include "CurveClass.h"
using namespace std;

//other poly classes based off this poly class
class powPoly : virtual public Curve {
public:
	vector<double> coefficients;
	int power;

	//constructor
	powPoly(vector<double> a, int b);

	double evaluate(double x);

	//creates string of equation that GNU plot can read
	string format();
};

class sinWave : virtual public Curve {
public:
	double coefficient1;
	double coefficient2;
	double trailingVal;
	double insideMinus;
	sinWave(double a, double b, double c, double d);
	double evaluate(double x);
	string format();
};
