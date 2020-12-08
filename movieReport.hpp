#ifndef MOVIEREPORT_H_
#define MOVIEREPORT_H_
#include <iostream>
#include <string>
#include "movie.hpp"

using namespace std;


class movieReport{
  private:
   int numMovies;//Numero de peliculas cargadas
  public:
    movieReport();
    ~movieReport();
    void loadMovies();//Carga Peliculas desde archivo csv
    void dispMovies();//Muestra toda la lista de peliculas
    void dispGenre(string);//Mustra Peliculas de un genero en particular
    void dispRating(int);//Muetsra Peliculas de una calificacion en particular
    void addNew(int,string,int,string,double,int);//Agrega nueva pelicula
    void changeOscars(int,int);//Cambia la cantidad de oscares

    movie *movieList[50];
};


#endif 