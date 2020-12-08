#include <iostream>
#include <string>
#include <math.h>
#include "movie.hpp"
using namespace std;

movie::movie(){
}
movie::movie(int i, std::string t, int d, std::string g, double r, int o){
  id=i;
  title=t;
  duration=d;
  genre=g;
  rating=r;
  oscars=o;
}


void movie::printAll(){
  cout<<id<<" "<<title<<" "<<duration<<" "<<genre<<" "<<rating<<" "<<oscars;
}

int movie::getId(){
  return id;
}

string movie::getGenre(){
  return genre;
}

float movie::getRating(){
  return rating;
}

void movie::realRating(){//Si la pelicual ha ganado un oscar se le suma +1 al su rating
  rating=round(rating);
  if (rating<5 && oscars>0){
    rating++;
  }
  //cout<<rating<<"\n";
}
void movie::setOscars(int o){
  oscars=o;
}