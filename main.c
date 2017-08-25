#include <stdio.h>
#include <malloc.h>
#include "main.h"

const int NB_OF_SOURCES = 2;
const int NB_OF_HOUSES = 6;

//
//
//int main() {
//
//    //On créé le graphe
//    List *list = initlist();
//    WeightedEdge edge1 = {2,5,3};
//    insertion(list, edge1);
//
//    //On créé la foret
//
//
//
//
//
//    printf("Hello, World!\n");
//    return 0;
//}
//
//
//
////Initialiser la liste d'arêtes
//List* initlist()
//{
//    List *liste = malloc(sizeof(*liste));
//    Element *element = malloc(sizeof(*element));
//
//    if (liste == NULL || element == NULL)
//    {
//        exit(EXIT_FAILURE);
//    }
//
//    element->edge = NULL;
//    element->suivant = NULL;
//    liste->first = element;
//
//    return liste;
//}
//
////Ajoute au début de la liste une arête
//void insertion(List *liste, WeightedEdge newEdge)
//{
//    /* Création du nouvel élément */
//    Element *nouveau = malloc(sizeof(*nouveau));
//    if (liste == NULL || nouveau == NULL)
//    {
//        exit(EXIT_FAILURE);
//    }
//    nouveau->edge = newEdge;
//
//    /* Insertion de l'élément au début de la liste */
//    nouveau->suivant = liste->first;
//    liste->first = nouveau;
//}
//
////Initialiser la forêt
//ListWeightedUnDiGraph *initforest()
//{
//    ListWeightedUnDiGraph *liste = malloc(sizeof(*liste));
//    WeightedUnDiGraph *graph = malloc(sizeof(*graph));
//
//    if (liste == NULL || graph == NULL)
//    {
//        exit(EXIT_FAILURE);
//    }
//
//    graph->edges = NULL;
//    graph->list = NULL;
//    liste->first = graph;
//
//    return liste;
//}
//void addGraph(List *liste, WeightedEdge newEdge)
//{
//    /* Création du nouvel élément */
//    Element *nouveau = malloc(sizeof(*nouveau));
//    if (liste == NULL || nouveau == NULL)
//    {
//        exit(EXIT_FAILURE);
//    }
//    nouveau->edge = newEdge;
//
//    /* Insertion de l'élément au début de la liste */
//    nouveau->suivant = liste->first;
//    liste->first = nouveau;
//}
//
//void initWeightedUnDiGraph(struct WeightedUnDiGraph *graph)
//{
//    graph->
//}
//
