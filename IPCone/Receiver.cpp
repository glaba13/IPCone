//
// Created by Guri on 13/07/2018.
//

#include "Receiver.h"
#include "Buffer.h"
#include "Message.h"
#include "Deserilizer.h"

#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include <strsafe.h>

#define BUFSIZE 512


enum STATE_RECEIVER{
    STATE_RECEIVER_START,
    STATE_RECEIVER_OP,
    STATE_RECEIVER_BUFF_NUM,
    STATE_RECEIVER_BUFF_DATA,
    STATE_RECEIVER_END,
};


bool handleStart(unsigned char start);

bool handleOP(char op, Message &request);

bool handleBuffNum(char *data, DWORD *num);

BOOL receive(HANDLE hPipe, int num, Buffer & buffer ) {
    buffer.length = 0;
    BOOL fSuccess = FALSE;
    if(num < 0){
        return TRUE;
    }

    fSuccess = ReadFile(
            hPipe,        // handle to pipe
            buffer.data,    // buffer to receive data
            num, // size of buffer
            &buffer.length, // number of bytes read
            NULL);        // not overlapped I/O

    if (!fSuccess || buffer.length != num)
    {

        int err = GetLastError();
        if(err == ERROR_MORE_DATA) {
            return TRUE;
        }
        if (err == ERROR_BROKEN_PIPE)
        {
            _tprintf(TEXT("InstanceThread: client disconnected.\n"), GetLastError());
        }
        else
        {
            _tprintf(TEXT("InstanceThread ReadFile failed, GLE=%d.\n"), GetLastError());
        }
        return false;
    }

    return true;
}


bool handleOP(char op, Message &request) {

    switch(op) {
        default:return false;
        case OP_DATA:
        case OP_FUNCTION:
        case OP_METHOD:
        case OP_CREATE_OBJ:
        case OP_GET_ATTRIBUTE:
        case OP_RESPONSE:
            request.op = (OPERATIONS)op;
            return true;
    }
}

bool handleStart(unsigned char start) {
    return start == SYNCH_START;
}
bool handleEnd(unsigned char start) {
    return start == SYNCH_END;
}




bool handleBuffNum(char *data, DWORD *num) {
    int numInt = 0;
    deserilizeInt(numInt, data);
    *num = static_cast<DWORD>(numInt);
    return TRUE;
}

////
///
BOOL   receiveMessage(HANDLE hPipe, Message &request) {
    Buffer buffer;
    int numToRead = 1;
    BOOL fSuccess = FALSE;
    STATE_RECEIVER state = STATE_RECEIVER_START;
    while(1) {
        fSuccess = receive(hPipe, numToRead, buffer);
        if(!fSuccess){

            return FALSE;
        }
        switch(state) {

            case STATE_RECEIVER_START:
                if(handleStart(buffer.data[0])) {
                    state = STATE_RECEIVER_OP;
                }else{
                    return false;
                }
                break;

            case STATE_RECEIVER_OP:
                fSuccess = handleOP(buffer.data[0], request);
                if(!fSuccess){
                    _tprintf(TEXT("Invalid Operation.\n"));
                    return FALSE;
                }
                numToRead = PROTOCOL_NUMBER_SIZE;
                state = STATE_RECEIVER_BUFF_NUM;
                break;
            case STATE_RECEIVER_BUFF_NUM:
                fSuccess = handleBuffNum(buffer.data, &request.buff.length);
                if(!fSuccess){
                    _tprintf(TEXT("Invalid number.\n"));
                    return FALSE;
                }
                state = STATE_RECEIVER_BUFF_DATA;
                numToRead = request.buff.length;
                break;
            case STATE_RECEIVER_BUFF_DATA:
                memcpy(request.buff.data, buffer.data, request.buff.length);
                state = STATE_RECEIVER_END;
                numToRead = 1;
                break;
            case STATE_RECEIVER_END:
                fSuccess = handleEnd(buffer.data[0]);
                if(!fSuccess){
                    _tprintf(TEXT("Invalid end.\n"));
                    return FALSE;
                }

               return true;
        }

    }


}