#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct name {
  int nr;
  char *name;
  struct name *next;
};

typedef struct name sname; /*So kann man sname statt struct name schreiben*/

sname *NewElement(int n, char *na) {
  sname *tE = (sname *)malloc(sizeof(sname));
  tE->name = (char *)malloc(sizeof(char) * (strlen(na) + 1));

  strcpy(tE->name, na);
  tE->nr = n;
  tE->next = NULL;

  return tE;
}

sname *AddElement(sname *lE, int n, char *na) {
  /*Funkltion hängt an Liste an und gibt die Adresse des letzten Elements
   * zurück*/

  sname *newElement = NewElement(n, na);

  if (lE != NULL) /*neue Liste*/
    lE->next = newElement;
  return newElement;
}

sname *InsertElement(sname *fE, int n, char *na) {
  /*Funktion hängt ein Element vorn an die Liste und gibt das neue erste Element
   * zurück*/

  if (fE == NULL)
    return AddElement(fE, n, na);
  else {
    sname *newElement = NewElement(n, na);
    newElement->next = fE;
    return newElement;
  }
}

void List(sname *tE) {
  for (; tE != NULL; tE = tE->next)
    printf("Element [%p] -> Nr: [%10d], Name: [%s]\n", tE, tE->nr, tE->name);
}

void Cleanup(sname *fE) {
  while (fE != NULL) {
    sname *tE = fE;
    fE = fE->next;
    free(tE->name);
    free(tE);
  }
}

void swap(sname *prevE, sname *currentE) {
  sname *nextE = currentE->next;
  sname *nnextE = nextE->next;

  if (prevE != NULL)
    prevE->next = nextE;
  currentE->next = nnextE;
  nextE->next = currentE;
}

sname *sort(sname *fE) {
  if (fE == NULL)
    return fE;

  sname *tE = fE;
  sname *pE = NULL; /*Vorheriges Element*/
  while (tE->next != NULL) {
    if (tE->nr > tE->next->nr) {
      if (pE == NULL)
        fE = tE->next;
      swap(pE, tE); /*tE und tE->next werden getauscht, pE wird mitgegeben, weil
                       es geändert werden muss*/
      tE = fE;
      pE = NULL;
    } else {
      pE = tE;
      tE = tE->next;
    }
  }
  return fE;
}

int main(void) {
  sname *firstElement = NULL, *lastElement = NULL;
  firstElement = lastElement =
      InsertElement(firstElement, 12, "Hans Mustermann");
  firstElement = InsertElement(firstElement, 13, "Marius Ahsmus");
  lastElement = AddElement(lastElement, 14, "Roland Neuber");
  lastElement = AddElement(lastElement, 15, "Rapahel Götz");
  lastElement = AddElement(lastElement, 16, "Moritz Poßecker");

  List(firstElement);
  printf("----------------------------------------------------------\n");
  firstElement = sort(firstElement);
  List(firstElement);

  Cleanup(firstElement);
  return 0;
}
