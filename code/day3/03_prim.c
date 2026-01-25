
#include<stdio.h>
#include<stdlib.h>

/*Strukturen*/
struct primzahlen
{
	long primzahl;
	struct primzahlen *next;
};

/*Globale Variablen*/
struct primzahlen *firstElement = NULL;
struct primzahlen *lastElement = NULL;

struct primzahlen *NeuePrimzahl(long p)
{
	struct primzahlen *tempPrimzahl = (struct primzahlen*)malloc(sizeof(struct primzahlen));
	tempPrimzahl->primzahl = p;
	tempPrimzahl->next = NULL;
	return tempPrimzahl;
}

void AddPrimzahl(long p)
{
	struct primzahlen *tempPrimzahl = NeuePrimzahl(p);
	if(firstElement == NULL)
		firstElement = lastElement = tempPrimzahl;
	else
	{
		/* neues Element hinter lastElement anhängen */
		lastElement->next = tempPrimzahl;
		lastElement = tempPrimzahl;
	}
}

void Cleanup()
{
	while(firstElement != NULL)
	{
		struct primzahlen *tempElement = firstElement;
		firstElement = firstElement->next;
		free(tempElement);
	}
	lastElement = firstElement = NULL;

}

void print_prim(long prim, long primcount, long oper)
{
	double prozent = ((double)primcount*100)/prim;
	printf("%10ld %10ld %10lf %10ld\n", prim, primcount, prozent, oper);
}

long is_prim(long prim)
{
	struct primzahlen *tempElement = firstElement;
	long multi1 = tempElement->primzahl, multi2 = prim/3;
	long oper = 1;
	for(;multi1<=multi2;tempElement=tempElement->next,oper++)
	{
		multi1 = tempElement->primzahl;
		if((prim%multi1) == 0)
		{
			return 0;
		}
		else
		{
			multi2 = prim/multi1;
		}
	}
	return oper;
}

int main(void)
{
	long primcount = 1;
	long prim = 2;
	printf("%10s %10s %10s %10s\n", "prim", "primcount","prozent", "oper");
	print_prim(prim, primcount++, 0);
	AddPrimzahl(2);

	for(prim=3;prim<100; prim+=2)
	{
		int oper = is_prim(prim);
		if(oper>0)
		{
			AddPrimzahl(prim);
			print_prim(prim, primcount++, oper);
		}
	}
}
