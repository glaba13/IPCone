//
// Created by Guri on 13/07/2018.
//

#include "Deserilizer.h"
#include "Buffer.h"
#include "protocol.h"



void deserilizeInt(int &value, char *buffer) {
    value =  int((unsigned char)(buffer[0]) << 24 |
                 (unsigned char)(buffer[1]) << 16 |
                 (unsigned char)(buffer[2]) << 8 |
                 (unsigned char)(buffer[3]));
}
