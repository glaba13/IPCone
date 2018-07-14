//
// Created by Guri on 13/07/2018.
//

#include "Cinema.h"

/**
 * Returns the Main Movie
 * @return Movie
 */
Movie Cinema::getMainMovie() {
    return mainMovie;
}

/**
 *  Constructor of the cinema with Main Movie
 * @param mainMovie
 */
Cinema::Cinema(Movie mainMovie) : mainMovie(mainMovie) {
}
