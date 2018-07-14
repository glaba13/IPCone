//
// Created by Guri on 13/07/2018.
//

#ifndef CLIENT_MESSAGEBUILDER_H
#define CLIENT_MESSAGEBUILDER_H


#include "Buffer.h"
#include "protocol.h"


 
     void generateDataSendMessage(DATA_TYPES data, Buffer&buffSrc, Buffer&buffRes);
     void generateCallFunMessage(FUNCTIONS fun, Buffer&buffSrc, Buffer&buffRes);
     void generateCallMethodMessage(int id, METHODS type, Buffer&buffSrc, Buffer&buffRes);
     void generateCreateObjMessage(DATA_TYPES data, Buffer&buffSrc, Buffer&buffRes);
     void generateGetAttributeMessage(int id, ATTRIBUTES att,  Buffer&buffSrc, Buffer&buffRes);
     void generateResponse(Buffer&buffSrc, Buffer&buffRes);
void generateErrorResponse(Buffer &buffRes);
void generateOKResponse(Buffer&buffSrc, Buffer &buffRes);


#endif //CLIENT_MESSAGEBUILDER_H
