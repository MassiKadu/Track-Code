#include <iostream>
#include <windows.h>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <time.h>

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

int contaSessoDonna(alunno* al)
{
    if (al == NULL) return 0;
    else {
        if (al->sesso == false) return contaSessoDonna(al->next) + 1;
        else return contaSessoDonna(al->next);
    }
}

void contaDonne(alunno* al)
{
    int n;
    alunno* temp = al;

    n = contaSessoDonna(temp);

    if (n == 0) cout << "\n\tSpiacente non ci sono donne." << endl;
    else cout << "\n\tLe donne presenti sono " << n << "." << endl;
}