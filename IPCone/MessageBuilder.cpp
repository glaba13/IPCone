//
// Created by Guri on 13/07/2018.
//

#include <wchar.h>
#include "MessageBuilder.h"
#include "protocol.h"
#include "Buffer.h"

void generateMessage(OPERATIONS op, Buffer&buff,  Buffer &buffRes) {
    int i = 0;
    char* buffResChar = (char *)buffRes.data;
    buffResChar[i++] = (char)SYNCH_START;
    buffResChar[i++] = (char)op;

    buffResChar[i++] = (char) (buff.length >> 24);
    buffResChar[i++] = (char) (buff.length >> 16);
    buffResChar[i++] = (char) (buff.length >> 8);
    buffResChar[i++] = (char) buff.length;

    if(buff.length > 0){
        memcpy(buffResChar + i, buff.data, buff.length);
    }
    buffResChar[i] = (char)SYNCH_END;
}

void generateDataSendMessage(Buffer&buffSrc, Buffer &buffRes) {
    generateMessage(OP_DATA, buffSrc, buffRes);
}

void generateCallFunMessage(Buffer&buffSrc, Buffer &buffRes) {
    generateMessage(OP_FUNCTION, buffSrc, buffRes);

}

void generateCallMethodMessage(Buffer&buffSrc, Buffer &buffRes) {
    generateMessage(OP_METHOD, buffSrc, buffRes);
}

void generateGetAttributeMessage(Buffer&buffSrc, Buffer &buffRes) {
    generateMessage(OP_GET_ATTRIBUTE, buffSrc, buffRes);

}

void generateCreateObjMessage(Buffer&buffSrc, Buffer &buffRes) {
    generateMessage(OP_CREATE_OBJ, buffSrc, buffRes);
}

void generateResponse(Buffer&buffSrc, Buffer &buffRes) {
    generateMessage(OP_RESPONSE, buffSrc,  buffRes);
}


void generateOKResponse(Buffer&buffSrc, Buffer &buffRes) {

    memmove(buffSrc.data + 1, buffSrc.data, buffSrc.length);
    buffSrc.data[0] = OK_RESPONSE;
    buffSrc.length+=1;
    generateMessage(OP_RESPONSE,  buffSrc,  buffRes);
}

void generateErrorResponse(Buffer &buffRes) {
    Buffer buffSrc;
    buffSrc.data[0] = ERROR_RESPONSE;
    buffSrc.data[1] = ERROR_RESPONSE;
    buffSrc.data[2] = ERROR_RESPONSE;
    buffSrc.data[3] = ERROR_RESPONSE;
    buffSrc.data[4] = ERROR_RESPONSE;
    buffSrc.length+=5;
    generateMessage(OP_RESPONSE,  buffSrc,  buffRes);
}

