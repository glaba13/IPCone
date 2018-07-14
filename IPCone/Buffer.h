//
// Created by Guri on 13/07/2018.
//

#ifndef SERVER_BUFFER_H
#define SERVER_BUFFER_H

#define BUFFER_SIZE 512

#include <windows.h>
#include <stdio.h>
#include <tchar.h>

/**
 * Buffer Structure with data and length: Use for simplicity
 */
struct Buffer {
    DWORD length;
    char data[BUFFER_SIZE];
};


#endif //SERVER_BUFFER_H
