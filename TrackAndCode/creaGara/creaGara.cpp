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

void creaGara(alunno*& al)
{
    string descNewGara;

    descNewGara = inputStringGetline("nuova gara", 3, 20);

    alunno* temp = al;

    while (temp != NULL) {  //si scorre ogni studente
        gara* t = new gara;
        t->descrizione = descNewGara;
        t->record = -1;

        t->next = temp->matri;
        temp->matri = t;

        temp = temp->next;
    }
}