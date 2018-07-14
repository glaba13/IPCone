//
// Created by Guri on 13/07/2018.
//

#ifndef CLIENT_MESSAGEBUILDER_H
#define CLIENT_MESSAGEBUILDER_H


#include "Buffer.h"
#include "protocol.h"


 
     void generateDataSendMessage(Buffer&buffSrc, Buffer&buffRes);
     void generateCallFunMessage(FUNCTIONS fun, Buffer&buffSrc, Buffer&buffRes);
     void generateCallMethodMessage(Buffer&buffSrc, Buffer&buffRes);
     void generateCreateObjMessage(Buffer&buffSrc, Buffer&buffRes);
     void generateGetAttributeMessage(Buffer&buffSrc, Buffer&buffRes);
     void generateResponse(Buffer&buffSrc, Buffer&buffRes);
void generateErrorResponse(Buffer &buffRes);
void generateOKResponse(Buffer&buffSrc, Buffer &buffRes);


#endif //CLIENT_MESSAGEBUILDER_H
