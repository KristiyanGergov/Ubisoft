#include <iostream>
#include <ostream>

using namespace std;

#pragma once
class Test
{
public:
	Test();
	~Test();

	ostream &operator <<(ostream &stream, const Test &value) {

	}

};

