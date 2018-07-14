//
// Created by Guri on 13/07/2018.
//

#ifndef SERVER_RECEIVER_H
#define SERVER_RECEIVER_H


#include <fibersapi.h>
#include "Message.h"

BOOL   receiveMessage(HANDLE hPipe, Message &request);

#endif //SERVER_RECEIVER_H
