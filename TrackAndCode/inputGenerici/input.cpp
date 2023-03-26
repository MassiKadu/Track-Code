#include <iostream>
#include <string>

using namespace std;

int inputInt(string x, int min, int max)
{
	int n;

	cout << "\n\tInserire " << x << ": ";
	cin >> n;

	while (n<min || n>max) {
		cout << "\n\tERRORE: Limiti di inserimento sforati." << endl;
		cout << "\t\tReinserire: ";
		cin >> n;
	}

	return n;
}

float inputFloat(string x, float min, float max)
{
	float n;

	cout << "\n\tInserire " << x << ": ";
	cin >> n;

	while (n<min || n>max) {
		cout << "\n\tERRORE: Limiti di inserimento sforati." << endl;
		cout << "\t\tReinserire: ";
		cin >> n;
	}

	return n;
}

bool inputBool(string x, char y, char z)
{
	char a;

	cout << "\n\tInserire " << x << " (" << y << " o " << z << "): ";
	cin >> a;

	a = tolower(a);

	while (a != y && a != z) {
		cout << "\n\tERRORE: caratteri inseriti non validi." << endl;
		cout << "\t\tReinserire: ";
		cin >> a;

		a = tolower(a);
	}

	if (a == y) return true;
	else return false;
}

string inputString(string x, int min, int max)
{
	string y;
	int len;

	cout << "\n\tInserire " << x << ": ";
	cin >> y;
		len = y.size();

	while (len<min || len>max) {
		cout << "\n\tERRORE: Limiti di inserimento sforati." << endl;
		cout << "\tReinerire: ";
		cin >> y;
			len = y.size();
	}

	return y;
}

char inputChar(string x)
{
	char ch;

	cout << "\n\tInserire " << x << ": ";
	cin >> ch;

	ch = toupper(ch);
	
	return ch;
}

string inputStringGetline(string x, int min, int max)
{
	string y;
	int len;

	cout << "\n\tInserire " << x << ": ";
		cin.ignore();
	getline(cin,y);
	len = y.size();

	while (len<min || len>max) {
		cout << "\n\tERRORE: Limiti di inserimento sforati." << endl;
		cout << "\tReinserire: ";
		
		getline(cin, y);
		len = y.size();
	}

	return y;
}