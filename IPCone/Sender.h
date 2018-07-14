//
// Created by Guri on 14/07/2018.
//

#ifndef SERVER_SENDER_H
#define SERVER_SENDER_H

using namespace std;

#include <ntdef.h>
#include <string>
#include "Buffer.h"

/**
 * Send Data Function into pipe
 * @param hPipe
 * @param buff
 * @param msg  for the debug use only
 * @return
 */
bool sendData(HANDLE hPipe, Buffer buff, string msg);


/**
 * Send Data Function into pipe
 * @param hPipe
 * @param buff
 * @param msg
 * @param ov    Use when Asynchronous
 * @return
 */
bool sendData(HANDLE hPipe, Buffer buff, string msg, OVERLAPPED *ov);

#endif //SERVER_SENDER_H
