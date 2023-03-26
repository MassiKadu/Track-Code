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

int massimoRis(alunno* al, string x)
{
    if (al == NULL) return -1;
    else {

        gara* t = al->matri;
        
        while (t != NULL) {

            if (t->descrizione == x) {
                if (t->record > massimoRis(al->next, x)) return t->record;
                
            }

            t = t->next;
        }

        return massimoRis(al->next, x);
    }
}

int minimoRis(alunno* al, string x)
{
    if (al == NULL) return 200;
    else {

        gara* t = al->matri;

        while (t != NULL) {

            if (t->descrizione == x) {
                if (t->peggioRis < minimoRis(al->next, x) && t->peggioRis!=-1) return t->peggioRis;

            }

            t = t->next;
        }

        return minimoRis(al->next, x);
    }
}

void massimoMinimo(alunno* al)
{
    int n;
    alunno* temp = al;
    string x = inputStringGetline("attivita'", 3, 20);

    cout << "\n\n\tIl massimo risultato ottenuto nella competizione '" << x << "' e': " << massimoRis(temp, x) << endl;
    cout << "\n\tIl minimo risultato ottenuto nella competizione '" << x << "' e': " << minimoRis(temp, x) << endl;
    
}