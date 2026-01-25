#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Strukturen */

struct student 
{
	int mtr;
	char *vorname;
	char *nachname;
};

struct student * createstudent(int m, char *v, char *n)
{
	/*Speicher reservieren für struct student*/
	struct student *newElement = (struct student*)malloc(sizeof(struct student));

	/*Speicher reservieren für die Elemente des structs student*/
	newElement->vorname = (char *)malloc(sizeof(char)*(strlen(v)+1));
	newElement->nachname = (char *)malloc(sizeof(char)*(strlen(n)+1));

	/*Beschreiben des Speichers*/
	strcpy(newElement->vorname, v);
	strcpy(newElement->nachname, n);
	newElement->mtr = m;

	return newElement; /*Der Rückgabewert ist nur eine Zahl*/
}

void deletestudent(struct student *s)
{
	free(s->vorname);
	free(s->nachname);
	free(s);
}

void outputstudent(struct student *s)
{
	printf("Student an Pointer [%p] ist Mtr: [%d], Vorname: [%s], Nachname [%s]\n",s, s->mtr, s->vorname, s->nachname);
}

int main(void)
{
	struct student *s1 = NULL;
	struct student *s2 = NULL;

	/*Speicher reservieren und befüllen*/
	s1 = createstudent(123, "Raphael", "Goetz");
	s2 = createstudent(123, "Moritz", "Posseker");

	/*Speicher ausgeben*/
	outputstudent(s1);
	outputstudent(s2);

	/*Speicher freiegeb*/
	deletestudent(s1);
	deletestudent(s2);

}
