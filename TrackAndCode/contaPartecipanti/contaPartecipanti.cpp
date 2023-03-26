#include <iostream>
#include <windows.h>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <time.h>

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

int contaPart(alunno* t, string x)
{
    if (t == NULL) return 0;
    else {
        gara* temp = t->matri;

        while (temp != NULL) {
            if (temp->descrizione == x && temp->record!=-1) return 1 + contaPart(t->next, x);

            temp = temp->next;
        }

        return contaPart(t->next, x);
    }
}

void contaPartecipanti(alunno* al)
{
    string x = inputStringGetline("attivita'", 3, 20);
    alunno* t = al;
    int n = contaPart(t, x);

    if (n == 0) cout << "Spiacente attivita' non trovata." << endl;
    else cout << "I partecipanti all'attivita '" << x << "' sono " << n << endl;
}