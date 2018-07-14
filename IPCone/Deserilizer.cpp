//
// Created by Guri on 13/07/2018.
//

#include "Deserilizer.h"
#include "Buffer.h"
#include "protocol.h"
#include "Examples/Movie.h"


void deserilizeInt(int &value, char *buffer) {
    value =  int((unsigned char)(buffer[0]) << 24 |
                 (unsigned char)(buffer[1]) << 16 |
                 (unsigned char)(buffer[2]) << 8 |
                 (unsigned char)(buffer[3]));
}

string deserilizeStr( char * buffer){
   return string(buffer);
}

void deserilizeMovie(Movie *m, char * buffer){
    string str(buffer);
    int rating;
    deserilizeInt(rating, buffer + str.length() + 1);
    m->name = str;
    m->rating = rating;
}



void deserilizeShort(short &value, char *buffer) {
    value =  short((unsigned char)(buffer[0]) << 8 |
                 (unsigned char)(buffer[1]));
}

