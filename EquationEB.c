#include <stdio.h>
#include <stdlib.h>
#include "EquationEB.h"


double EquationEB1_I1_N1y(double mirrorPoloidalAngle, double frameToroidalAngle) //I1 = [-13.5°;-10.35°[  
{
	return (1.0391 * mirrorPoloidalAngle) - (0.365 * frameToroidalAngle) - 0.3;
}

double EquationEB1_I2_N1y(double mirrorPoloidalAngle, double frameToroidalAngle) //I2 = [-10.8°;-3.6°[  
{
	return (1.0372 * mirrorPoloidalAngle) - (0.365 * frameToroidalAngle) - 0.3;
}

double EquationEB1_I3_N1y(double mirrorPoloidalAngle, double frameToroidalAngle) //I3 = [-3.6°;3.6°[  
{
	return (1.039 * mirrorPoloidalAngle) - (0.365 * frameToroidalAngle) - 0.3;
}

double EquationEB1_I4_N1y(double mirrorPoloidalAngle, double frameToroidalAngle) //I4 = [3.6°;10.4°[  
{
	return (1.0261 * mirrorPoloidalAngle) - (0.365 * frameToroidalAngle) - 0.3;
}

double EquationEB1_I5_N1y(double mirrorPoloidalAngle, double frameToroidalAngle) //I5 = [10.4°;15°] 
{
	return (1.0323 * mirrorPoloidalAngle) - (0.365 * frameToroidalAngle) - 0.3;
}

double EquationEB2_N1x(double frameToroidalAngle)
{
	return -0.0319 * (frameToroidalAngle * frameToroidalAngle) + 3.1677 * frameToroidalAngle;
}