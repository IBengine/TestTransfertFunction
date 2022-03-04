#include <stdio.h>
#include <stdlib.h>
#include "betaAngleCalculation.h"



int mainbetaAngleCalculation(double dm, double tm, double fixedMirror_X, double fixedMirror_Y, double movableMirror_X, double movableMirror_Y)
{
	return 0;
}

double U_ScalarProduct_V(double U[3], double V[3])
{
	//printf("%lf\n", U[X] * V[X] + U[Y] * V[Y] + U[Z] * V[Z]);
	return U[X]*V[X]+U[Y]*V[Y]+U[Z]*V[Z];
}

double *a_coefficientProduct_V(double a, double V[3])
{
	V[X] *= a;
	//displayDouble(V[X]);
	V[Y] *= a;
	//displayDouble(V[Y]);
	V[Z] *= a;
	//displayDouble(V[Z]);
	return V;
}

double *U_minus_V(double U[3], double V[3])
{
	static double  W[3];
	W[X] = U[X] - V[X];
	W[Y] = U[Y] - V[Y];
	W[Z] = U[Z] - V[Z];
	return W;
}

double *U_sum_V(double U[3], double V[3])
{
	static double  W[3];
	W[X] = U[X] + V[X];
	W[Y] = U[Y] + V[Y];
	W[Z] = U[Z] + V[Z];
	return W;
}

void displayArray(double U[3])
{
	printf("[X] : %lf\n", U[X]);
	printf("[Y] : %lf\n", U[Y]);
	printf("[Z] : %lf\n", U[Z]);
}

void displayPointer(double *P)
{
	printf("[X] : %lf\n", *P);
	printf("[Y] : %lf\n", *(P+1));
	printf("[Z] : %lf\n", *(P+2));
}

void displayDouble(double a)
{
	printf("%lf\n", a);
}