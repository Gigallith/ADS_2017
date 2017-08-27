#include <stdio.h>
#include "main.h"


const int NB_OF_NODE = 6;

int *fcm(WeightedUnDiGraph graph, int sources[]) {
    return 0;
}


int main() {

    //création du graphe
    int wudg[6][6];
    wudg[1][2] = 7;
    wudg[1][3] = 2;
    wudg[2][1] = 7;
    wudg[2][5] = 3;
    wudg[3][1] = 2;
    wudg[3][4] = 6;
    wudg[3][6] = 4;
    wudg[4][3] = 6;
    wudg[4][5] = 5;
    wudg[4][6] = 3;
    wudg[5][2] = 3;
    wudg[5][4] = 1;
    wudg[5][6] = 2;
    wudg[6][3] = 4;
    wudg[6][4] = 3;
    wudg[6][5] = 2;

    //liste des coûts
    int cost[NB_OF_NODE];
    //liste des précédents
    int prev[NB_OF_NODE];
    //liste des coûts connus
    int know[NB_OF_NODE];
    know[0] = 1;
    know[3] = 1;
    //int allKnow = 0;

    //création des graphes de sorties
    int src1[NB_OF_NODE][NB_OF_NODE];
    int in1[NB_OF_NODE];
    in1[0] = 1;
    //int pt1 = 0;
    int src2[NB_OF_NODE][NB_OF_NODE];
    int in2[NB_OF_NODE];
    in2[3] = 1;
    //int pt2 = 0;

    //Pour savoir si tous les sommets sont connus
    int allKnow()
    {
        for ( int i = 0; i<NB_OF_NODE; i++)
        {
            if ( know[i] == 0)
                return 0 ;
        }
        return 1;
    }

    //Première étape de l'algo, on récupère les coûts minimaux des neuds adjacents aux sources
    for (int i = 0; i < NB_OF_NODE; i++) {
        if (know[i] == 1) {
            for (int j = 0; j < NB_OF_NODE; j++) {
                if (wudg[i][j] != 0) {
                    if ((cost[j] == 0 && i != j) || cost[j] > wudg[i][j])
                        cost[j] = wudg[i][j];
                    prev[j] = i;

                }
            }
        }
    }

    while ( allKnow() != 1 ) {
        //On récupère le neud avec le coût le plus petit
        int lowest = cost[0];
        for (int i = 0; i < NB_OF_NODE; i++) {
            if (cost[i] < lowest && cost[i] != 0) {
                lowest = cost[i];
            }
        }
        //On le marque comme connu et on l'ajoute à l'arbre correspondant
        know[lowest] = 1;
        if (in1[prev[lowest]] == 1) {
            src1[lowest][prev[lowest]] = cost[lowest];
            src1[prev[lowest]][lowest] = cost[lowest];
            in1[lowest] = 1;
        } else if (in2[prev[lowest]] == 1) {
            src2[lowest][prev[lowest]] = cost[lowest];
            src2[prev[lowest]][lowest] = cost[lowest];
            in1[lowest] = 1;
        } else {
            printf("Erreur, ajout impossible de l'arête");
        }
        //On met à jour les coûts
        for (int i = 0; i < NB_OF_NODE; i++)
        {
            if (wudg[lowest][i] !=0 && wudg[lowest][i] < cost[i])
            {
                cost[i] = wudg[lowest][i];
                prev[i] = lowest;
            }
        }


    }


    return 0;
}


