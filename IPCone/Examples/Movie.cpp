//
// Created by Guri on 13/07/2018.
//

#include "Movie.h"

/**
 * Constrcutor
 * @param name
 * @param rating
 */
Movie::Movie(string name, int rating) {
    this->name = name;
    this->rating = rating;
}

/**
 * Name getter
 * @return name
 */
string Movie::getName() {
    return name;
}

/**
 * rating getter
 * @return rating
 */
int Movie::getRating() {
    return rating;
}

/**
 * rating setter
 * @param rating
 */
void Movie::setRating(int rating) {
    this->rating = rating;
}

/**
 * name setter
 * @param name
 */
void Movie::setName(string name) {
    this->name = name;
}
