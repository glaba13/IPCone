//
// Created by Guri on 13/07/2018.
//

#ifndef SERVER_CINEMA_H
#define SERVER_CINEMA_H


#include <string>
#include "Movie.h"

using namespace std;
class Cinema {


public:


    Cinema(Movie mainMovie);

    Movie getMainMovie();
    Movie mainMovie;
};


#endif //SERVER_CINEMA_H
