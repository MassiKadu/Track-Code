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


bool listaVuotaAl(alunno* al)
{
    if (al == NULL) return true;
    else return false;
}

bool listaVuotaGa(gara* matri)
{
    if (matri == NULL) return true;
    else return false;
}

bool listaVuotaRis(risultato* studente)
{
    if (studente == NULL) return true;
    else return false;
}

void preCaricamento(alunno*& al)
{
    string nome[15] = { "Camillo", "Lorenzo", "Matteo", "Chiara", "Sara", "Mirco", "Carlos", "Mike", "Moira", "Amadeo", "Noah", "Jasmine", "Amelia", "Eduardo", "Juan" };
    string matric[15] = { "Cam.15", "AmongFonta.14", "Mat.13", "Val.12", "Cor.11", "Verdi.10", "Tai.09", "Green.08", "Van.07", "Rov.06", "Mc.05", "Cro.04", "Duc.03", "Eduard.02", "Juan.01" };
    string cognome[15] = { "Brown", "Rossi", "Chari", "Valenti", "Corti", "Verdi", "Tailor", "Green", "Van", "Roversi", "McRed", "Crompton", "Ducetti", "Iannone", "Chin" };
    string attiv[5] = { "Atletica", "Staffetta", "Salto in lungo", "Salto in alto", "100 metri" };
    bool sex[15] = { true, true, true, false, false, true, false, true, false, true, true,false,false,true, true };

    for (int i = 0; i < 15; i++) {
        alunno* nuovo = new alunno;
        
        nuovo->nome = nome[i];              //caricamento al
        nuovo->cognome = cognome[i];
        nuovo->matricola = matric[i];
        nuovo->sesso = sex[i];
        nuovo->classe = rand() % 5 + 1;
        nuovo->sezione = 'A' + rand() % 6;
        nuovo->next = NULL;

        for (int j = 0; j < 5; j++) {
            gara* nuovaGara = new gara;
                                                //caricamento di al->matri
            nuovaGara->descrizione = attiv[j];
            nuovaGara->next = NULL;
            
            for (int y = 0; y < 5; y++) {
                risultato* nuovoRis = new risultato;    //caricamento al->matri->studenti
                
                nuovoRis->result = rand()%100-1;
                if (nuovoRis->result <= 5) nuovoRis->result = -1;
                nuovoRis->next = NULL;

                if (listaVuotaRis(nuovaGara->studente)) nuovaGara->studente = nuovoRis;
                else {
                    nuovoRis->next = nuovaGara->studente;
                    nuovaGara->studente = nuovoRis;
                }

            }

            nuovaGara->record = nuovaGara->studente->result;

            risultato* t = new risultato;
            t = nuovaGara->studente;
            while (t != NULL) {
                if (nuovaGara->record < t->result) {
                    nuovaGara->record = t->result;
                }

                else {
                    if (nuovaGara->peggioRis > t->result) {
                        nuovaGara->peggioRis = t->result;
                    }
                }

                t = t->next;
            }



            if (listaVuotaGa(nuovo->matri)) nuovo->matri = nuovaGara;
            else {
                nuovaGara->next = nuovo->matri;
                nuovo->matri = nuovaGara;
            }
        }

        if (listaVuotaAl(al)) al = nuovo;
        else {
            nuovo->next = al;
            al = nuovo;
        }
    }

}