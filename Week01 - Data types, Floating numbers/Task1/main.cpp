#include <iostream>
#include <ostream>
#include <bitset>
#include "LargeFloat.h"

using namespace std;

int main() {

	LargeFloat float1 = LargeFloat(25.4);
	LargeFloat float2 = LargeFloat(100.5);
	LargeFloat float3 = LargeFloat(11.6);
	cout << float1 << endl;
	cout << float2 << endl;
	cout << float3 << endl;

	return 0;
}