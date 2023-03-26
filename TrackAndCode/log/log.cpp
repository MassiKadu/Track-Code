#include <iostream>
#include <windows.h>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <time.h>

using namespace std;

struct logUtente {
	int azioni;

	logUtente* next;
};

void insLog(logUtente*& testa, int n)
{
	logUtente* nuovo = new logUtente;
	nuovo->azioni = n;
	nuovo->next = NULL;

	if (testa == NULL) testa = nuovo;
	else {
		logUtente* temp = testa;
		while (temp->next != NULL) {
			temp = temp->next;
		}

		temp->next = nuovo;
		nuovo->next = NULL;
	}
}

void visuaLog(logUtente* testa)
{
	if (testa == NULL) return;
	else {
		cout << testa->azioni << " -> ";
		visuaLog(testa->next);
	}
}