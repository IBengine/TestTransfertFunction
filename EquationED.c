#include <stdio.h>
#include <stdlib.h>
#include "EquationED.h"


double EquationED1_I1_mirrorPoloidalAngle(double N1y, double frameToroidalAngle) //I1 = [-13.5°;-10.35°[  
{
	return (N1y + 0.3 + (0.365 * frameToroidalAngle)) / (1.0391);
}

double EquationED1_I2_mirrorPoloidalAngle(double N1y, double frameToroidalAngle) //I2 = [-10.8°;-3.6°[   
{
	return (N1y + 0.3 + (0.365 * frameToroidalAngle)) / (1.0372);
}

double EquationED1_I3_mirrorPoloidalAngle(double N1y, double frameToroidalAngle) //I3 = [-3.6°;3.6°[    
{
	return (N1y + 0.3 + (0.365 * frameToroidalAngle)) / (1.039);
}

double EquationED1_I4_mirrorPoloidalAngle(double N1y, double frameToroidalAngle) //I4 = [3.6°;10.4°[    
{
	return (N1y + 0.3 + (0.365 * frameToroidalAngle)) / (1.0261);
}

double EquationED1_I5_mirrorPoloidalAngle(double N1y, double frameToroidalAngle) //I5 = [10.4°;15°]    
{
	return (N1y + 0.3 + (0.365 * frameToroidalAngle)) / (1.0323);
}

double EquationED2_frameToroidalAngle(double N1x)
{
	return 0.00105 * (N1x * N1x) + 0.32505 * N1x;
}