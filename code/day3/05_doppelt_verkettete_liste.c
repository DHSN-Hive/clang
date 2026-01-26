#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct namen {
  int nr;
  char *name;
  struct namen *prev;
  struct namen *next;
};

typedef struct namen sname;

sname *firstElement = NULL, *lastElement = NULL;

sname *NewElement(int n, char *na) {
  sname *nE = (sname *)malloc(sizeof(sname));
  nE->next = NULL;
  nE->prev = NULL;

  nE->name = (char *)malloc(sizeof(char) * (strlen(na) + 1));
  strcpy(nE->name, na);
  nE->nr = n;

  return nE;
}

void InsertElement(int n, char *na) {
  sname *nE = NewElement(n, na);

  if (firstElement == NULL)
    firstElement = lastElement = nE;
  else {
    firstElement->prev = nE;
    nE->next = firstElement;
    firstElement = nE;
  }
}

void AddElement(int n, char *na) {
  if (firstElement == NULL)
    InsertElement(n, na);
  else {
    sname *nE = NewElement(n, na);
    lastElement->next = nE;
    nE->prev = lastElement;
    lastElement = nE;
  }
}

void List() {
  sname *aE = firstElement; /*aE für aktuelles Element*/
  while (aE != NULL) {
    printf("Element %p, Nr: %d, Name: %s\n", aE, aE->nr, aE->name);
    aE = aE->next;
  }
}

void Cleanup() {
  while (firstElement != NULL) {
    sname *nE = firstElement->next;
    free(firstElement->name);
    free(firstElement);
    firstElement = nE;
  }
}

/* Vier Elemente sind vom Tausch betroffen
 *	    <->
 * 	[] [] [] []
 * 	pE aE nE nnE
 *
 * Es müssen pE->next, aE->prev, aE->next, nE->prev, nE->next, nnE->prev
 * angepasst werden
 */
sname *Swap(sname *aE) {
  if (aE == NULL || aE->next == NULL)
    return aE;

  sname *pE = aE->prev;
  sname *nE = aE->next;
  sname *nnE = nE->next;

  if (pE != NULL && nnE != NULL) {
    pE->next = nE;
    nnE->prev = aE;
  }

  else if (pE == NULL)
    nnE->prev = aE;

  else if (nnE == NULL)
    pE->next = nE;

  aE->prev = nE;
  aE->next = nnE;
  nE->prev = pE;
  nE->next = aE;

  return nE;
}

void Sort() {
  sname *aE = firstElement;
  if (aE == NULL || aE->next == NULL)
    return;

  while (aE->next != NULL) {
    if (aE->nr > aE->next->nr) {
      aE = Swap(aE);
      if (aE->prev != NULL)
        aE = aE->prev;
      else
        firstElement = aE;
    } else {
      aE = aE->next;
    }
  }
  lastElement = aE;
}

int main(void) {
  AddElement(1, "Raphael Götz");
  InsertElement(2, "Moritz Poßecker");
  AddElement(5, "Marius Ahsmus");
  AddElement(6, "Kevin Schubert");
  AddElement(3, "Roland Neuber");
  InsertElement(4, "Marlon Lange");
  AddElement(7, "Tim Möller");

  List();
  printf("__________________________________\n");
  Sort();
  List();
  Cleanup();
  return 0;
}

/* Hausaufgabe: Wv Swapaufrufe brauchen wir? Kann man das noch optimieren? */
