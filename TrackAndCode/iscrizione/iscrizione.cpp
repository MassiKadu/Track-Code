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

void iscrizione(alunno*& al)
{
    alunno* temp = new alunno;


    temp->nome = inputString("nome studente", 2, 100);
    temp->cognome = inputString("cognome studente", 2, 100);
    temp->matricola = inputString("matricola studente", 2, 10);
    temp->classe = inputInt("classe studente", 1, 5);
    temp->sezione = inputChar("sezione classe studente");
    temp->sesso = inputBool("sesso", 'm', 'f');


    if (al == NULL) al = temp;
    else {
        temp->next = al;
        al = temp;
    }
}

void attivita(alunno*& al)
{
    gara* temp = al->next->matri;

    while (temp != NULL) {
        gara* nuovo = new gara;

        nuovo->descrizione = temp->descrizione;
        nuovo->record = -1;
        if (al->matri == NULL) al->matri = nuovo;
        else {
            nuovo->next = al->matri;
            al->matri = nuovo;
        }

        temp = temp->next;
    }

}