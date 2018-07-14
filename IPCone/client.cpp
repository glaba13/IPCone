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

void objectOperations(HANDLE pVoid);

void objectMethod(HANDLE pVoid);

void objectAttribute(HANDLE pVoid);

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



void dataSend(HANDLE pipe) {

    printf("\n===== START Data Semd TEST (Int) =====\n");

    Buffer buff, resultBuff;

    //serilize string
    int length;
    int num = 42;
    int res = 0;
    serilizeInt(num, buff.data , &length);
    buff.length = static_cast<DWORD>(length);
    generateDataSendMessage(DATA_INT, buff,resultBuff);

    //send msg
    if(!sendData(pipe, resultBuff, "Testing Data Fetch(1) to server")){
        printf("\nFailed Send\n");
        return;
    }

    //receive msg
    Message response;
    if(!receiveMessage(pipe,  response) || verifyResponse(response)){
        printf("\nTest Data Fetch Failed\n");
        return;
    }else{
        printf("\n>>>>>>>>>>>>>>> SUCCESS <<<<<<<<<<<<<<<<<<<\n");
    }
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

        deserilizeInt(res, response.buff.data + 1);
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
    dataSend(hPipe);
    objectOperations(hPipe);





    printf("\n<End of message, press ENTER to terminate connection and exit>");
    _getch();

    CloseHandle(hPipe);

    return 0;
}


int objectOperationsCreate(HANDLE pipe) {
    printf("\n===== START OBJECT OPERATIONS =====\n\n");

    printf("\n===== START CREATE OBJECT =====\n");
    int id = -1;
    Buffer buff, resultBuff;

    //serilize string
    int length;
    Movie movie("Titanic", 9);
    serilizeMovie(&movie, buff.data , &length);
    buff.length = static_cast<DWORD>(length);
    generateCreateObjMessage(DATA_CINEMA, buff,resultBuff);

    //send msg
    if(!sendData(pipe, resultBuff, "Testing Object Creation to server")){
        printf("\nFailed Send\n");
        return -1;
    }

    //receive msg
    Message response;
    if(!receiveMessage(pipe,  response) || verifyResponse(response) || response.buff.length != 5){
        printf("\nTest Operation Faild\n");
        return -1;
    }else{

        deserilizeInt(id, response.buff.data + 1);
        printf("\n>>>>>>>>>>>>>>> SUCCESS: get ID = %d\n", id);

    }


    return id;
}

void objectOperations(HANDLE pipe) {
    for (int i = 0; i < 5; ++i) {
        if(objectOperationsCreate(pipe) < 0){
            return;
        }
    }
    objectMethod(pipe);
    objectAttribute(pipe);
}

void objectAttribute(HANDLE pipe) {
    printf("\n===== START GET ATTRIBUTE =====\n");
    int id = -1;
    Buffer buff, resultBuff;

    //serilize string
    int length;

    buff.length =0;
    generateGetAttributeMessage(1, ATT_MOVIE_CINEMA, buff,resultBuff);
//    generateCallMethodMessage(1, METHOD_CINEMA_GET_MOVIE, buff,resultBuff);

    //send msg
    if(!sendData(pipe, resultBuff, "Testing Object Attribute Obtain to server")){
        printf("\nFailed Send\n");
        return;
    }

    //receive msg
    Message response;
    if(!receiveMessage(pipe,  response) || verifyResponse(response) || response.buff.length < 1){
        printf("\nTest GET ATTRIBUTE Failed\n");
        return;
    }else{
        Movie *m = new Movie("", 0);
        deserilizeMovie(m, response.buff.data + 1);
        if(m == NULL){
            printf("\nTest GET ATTRIBUTE DESERIALISATION Failed\n");
            return;
        }
        const char * name = m->name.c_str();
        printf("\n>>>>>>>>>>>>>>> SUCCESS: Movie: = '%s' with rating %d\n", name , m->rating);

    }

}

void objectMethod(HANDLE pipe) {

    printf("\n===== START GET ATTRIBUTE =====\n");
    Buffer buff, resultBuff;

    //serilize string
    int length;

    buff.length =0;
    generateCallMethodMessage(1, METHOD_CINEMA_GET_MOVIE, buff,resultBuff);

    //send msg
    if(!sendData(pipe, resultBuff, "Testing CALLing METHOD to server")){
        printf("\nFailed Send\n");
        return;
    }

    //receive msg
    Message response;
    if(!receiveMessage(pipe,  response) || verifyResponse(response) || response.buff.length < 1){
        printf("\nTest CALL METHOD Failed\n");
        return;
    }else{
        Movie *m = new Movie("", 0);
        deserilizeMovie(m, response.buff.data + 1);
        if(m == NULL){
            printf("\nTest CALL METHOD Failed\n");
            return;
        }
        const char * name = m->name.c_str();
        printf("\n>>>>>>>>>>>>>>> SUCCESS: CALL METHOD: Movie: = '%s' with rating %d\n", name, m->rating);

    }
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


