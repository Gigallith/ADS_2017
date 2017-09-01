#include "table.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//
// Fonctions elementaires de manipulation de la table
//


/* Creation d'une table vide */
Table creer_table(void) {
	return NULL;
}

/* Insertion d'un élément dans la table triée. Si l'élément est déjà
 * présent dans la table, le compteur d'occurrences est incrémenté.
 * La fonction renvoie le nombre actuel d'occurrences de elt */
 //D'abord, on trouve où faire l'insertion.
 //pp sert à garder en mémoire l'élément d'avant pour changer son next.
int ajouter_table(Table *t, int elt) {
	t_table *p = *t;
	t_table *d = p;
	t_table *pp = NULL;
	while (p != NULL) {
		pp = p;
		p = p-> next;
	}
	t_table *e = malloc(sizeof(t_table));
	e -> next = p;
	if (pp == NULL) {
		*t = e;
	} else {
		pp -> next = e;
	}

	e-> vertice = elt;
	return 1;
}
/*
Suppression d'un élément de la table, peu importe son nombre d'occurence
*/
int supprimer_table(Table *t, int elt){
	int r = 0;
	t_table *p = *t;
	t_table *pp = NULL;
	while (p != NULL && (p-> vertice != elt)) {
		pp = p;
		p = p-> next;
	}
	if(pp == NULL){
		if(p != NULL){
			r = 1;
		}
		pp = p -> next;
	}
	else{
		pp -> next = p -> next;
		if(p -> next != NULL){
			r = 1;
		}
	}
	*t = pp;
	return r;
}

/* Impression triée des éléments de la table */
void imprimer_table(Table table) {
	t_table *p;
	for (p = table; p != NULL; p = p -> next) {
		printf("%d ",p-> vertice);
	}
	printf("\n");
}

/* Appel d'une fonction sur chacun des éléments de la table */
//void appliquer_table(Table table, t_fonction fonction) {}

/* Recherche du nombre d'occurrences d'un élément */
//int rechercher_table(Table table, char *elt){}

/* Destruction d'une table */
void detruire_table(Table *table){
	free(table);
}

/*int main() {
	int *a = malloc(10 * sizeof(int));
  *(a+1) = 1;
  int *b = (int *)realloc(a,20 * sizeof(int));
	free(a);
	a = b;
  *(a+15) = 2;
  printf("%d\n",*(a+15));
	Table t;
	t = creer_table();
	ajouter_table(&t, 1);
	imprimer_table(t);
	ajouter_table(&t, 2);
	imprimer_table(t);
	ajouter_table(&t, 3);
	ajouter_table(&t, 4);
	ajouter_table(&t, 5);
	ajouter_table(&t, 6);
	imprimer_table(t);
	supprimer_table(&t,1);
	ajouter_table(&t,1);
	imprimer_table(t);
	return 0;
}*/
