//
// Created by Guri on 13/07/2018.
//

#include "Movie.h"

Movie::Movie(string name, int rating) {
    this->name = name;
    this->rating = rating;
}

string Movie::getName() {
    return name;
}

int Movie::getRating() {
    return rating;
}

void Movie::setRating(int rating ) {
    this->rating  = rating;
}

void Movie::setName(string name) {
    this->name = name;
}
