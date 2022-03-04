#include <stdio.h>

/* Fonction pour g�n�rer et retourner des nombres al�atoires */
int * Random() {

	static int  r[10];
	int i;

	/* D�finir la graine */
	srand((unsigned)time(NULL));

	for (i = 0; i < 10; ++i) {
		r[i] = rand();
		printf("r[%d] = %dn", i, r[i]);
	}

	return r;
}

/* Fonction principale qui va appeler la fonction ci-dessus*/
int mainpointerToArray() {

	/* Un pointeur vers un entier  */
	int *p;
	int i;

	p = Random();

	for (i = 0; i < 10; i++) {
		printf("*(p + %d) : %dn", i, *(p + i));
	}

	return 0;
}