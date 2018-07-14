//
// Created by Guri on 13/07/2018.
//

#ifndef SERVER_DESERILIZER_H
#define SERVER_DESERILIZER_H


#include <string>
#include "Buffer.h"
#include "Examples/Movie.h"

using namespace std;

void deserilizeInt(int &value, char * buffer);


void deserilizeStr(string &value, char * buffer);

void deserilizeShort(short &value, char *buffer);

void deserilizeMovie(Movie *m, char * buffer);

#endif //SERVER_DESERILIZER_H
