#include <iostream>

using namespace std;

class Integrate {

private:
	double(*F)(double*, int);
	int elCount;

public:
	Integrate(int elCount, double(*F)(double*, int))
	{
		this->F = F;
		this->elCount = elCount;
	}

	double integrateFunction(pair<int, int> * limits)
	{

		int n = 100;

		double area = 0.0;
		double y = 0.0;
		double* steps = new double[elCount];
		double* arguments = new double[elCount];

		for (int i = 0; i < elCount; i++)
			steps[i] = (limits[i].second - limits[i].first) / n;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < elCount; j++)
			{
				arguments[j] = limits[j].first + (i + 0.5) * steps[j];
			}
			y = F(arguments, elCount);
			area += y * 1;
		}
		
		delete[] steps;
		delete[] arguments;

		return area;
	}

};

double integrateFunction(double A, double B, double(*F)(double))
{
	int n = 100;

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

	cout << area << endl;
	getchar();
	return 0;
}