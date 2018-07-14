//
// Created by Guri on 13/07/2018.
//

#ifndef CLIENT_SERILIZER_H
#define CLIENT_SERILIZER_H

#include <string>
#include "Examples/Movie.h"

using namespace std;

/**
 * Integer Serilizer
 * @param value
 * @param buff
 * @param length
 */
void serilizeInt(int value, char *buff, int *length);

/**
 * String Serilizer
 * @param str
 * @param buff
 * @param length
 */
void serilizeString(string str, char *buff, int *length);

/**
 * Movie Serializer
 * @param m
 * @param buff
 * @param length
 */
void serilizeMovie(Movie *m, char *buff, int *length);


#endif //CLIENT_SERILIZER_H
