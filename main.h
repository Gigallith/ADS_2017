//
// Created by user on 20/08/2017.
//

#ifndef ADS_2017_MAIN_H
#define ADS_2017_MAIN_H

#endif //ADS_2017_MAIN_H



typedef struct WeightedEdge WeightedEdge;
struct WeightedEdge
{
    int x;
    int y;
    int cost;
};



// Liste chainée d'arêtes
typedef struct Element Element;
struct Element
{
    struct WeightedEdge edge;
    Element *suivant;
};
typedef struct List List;
struct List
{
    Element *first;
};




typedef struct WeightedUnDiGraph WeightedUnDiGraph;
struct WeightedUnDiGraph
{
    List list;
};
typedef struct ListWeightedUnDiGraph ListWeightedUnDiGraph;
struct ListWeightedUnDiGraph
{
    WeightedUnDiGraph *first;

};
