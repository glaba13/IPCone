//
// Created by Guri on 13/07/2018.
//

#include "Cinema.h"

Movie Cinema::getMainMovie() {
    return mainMovie;
}

Cinema::Cinema(Movie mainMovie) : mainMovie(mainMovie) {
}
