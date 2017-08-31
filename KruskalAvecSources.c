//
// Created by user on 27/08/2017.
//

const int NB_OF_NODE = 6;
const int MAX_WEIGHT = 15;

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

    //On récupère le nombre d'arètes
    int nbOfEdges = 0;
    for (int i = 0; i<NB_OF_NODE; i++)
    {
        for (int j = 0; j<NB_OF_NODE; j++)
        {
            if (wudg[i][j] != 0)
            {
                nbOfEdges++;
            }
        }
    }
    nbOfEdges = nbOfEdges / 2;

    //On fait une liste contenant le nombre d'arêtes de même poids
    int weights[MAX_WEIGHT];
    for (int i = 0; i<MAX_WEIGHT; i++)
    {
        for (int j = 0; j<MAX_WEIGHT; j++)
        {
            if (j > i)
                weights[wudg[i][j]]++;
        }
    }

    //création des tableaux contenant les arêtes
    int edgeWeight1[2][weights[1]];
    int edgeWeight2[2][weights[2]];
    int edgeWeight3[2][weights[3]];
    int edgeWeight4[2][weights[4]];
    int edgeWeight5[2][weights[5]];
    int edgeWeight6[2][weights[6]];
    int edgeWeight7[2][weights[7]];
    int edgeWeight8[2][weights[8]];
    int edgeWeight9[2][weights[9]];
    int edgeWeight10[2][weights[10]];
    int edgeWeight11[2][weights[11]];
    int edgeWeight12[2][weights[12]];
    int edgeWeight13[2][weights[13]];
    int edgeWeight14[2][weights[14]];
    int edgeWeight15[2][weights[15]];




    return 0;
}