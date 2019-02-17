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
		double step = 1.0 / 100;
		double* arguments = new double[elCount];

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < elCount; j++)
			{
				arguments[j] = limits[j].first + (i + 0.5) * step;
			}
			y = F(arguments, elCount);
			area += y * step;
		}

		delete[] arguments;

		return area;
	}

};

double power(double* value, int el) {
	return value[0] * value[0];
}

int main()
{
	Integrate integrate = Integrate(1, power);

	pair<int, int>* p = new pair<int, int>[1];

	p[0] = { 0, 1 };
	double area = integrate.integrateFunction(p);

	cout << area << endl;
	getchar();
	return 0;
}