//
// Created by Guri on 13/07/2018.
//

#ifndef SERVER_MOVIE_H
#define SERVER_MOVIE_H


#include <string>

using namespace std;


/**
 *  Movie Example Class
 */
class Movie {


public:
/**
 * Constructor
 * @param name
 * @param rating
 */
    Movie(string name, int rating);

/**
 * getter of the name
 * @return name
 */
    string getName();

/**
 * Get Rating Method
 * @return rating
 */
    int getRating();

/**
 * Set rating Method
 */
    void setRating(int);

/**
 * Set Name Method
 */
    void setName(string);

/**
 * some puclic varibaels for demostration
 */
    string name;
    int rating;
};


#endif //SERVER_MOVIE_H
