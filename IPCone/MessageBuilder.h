//
// Created by Guri on 13/07/2018.
//

#ifndef CLIENT_MESSAGEBUILDER_H
#define CLIENT_MESSAGEBUILDER_H


#include "Buffer.h"
#include "protocol.h"

/**
 * General Data Message Builder
 * @param data
 * @param buffSrc
 * @param buffRes
 */
void generateDataSendMessage(DATA_TYPES data, Buffer &buffSrc, Buffer &buffRes);

/**
 * Function Message Builder
 * @param fun
 * @param buffSrc
 * @param buffRes
 */
void generateCallFunMessage(FUNCTIONS fun, Buffer &buffSrc, Buffer &buffRes);

/**
 *  Method Message Builder
 * @param id
 * @param type
 * @param buffSrc
 * @param buffRes
 */
void generateCallMethodMessage(int id, METHODS type, Buffer &buffSrc, Buffer &buffRes);

/**
 *  Object Creation Message Builder
 * @param data
 * @param buffSrc
 * @param buffRes
 */
void generateCreateObjMessage(DATA_TYPES data, Buffer &buffSrc, Buffer &buffRes);

/**
 *  Getting Attribute Message Builder
 * @param id
 * @param att
 * @param buffSrc
 * @param buffRes
 */
void generateGetAttributeMessage(int id, ATTRIBUTES att, Buffer &buffSrc, Buffer &buffRes);

/**
 * General Response message builder
 * @param buffSrc
 * @param buffRes
 */
void generateResponse(Buffer &buffSrc, Buffer &buffRes);

/**
 *  Error Message Builder
 * @param buffRes
 */
void generateErrorResponse(Buffer &buffRes);

/**
 *  OK (Success) Message Builder
 * @param buffSrc
 * @param buffRes
 */
void generateOKResponse(Buffer &buffSrc, Buffer &buffRes);


#endif //CLIENT_MESSAGEBUILDER_H
