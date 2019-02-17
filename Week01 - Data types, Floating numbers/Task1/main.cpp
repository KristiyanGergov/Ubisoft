#include <iostream>
#include <ostream>
#include <bitset>
#include "LargeFloat.h"

using namespace std;

int main() {

	LargeFloat flot = LargeFloat(100) + LargeFloat(100);
	cout << flot << endl;

	system("pause");

	return 0;
}