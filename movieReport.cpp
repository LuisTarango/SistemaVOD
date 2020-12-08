#include <iostream>
#include <string>
#include <fstream>
#include "movie.hpp"
#include "movieReport.hpp"
using namespace std;


movieReport::movieReport(){
  numMovies=0;
}

movieReport::~movieReport(){
   for (int i = 0; i <= numMovies; i++){
    delete movieList[i];
   }
}

void movieReport::loadMovies(){
  string line;
  int id;
  string title;
  int duration;
  string genre;
  double rating;
  int oscars;

  ifstream movies;
  movies.open("Peliculas.csv");

  while (movies.good()){

    getline(movies,line,',');
    id=stoi(line);

    getline(movies,line,',');
    title=line;

    getline(movies,line,',');
    duration=stoi(line);

    getline(movies,line,',');
    genre=line;

    getline(movies,line,',');
    rating=stod(line);

    getline(movies,line,'\n');
    oscars=stoi(line);
  
    //cout<<id<<" "<<title<<" "<<duration<<" "<<genre<<" "<<rating<<" "<<oscars<<endl;
    movieList[numMovies]=new movie(id,title,duration,genre,rating,oscars);
    numMovies++;
  }
  cout<<numMovies<<" Movies Loaded Succesfully."<<endl;
}

void movieReport::dispMovies(){
  for (int i=0; i < numMovies; i++ ){
    movieList[i]->printAll();
    cout<<"\n";
  }
}

void movieReport::dispGenre(string gen){
  bool validate=false;
  string genre;
  for (int i=0; i < numMovies; i++ ){
    genre=movieList[i]->getGenre();
    if (gen==genre){
      movieList[i]->printAll();
      cout<<"\n";
      validate=true;
    }
  }
  if (validate==false){
    cout<<"No movies found\n";
  }
}

void movieReport::dispRating(int rat){
  bool validate=false;
  int rating;
  for (int i=0; i < numMovies; i++ ){
    movieList[i]->realRating();
  }
  for (int i=0; i < numMovies; i++ ){
    rating=movieList[i]->getRating();
    if (rat==rating){
      movieList[i]->printAll();
      cout<<"\n";
      validate=true;
    }
  }
  if (validate==false){
    cout<<"No movies found\n";
  }
}

void movieReport::addNew(int i, std::string t, int d, std::string g, double r, int o){
  //ofstream movies;                                //Este segmento agregaba las peliculas al archivo csv, para guardalas anque se cierre el programa
  //movies.open("Peliculas.csv",fstream::app);      //Funciona per no lo inclui en la Build Final
  //movies<<"\n";
  //movies<<i<<","<<t<<","<<d<<","<<g<<","<<r<<","<<o;
  //movies.close();
  movieList[numMovies]=new movie(i,t,d,g,r,o);
  numMovies++;
  cout<<"Succesfully Added Movie to Catalog\n";
}

void movieReport::changeOscars(int id,int o){
  bool validate=false;
  int idCheck;
  for (int i=0; i < numMovies; i++ ){
    idCheck=movieList[i]->getId();
    if (id==idCheck){
      movieList[i]->setOscars(o);
      cout<<"\n";
      validate=true;
    }
  }
  if (validate==false){
    cout<<"No movies found\n";
  }
}