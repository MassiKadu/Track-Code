#pragma once
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

void insLog(logUtente*& testa, int n);
void visuaLog(logUtente* testa);
