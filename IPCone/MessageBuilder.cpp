//
// Created by Guri on 13/07/2018.
//

#include <wchar.h>
#include "MessageBuilder.h"
#include "protocol.h"

void generateMessage(OPERATIONS op, char *buff, int length, void*buffRes) {
    int i = 0;
    char* buffResChar = (char *)buffRes;
    buffResChar[i++] = (char)SYNCH_START;

    buffResChar[i++] = (char) (length >> 24);
    buffResChar[i++] = (char) (length >> 16);
    buffResChar[i++] = (char) (length >> 8);
    buffResChar[i++] = (char) length;

    if(length > 0){
        memcpy(buffResChar + i, buff, length);
    }
    buffResChar[i] = (char)SYNCH_END;
}

void MessageBuilder::generateDataSendMessage(void *buff, int length, void*buffRes) {
    generateMessage(OP_DATA, (char *)buff, length, buffRes);
}

void MessageBuilder::generateCallFunMessage(void *buff, int length, void*buffRes) {
    generateMessage(OP_FUNCTION, (char *)buff, length, buffRes);

}

void MessageBuilder::generateCallMethodMessage(void *buff, int length, void*buffRes) {
    generateMessage(OP_METHOD, (char *)buff, length, buffRes);
}

void MessageBuilder::generateGetAttributeMessage(void *buff, int length, void*buffRes) {
    generateMessage(OP_GET_ATTRIBUTE, (char *)buff, length, buffRes);

}

void MessageBuilder::generateCreateObjMessage(void *buff, int length, void*buffRes) {
    generateMessage(OP_CREATE_OBJ, (char *)buff, length, buffRes);
}

void MessageBuilder::generateResponse(void *buff, int length, void *buffRes) {
    generateMessage(OP_RESPONSE, (char *)buff, length, buffRes);
}
