#pragma once
/*
betaAngleCalculation.h
-----

Rôle : prototypes des fonctions du jeu.
*/

enum COORDONNEES
{
	X = 0, Y = 1, Z = 2
};

int mainbetaAngleCalculation(double dm, double tm, double fixedMirror_X, double fixedMirror_Y, double movableMirror_X, double movableMirror_Y);
double U_ScalarProduct_V(double U[3], double V[3]);
double *a_coefficientProduct_V(double a, double V[3]);
double *U_minus_V(double U[3], double V[3]);
double *U_sum_V(double U[3], double V[3]);
void displayArray(double U[3]);
void displayPointer(double *P);
void displayDouble(double a);