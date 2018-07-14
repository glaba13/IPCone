//
// Created by Guri on 13/07/2018.
//

#ifndef CLIENT_MESSAGEBUILDER_H
#define CLIENT_MESSAGEBUILDER_H


#define ADDITIONAL_LENGTH_OF_REQUEST  (7)

 class MessageBuilder {


    static void generateDataSendMessage(void* buff, int length, void*buffRes);
    static void generateCallFunMessage(void* buff, int length, void*buffRes);
    static void generateCallMethodMessage(void* buff, int length, void*buffRes);
    static void generateCreateObjMessage(void* buff, int length, void*buffRes);
    static void generateGetAttributeMessage(void* buff, int length, void*buffRes);
    static void generateResponse(void* buff, int length, void*buffRes);
};


#endif //CLIENT_MESSAGEBUILDER_H
