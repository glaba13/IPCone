//
// Created by Guri on 13/07/2018.
//

#ifndef SERVER_MOVIE_H
#define SERVER_MOVIE_H


#include <string>
using namespace std;

class Movie {


public:
    Movie(string name, int rating);
    string getName();
    int getRating();

    void setRating(int );
    void setName(string);

    string name;
    int rating;
};


#endif //SERVER_MOVIE_H
