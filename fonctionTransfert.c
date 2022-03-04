#include <stdio.h>
#include <stdlib.h>
//#include "fonctionTransfert.h"


/*
int mainft()
{
	double TA_setpoint, TA_mesured, PA_setpoint, PA_mesured, n1x, n1y;
	int Interval = 0;

	TA_setpoint = 5; //frame
	PA_setpoint = 10; //mirror

	printf("PA_setpoint = %f\n", PA_setpoint);
	printf("TA_setpoint = %f\n", TA_setpoint);
	n1x = 0;
	n1y = 0;

	printf("EquationEB2_N1x(%f) = %f\n", TA_setpoint, EquationEB2_N1x(TA_setpoint));

	if (TA_setpoint >= -13.5 && TA_setpoint < -10.35)
	{
		Interval = 1;
		printf("EquationEB1_I1_N1y(%f,%f) = %f\n\n", TA_setpoint, PA_setpoint, EquationEB1_I1_N1y(PA_setpoint, TA_setpoint));

		n1y = EquationEB1_I1_N1y(PA_setpoint, TA_setpoint);
	}

	if (TA_setpoint >= -10.35 && TA_setpoint < -3.6)
	{
		Interval = 2;
		printf("EquationEB1_I2_N1y(%f,%f) = %f\n\n", TA_setpoint, PA_setpoint, EquationEB1_I2_N1y(PA_setpoint, TA_setpoint));

		n1y = EquationEB1_I2_N1y(PA_setpoint, TA_setpoint);
	}

	if (TA_setpoint >= -3.6 && TA_setpoint < 3.6)
	{
		Interval = 3;
		printf("EquationEB1_I3_N1y(%f,%f) = %f\n\n", TA_setpoint, PA_setpoint, EquationEB1_I3_N1y(PA_setpoint, TA_setpoint));

		n1y = EquationEB1_I3_N1y(PA_setpoint, TA_setpoint);
	}

	if (TA_setpoint >= 3.6 && TA_setpoint < 10.4)
	{
		Interval = 4;
		printf("EquationEB1_I4_N1y(%f,%f) = %f\n\n", TA_setpoint, PA_setpoint, EquationEB1_I4_N1y(PA_setpoint, TA_setpoint));

		n1y = EquationEB1_I4_N1y(PA_setpoint, TA_setpoint);
	}

	if (TA_setpoint >= 10.4 && TA_setpoint < 15)
	{
		Interval = 5;
		printf("EquationEB1_I5_N1y(%f,%f) = %f\n\n", TA_setpoint, PA_setpoint, EquationEB1_I5_N1y(PA_setpoint, TA_setpoint));

		n1y = EquationEB1_I5_N1y(PA_setpoint, TA_setpoint);
	}


	n1x = EquationEB2_N1x(TA_setpoint);
	printf("n1x = %f\n", n1x);
	printf("n1y = %f\n", n1y);

	TA_mesured = EquationED2_frameToroidalAngle(n1x);

	if (TA_mesured >= -13.5 && TA_mesured < -10.35)
	{
		Interval = 1;
		printf("EquationED1_I1_mirrorPoloidalAngle(%f,%f) = %f\n\n", n1x, TA_setpoint, EquationED1_I1_mirrorPoloidalAngle(n1y, TA_mesured));

		PA_mesured = EquationED1_I1_mirrorPoloidalAngle(n1y, TA_mesured);
	}

	if (TA_mesured >= -10.35 && TA_mesured < -3.6)
	{
		Interval = 2;
		printf("EquationED1_I2_mirrorPoloidalAngle(%f,%f) = %f\n\n", n1x, TA_setpoint, EquationED1_I2_mirrorPoloidalAngle(n1y, TA_mesured));

		PA_mesured = EquationED1_I2_mirrorPoloidalAngle(n1y, TA_mesured);
	}

	if (TA_mesured >= -3.6 && TA_mesured < 3.6)
	{
		Interval = 3;
		printf("EquationED1_I3_mirrorPoloidalAngle(%f,%f) = %f\n\n", n1x, TA_setpoint, EquationED1_I3_mirrorPoloidalAngle(n1y, TA_mesured));

		PA_mesured = EquationED1_I3_mirrorPoloidalAngle(n1y, TA_mesured);
	}

	if (TA_mesured >= 3.6 && TA_mesured < 10.4)
	{
		Interval = 4;
		printf("EquationED1_I4_mirrorPoloidalAngle(%f,%f) = %f\n\n", n1x, TA_setpoint, EquationED1_I4_mirrorPoloidalAngle(n1y, TA_mesured));

		PA_mesured = EquationED1_I4_mirrorPoloidalAngle(n1y, TA_mesured);
	}

	if (TA_mesured >= 10.4 && TA_mesured < 15)
	{
		Interval = 5;
		printf("EquationED1_I5_mirrorPoloidalAngle(%f,%f) = %f\n\n", n1x, TA_setpoint, EquationED1_I5_mirrorPoloidalAngle(n1y, TA_mesured));

		PA_mesured = EquationED1_I5_mirrorPoloidalAngle(n1y, TA_mesured);
	}

	printf("EquationED2_frameToroidalAngle(%f) = %f\n", n1x, EquationED2_frameToroidalAngle(n1x));


	return 0;
}

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
*/