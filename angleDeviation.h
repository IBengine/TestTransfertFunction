#pragma once
/*
fonctionTransfert.h
-----

Par mateo21, pour Le Site du Zéro (www.siteduzero.com)

Rôle : prototypes des fonctions du jeu.
*/

double EquationEB_I1_N1y(double mirrorPoloidalAngle, double frameToroidalAngle);
double EquationEB_I2_N1y(double mirrorPoloidalAngle, double frameToroidalAngle);
double EquationEB_I3_N1y(double mirrorPoloidalAngle, double frameToroidalAngle);
double EquationEB_I4_N1y(double mirrorPoloidalAngle, double frameToroidalAngle);
double EquationEB_I5_N1y(double mirrorPoloidalAngle, double frameToroidalAngle);

double EquationEB_N1x(double frameToroidalAngle);

double EquationED_I1_mirrorPoloidalAngle(double N1y, double frameToroidalAngle);
double EquationED_I2_mirrorPoloidalAngle(double N1y, double frameToroidalAngle);
double EquationED_I3_mirrorPoloidalAngle(double N1y, double frameToroidalAngle);
double EquationED_I4_mirrorPoloidalAngle(double N1y, double frameToroidalAngle);
double EquationED_I5_mirrorPoloidalAngle(double N1y, double frameToroidalAngle);

double EquationED_frameToroidalAngle(double N1y);

double chooseEquationEBByIntervalAndCompute(double TA, double PA);

void angleDeviationCalculation(double TA_setpoint, double PA_setpoint);
void displayN1X(double equation, double TA);
void displayN1Y(double equation, double TA, double PA);

double askDoubleTA(void);
double askDoublePA(void);