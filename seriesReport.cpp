#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include "seriesReport.hpp"

using namespace std;

seriesReport::seriesReport(){
}

seriesReport::~seriesReport(){
}

void seriesReport::loadSeries(){
  string line;
  int id;
  string title;
  int duration;
  string genre;
  double rating;
  int episodes;

  ifstream ser;
  ser.open("ArchivoSerie.csv");

  while (ser.good()){

    getline(ser,line,',');
    id=stoi(line);

    getline(ser,line,',');
    title=line;

    getline(ser,line,',');
    duration=stoi(line);

    getline(ser,line,',');
    genre=line;

    getline(ser,line,',');
    rating=stod(line);

    getline(ser,line,'\n');
    episodes=stoi(line);
  
    //cout<<id<<" "<<title<<" "<<duration<<" "<<genre<<" "<<rating<<" "<<episodes<<endl;
    seriesList[numSeries]=new series(id,title,duration,genre,rating,episodes);
    seriesList[numSeries]->loadEpisodes();
    numSeries++;
  }
  cout<<numSeries<<" Series Loaded Succesfully."<<endl;
}

void seriesReport::dispSeries(){
  for (int i=0; i < numSeries; i++ ){
    seriesList[i]->printAll();
    cout<<"\n";
  }
}

void seriesReport::dispGenre(string gen){
  bool validate=false;
  string genre;
  for (int i=0; i < numSeries; i++ ){
    genre=seriesList[i]->getGenre();
    if (gen==genre){
      seriesList[i]->printAll();
      cout<<"\n";
      validate=true;
    }
  }
  if (validate==false){
    cout<<"No series found\n";
  }
}

void seriesReport::dispRating(int rat){
  bool validate=false;
  int rating;
  for (int i=0; i < numSeries; i++ ){
    rating=seriesList[i]->getRating();
    
    if (rat==rating){
      seriesList[i]->printAll();
      cout<<"\n";
      validate=true;
    }
  }
  if (validate==false){
    cout<<"No series found\n";
  }
}

void seriesReport::addEpisode(int id){
   bool validate=false;
    int idCheck;
    for (int i=0; i < numSeries; i++ ){
      idCheck=seriesList[i]->getId();
      if (id==idCheck){
        seriesList[i]->addEpisode();
        validate=true;
      }
    }
    if (validate==false){
      cout<<"No series found\n";
    }
}

void seriesReport::dispEpisodes(int id){
   bool validate=false;
    int idCheck;
    for (int i=0; i < numSeries; i++ ){
      idCheck=seriesList[i]->getId();
      if (id==idCheck){
        seriesList[i]->printEpisodes();
        validate=true;
      }
    }
    if (validate==false){
      cout<<"No episodes found\n";
    }
}

void seriesReport::printEpisodesByRating(int id,int rat){
 bool validate=false;
    int idCheck;
    for (int i=0; i < numSeries; i++ ){
      idCheck=seriesList[i]->getId();
      if (id==idCheck){
        seriesList[i]->printEpisodesRating(rat);
        validate=true;
      }
    }
    if (validate==false){
      cout<<"No series found\n";
    }
  if (validate==false){
    cout<<"No series found\n";
  }
}

void seriesReport::avgRating(){
  series temp;
  for (int i=0; i < numSeries; i++ ){
    temp=*seriesList[i];
    float avgRating=*seriesList[i]+temp;
    seriesList[i]->printAll();
    cout<<"  Average Rating: "<<avgRating<<endl;
  }
}
