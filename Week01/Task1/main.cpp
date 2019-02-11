#include <iostream>
#include <ostream>
#include <bitset>
#include <algorithm>

using namespace std;


class LargeFloat {

private:
	bitset<1> sign;
	bitset<8> exponent;
	bitset<40> mantissa;

	void setMantissa(double value)
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
		this->exponent = 127 + power;
		setMantissa(value - 1);
	}

public:

	friend ostream & operator << (ostream &stream, const LargeFloat &value) {
		stream << 5;
	}

	friend LargeFloat operator+(const LargeFloat & a, const LargeFloat & b) {

	}



	LargeFloat(double value) {
		setSign(value);
		this->sign = 0;
		this->exponent = 0;
		this->mantissa = 0;
	}

};

int main() {

	LargeFloat flot = LargeFloat(173.7);

	return 0;
}