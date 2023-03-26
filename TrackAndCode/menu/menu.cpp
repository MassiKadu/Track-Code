#include <iostream>
#include <windows.h>

#include "../inputGenerici/input.h"

using namespace std;

void menu(int& sc)
{
	cout << "\n\n\n";
	cout << "\t| ================================= MENU ================================= |" << endl;
	cout << "\n\n" << endl;
	cout << "\t0. Esci dal programma." << endl;
	cout << "\t1. Iscrizione alunno." << endl;
	cout << "\t2. Crea gara." << endl;
	cout << "\t3. Inserisci risultato." << endl;
	cout << "\t4. Visualizza podio." << endl;
	cout << "\t5. Visualizza score studente." << endl;
	cout << "\t6. Attestato di partecipazione dato studente e gara." << endl;
	cout << "\t7. Numero gare di uno studente." << endl;
	cout << "\t8. Numero di partecipanti ad una gara." << endl;
	cout << "\t9. Numero di maschi e numero di femmine." << endl;
	cout << "\t10. Risultato massimo e minimo di cui si indica la gara." << endl;
	cout << "\t11. Verificare se esiste una gara." << endl;
	cout << "\t12. Ricerca di uno studente data la matricola." << endl;
	cout << "\t13. Log utente corrente." << endl;
	cout << "\n\t";

	sc = inputInt("scelta", 0, 13);
}