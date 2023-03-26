#include <iostream>
#include <windows.h>
#include <string>
#include <iomanip>

#include "../inputGenerici/input.h"

using namespace std;

struct risultato {
	int result{};

	risultato* next{};
};

struct gara {
	risultato* studente{};
	int record{};
	int peggioRis{};
	string descrizione{};

	gara* next{};
};

struct alunno {
	gara* matri{};
	string matricola{};
	string cognome{};
	string nome{};
	bool sesso{};
	int classe{};
	char sezione{};

	alunno* next{};
};

void visuaScore(alunno* al) {

	string alun;
	bool trovato = false;

	alun = inputString("matricola", 2, 20);

	alunno* p = al;

	while (p != NULL) {
		if (alun == p->matricola) {

			cout << "\n\tAlunno trovato\n" << endl;
			trovato = true;

			string colonne[5] = { "Cognome", "Nome", "Attivita", "Record", "-------------------------------------- Risultati --------------------------------------" };

			cout << setw(9) << "| " << colonne[0] << " |" << setw(12);
			for (int i = 1; i < 5; i++) {
				cout << setw(13) << "| " << colonne[i] << " |" << setw(11);
			}

			cout << "\n";
			cout << setw(15) << p->cognome;
			cout << setw(20) << p->nome;

			gara* d = p->matri;

			while (d != NULL) {
				cout << "\n";
				cout << setw(58) << d->descrizione;

				cout << setw(20) << d->record;

				risultato* s = d->studente;

				while (s != NULL) {
					cout << setw(20) << s->result;
					s = s->next;
				}

				d = d->next;
			}

		}
		p = p->next;

	}

	if (trovato == false) cout << "\n\tAlunno non trovato" << endl;

	cout << "\n";
}