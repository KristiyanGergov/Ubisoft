#include <iostream>

using namespace std;

double integrateFunction(double A, double B, double(*F)(double))
{

	int n = 1;

	double step = (B - A) / n;
	double area = 0.0;
	double y = 0;

	for (int i = 0; i < n; ++i)
	{
		y = F(A + (i + 0.5) * step);
		area += y * step;
	}

	return area;
}

double power(double value) {
	return value * value;
}

int main()
{
	double area = integrateFunction(0, 1, power);

	return 0;
}