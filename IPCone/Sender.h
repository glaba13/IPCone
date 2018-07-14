//
// Created by Guri on 14/07/2018.
//

#ifndef SERVER_SENDER_H
#define SERVER_SENDER_H

using namespace std;
#include <ntdef.h>
#include <string>
#include "Buffer.h"

bool sendData(HANDLE hPipe, Buffer buff, string msg);
bool sendData(HANDLE hPipe, Buffer buff, string msg, OVERLAPPED * ov);
#endif //SERVER_SENDER_H
