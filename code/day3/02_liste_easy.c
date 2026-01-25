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

void List()
{
	struct primzahlen *tempElement = firstElement;
	int count = 1;

	while(tempElement != NULL)
	{
		printf("Zahl[%d] ist [%ld]\n", count, tempElement->primzahl);
		/*zum nächsten Element springen*/
		tempElement = tempElement->next;
		count++;
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

int IstPrim(int n)
{
	struct primzahlen *tempElement = firstElement;
	while(tempElement != NULL)
	{
		if(n % tempElement->primzahl == 0)
		{
			return 0;
		}
		tempElement = tempElement->next;
	}
	return 1;
}

int GetAnzahlPrim()
{

	if(firstElement == NULL)
		return 0;

	int i = 0;
	struct primzahlen *tempElement = firstElement;
	
	while(tempElement != NULL)
	{
		tempElement = tempElement->next;
		i++;
	}
	
	return i;
}

int main(void)
{
	int anzahlGesamt = 0;
	AddPrimzahl(2);

	int i = 3;
	for(;i<=100;i++)
	{
		anzahlGesamt++;
		if(IstPrim(i))
		{
			AddPrimzahl(i);
			int anzPrim = GetAnzahlPrim();
		}
	}

	/*List();*/
	Cleanup();

	return 0;
}
