#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct element
{
	int mtr;
	char *vorname;
	char *nachname;
	struct element *next;
};

/*globale Variable Erstes Element der Liste*/
struct element *firstElement = NULL;

struct element * NewElement(int m, char *v, char *n) /*Neues Element erstellen*/
{
	struct element *tempElement = (struct element*)malloc(sizeof(struct element));
	tempElement->vorname = (char*)malloc(sizeof(char)*(strlen(v)+1));
	tempElement->nachname = (char*)malloc(sizeof(char)*(strlen(n)+1));

	/*Beschreiben des Speichers*/ /* (*tempElement).vorname ist eine andere Schreibweise von tempElement->vorname */
	strcpy((*tempElement).vorname, v);
	strcpy((*tempElement).nachname, n);
	(*tempElement).mtr = m;
	
	(*tempElement).next = NULL;

	return tempElement;
}

void AddElement(int m, char *v, char *n) /*Element an Liste anhängen*/
{
	if (firstElement == NULL) 
		firstElement = NewElement(m, v, n);
	else
	{
		struct element *newElement = NewElement(m,v,n);
		/*Neues Element mit dem bisherigen firstElement verknüpfen*/
	       	newElement->next = firstElement;

		/*firstElement new setzen, denn das neue Element ist das neue firstElement*/
		firstElement = newElement;			
	}
}

void OutputElement(struct element *e)
{
	printf("Element Speicher [%p]: Vorname :[%s], Nachname [%s], Mtr: [%d]\n", e, e->vorname, e->nachname, e->mtr);
}

void List() /*Liste ausgeben*/
{
	/*Adresse des ersten Elements in Tempvariable holen*/
	struct element *tempElement = firstElement;

	while(tempElement != NULL)
	{
		OutputElement(tempElement);
		tempElement = tempElement->next;
	}
}

void Cleanup() /*Speicher freigeben*/
{

	while(firstElement != NULL)
	{
		/*firstElement auf das neue erste Element setzen*/
		struct element *tempElement = firstElement;
		firstElement = tempElement->next;

		/*zerstören des Speichers von tempElement, was das alte firstElement ist*/
		free(tempElement->vorname);
		free(tempElement->nachname);
		free(tempElement);
		
	}
}

int main(void)
{
	/*erstes Add erstellt die Liste*/
	AddElement(123, "Hans", "Mustermann");

	/*Fügen Elemente an den Anfang der Liste*/
	AddElement(124, "Raphael", "Goetz");
	AddElement(125, "Moritz", "Possecker");
	AddElement(126, "Roland", "Neuber");

	/*Ausgabe der Liste*/
	List();

	/*Speicher wieder freigeben*/
	Cleanup();

	return 0;
}
