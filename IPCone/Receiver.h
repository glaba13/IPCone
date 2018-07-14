//
// Created by Guri on 13/07/2018.
//

#ifndef SERVER_RECEIVER_H
#define SERVER_RECEIVER_H


#include <fibersapi.h>
#include "Message.h"

/**
 * Generic Receive message function:
 * Reads from pipe and parses
 * @param hPipe
 * @param request
 * @return
 */
BOOL receiveMessage(HANDLE hPipe, Message &request);

/**
 * Only synchronous message receiver function
 * @param hPipe
 * @param request
 * @param ov
 * @return
 */
BOOL receiveMessage(HANDLE hPipe, Message &request, OVERLAPPED *ov);

#endif //SERVER_RECEIVER_H
