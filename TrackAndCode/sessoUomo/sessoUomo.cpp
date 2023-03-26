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

int contaSessoUomo(alunno* al)
{
    if (al == NULL) return 0;
    else {
        if (al->sesso == true) return contaSessoUomo(al->next) + 1;
        else return contaSessoUomo(al->next);
    }
}

void contaUomo(alunno* al)
{
    int n;
    alunno* temp = al;

    n = contaSessoUomo(temp);

    if (n == 0) cout << "\n\n\tSpiacente non ci sono uomini." << endl;
    else cout << "\n\n\tGli uomini presenti sono " << n << "." << endl;
}