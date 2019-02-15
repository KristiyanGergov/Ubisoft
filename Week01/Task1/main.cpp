#include <iostream>
#include <ostream>
#include <bitset>

using namespace std;

const int BIAS = 63;
const int SHORT_BITS = 16;
const int MANTISSA_BITS = 40;

const int SIGN_BITS = 1;
const int EXPONENT_BITS = 7;
const int MANTISSA_ONE_BITS = 8;

const int MANTISSA_ONE_PADDING = 32;
const int MANTISSA_TWO_PADDING = 16;

class LargeFloat {

public:
	short sign : SIGN_BITS;
	short exponent : EXPONENT_BITS;
	short mantissaOne : MANTISSA_ONE_BITS;
	short mantissaTwo;
	short mantissaThree;

	void setMantissa_Two_Three(double value, int size, short* mantissa) {

		for (int i = size - 1; i >= 0; i--)
		{
			value *= 2;

			if (value > 1)
			{
				value -= 1;
				*mantissa |= (1 << i);
			}
		}
	}

	void setMantissa(double value)
	{
		for (int i = MANTISSA_ONE_BITS - 1; i >= 0; i--)
		{
			value *= 2;

			if (value >= 1)
			{
				value -= 1;
				mantissaOne |= (1 << i);
			}
		}

		setMantissa_Two_Three(value, SHORT_BITS, &mantissaTwo);
		setMantissa_Two_Three(value, SHORT_BITS, &mantissaThree);
	}

	void setSign(double value)
	{
		sign = value > 0 ? 0 : 1;
		setExponent(abs(value));
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
		this->exponent = BIAS + power;

		setMantissa(value - 1);
	}

public:

	friend ostream & operator << (ostream &stream, const LargeFloat &value)
	{
		short sign = value.sign == 0 ? 1 : -1;
		int power = bitset<EXPONENT_BITS>(value.exponent).to_ulong() - BIAS;

		long long first = value.mantissaOne;
		long long second = value.mantissaTwo;
		first <<= MANTISSA_ONE_PADDING;
		second <<= MANTISSA_TWO_PADDING;

		long long mantissa = first | second | value.mantissaThree;

		string mmm = bitset<MANTISSA_BITS>(mantissa).to_string();
		double sum = 0;

		double startPower = 0;

		for (int i = MANTISSA_BITS - 1; i >= 0; i--)
		{
			--startPower;
			if ((1ll << i) & mantissa) {
				sum += pow(2, startPower);
			}
		}

		stream << sign * (1 + sum) * pow(2, power);

		return stream;
	}

	friend LargeFloat operator+(const LargeFloat & a, const LargeFloat & b)
	{

	}

	LargeFloat(double value) {
		sign = 0;
		exponent = 0;
		mantissaOne = 0;
		mantissaTwo = 0;
		mantissaThree = 0;

		setSign(value);
	}

};

int main() {

	LargeFloat flot = LargeFloat(173.7);

	cout << flot << endl;
	cout << sizeof(flot);

	system("pause");

	return 0;
}