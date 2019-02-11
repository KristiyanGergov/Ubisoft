#include <iostream>
#include <ostream>
#include <bitset>
#include <algorithm>

using namespace std;

const int MAXIMUM_BITS = 63;
const int EXPONENT_BITS = 7;
const int MANTISSA_BITS = 40;
const int FLOAT_BITS = 48;


class LargeFloat {

private:
	bitset<1> sign;
	bitset<EXPONENT_BITS> exponent;
	bitset<MANTISSA_BITS> mantissa;

	void setMantissa(double value)
	{
		for (int i = 0; i < MANTISSA_BITS; i++)
		{
			value *= 2;

			if (value > 1)
			{
				value -= 1;
				mantissa |= (1ll << i);
			}
		}
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
		this->exponent = MAXIMUM_BITS + power;
		setMantissa(value - 1);
	}

public:

	bitset<MANTISSA_BITS> getMantissa() {

		return mantissa;
	}

	friend ostream & operator << (ostream &stream, const LargeFloat &value)
	{
		bitset<FLOAT_BITS> floatNumber;
		floatNumber |= bitset<FLOAT_BITS>(value.mantissa.to_ullong());
		floatNumber |= (bitset<FLOAT_BITS>(value.exponent.to_ullong()) << 39);
		floatNumber |= (bitset<FLOAT_BITS>(value.sign.to_ullong()) << 47);
		
		return stream;
	}

	friend LargeFloat operator+(const LargeFloat & a, const LargeFloat & b)
	{
	}

	LargeFloat(double value) {
		setSign(value);
	}

};

int main() {

	LargeFloat flot = LargeFloat(173.7) + LargeFloat(10);


	cout << flot;

	system("pause");

	return 0;
}