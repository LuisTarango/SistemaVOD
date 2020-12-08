#include <iostream>
#include <string>
#include "episodes.hpp"

episodes::episodes(){
}

episodes::episodes(string t,int s,float r){
    title=t;
    season=s;
    rating=r;
}

void episodes::printAll(){
    cout<<title<<" "<<season<<" "<<rating<<endl;
}

float episodes::getRating(){
    return rating;
}
