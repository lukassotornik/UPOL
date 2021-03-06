// ex2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

const char *Jmena[] =
	{ "Marie","Jan","Jana","Petr","Josef","Pavel","Jaroslav","Martin","Miroslav","Eva",
		"Anna","Hana","Karel","Lenka","Milan","Michal","Alena","Petra","Lucie","Jaroslava",
		"Ludmila","Helena","David","Ladislav","Marie","Jan","Jana","Petr","Jitka","Martina","Jakub","Veronika","Jarmila","Stanislav",
		"Michaela","Ivana","Roman","Jarmila","Monika","Tereza","Zuzana","Radek","Vlasta","Marcela","Marek",
		"Dagmar","Dana","Daniel","Marta","Irena","Monika","Miroslava","Barbora","Ilona","Pavla","Miloslav","Olga",
		"Andrea","Iveta","Hana","Filip","Ilona","Blanka","Milada","Ivan","Zdenka","Libor","Renata","Rudolf",
		"Vlastimil","Nikola","Gabriela","Lenka","Adam","Lenka","Milan","Radka","Simona","Milena","Miloslava","Iva","Daniela",
		"Patrik","Bohumil","Denisa","Robert","Diana","Romana","Aneta","Ilona","Dominik","Jakub","Stanislava","Emilie",
		"Radim","Richard","Kamila","Ivo","Monika","Rostislav","Vladislav","Bohuslav","Alois","Vit","Kamil",
		"Jozef","Vendula","Bohumila","Viktor","Emil","Michael","Ladislava","Diana","Magdalena","Eduard","Dominika",
		"Marcel","Adam","Sabina","Julie","David","Johana","Antonie","Josef","Alice","Peter","Dalibor","Kristina","Otakar","Karla",
		"Hedvika","Alexandra","Silvie","Erika","Nela","Irena","Vratislav","Nikol","Leona","Jolana","Margita",
		"Bohuslava","Radovan","Jan","Jana","Josefa","Terezie","Marian","Linda","Igor","Jarmila","Magda","Lada","Bohumir",
		"Alexandr","Radim","Adriana","Dita","Hana","Vladislava","Otto","Sandra","Radmila","Svatava","Darina","Sylva",
		"Viktorie","Ivona","David","Monika","Jarmila","Lenka","Bronislava","Elena","Svatopluk","Ivanka","Denis","Adolf","Hynek","Erik",
		"Bronislav","Jakub","Drahoslava","Petr","Alexander","Robin","Maria","Diana","Lidmila","Vlastislav","Michala","Jindra",
		"Juraj","Vlastimila","Karin","Zdena","Jan","Josef","Jana","Karolina","Mykola","Pavol","Vanda","Radoslav","Zdenek",
		"Alenka","Ema","Andrej","Tibor","Anton","Ingrid","Nina","Irena","Viera","Linda","Valerie","Samuel",
		"Zlata","Lydie","Tamara","Johana","Jan","Jana","Patricie","Julius","Boris","Leopold","Ota","Ester",
		"Gertruda","Sylvie","Aloisie","Oto","Barbara","Gustav","Marika","Yvona","Jitka","Oksana","Bohdan" };

vector<string>::iterator prvni(vector<string> &v, const char * c) {
	vector<string>::iterator iterator = v.end();
	string word = "";
	for (string s : v) {
		for (int i = 0; i < strlen(c) && c != '\0'; i++) {

			if (s[i] != c[i]) break;
			else if (s[i] != '\0' && i == strlen(c) - 1) {
				word = s;
				iterator = find(v.begin(), v.end(), word);
			}
			if (word != "") break;
		}
	}
	return iterator;
}

vector<string>::iterator dalsi(vector<string>::iterator start_iterator, vector<string> &v, const char * filter) {
	vector<string>::iterator result_iterator = v.end();
	string word = "";
	for (vector<string>::iterator current_iterator = start_iterator + 1; current_iterator != v.end(); current_iterator++) {
		for (int i = 0; i < strlen(filter) && filter != '\0'; i++) {

			if ((*current_iterator)[i] != filter[i]) break;
			else if ((*current_iterator)[i] != '\0' && i == strlen(filter) - 1) {
				word = (*current_iterator);
				result_iterator = find(current_iterator, v.end(), word);
			}
			if (word != "") break;
		}
	}
	return result_iterator;
}

void find_all(const char* filter, vector<string> source_vector) {
	vector<string>::iterator it = prvni(source_vector, filter);
	while (it != source_vector.end()) {
		if (it != source_vector.end()) {
			cout << *it << endl;
		}
		it = dalsi(it, source_vector, filter);
	}
}

int main()
{
	vector<string> jmena;
	for (auto j : Jmena) {
		jmena.push_back(j);
	}
	string input;
	cin >> input;
	const char* filter = input.c_str();
	find_all(filter, jmena);

	//ctrl + F5 to debug
	//enter filter to search for words
	//e.g.: input "Ja"

    return 0;
}

