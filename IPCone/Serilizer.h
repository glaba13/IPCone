//
// Created by Guri on 13/07/2018.
//

#ifndef CLIENT_SERILIZER_H
#define CLIENT_SERILIZER_H

#include <string>
using namespace std;

class Serilizer {


    void serilizeInt(int value, char *buff, int *length);

    void serilizeString(string str, char *buff, int *length);



};


#endif //CLIENT_SERILIZER_H
