#include <iostream>
#include <ostream>

using namespace std;


class LargeFloat {

private:
	double value;

public:

	friend ostream & operator << (ostream &stream, const LargeFloat &value) {
		stream << 5;
	}

	friend LargeFloat operator+(const LargeFloat & a, const LargeFloat & b) {

	}

	LargeFloat(double value) {
		this->value = value;
	}

};

int main() {

	return 0;
}