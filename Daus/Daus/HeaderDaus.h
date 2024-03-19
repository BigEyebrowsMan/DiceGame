#pragma once

//Libraries used during the code
#include <iostream>
#include <Windows.h>

//Space where the program is displayed
using namespace std;

//Functions used during the program

void gambling(int& aposta, int* cartera, int* numero);

void menu(int opcio, int* cartera);

void tirada(int* dau1, int* dau2);

void resultat(int* total, int* aposta, int& cartera, int* numero);