#include <iostream>
#include <windows.h>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <time.h>

#include "inputGenerici/input.h"
#include "menu/menu.h"
#include "caricamento/caricamento.h"
#include "visua/visua.h"
#include "iscrizione/iscrizione.h"
#include "creaGara/creaGara.h"
#include "insRisultato/insRisultato.h"
#include "ordinamentoGenerale/ordinamento.h"
#include "visuaScore/visuaScore.h"
#include "contaGare/contaGare.h"
#include "contaPartecipanti/contaPartecipanti.h"
#include "sessoDonna/sessoDonna.h"
#include "sessoUomo/sessoUomo.h"
#include "MassimoMinimo/massimoMinimo.h"
#include "esistenzaGara/esistenzaGara.h"
#include "cercaMatricola/cercaMatricola.h"
#include "log/log.h"

using namespace std;

int main()
{
    int sc;
    alunno* al=NULL;
    logUtente* testa = NULL;
    

    preCaricamento(al);
    visua(al);

    menu(sc);

    while (sc != 0) {
        switch (sc) {
            case 1:     //Iscrizione alunno
                iscrizione(al);
                attivita(al);
               break;

            case 2:     //Crea gara
                creaGara(al);
                break;

            case 3:     //Inserisci risultato
                insRis(al);
                break;

            case 4:     //Visualizza podio
                podio(al);
                break;

            case 5:     //Visualizza score studente
                visuaScore(al);
                break;

            case 6:     //Attestato di partecipazione dato studente e gara
                visuaReport(al);
                break;

            case 7:     //Numero gare di uno studente
                cercaEconta(al);
                break;

            case 8:     //Numero di partecipanti ad una gara
                contaPartecipanti(al);
                break;

            case 9:     //Numero maschi e numero femmine
                contaUomo(al);
                contaDonne(al);
                break;

            case 10:    //Risultato max e min di cui si indica la gara
                massimoMinimo(al);
                break;

            case 11:    //Verificare se esiste una gara
                cercaEtrovaGara(al);
                break;

            case 12:    //Ricerca di uno studente data la matricola
                cercaMatricola(al);
                break;

            case 13:    //Log utente corrente
                cout << "\n\n\tLOG UTENTE CORRENTE" << endl;
                cout << "\t";
                visuaLog(testa);
                cout << endl;
                break;
        }
        
        system("pause");
        system("cls");

        insLog(testa,sc);
        visua(al);
        menu(sc);
    }
   
    system("walter.png");

	return 0;
}