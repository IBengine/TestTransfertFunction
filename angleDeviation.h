#pragma once
/*
angleDeviation.h
-----


Rôle : prototypes des fonctions du jeu.
*/



double chooseEquationEBByIntervalAndCompute(double TA, double PA);

void angleDeviationCalculation(double TA_setpoint, double PA_setpoint);
void displayN1X(double equation, double TA);
void displayN1Y(double equation, double TA, double PA);

double askDoubleTA(void);
double askDoublePA(void);