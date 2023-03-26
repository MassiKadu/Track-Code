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

bool garaTrovata(alunno* al, string x)
{
    if (al == NULL) return false;
    else {
        gara* t = al->matri;
        while (t != NULL) {
            if (t->descrizione == x) return true + garaTrovata(al->next, x);

            t = t->next;
        }

        return false;
    }
}

void cercaEtrovaGara(alunno* al)
{
    string x = inputStringGetline("attivita'", 3, 20);
    alunno* temp = al;
    bool flag = garaTrovata(temp, x);

    if (flag == true) cout << "\n\tL'attivita' inserita e' stata trovata." << endl;
    else cout << "\n\tSpiacente, l'attivita' inserita non e' stata trovata." << endl;
}