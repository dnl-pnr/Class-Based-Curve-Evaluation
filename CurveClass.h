#pragma once
using namespace std;

class Curve {
public:
	virtual double evaluate(double x) = 0;
	virtual string format() = 0;
	void GNUPlot(double x); //plots curve
	double derive(double x);
};