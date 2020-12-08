#ifndef EPISODES_H_
#define EPISODES_H_
#include <iostream>
#include <string>

using namespace std;

//Clase independiente que guarda los episodios de una serie

class episodes{
    private:
    string title;
    int season;
    float rating;
    public:
    episodes();
    episodes(string,int,float);
    void printAll();//Imprime el episodio
    float getRating();
};

#endif