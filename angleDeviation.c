#include <stdio.h>
#include <stdlib.h>
#include "angleDeviation.h"

int main()
{
	int length = 3;

	for (double j = -2; j < length; j++)
	{
		if (j != 0)
		{
			for (double i = -2; i < length; i++)
			{
				if (i != 0)
				{
					angleDeviationCalculation(i * 5, j * 5);
				}
			}
		}
	}

	return 0;
}

void angleDeviationCalculation(double TA_setpoint, double PA_setpoint) //affiche l'ecart entre consignes et mesures
{
	double TA_measure, PA_measure, n1x, n1y;
	int Interval = 0;

	//TA_setpoint = 5; //frame
	//PA_setpoint = 10; //mirror

	n1x = 0;
	n1y = 0;

	if (TA_setpoint >= -13.5 && TA_setpoint < -10.35)
	{
		Interval = 1;

		n1y = EquationEB_I1_N1y(PA_setpoint, TA_setpoint);
	}

	if (TA_setpoint >= -10.35 && TA_setpoint < -3.6)
	{
		Interval = 2;

		n1y = EquationEB_I2_N1y(PA_setpoint, TA_setpoint);
	}

	if (TA_setpoint >= -3.6 && TA_setpoint < 3.6)
	{
		Interval = 3;

		n1y = EquationEB_I3_N1y(PA_setpoint, TA_setpoint);
	}

	if (TA_setpoint >= 3.6 && TA_setpoint < 10.4)
	{
		Interval = 4;

		n1y = EquationEB_I4_N1y(PA_setpoint, TA_setpoint);
	}

	if (TA_setpoint >= 10.4 && TA_setpoint < 15)
	{
		Interval = 5;

		n1y = EquationEB_I5_N1y(PA_setpoint, TA_setpoint);
	}


	n1x = EquationEB_N1x(TA_setpoint);
	TA_measure = EquationED_frameToroidalAngle(n1x);
	PA_measure = 666;

	if (TA_measure >= -13.5 && TA_measure < -10.35)
	{
		Interval = 1;

		PA_measure = EquationED_I1_mirrorPoloidalAngle(n1y, TA_measure);
	}

	if (TA_measure >= -10.35 && TA_measure < -3.6)
	{
		Interval = 2;

		PA_measure = EquationED_I2_mirrorPoloidalAngle(n1y, TA_measure);
	}

	if (TA_measure >= -3.6 && TA_measure < 3.6)
	{
		Interval = 3;

		PA_measure = EquationED_I3_mirrorPoloidalAngle(n1y, TA_measure);
	}

	if (TA_measure >= 3.6 && TA_measure < 10.4)
	{
		Interval = 4;

		PA_measure = EquationED_I4_mirrorPoloidalAngle(n1y, TA_measure);
	}

	if (TA_measure >= 10.4 && TA_measure < 15)
	{
		Interval = 5;

		PA_measure = EquationED_I5_mirrorPoloidalAngle(n1y, TA_measure);
	}

	printf("XA ------- Setpoint -------  Measure ------- Deviation\n");
	printf("TA: -----    %f    -----   %f    -----     %f\n", TA_setpoint, TA_measure, (TA_setpoint - TA_measure) *100 / TA_setpoint);
	printf("PA: -----    %f    -----   %f    -----     %f\n\n", PA_setpoint, PA_setpoint, (PA_setpoint - PA_measure) *100 / PA_setpoint);

	return 0;
}

double EquationEB_I1_N1y(double mirrorPoloidalAngle, double frameToroidalAngle) //I1 = [-13.5°;-10.35°[  
{
	return (1.0391 * mirrorPoloidalAngle) - (0.365 * frameToroidalAngle) - 0.3;
}

double EquationEB_I2_N1y(double mirrorPoloidalAngle, double frameToroidalAngle) //I2 = [-10.8°;-3.6°[  
{
	return (1.0372 * mirrorPoloidalAngle) - (0.365 * frameToroidalAngle) - 0.3;
}

double EquationEB_I3_N1y(double mirrorPoloidalAngle, double frameToroidalAngle) //I3 = [-3.6°;3.6°[  
{
	return (1.039 * mirrorPoloidalAngle) - (0.365 * frameToroidalAngle) - 0.3;
}

double EquationEB_I4_N1y(double mirrorPoloidalAngle, double frameToroidalAngle) //I4 = [3.6°;10.4°[  
{
	return (1.0261 * mirrorPoloidalAngle) - (0.365 * frameToroidalAngle) - 0.3;
}

double EquationEB_I5_N1y(double mirrorPoloidalAngle, double frameToroidalAngle) //I5 = [10.4°;15°] 
{
	return (1.0323 * mirrorPoloidalAngle) - (0.365 * frameToroidalAngle) - 0.3;
}

double EquationEB_N1x(double frameToroidalAngle)
{
	return -0.0319 * (frameToroidalAngle * frameToroidalAngle) + 3.1677 * frameToroidalAngle;
}


double EquationED_I1_mirrorPoloidalAngle(double N1y, double frameToroidalAngle) //I1 = [-13.5°;-10.35°[  
{
	return (N1y + 0.3 + (0.365 * frameToroidalAngle)) / (1.0391);
}

double EquationED_I2_mirrorPoloidalAngle(double N1y, double frameToroidalAngle) //I2 = [-10.8°;-3.6°[   
{
	return (N1y + 0.3 + (0.365 * frameToroidalAngle)) / (1.0372);
}

double EquationED_I3_mirrorPoloidalAngle(double N1y, double frameToroidalAngle) //I3 = [-3.6°;3.6°[    
{
	return (N1y + 0.3 + (0.365 * frameToroidalAngle)) / (1.039);
}

double EquationED_I4_mirrorPoloidalAngle(double N1y, double frameToroidalAngle) //I4 = [3.6°;10.4°[    
{
	return (N1y + 0.3 + (0.365 * frameToroidalAngle)) / (1.0261);
}

double EquationED_I5_mirrorPoloidalAngle(double N1y, double frameToroidalAngle) //I5 = [10.4°;15°]    
{
	return (N1y + 0.3 + (0.365 * frameToroidalAngle)) / (1.0323);
}

double EquationED_frameToroidalAngle(double N1x)
{
	return 0.00105 * (N1x * N1x) + 0.32505 * N1x;
}
