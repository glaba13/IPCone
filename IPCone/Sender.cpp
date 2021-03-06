//
// Created by Guri on 14/07/2018.
//

#include "Sender.h"
#include <sstream>
#include <iomanip>
#include <iostream>

/**
 * Data hex converter For visualisation and error checking
 * @param data
 * @param len
 * @return
 */
std::string hexStr(BYTE *data, int len) {
    std::stringstream ss;
    ss << std::hex;
    for (int i(0); i < len; ++i) {
        ss << "0x";
        ss << (int) data[i];
        ss << " ";
    }

    return ss.str();
}

/**
 * send Data Generic Implementation into Pipe
 * @param hPipe
 * @param buff
 * @param msg
 * @param ov
 * @return
 */
bool sendData(HANDLE hPipe, Buffer buff, string msg, OVERLAPPED *ov) {
    DWORD cbRead, cbToWrite, cbWritten, dwMode;
    cbToWrite = buff.length;

    cout << msg << endl << ":" << "Sending " << buff.length << " byte message: "
         << hexStr((BYTE *) (buff.data), buff.length) << endl;

    BOOL fSuccess = WriteFile(
            hPipe,                  // pipe handle
            buff.data,             // message
            cbToWrite,              // message length
            &cbWritten,             // bytes written
            ov);                  // not overlapped

    if (cbToWrite != cbWritten || !fSuccess) {
        _tprintf(TEXT("WriteFile to pipe failed. GLE=%d\n"), GetLastError());
        return -1;
    }

    printf("\nMessage sent to server, receiving reply as follows:\n");

    return true;
}

/*
 * Send data Implementation (synchronous)
 */
bool sendData(HANDLE hPipe, Buffer buff, string msg) {
    return sendData(hPipe, buff, msg, NULL);

}