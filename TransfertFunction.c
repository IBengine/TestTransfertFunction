#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "TransfertFunction.h"
#include "betaAngleCalculation.h"
#include "EquationEA.h"

int main() {

	double *p = EquationEA(1, 1, 1, 45);
	//displayArray(p);

	return 0;
}
