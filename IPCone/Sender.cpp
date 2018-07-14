//
// Created by Guri on 14/07/2018.
//

#include "Sender.h"


bool sendData(HANDLE hPipe, Buffer buff, string msg) {
    DWORD  cbRead, cbToWrite, cbWritten, dwMode;
    cbToWrite = buff.length;
    _tprintf( TEXT("Sending %d byte message: \"%s\"\n"), cbToWrite, msg);

    BOOL fSuccess = WriteFile(
            hPipe,                  // pipe handle
            buff.data,             // message
            cbToWrite,              // message length
            &cbWritten,             // bytes written
            NULL);                  // not overlapped

    if (cbToWrite!=cbWritten || ! fSuccess)
    {
        _tprintf( TEXT("WriteFile to pipe failed. GLE=%d\n"), GetLastError() );
        return -1;
    }

    printf("\nMessage sent to server, receiving reply as follows:\n");

    return true;
}