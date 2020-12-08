#include <iostream>
#include <string>
#include <fstream>
#include "series.hpp"

using namespace std;

series::series(){
    nEpisodes=0;
}

series::series(int i ,string t ,int d,string g ,double r,int n){
    id=i;
    title=t;
    duration=d;
    genre=g;
    rating=r;
    numEp=n;
}

void series::printAll(){
    cout<<id<<" "<<title<<" "<<duration<<" "<<genre<<" "<<rating<<" "<<numEp;
}

void series::loadEpisodes(){
    string line;
    int i;
    string t;
    int s;
    double r;
    ifstream ser;
    ser.open("Episodios.csv");
    while (ser.good()){
        getline(ser,line,',');
        i=stoi(line);
        getline(ser,line,',');
        t=line;
        getline(ser,line,',');
        s=stoi(line);
        getline(ser,line,'\n');
        r=stod(line);
        if (i==id){
            episodeList[nEpisodes]= new episodes(t,s,r);
            //cout<<i<<" "<<t<<" "<<s<<" "<<r<<endl;
            nEpisodes++;
            if (nEpisodes==5){break;}
        }
    }
}



void series::printEpisodes(){
    for (int i=0;i<nEpisodes;i++){
        episodeList[i]->printAll();
    }
}

void series::addEpisode(){
    string t;
    int s;
    double r;
    cout<<"Enter episode title\n";cin.ignore();getline(cin,t);
    cout<<"Enter season\n";cin>>s;
    cout<<"Enter episode rating\n";cin>>r;

    episodeList[nEpisodes]=new episodes(t,s,r);
    nEpisodes++;
}

string series::getGenre(){
    return genre;
}

float series::getRating(){
    return rating;
}

int series::getId(){
    return id;
}

float series::operator+(series a){
    float sum=0;
    float avg;
    for (int i=0;i<nEpisodes;i++){
        sum+=episodeList[i]->getRating();
    }
    avg=sum/nEpisodes;
    return avg;
}

void series::printEpisodesRating(int rat){
    bool validate=false;
  int rating;
  for (int i=0; i < nEpisodes; i++ ){
    rating=episodeList[i]->getRating();
    
    if (rat==rating){
      episodeList[i]->printAll();
      validate=true;
    }
  }
  if (validate==false){
    cout<<"No series found\n";
  }
}