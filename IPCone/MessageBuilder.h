//
// Created by Guri on 13/07/2018.
//

#ifndef CLIENT_MESSAGEBUILDER_H
#define CLIENT_MESSAGEBUILDER_H


#include "Buffer.h"

#define ADDITIONAL_LENGTH_OF_REQUEST  (7)

 
    static void generateDataSendMessage(Buffer&buffSrc, Buffer&buffRes);
    static void generateCallFunMessage(Buffer&buffSrc, Buffer&buffRes);
    static void generateCallMethodMessage(Buffer&buffSrc, Buffer&buffRes);
    static void generateCreateObjMessage(Buffer&buffSrc, Buffer&buffRes);
    static void generateGetAttributeMessage(Buffer&buffSrc, Buffer&buffRes);
    static void generateResponse(Buffer&buffSrc, Buffer&buffRes);
void generateErrorResponse(Buffer &buffRes);
void generateOKResponse(Buffer&buffSrc, Buffer &buffRes);


#endif //CLIENT_MESSAGEBUILDER_H
