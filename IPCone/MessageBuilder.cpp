//
// Created by Guri on 13/07/2018.
//

#include <wchar.h>
#include "MessageBuilder.h"
#include "protocol.h"
#include "Buffer.h"
#include "Serilizer.h"

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
    buffResChar[buff.length + i] = (char)SYNCH_END;
    buffRes.length = buff.length + 7;
}

void generateWithDesctiptor(int des, OPERATIONS op, Buffer&buffSrc, Buffer &buffRes) {
    memmove(buffSrc.data + 4, buffSrc.data, buffSrc.length);
    int dummy;
    serilizeInt(des, buffSrc.data, &dummy);
    buffSrc.length+=4;
    generateMessage(op, buffSrc, buffRes);
}

void generateWithDesctiptor(int id, int des, OPERATIONS op, Buffer&buffSrc, Buffer &buffRes) {
    memmove(buffSrc.data + 8, buffSrc.data, buffSrc.length);
    int dummy;
    serilizeInt(id, buffSrc.data, &dummy);
    serilizeInt(des, buffSrc.data + 4, &dummy);
    buffSrc.length+=8;
    generateMessage(op, buffSrc, buffRes);
}

void generateDataSendMessage(DATA_TYPES type, Buffer&buffSrc, Buffer &buffRes) {
    if(buffSrc.length > 0){
        memcpy(buffSrc.data + 1, buffSrc.data, buffSrc.length);
    }
    buffSrc.data[0] = type;
    buffSrc.length+=1;
    generateMessage( OP_DATA, buffSrc, buffRes);
}

void generateCallFunMessage(FUNCTIONS fun, Buffer&buffSrc, Buffer &buffRes) {
    generateWithDesctiptor(fun, OP_FUNCTION, buffSrc, buffRes);
}

void generateCallMethodMessage(int id, METHODS type,Buffer&buffSrc, Buffer &buffRes) {
    generateWithDesctiptor(type, id, OP_METHOD, buffSrc, buffRes);
}

void generateGetAttributeMessage(int id, ATTRIBUTES type, Buffer&buffSrc, Buffer &buffRes) {
    generateWithDesctiptor(type, id,OP_GET_ATTRIBUTE, buffSrc, buffRes);
}

void generateCreateObjMessage(DATA_TYPES type,  Buffer&buffSrc, Buffer &buffRes) {

    if(buffSrc.length > 0){
        memcpy(buffSrc.data + 1, buffSrc.data, buffSrc.length);
    }
    buffSrc.data[0] = type;
    buffSrc.length+=1;
    generateMessage( OP_CREATE_OBJ, buffSrc, buffRes);
}

void generateResponse(Buffer&buffSrc, Buffer &buffRes) {
    generateMessage(OP_RESPONSE, buffSrc,  buffRes);
}


void generateOKResponse(Buffer&buffSrc, Buffer &buffRes) {

    memmove(buffSrc.data + 1, buffSrc.data, buffSrc.length);
    buffSrc.data[0] = OK_RESPONSE;
    buffSrc.length= buffSrc.length +1;
    generateMessage(OP_RESPONSE,  buffSrc,  buffRes);
}

void generateErrorResponse(Buffer &buffRes) {
    Buffer buffSrc;
    buffSrc.data[0] = ERROR_RESPONSE;
    buffSrc.length=1;
    generateMessage(OP_RESPONSE,  buffSrc,  buffRes);


}

