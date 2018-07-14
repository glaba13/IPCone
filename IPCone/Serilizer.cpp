//
// Created by Guri on 13/07/2018.
//

#include "Serilizer.h"

/**
 * Integer Serilizer
 * @param value
 * @param buff
 * @param length
 */
void serilizeInt(int value, char *buff, int *length) {
    buff[0] = (char) (value >> 24);
    buff[1] = (char) (value >> 16);
    buff[2] = (char) (value >> 8);
    buff[3] = (char) value;
    *length = 4;
}


/**
 * String Serilizer
 * @param str
 * @param buff
 * @param length
 */
void serilizeString(string str, char *buff, int *length) {
    memcpy(buff, str.c_str(), str.length());
    buff[str.length()] = 0;
    *length = str.length() + 1;
}


/**
 * Movie serilizer
 * @param m
 * @param buff
 * @param length
 */
void serilizeMovie(Movie *m, char *buff, int *length) {
    int intLength = 0;
    serilizeString(m->name, buff, &intLength);
    *length = intLength;
    serilizeInt(m->rating, buff + intLength, &intLength);
    *length = *length + intLength;


}
