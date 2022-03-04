#include <stdio.h>
#include <stdlib.h>
#include "angleDeviation.h"
#include <math.h>
#include "betaAngleCalculation.h"

int mainAngleDeviation()
{
	/*
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
	*/

	double TA = askDoubleTA();
	double PA = askDoublePA();
	displayN1X(EquationEB2_N1x(TA),TA);
	displayN1Y(chooseEquationEBByIntervalAndCompute(TA,PA), TA, PA);

	double Bo[3];


	return 0;
}




double chooseEquationEBByIntervalAndCompute(double TA, double PA) //choose the equation to convert the mirror angles to motor turn according to the interval
{
	double n1y;
	if (TA >= -13.5 && TA < -10.35)
	{
		n1y = EquationEB1_I1_N1y(PA, TA);
	}

	if (TA >= -10.35 && TA < -3.6)
	{
		n1y = EquationEB1_I2_N1y(PA, TA);
	}

	if (TA >= -3.6 && TA < 3.6)
	{
		n1y = EquationEB1_I3_N1y(PA, TA);
	}

	if (TA >= 3.6 && TA < 10.4)
	{
		n1y = EquationEB1_I4_N1y(PA, TA);
	}

	if (TA >= 10.4 && TA <= 15)
	{
		n1y = EquationEB1_I5_N1y(PA, TA);
	}
	return n1y;
}

void angleDeviationCalculation(double TA_setpoint, double PA_setpoint) //affiche l'ecart entre consignes et mesures
{
	double TA_measure, PA_measure, n1x, n1y;
	int Interval = 0;

	//TA_setpoint = 5; //frame
	//PA_setpoint = 10; //mirror

	n1x = 0;
	n1y = 0;
	/*
	if (TA_setpoint >= -13.5 && TA_setpoint < -10.35)
	{
		Interval = 1;

		n1y = EquationEB1_I1_N1y(PA_setpoint, TA_setpoint);
	}

	if (TA_setpoint >= -10.35 && TA_setpoint < -3.6)
	{
		Interval = 2;

		n1y = EquationEB1_I2_N1y(PA_setpoint, TA_setpoint);
	}

	if (TA_setpoint >= -3.6 && TA_setpoint < 3.6)
	{
		Interval = 3;

		n1y = EquationEB1_I3_N1y(PA_setpoint, TA_setpoint);
	}

	if (TA_setpoint >= 3.6 && TA_setpoint < 10.4)
	{
		Interval = 4;

		n1y = EquationEB1_I4_N1y(PA_setpoint, TA_setpoint);
	}

	if (TA_setpoint >= 10.4 && TA_setpoint < 15)
	{
		Interval = 5;

		n1y = EquationEB1_I5_N1y(PA_setpoint, TA_setpoint);
	}
	*/
	n1y = chooseEquationEBByIntervalAndCompute(TA_setpoint, PA_setpoint);

	n1x = EquationEB2_N1x(TA_setpoint);
	TA_measure = EquationED2_frameToroidalAngle(n1x);
	PA_measure = 666;

	if (TA_measure >= -13.5 && TA_measure < -10.35)
	{
		Interval = 1;

		PA_measure = EquationED1_I1_mirrorPoloidalAngle(n1y, TA_measure);
	}

	if (TA_measure >= -10.35 && TA_measure < -3.6)
	{
		Interval = 2;

		PA_measure = EquationED1_I2_mirrorPoloidalAngle(n1y, TA_measure);
	}

	if (TA_measure >= -3.6 && TA_measure < 3.6)
	{
		Interval = 3;

		PA_measure = EquationED1_I3_mirrorPoloidalAngle(n1y, TA_measure);
	}

	if (TA_measure >= 3.6 && TA_measure < 10.4)
	{
		Interval = 4;

		PA_measure = EquationED1_I4_mirrorPoloidalAngle(n1y, TA_measure);
	}

	if (TA_measure >= 10.4 && TA_measure <= 15)
	{
		Interval = 5;

		PA_measure = EquationED1_I5_mirrorPoloidalAngle(n1y, TA_measure);
	}

	//char nameOfTheFile[] = "resultAngleDeviation";
	//char numberToWrite[100];

	printf("XA ------- Setpoint -------  Measure ------- Deviation\n");
	printf("TA: -----    %f    -----   %f    -----     %f\n", TA_setpoint, TA_measure, (TA_setpoint - TA_measure) *100 / TA_setpoint);
	//writeOnTextFile(numberToWrite);
	printf("PA: -----    %f    -----   %f    -----     %f\n\n", PA_setpoint, PA_measure, (PA_setpoint - PA_measure) *100 / PA_setpoint);

}

void displayN1X(double equation,double TA)
{
	printf("With TA = %f    -----   N1X = %f\n", TA, equation);
}

void displayN1Y(double equation, double TA, double PA)
{
	printf("With TA = %f and PA = %f -----   N1Y = %f\n", TA, PA, equation);
}

double askDoubleTA(void)
{
	double TA;
	printf("Enter a Toroidal Angle to have is equivalent in turn for N1X or N1Y\n");
	scanf_s("%lf", &TA);
	return TA;
}

double askDoublePA(void)
{
	double PA;
	printf("Enter a Poroidal Angle to have is equivalent in turn for N1Y\n");
	scanf_s("%lf", &PA);
	return PA;
}

/*
void writeOnTextFile(char numberToWrite)
{
	FILE* fichier = NULL;

		fichier = fopen("test.txt", "a");
	if (fichier != NULL)
	{
		fputs(numberToWrite, fichier);
		fclose(fichier);
	}
}
*/

