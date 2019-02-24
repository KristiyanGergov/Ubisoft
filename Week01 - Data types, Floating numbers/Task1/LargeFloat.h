#pragma once

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

private:
	short sign : SIGN_BITS;
	short exponent : EXPONENT_BITS;
	short mantissaOne : MANTISSA_ONE_BITS;
	short mantissaTwo;
	short mantissaThree;

	LargeFloat() {
		setDefaults();
	}

	void setDefaults() {
		sign = 0;
		exponent = 0;
		mantissaOne = 0;
		mantissaTwo = 0;
		mantissaThree = 0;
	}

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

	long long static getMantissa(const LargeFloat &value) {
		long long first = value.mantissaOne;
		long long second = value.mantissaTwo;

		first <<= MANTISSA_ONE_PADDING;
		second <<= MANTISSA_TWO_PADDING;

		return first | second | value.mantissaThree;
	}

public:

	friend ostream & operator << (ostream &stream, const LargeFloat &value)
	{
		short sign = value.sign == 0 ? 1 : -1;
		int power = bitset<EXPONENT_BITS>(value.exponent).to_ulong() - BIAS;

		long long mantissa = value.getMantissa(value);

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
		LargeFloat result = LargeFloat();

		short x = bitset<EXPONENT_BITS>(a.exponent).to_ulong() - BIAS;
		short y = bitset<EXPONENT_BITS>(b.exponent).to_ulong() - BIAS;

		short sign;
		short exponent;

		long long mantissaX = (1ll << MANTISSA_BITS - 1) | (bitset<MANTISSA_BITS>(a.getMantissa(a)).to_ullong() >> 1);
		long long mantissaY = (1ll << MANTISSA_BITS - 1) | (bitset<MANTISSA_BITS>(b.getMantissa(b)).to_ullong() >> 1);

		long long mantissa;

		if (x >= y)
		{
			sign = abs(y) > x ? 1 : 0;
			exponent = x + BIAS;

			mantissa = mantissaX + bitset<MANTISSA_BITS>(mantissaY >> (x - y)).to_ullong();
		}
		else
		{
			sign = abs(x) > y ? 1 : 0;
			exponent = y + BIAS;

			mantissa = mantissaY + bitset<MANTISSA_BITS>(mantissaX >> (y - x)).to_ullong();
		}

		mantissa = bitset<40>(mantissa << 1).to_ullong();

		result.sign = sign;
		result.exponent = exponent;

		result.mantissaThree = mantissa;
		result.mantissaTwo = (unsigned short)(mantissa >> MANTISSA_TWO_PADDING);
		result.mantissaOne = (unsigned short)(mantissa >> MANTISSA_ONE_PADDING);

		return result;
	}

	LargeFloat(double value) {
		setDefaults();
		setSign(value);
	}

};
