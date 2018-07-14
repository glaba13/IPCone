#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include "Receiver.h"
#include "Sender.h"
#include "OperatorResolver.h"

#define BUFSIZE 512

DWORD WINAPI InstanceThread(LPVOID);

VOID GetAnswerToRequest(LPTSTR, LPTSTR, LPDWORD);

/**
 * Main Function for Server
 * @return
 */
int _tmain(VOID) {
    BOOL fConnected = FALSE;
    DWORD dwThreadId = 0;
    HANDLE hPipe = INVALID_HANDLE_VALUE, hThread = NULL;
    LPTSTR lpszPipename = LPTSTR(TEXT("\\\\.\\pipe\\StreamLabsPipe"));


    for (;;) {
        _tprintf(TEXT("\nPipe IPCone: Main thread awaiting client connection on %s\n"), lpszPipename);
        hPipe = CreateNamedPipe(
                lpszPipename,             // pipe name 
                PIPE_ACCESS_DUPLEX,       // read/write access 
                PIPE_TYPE_MESSAGE |       // message type pipe 
                PIPE_READMODE_MESSAGE |   // message-read mode 
                PIPE_WAIT,                // blocking mode 
                PIPE_UNLIMITED_INSTANCES, // max. instances  
                BUFSIZE,                  // output buffer size 
                BUFSIZE,                  // input buffer size 
                0,                        // client time-out 
                NULL);                    // default security attribute 

        if (hPipe == INVALID_HANDLE_VALUE) {
            _tprintf(TEXT("CreateNamedPipe failed, GLE=%d.\n"), GetLastError());
            return -1;
        }

        fConnected = ConnectNamedPipe(hPipe, NULL) ?
                     TRUE : (GetLastError() == ERROR_PIPE_CONNECTED);

        if (fConnected) {
            printf("Client connected, creating a processing thread.\n");

            hThread = CreateThread(
                    NULL,              // no security attribute 
                    0,                 // default stack size 
                    InstanceThread,    // thread proc
                    (LPVOID) hPipe,    // thread parameter 
                    0,                 // not suspended 
                    &dwThreadId);      // returns thread ID 

            if (hThread == NULL) {
                _tprintf(TEXT("CreateThread failed, GLE=%d.\n"), GetLastError());
                return -1;
            } else CloseHandle(hThread);
        } else
            // The client could not connect, so close the pipe. 
            CloseHandle(hPipe);
    }

    return 0;
}

/**
 * function for Thread Runner
 * @param lpvParam
 * @return
 */
DWORD WINAPI InstanceThread(LPVOID lpvParam) {
    HANDLE hHeap = GetProcessHeap();
    TCHAR *pchRequest = (TCHAR *) HeapAlloc(hHeap, 0, BUFSIZE * sizeof(TCHAR));
    TCHAR *pchReply = (TCHAR *) HeapAlloc(hHeap, 0, BUFSIZE * sizeof(TCHAR));

    HANDLE hPipe = NULL;


    if (lpvParam == NULL) {
        printf("\nERROR - Pipe IPCone Failure:\n");
        printf("   InstanceThread got an unexpected NULL value in lpvParam.\n");
        printf("   InstanceThread exitting.\n");
        if (pchReply != NULL) HeapFree(hHeap, 0, pchReply);
        if (pchRequest != NULL) HeapFree(hHeap, 0, pchRequest);
        return (DWORD) -1;
    }

    if (pchRequest == NULL) {
        printf("\nERROR - Pipe IPCone Failure:\n");
        printf("   InstanceThread got an unexpected NULL heap allocation.\n");
        printf("   InstanceThread exitting.\n");
        if (pchReply != NULL) HeapFree(hHeap, 0, pchReply);
        return (DWORD) -1;
    }

    if (pchReply == NULL) {
        printf("\nERROR - Pipe IPCone Failure:\n");
        printf("   InstanceThread got an unexpected NULL heap allocation.\n");
        printf("   InstanceThread exitting.\n");
        if (pchRequest != NULL) HeapFree(hHeap, 0, pchRequest);
        return (DWORD) -1;
    }


    printf("InstanceThread created, receiving and processing messages.\n");


    hPipe = (HANDLE) lpvParam;

    while (1) {
        Message request;
        //receive request
        if (!receiveMessage(hPipe, request)) {
            break;
        }

        //get response buffer
        Buffer response = resolveOperator(request);

        //send response
        if (!sendData(hPipe, response, "Sending Response")) {
            printf("Failed to send message.\n");
            break;
        }

    }

    FlushFileBuffers(hPipe);
    DisconnectNamedPipe(hPipe);
    CloseHandle(hPipe);

    HeapFree(hHeap, 0, pchRequest);
    HeapFree(hHeap, 0, pchReply);

    printf("InstanceThread exitting.\n");
    return 1;
}

