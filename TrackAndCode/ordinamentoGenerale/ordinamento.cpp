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

struct alCopy {
    string matricola{};
    string cognome{};
    string nome{};
    int classe{};
    char sezione{};
    int record{};
    string descrizione{};

    alCopy() {};
};

void ordinamento(alunno* al, alCopy copy[], string x, int& c)
{
    while (al != NULL) {
        copy[c].matricola = al->matricola;
        copy[c].nome = al->nome;
        copy[c].cognome = al->cognome;
        copy[c].classe = al->classe;
        copy[c].sezione = al->sezione;
        
        gara* t = al->matri;
        while (t != NULL) {
            if (t->descrizione == x) {
                copy[c].descrizione = t->descrizione;
                copy[c].record = t->record;
            }

            t = t->next;
        }

        al = al->next;
        c++;
    }

    for (int i = 0; i < c - 1; i++) {
        for (int j = i + 1; j < c; j++) {
            if (copy[i].record < copy[j].record) {
                alCopy box = copy[i];
                copy[i] = copy[j];
                copy[j] = box;
            }
        }
    }
}

void podio(alunno* al)
{
    int c = 0;
    string x = inputStringGetline("attivita'", 3, 20);
    alunno* temp = al;
    alCopy copy[100];

    ordinamento(temp, copy, x, c);

    cout << "\n\tCLASSIFICA (" << x << "):" << endl;
        cout << endl;

    if (copy[0].record == 0 || copy[0].record == -1) cout << "\n\tERRORE: L'attivita' inserita non esiste oppure non ha ancora partecipanti." << endl;
    else {
        for (int i = 0; i < 3; i++) {
            cout << setw(20) << i + 1 << "^ classificato: " << copy[i].nome << " " << copy[i].cognome << setw(20) << " | " << copy[i].classe << "^" << copy[i].sezione << " | Risultato: " << copy[i].record << endl;
        }
    }
}

void visuaReport(alunno* al)
{

    int c = 0;
    string y = inputString("matricola", 3, 20);
    string x = inputStringGetline("attivita'", 3, 20);
    alunno* temp = al;
    alCopy copy[100];
    bool flag = false;

    ordinamento(temp, copy, x, c);

    for (int i = 0; i < c; i++) {
        if (copy[i].matricola == y) {
            //OUTPUT
            flag = true;
            cout << "\n\t";
            for (int i = 0; i < 55; i++) cout << "*";
            cout << "\n";
            cout << "\t*" << setw(49) << "IIS Blaise Pascal" << setw(5) << "*" << endl;
            cout << "\t*" << setw(15) << copy[i].cognome << setw(10) << copy[i].nome << setw(15) << copy[i].classe << "^" << copy[i].sezione << setw(12) << "*" << endl;
            cout << "\t*" << setw(54) << "*" << endl;
            cout << "\t*" << setw(15) << "SPECIALITA':" << setw(15) << copy[i].descrizione << setw(24) << "*" << endl;
            cout << "\t*" << setw(15) << "CLASSIFICATO:" << setw(15) << i+1 << "^" << setw(23) << "*" << endl;
            cout << "\t*" << setw(54) << "*" << endl;
            cout << "\t*" << setw(54) << "*" << endl;
            cout << "\t*" << setw(32) << "DATA(" << "";   printf(" %s ", __DATE__);cout << ")" << setw(8) << "*" << endl;
            cout << "\t*" << setw(54) << "*" << endl;
            cout << "\t";
            for (int i = 0; i < 55; i++) cout << "*";
            cout << "\n";

            //FINE OUTPUT
        }
    }

    if (flag == false) cout << "\n\tSpiacente, matricola e attivita' non trovati." << endl;
}