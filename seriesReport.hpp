#ifndef SERIESREPORT_H_
#define SERIESREPORT_H_
#include <iostream>
#include <string>
#include "series.hpp"

using namespace std;

class seriesReport{
    private:
        int numSeries=0;//Numero de series caragdas
    public:
    seriesReport();
    ~seriesReport();
    void loadSeries();//Cragar series desde archivo csv
    void dispSeries();//Mostrar todas las series
    void dispGenre(string);//Mostrar series de cierto Genero
    void dispEpisodes(int);//Mostrar Episodios de una serie
    void dispRating(int);//Mostrar Serie de cierta calificacion
    void printEpisodesByRating(int,int);//Mostarra episodios de una serie de cierta calificacion
    void avgRating();//Mostrar calificacion promedio de episodios de una serie
    void addEpisode(int);//Agregar un nuevo episodio

    series *seriesList[50];//Lista de series, el tamano es la mayor capacidad de series que se pueden tener
};

#endif