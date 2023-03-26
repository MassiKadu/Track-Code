#include <iostream>
#include <windows.h>
#include <string>
#include <iomanip>

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

void visua(alunno* al)
{
    alunno* p = al;

    string colonne[8] = { "Matricole", "Cognome", "Nome", "Sesso", "Classe", "Attivita", "Record", "-------------------------------------- Risultati --------------------------------------" };

    cout << "\n\n";
    cout << "\t=============================================================================================================== GIORNATA ATLETICA ===============================================================================================================" << endl;
    cout << "\n\n";

    cout << setw(9) << "| " << colonne[0] << " |" << setw(12);
    for (int i = 1; i < 8; i++) {
        cout << setw(13) << "| " << colonne[i] << " |" << setw(11);
    }

    cout << "\n\n";

    while (p != NULL) {
            
            //OUTPUT DATI ALUNNO
        cout << setw(17) << p->matricola;
        cout << setw(22) << p->cognome;
        cout << setw(20) << p->nome;
        if (p->sesso == true) cout << setw(21) << "Maschio";
        else cout << setw(21) << "Femmina";
        cout << setw(17) << p->classe << "^" << p->sezione;
            
            //OUTPUT ATTIVITA' RECORD E RISULTATI
        gara* d = p->matri;

        while (d != NULL) {
            cout << "\n";
            cout << setw(124) << d->descrizione;

            cout << setw(20) << d->record;

            risultato* s = d->studente;

            while (s != NULL) {
                cout << setw(20) << s->result;
                s = s->next;
            }

            d = d->next;
        }

        cout << "\n\n\n";

        p = p->next;
    }

    cout << "\n\n";
}