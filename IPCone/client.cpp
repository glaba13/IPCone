#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <tchar.h>
#include <string>
#include "Buffer.h"
#include "Serilizer.h"
#include "protocol.h"
#include "MessageBuilder.h"
#include "Message.h"
#include "Receiver.h"
#include "Sender.h"
#include "Deserilizer.h"

#define BUFSIZE 512

void functionSample1(HANDLE pVoid);

bool verifyResponse(Message message);

using namespace std;


bool createPipe(HANDLE &hPipe) {
    LPTSTR lpvMessage=TEXT("Default message from client.");
    TCHAR  chBuf[BUFSIZE];
    BOOL   fSuccess = FALSE;
    DWORD  cbRead, cbToWrite, cbWritten, dwMode;

    LPTSTR lpszPipename = TEXT("\\\\.\\pipe\\StreamLabsPipe");
    hPipe = CreateFile(
            lpszPipename,   // pipe name
            GENERIC_READ |  // read and write access
            GENERIC_WRITE,
            0,              // no sharing
            NULL,           // default security attributes
            OPEN_EXISTING,  // opens existing pipe
            0,              // default attributes
            NULL);          // no template file

    // Break if the pipe handle is valid.

    if (hPipe != INVALID_HANDLE_VALUE)
       return TRUE;

    // Exit if an error other than ERROR_PIPE_BUSY occurs.

    if (GetLastError() != ERROR_PIPE_BUSY)
    {
        _tprintf( TEXT("Could not open pipe. GLE=%d\n"), GetLastError() );
        return FALSE;
    }

    // All pipe instances are busy, so wait for 20 seconds.

    if ( ! WaitNamedPipe(lpszPipename, 20000))
    {
        printf("Could not open pipe: 20 second wait timed out.");
        return FALSE;
    }
    // The pipe connected; change to message-read mode.

    dwMode = PIPE_READMODE_MESSAGE;
    fSuccess = SetNamedPipeHandleState(
            hPipe,    // pipe handle
            &dwMode,  // new pipe mode
            NULL,     // don't set maximum bytes
            NULL);    // don't set maximum time
    if ( ! fSuccess)
    {
        _tprintf( TEXT("SetNamedPipeHandleState failed. GLE=%d\n"), GetLastError() );
        return -1;
    }


    return TRUE;

}


void functionSample2(HANDLE pipe) {

    printf("\n===== START FUNCTION TEST 2 (Increment) =====\n");

    Buffer buff, resultBuff;

    //serilize string
    int length;
    int num = 41;
    int res = 0;

    serilizeInt(num, buff.data, &length);
    buff.length = static_cast<DWORD>(length);
    generateCallFunMessage(FUN_INCREMENT, buff,resultBuff);

    //send msg
    if(!sendData(pipe, resultBuff, "Testing Fuction Calls(1) to server")){
        printf("\nFailed Send\n");
        return;
    }

    //receive msg
    Message response;
    if(!receiveMessage(pipe,  response) || verifyResponse(response) || response.buff.length != 5){
        printf("\nTest Operation Faild\n");
        return;
    }else{

        deserilizeInt(res, response.buff.data);
        printf("\n>>>>>>>>>>>>>>> was %d, incremented, received %d\n", num, res);
        if(num + 1 == res) {
            printf("\n>>>>>>>>>>>>>>> SUCCESS <<<<<<<<<<<<<<<<<<<\n");
        }
    }
}

int _tmain(int argc, TCHAR *argv[])
{
    HANDLE hPipe;
    LPTSTR lpvMessage=TEXT("Default message from client.");
    TCHAR  chBuf[BUFSIZE];
    BOOL   fSuccess = FALSE;



    if(!createPipe(hPipe)){
        return -1;
    }


    functionSample1(hPipe);
    functionSample2(hPipe);
//    dataSend(hPipe);
//    objectOperations(hPipe);





    printf("\n<End of message, press ENTER to terminate connection and exit>");
    _getch();

    CloseHandle(hPipe);

    return 0;
}

void functionSample1(HANDLE pipe) {

    printf("\n===== START FUNCTION TEST 1 (Print Text) =====\n");

    Buffer buff, resultBuff;

    //serilize string
    int length;
    serilizeString("StreamLabsPipe Fun1 Test", buff.data, &length);
    buff.length = static_cast<DWORD>(length);
    generateCallFunMessage(FUN_PRINT_TEXT, buff,resultBuff);

    //send msg
    if(!sendData(pipe, resultBuff, "Testing Fuction Calls(1) to server")){
        printf("\nFailed Send\n");
        return;
    }

    //receive msg
    Message response;
    if(!receiveMessage(pipe,  response) || verifyResponse(response)){
        printf("\nTest Operation Faild\n");
        return;
    }else{
        printf("\n>>>>>>>>>>>>>>> SUCCESS <<<<<<<<<<<<<<<<<<<\n");
    }
}


bool verifyResponse(Message response) {
    return  response.op != OP_RESPONSE || response.buff.length == 0 || response.buff.data[0] != OK_RESPONSE;
}


