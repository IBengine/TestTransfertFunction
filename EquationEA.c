#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "EquationEA.h"
#include "betaAngleCalculation.h"

double *EquationEA(double beta_V, double beta_H, double alpha_V, double alpha_H) //4 angles in degrees
{
	double ds = 900;
	double tm = 12;
	double rToDCC = 180 / 3.14;//radianToDegreesCoefficientConversion
	double Bi[3] = { cos(beta_V*rToDCC) * cos(beta_H*rToDCC), -cos(beta_V*rToDCC) * sin(beta_H*rToDCC), -sin(beta_V*rToDCC) };
	double N[3] = { cos(alpha_V*rToDCC) * cos(alpha_H*rToDCC), cos(alpha_V*rToDCC) * sin(alpha_H*rToDCC), sin(alpha_V*rToDCC) };
	double *p_temp;
	double *p_Bi;
	double *p_Bo;
	double *p_N;
	double *p_Po;
	double *p_Pm;
	double *p_Ps;

	//U_ScalarProduct_V(Bi, N);
	//printf("%lf\n",U_ScalarProduct_V(Bi, N));
	p_temp = a_coefficientProduct_V(2.0*(U_ScalarProduct_V(Bi, N)), N);
	double U_temp[3] = { *p_temp,*(p_temp + 1),*(p_temp + 2) };
	p_Bo = U_minus_V(U_temp, Bi);
	displayPointer(p_Bo);
	//Bo[X] = 2 * (Bi[X] * N[X]) * N[X] - Bi[X];
	//Bo[Y] = 2 * (Bi[Y] * N[Y]) * N[Y] - Bi[Y];
	//Bo[Z] = 2 * (Bi[Z] * N[Z]) * N[Z] - Bi[Z];

	/*
	double *Bo = U_minus_V((a_coefficientProduct_V(2.0*( U_ScalarProduct_V(Bi , N)),N)), Bi);
	double *Po = calculationOfPo(0,0,0,0,Bi);
	double *Pm = U_sum_V(Po, a_coefficientProduct_V((U_ScalarProduct_V(N,Po) - tm)/ U_ScalarProduct_V(N, Bi),Bi));
	return U_sum_V(Pm, a_coefficientProduct_V((ds - Pm[Y])/ *(Bo+Y), Bo)); //Ps
	*/
	//return 0;
}

double *calculationOfPo(double fixedMirror_X, double fixedMirror_Y, double movableMirror_X, double movableMirror_Y)
{

}
	