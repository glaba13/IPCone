//
// Created by Guri on 13/07/2018.
//

#ifndef SERVER_DESERILIZER_H
#define SERVER_DESERILIZER_H


#include <string>
#include "Buffer.h"
#include "Examples/Movie.h"

using namespace std;

/**
 * Int Deserilizer
 * @param value
 * @param buffer
 */
void deserilizeInt(int &value, char *buffer);

/**
 * String Deserilizer
 * @param buffer
 * @return
 */
string deserilizeStr(char *buffer);

/**
 * Short Deserilizer
 * @param value
 * @param buffer
 */
void deserilizeShort(short &value, char *buffer);

/**
 * Movie Deserilizer
 * @param m
 * @param buffer
 */
void deserilizeMovie(Movie *m, char *buffer);

#endif //SERVER_DESERILIZER_H
