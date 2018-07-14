//
// Created by Guri on 13/07/2018.
//

#ifndef SERVER_CINEMA_H
#define SERVER_CINEMA_H


#include <string>
#include "Movie.h"

using namespace std;

/**
 * Cinema class with main Movie [Example]
 */
class Cinema {


public:

/**
 *  Constrcutor with Main Movie
 * @param mainMovie
 */
    Cinema(Movie mainMovie);

/**
 * Get the main Movie
 * @return Movie
 */
    Movie getMainMovie();

/**
 * Main Movie variable (Pulic for use)
 */
    Movie mainMovie;
};


#endif //SERVER_CINEMA_H
