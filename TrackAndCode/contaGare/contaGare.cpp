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

int contaGare(gara* studente)
{
    if (studente == NULL) return 0;
    else {
        if (studente->record != -1) return 1 + contaGare(studente->next);
        else return contaGare(studente->next);
    }
}

void cercaEconta(alunno* al)
{
    string v = inputString("matricola", 3, 20);
    int n;
    bool trovato = false;

    alunno* temp = al;

    while (temp != NULL) {
        
        if (temp->matricola == v) {
            n = contaGare(temp->matri);
            trovato = true;
        }

        temp = temp->next;
    }

    if (trovato == true) cout << "\n\tMatricola trovata e ha partecipato a " << n << " gare." << endl;
    else cout << "\n\tSpiaciente, matricola non trovata." << endl;
}