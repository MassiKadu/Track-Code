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

void insRis(alunno*& al)
{
    int n;
    string matr;
    string atti;
    bool trovato = false;
    matr = inputString("matricola", 3, 20);
    atti = inputStringGetline("attivita'", 3, 20);
    n = inputInt("risultato", -1, 100);

    alunno* temp = al;

    while (temp != NULL) {
        if (temp->matricola == matr) {
            gara* t = temp->matri;

            while (t != NULL) {
                
                if (t->descrizione == atti) {
                    trovato = true;
                    
                    risultato* nuovo = new risultato;
                    
                    nuovo->result = n;
                    nuovo->next = NULL;

                    if (t->studente == NULL) t->studente = nuovo;
                    else {
                        nuovo->next = t->studente;
                        t->studente = nuovo;
                    }

                    if (t->record < t->studente->result) {
                        t->record = t->studente->result;
                    }
                }

                t = t->next;
            }

        }

        temp = temp->next;
    }

    if (trovato == true) cout << "\n\tLo studente e' stato trovato con successo." << endl;
    else cout << "\n\tSpiacente, lo studente non e' stato trovato" << endl;

}