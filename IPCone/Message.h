//
// Created by Guri on 13/07/2018.
//

#ifndef SERVER_REQUEST_H
#define SERVER_REQUEST_H


#include "protocol.h"
#include "Buffer.h"

/**
 * Message structure (used for parsing)
 */
struct Message {

    OPERATIONS op;
    Buffer buff;

};


#endif //SERVER_REQUEST_H
