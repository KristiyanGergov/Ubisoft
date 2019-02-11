#include <iostream>
#include <ostream>
#include <algorithm>

using namespace std;


class LargeFloat {

private:
	int sign : 1;
	int exponent : 7;
	long long mantissa : 40;

	void setMantissa(double value, int power) 
	{

	}

	void setSign(double value)
	{
		sign = value > 0 ? 0 : 1;
		setExponent(value);
	}

	void setExponent(double value)
	{
		int power = 0;
		while (value < 1)
		{
			value *= 2;
			power--;
		}
		while (value / 2 > 1)
		{
			value /= 2;
			power++;
		}
		this->exponent = 63 + power;
	}

public:

	friend ostream & operator << (ostream &stream, const LargeFloat &value) {
		stream << 5;
	}

	friend LargeFloat operator+(const LargeFloat & a, const LargeFloat & b) {

	}

	LargeFloat(double value) {
	}

};

int main() {

	double value = 0.75;




	return 0;
}