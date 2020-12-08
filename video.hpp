#ifndef VIDEO_H_
#define VIDEO_H_

#include <iostream>
#include <string>

using namespace std;

class video{//Clase Abstracta y madre de clases movies y series
  protected:
  int id;
  string title;
  int duration;
  string genre;
  double rating;

  public:
    video();
    video(int,string,int,string,int);
    virtual void printAll()=0;
    virtual float getRating()=0;
    virtual string getGenre()=0;
    virtual int getId()=0;
};

#endif 