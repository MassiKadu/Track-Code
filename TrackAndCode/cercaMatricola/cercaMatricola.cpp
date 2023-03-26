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

bool trovaMatri(alunno* al, string x)
{
    if (al == NULL) return false;
    else {
        if (al->matricola == x) return true + trovaMatri(al->next, x);
        else return trovaMatri(al->next, x);
    }
}

void cercaMatricola(alunno* al)
{
    string x = inputString("matricola", 3, 20);
    alunno* temp = al;
    bool flag = trovaMatri(temp, x);

    if (flag == true) cout << "\n\tLa matricola inserita e' stata trovata." << endl;
    else cout << "\n\tSpiacente la matricola inserita non esiste." << endl;
}