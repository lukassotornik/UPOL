// ex6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "fstream"
#include <set>
#include <string>
using namespace std;

int main()
{

	try {
		ifstream file("E:/Jmena", ios_base::binary);
		if (!file.is_open()) throw "Chyba cteni";
		char c;
		string name;
		set<string> names;

		c = file.get();

		while (file.good()) {
			if (c >= 'A') {
				name += c;
			}
			else
			{
				names.insert(name);
				name = "";
			}
			c = file.get();
		}
		file.close();
		names.insert(name);

		for (auto x : names) {
			cout << x << endl;;
		}

		ofstream out("E:/JmenaC", ios::binary);
		if (!out.is_open()) throw "Neotevrel se pro zapis.";
		for (auto x : names) {
			out.write(x.c_str(), x.size());
			out.write("\0", sizeof(char));
		}
		out.close();

		cout << endl;

		ifstream jmenac("E:/JmenaC", ios_base::binary);
		if (!jmenac.is_open()) throw "Chyba cteni!";
		c = jmenac.get();
		name = "";
		int count = 0;
		while (jmenac.good()) {
			if (c >= 'A') {
				name += c;
				cout << c;

			}
			else if (count % 10 == 0) {
				cout << endl;
				count++;
			}
			else
			{

				count++;
				cout << " ";

			}
			c = jmenac.get();
		}
		jmenac.close();
		cout << endl << "Pocet jmen: " << count - 1 << endl;
	}
	catch (exception e) {
		cout << "Error " << endl;
	}
    return 0;
}

