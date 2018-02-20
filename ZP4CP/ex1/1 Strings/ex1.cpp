// ex1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include "iostream"
using namespace std;

int main()
{
	string v("In the C++ programming language, the retez trida is a standard reprezentation for a retez of text.\n"
			"The trida provides some typical retez operations like comparison, concatenation, find and replace.\n");
	string s[] = {string("retez"), string("string"), string("trida"), string("class")};
	
	cout << v << endl;

	//cout<<v.find(s[0]);

	for (int i = 0; i < sizeof(s)/sizeof(*s);) {
		int pozition = v.find(s[i]);
		v.replace(pozition, s[i].length(), s[i + 1]);
		if (v.find(s[i]) >= v.size()) {
			i += 2;
		}
	}

	cout << v << endl;

    return 0;
}

