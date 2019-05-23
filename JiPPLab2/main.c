#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void formatuj_rnie(int tab[]);
double oblicz_delte(int tab[]);
void oblicz_pierwiastki(int tab[], double* x1r, double* x2r, double* x3r, double* x4r,
	double* x1u, double* x2u, double* x3u, double* x4u);
void dodaj_l_zesp(double* x1r, double* x2r, double* x3r, double* x4r,
	double* x1u, double* x2u, double* x3u, double* x4u, double* sr, double* su);
void odejm_l_zesp(double* x1r, double* x2r, double* x3r, double* x4r,
	double* x1u, double* x2u, double* x3u, double* x4u, double* sr, double* su);
void wyswietl_wyniki(int tab[], double* x1r, double* x2r, double* x3r, double* x4r,
	double* x1u, double* x2u, double* x3u, double* x4u, double* sr, double* su, double* rr, double* ru);
double oblicz_delte(int tab[]);

int main()
{
	int* tab = malloc(3 * sizeof(int));

	printf("a: ");
	scanf_s("%d", &tab[0]);

	printf("b: ");
	scanf_s("%d", &tab[1]);

	printf("c: ");
	scanf_s("%d", &tab[2]);

	int a = tab[0];
	int b = tab[1];
	int c = tab[2];

	double x1r = 0, x2r = 0, x3r = 0, x4r = 0, x1u = 0, x2u = 0, x3u = 0, x4u = 0;
	double sr = 0, su = 0, rr = 0, ru = 0;

	formatuj_rnie(tab);

	if (a != 0 || b != 0) {
		oblicz_pierwiastki(tab, &x1r, &x2r, &x3r, &x4r, &x1u, &x2u, &x3u, &x4u);
		dodaj_l_zesp(&x1r, &x2r, &x3r, &x4r, &x1u, &x2u, &x3u, &x4u, &sr, &su);
		odejm_l_zesp(&x1r, &x2r, &x3r, &x4r, &x1u, &x2u, &x3u, &x4u, &sr, &su);
		wyswietl_wyniki(tab, &x1r, &x2r, &x3r, &x4r, &x1u, &x2u, &x3u, &x4u, &sr, &su, &rr, &ru);
	}

	return 0;
}

double oblicz_delte(int tab[]) {
	int a = tab[0];
	int b = tab[1];
	int c = tab[2];
	double delta = 0;
	if (a != 0) {
		delta = 1.0 * a * a - 4.0 * a * c;
	}
	else if (b != 0) {
		delta = -4.0 * b * c;
	}
	return delta;
}

void formatuj_rnie(int tab[]) {
	int a = tab[0];
	int b = tab[1];
	int c = tab[2];

	//wszystkie mozliwosci a
	if (a != 0)
	{
		if (a == -1)
		{
			printf("-xxxx");
		}
		else if (a == 1)
		{
			printf("xxxx");
		}
		else
		{
			printf("%dxxxx", a);
		}

		//wszystkie mozliwosci b
		if (b != 0)
		{
			if (b < 0) //b ujemne
			{
				printf("%dxx", b);
			}
			else {
				printf("+%dxx", b);
			}
		}

		//c
		if (c != 0) {
			if (c < 0) {
				printf("%d", c);
			}
			else {
				printf("+%d", c);
			}
		}
		printf("=0\n");
	}
	else {
		if (b != 0) {
			printf("%dxx", b);
			if (c != 0) {
				if (c < 0) {
					printf("%d", c);
				}
				else {
					printf("+%d", c);
				}
			}
			printf("=0\n");
		}
		else {
			if (c != 0) {
				printf("Równanie sprzeczne.\n");
			}
			else {
				printf("Równanie to¿samoœciowe.\n");
			}
		}
	}
	//koniec wypisywania
}

void oblicz_pierwiastki(int tab[], double* x1r, double* x2r, double* x3r, double* x4r,
	double* x1u, double* x2u, double* x3u, double* x4u) {
	int a = tab[0];
	int b = tab[1];
	int c = tab[2];

	if (a != 0) { //a nierwone 0
		double delta = oblicz_delte(tab);

		if (delta > 0) { //delta dodatnia
			double pdelta = sqrt(delta);

			double t1 = (-1.0 * a - pdelta) / (2.0 * a);
			double t2 = (-1.0 * a + pdelta) / (2.0 * a);

			if (t1 >= 0) { //t1 dodatnie lub rowne 0
				*x1r = sqrt(t1);
				*x2r = -1.0 * sqrt(t1);
			}
			else { //t1 ujemne
				*x1r = 0.0;
				*x1u = sqrt(-1.0 * t1);
				*x2r = *x1r;
				*x2u = -1.0 * *x1u;
			}

			if (t2 >= 0) { //t2 wieksze lub rowne 0
				*x3r = sqrt(t2);
				*x4r = -1.0 * sqrt(t2);
			}
			else { //t2 ujemne
				*x3r = 0.0;
				*x3u = sqrt(-1.0 * t2);
				*x4r = *x3r;
				*x4u = -1.0 * *x3u;
			}
		}
		else if (delta == 0) {//delta rowna 0
			double t = (-1.0 * b) / (2.0 * a);

			if (t >= 0) { // t wieksze lub rowne 0
				*x1r = sqrt(t);
				*x2r = -1.0 * sqrt(t);
			}
			else { // t ujemne
				*x1r = 0.0;
				*x1u = sqrt(-1.0 * t);
				*x2r = *x1r;
				*x2u = -1.0 * *x1u;
			}
		}
		else { //delta ujemna
			double pdelta = sqrt(-1.0 * delta);

			double t1r = (-1.0 * b) / (2.0 * a);
			double t1u = (-1.0 * pdelta) / (2.0 * a);
			double t2r = t1r;
			double t2u = (1.0 * pdelta) / (2.0 * a);

			*x1r = sqrt((sqrt(t1r * t1r + t1u * t1u) + t1r) / 2.0);
			*x1u = sqrt((sqrt(t1r * t1r + t1u * t1u) - t1r) / 2.0);

			*x2r = *x1r;
			*x2u = -1.0 * *x1u;

			*x3r = -1.0 * sqrt((sqrt(t2r * t2r + t2u * t2u) + t2r) / 2.0);
			*x3u = -1.0 * sqrt((sqrt(t2r * t2r + t2u * t2u) - t2r) / 2.0);

			*x4r = *x3r;
			*x4u = -1.0 * *x3u;
		}
	}
	else if (b != 0) {//a rowne 0, b rozne od 0
		double delta = oblicz_delte(tab);

		if (delta > 0) { //delta dodatnia
			double pdelta = sqrt(delta);
			*x1r = (-1.0 * pdelta) / (2.0 * b);
			*x2r = (1.0 * pdelta) / (2.0 * b);
		}
		else if (delta == 0) {//delta rowna 0
			*x1r = 0.0;
			*x2r = *x1r;
		}
		else { //delta ujemna
			double delta_2 = -1.0 * delta;
			double pdelta = sqrt(delta_2);

			*x1r = 0.0;
			*x1u = (-1.0 * pdelta) / (2.0 * b);
			*x2r = 0.0;
			*x2u = (1.0 * pdelta) / (2.0 * b);
		}
	}
}

void dodaj_l_zesp(double* x1r, double* x2r, double* x3r, double* x4r,
	double* x1u, double* x2u, double* x3u, double* x4u, double* sr, double* su) {
	*sr = *x1r + *x2r + *x3r + *x4r;
	*su = *x1u + *x2u + *x3u + *x4u;
}

void odejm_l_zesp(double* x1r, double* x2r, double* x3r, double* x4r,
	double* x1u, double* x2u, double* x3u, double* x4u, double* sr, double* su) {
	*sr = 0 - *x1r - *x2r - *x3r - *x4r;
	*su = 0 - *x1u - *x2u - *x3u - *x4u;
}

void wyswietl_wyniki(int tab[], double* x1r, double* x2r, double* x3r, double* x4r,
	double* x1u, double* x2u, double* x3u, double* x4u, double* sr, double* su, double* rr, double* ru) {
	int a = tab[0];
	int b = tab[1];
	int c = tab[2];
	if (a != 0) {
		double delta = oblicz_delte(tab);

		if (delta != 0) //delta rozna od zera
		{
			//wypisz x1
			printf("x1 = %f", *x1r);
			if (*x1u < 0) //x1u mniejsze od zera
			{
				printf("%fi\n", *x1u);
			}
			else // x1u wieksze lub rowne 0
			{
				printf("+%fi\n", *x1u);
			}
			//wypisz x2
			printf("x2 = %f", *x2r);
			if (*x2u < 0) //x2u mniejsze od zera
			{
				printf("%fi\n", *x2u);
			}
			else // x2u wieksze lub rowne 0
			{
				printf("+%fi\n", *x2u);
			}
			//wypisz x3
			printf("x3 = %f", *x3r);
			if (*x3u < 0) //x2u mniejsze od zera
			{
				printf("%fi\n", *x3u);
			}
			else // x3u wieksze lub rowne 0
			{
				printf("+%fi\n", *x3u);
			}
			//wypisz x4
			printf("x4 = %f", *x4r);
			if (*x4u < 0) //x2u mniejsze od zera
			{
				printf("%fi\n", *x4u);
			}
			else // x4u wieksze lub rowne 0
			{
				printf("+%fi\n", *x4u);
			}
		}
		else // delta rowna 0
		{
			printf("x1 = %f", *x1r); // wypisz x1
			if (*x1u < 0) //x1u mniejsze od zera
			{
				printf("%fi\n", x1u);
			}
			else//x1u wieksze lub rowne zero
			{
				printf("+%fi\n", x1u);
			}
			printf("x2 = %f", *x1r); // wypisz x2
			if (*x2u < 0) //x2u mniejsze od zera
			{
				printf("%fi\n", x2u);
			}
			else//x2u wieksze lub rowne zero
			{
				printf("+%fi\n", x2u);
			}
		}
	}
	else //a rowne zero
	{
		double delta = oblicz_delte(tab);

		if (delta < 0) //delta ujemna
		{
			printf("x1: %f", *x1r); //wypisz x1
			if (*x1u < 0)//x1u ujemne
			{
				printf("%fi\n", *x1u);
			}
			else //x1u wieksze lub rowne zero
			{
				printf("+%fi\n", *x1u);
			}
			printf("x2: %f", *x2r); //wypisz x2
			if (*x2u < 0)//x2u ujemne
			{
				printf("%fi\n", *x2u);
			}
			else //x2u wieksze lub rowne zero
			{
				printf("+%fi\n", *x2u);
			}
		}
		else //delta wieksza lub rowna zero
		{
			printf("x1: %f\n", *x1r);
			printf("x2: %f\n", *x2r);
		}
	}

	printf("sr: %f\n", *sr);
	printf("su: %f\n", *su);
	printf("rr: %f\n", *rr);
	printf("ru: %f\n", *ru);
}