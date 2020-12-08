#ifndef SERIES_H_
#define SERIES_H_
#include <iostream>
#include <string>
#include "video.hpp"
#include "episodes.hpp"

using namespace std;

class series:public video{//Hereda de clase video
  private:
    int nEpisodes=0;//Contador de Episodios en serie
    int numEp;
  public:
    series();
    series(int,string,int,string,double,int);
    void printAll();
    void loadEpisodes();//Carag episodios desde archivo csb
    void printEpisodes();//Imprime todos los episodios de la serie
    void printEpisodesRating(int);//Imprime episodios de cierta calificacion de la serie
    void addEpisode();//Agerga un nuevo episodio
    string getGenre();
    float getRating();
    int getId();
    float operator+(series);//Sobre carga que calcula el promedio de los episodios de una serie

    episodes *episodeList[10];//Lista de episodios, el tamano es la mayor cantidad de episodios que se pueden tener
};


#endif 