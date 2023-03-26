#pragma once
#include <iostream>
#include <windows.h>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <time.h>

#include "../inputGenerici/input.h"

using namespace std;

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

void ordinamento(alunno* al, alCopy copy[], string x, int& c);
void podio(alunno* al);
void visuaReport(alunno* al);
