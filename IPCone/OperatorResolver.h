//
// Created by Guri on 13/07/2018.
//

#ifndef SERVER_OPERATORRESOLVER_H
#define SERVER_OPERATORRESOLVER_H


#include "Buffer.h"
#include "Message.h"

/**
 * Generic Operator Resolver
 * @param req
 * @return Message which should be sent
 */
Buffer resolveOperator(Message req);

#endif //SERVER_OPERATORRESOLVER_H
