#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student 
{
	char *vorname;
	char *nachname;
	int mtr;
}staticstudent, *dynamicstudent; /*staticstudent & dynamicstudent sind globale Variablen vom Typ student*/


int main(void)
{
	/* ++++++++++++++++++++Verarbeiten von staticstudent++++++++++++++++++++++++*/
	staticstudent.vorname = (char*)malloc(sizeof(char)*32);
	staticstudent.nachname = (char*)malloc(sizeof(char)*32);

	strcpy(staticstudent.vorname, "Hans");
	strcpy(staticstudent.nachname, "Mustermann");
	staticstudent.mtr = 123;

	/*Ausgabe*/
	printf("%s %s %d", staticstudent.vorname, staticstudent.nachname, staticstudent.mtr);

	/*Inneren Speicher freigeben*/
	free(staticstudent.vorname);
	free(staticstudent.nachname);
	staticstudent.vorname = NULL;
	staticstudent.nachname = NULL;


	/* ++++++++++++++++++++Verarbeiten von dynamicstudent++++++++++++++++++++++++*/
	dynamicstudent = (struct student*)malloc(sizeof(struct student));
	dynamicstudent->vorname = (char*)malloc(sizeof(char)*32);

	strcpy(dynamicstudent->vorname, "Hans");
	strcpy(dynamicstudent->nachname, "Mustermann");
	dynamicstudent->mtr = 123;

	/*Ausgabe*/
	printf("%s %s %d", dynamicstudent->vorname, dynamicstudent->nachname, dynamicstudent->mtr);
	
	/*Freigabe, erst innere Speicher, dann struct selbst*/
	free(dynamicstudent->vorname);
	free(dynamicstudent->nachname);

	free(dynamicstudent);
	dynamicstudent = NULL; /*UseAfterFree verhindern*/

	return 0;
}


/*
 *	staticstudent ist im statischen Bereich (Stack) 20Byte groß. 
 *	8Byte Pointer Vorname + 8Byte Pointer Vorname + 4Byte int mtr
 *	im dynamischen Bereich (Heap) 2*32Byte für malloc Vor- und Nachname
 *
 *	dynamicstudent ist im statischen Bereich 8Byte groß (weil Pointer)
 *	im dynamischen Bereich (Heap) 8Byte Pointer Vorname + 8Byte Pointer Vorname + 4Byte int mtr + 2*32Byte für malloc Vor- und Nachname
 *
 *
 *
 *
 *
 */
