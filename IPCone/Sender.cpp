//
// Created by Guri on 14/07/2018.
//

#include "Sender.h"
#include <sstream>
#include <iomanip>
#include <iostream>

std::string hexStr(BYTE *data, int len)
{
    std::stringstream ss;
    ss<<std::hex;
    for(int i(0);i<len;++i) {
        ss << "0x";
        ss << (int) data[i];
        ss << " ";
    }

    return ss.str();
}

bool sendData(HANDLE hPipe, Buffer buff, string msg) {
    DWORD  cbRead, cbToWrite, cbWritten, dwMode;
    cbToWrite = buff.length;

    cout<<msg<<endl<<":"<<"Sending "<< buff.length<<" byte message: "<< hexStr((BYTE *)(buff.data), buff.length) <<endl;

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