#ifndef MOVIE_H_
#define MOVIE_H_
#include <iostream>
#include <string>
#include "video.hpp"

using namespace std;

class movie:public video{//Hereda de clase video
  private:
    int oscars;
  public:
    movie();
    movie(int,string,int,string,double,int);
    void printAll();//Imprime todos los datos de la pelicula
    int getId();
    string getGenre();
    float getRating();
    void realRating();//Calcula el Rating de las peliculas redondeado y suma +1 si la pelicula tiene oscares
    void setOscars(int);
};


#endif 