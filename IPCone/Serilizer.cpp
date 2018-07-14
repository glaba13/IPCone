//
// Created by Guri on 13/07/2018.
//

#include "Serilizer.h"
void serilizeInt(int value, char *buff, int *length) {
    buff[0] = (char) (value >> 24);
    buff[1] = (char) (value >> 16);
    buff[2] = (char) (value >> 8);
    buff[3] = (char) value;
    *length = 4;
}

void serilizeString(string str, char *buff, int *length) {
    memcpy(buff, str.c_str(), str.length());
    *length = str.length();
}
