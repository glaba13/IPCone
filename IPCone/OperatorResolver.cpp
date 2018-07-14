//
// Created by Guri on 13/07/2018.
//

#include "OperatorResolver.h"
#include "ObjectPool.h"
#include "Deserilizer.h"
#include "Examples/ExampleFunctions.h"
#include "Examples/Cinema.h"
#include "MessageBuilder.h"
#include "Serilizer.h"

static ObjectPool pool;

Buffer BuildErrorResponse();

Buffer resolveDataOperator(Buffer buffer);

Buffer resolveFuncOperator(Buffer buffer);

Buffer resolveMethodOperator(Buffer buffer);

Buffer resolveCreateObJOperator(Buffer buffer);

Buffer resolveAttrOperator(Buffer buffer);

Buffer resolveFunIncrement(Buffer buffer);

Buffer resolvePrintText(Buffer buffer);

Buffer createCinemaResolver(Buffer buffer);

Buffer resolveCinGetMovie(Buffer buffer);

Buffer intDataResolver(Buffer buffer);

Buffer resolveOperator(Request req) {
    switch(req.op) {

        case OP_DATA:
            return resolveDataOperator(req.buff);
        case OP_FUNCTION:
            return resolveFuncOperator(req.buff);
        case OP_METHOD:
            return resolveMethodOperator(req.buff);
        case OP_CREATE_OBJ:
            return resolveCreateObJOperator(req.buff);
        case OP_GET_ATTRIBUTE:
            return resolveAttrOperator(req.buff);
        case OP_RESPONSE:
            return BuildErrorResponse();

    }

}

Buffer resolveGetMovie(Buffer buffer) {
    char type = buffer.data[PROTOCOL_FUN_ID_SIZE];
    if(type != DATA_INT || buffer.length != PROTOCOL_FUN_ID_SIZE + PROTOCOL_NUMBER_SIZE) {
        return BuildErrorResponse();
    }
    int value;
    deserilizeInt(value, buffer.data + PROTOCOL_FUN_ID_SIZE);

    auto *c = (Cinema *)pool.getObject(value);

    Buffer buff{};
    buff.data[0] = DATA_MOVIE;
    int length;
    serilizeMovie(&c->mainMovie, buff.data + 1, &length);
    buff.length = static_cast<DWORD>(1 + length);
    Buffer res{};
    generateOKResponse(buff, res);


    return res;
}

Buffer resolveAttrOperator(Buffer buffer) {
    if(buffer.length != PROTOCOL_METH_ID_SIZE + 1) {
        return BuildErrorResponse();
    }
    int num = 0;
    deserilizeInt(num, buffer.data);

    switch(num){
        case OP_GET_ATTRIBUTE: {
            return resolveGetMovie(buffer);
        }
    }
    return BuildErrorResponse();
}

Buffer resolveCreateObJOperator(Buffer buffer) {
    if(buffer.length  < 1) {
        return BuildErrorResponse();
    }

    DATA_TYPES type = (DATA_TYPES)(buffer.data[0]);
    switch(type) {
        case DATA_CINEMA:
            return createCinemaResolver(buffer);


    }

    return BuildErrorResponse();
}

Buffer createCinemaResolver(Buffer buffer) {
    Movie *m = new Movie("", 0);
    char type = buffer.data[PROTOCOL_FUN_ID_SIZE];
    if(type != DATA_MOVIE){
        return BuildErrorResponse();
    }



    deserilizeMovie(m, buffer.data + 2);

    Cinema cinema(*m);
    int value = pool.registerObject(m);

    Buffer buff;
    buff.length = 1 + PROTOCOL_NUMBER_SIZE;
    deserilizeInt(value, buff.data + 1);
    return buff;
}

Buffer resolveMethodOperator(Buffer buffer) {
    if(buffer.length != PROTOCOL_METH_ID_SIZE + 1) {
        return BuildErrorResponse();
    }
    int num = 0;
    deserilizeInt(num, buffer.data);

    switch(num){
        case METHOD_CINEMA_GET_MOVIE: {
            return resolveCinGetMovie(buffer);
        }
    }
    return BuildErrorResponse();
}

Buffer resolveCinGetMovie(Buffer buffer) {
    char type = buffer.data[PROTOCOL_FUN_ID_SIZE];
    if(type != DATA_INT || buffer.length != PROTOCOL_FUN_ID_SIZE + PROTOCOL_NUMBER_SIZE) {
        return BuildErrorResponse();
    }
    int value;
    deserilizeInt(value, buffer.data + PROTOCOL_FUN_ID_SIZE);

    Cinema *c = (Cinema *)pool.getObject(value);

    Buffer buff;
    buff.data[0] = DATA_MOVIE;
    int length;
    Movie m = c->getMainMovie();
    serilizeMovie(&m, buff.data + 1, &length);
    buff.length = 1 + length;
    Buffer res;
    generateOKResponse(buff, res);


    return res;
}


Buffer resolveFuncOperator(Buffer buffer) {
    if(buffer.length != PROTOCOL_FUN_ID_SIZE + 1) {
        return BuildErrorResponse();
    }
    int num = 0;
    deserilizeInt(num, buffer.data);

    switch(num){
        case FUN_INCREMENT: {
            return resolveFunIncrement(buffer);
        }
        case FUN_PRINT_TEXT: {
            return resolvePrintText(buffer);
        }
    }
    return BuildErrorResponse();
}

Buffer BuildOKResponse() {
    Buffer buff;
    buff.length = 0;
    Buffer ress;
    generateOKResponse(buff, ress);
    return ress;
}

Buffer resolvePrintText(Buffer buffer) {
    char type = buffer.data[PROTOCOL_FUN_ID_SIZE];
    if(type != DATA_STRING || buffer.length < PROTOCOL_FUN_ID_SIZE) {
        return BuildErrorResponse();
    }
    string str;
    deserilizeStr(str, buffer.data + PROTOCOL_FUN_ID_SIZE + 1);
    printText(str);

    return BuildOKResponse();
}

Buffer resolveFunIncrement(Buffer buffer) {
    char type = buffer.data[PROTOCOL_FUN_ID_SIZE];
    if(type != DATA_INT || buffer.length != PROTOCOL_FUN_ID_SIZE + 1 + PROTOCOL_NUMBER_SIZE) {
        return BuildErrorResponse();
    }
    int value;
    deserilizeInt(value, buffer.data + PROTOCOL_FUN_ID_SIZE + 1);
    value = incrementInt(value);

    Buffer buff;
    buff.data[0] = DATA_INT;
    buff.length = 1 + PROTOCOL_NUMBER_SIZE;
    deserilizeInt(value, buff.data + 1);
    Buffer res;
    generateOKResponse(buff, res);
    return res;
}

Buffer resolveDataOperator(Buffer buffer) {
    if(buffer.length < PROTOCOL_OBJ_ID_SIZE + 1) {
        return BuildErrorResponse();
    }
    DATA_TYPES type = (DATA_TYPES)(buffer.data[0]);
    switch(type) {
        case DATA_INT:
            return intDataResolver(buffer);
    }
    return BuildErrorResponse();
}

Buffer intDataResolver(Buffer buffer) {
    if(buffer.length != 1 + PROTOCOL_NUMBER_SIZE) {
        return BuildErrorResponse();
    }
    int value;
    deserilizeInt(value, buffer.data + PROTOCOL_FUN_ID_SIZE + 1);
    return BuildOKResponse();
}

Buffer BuildErrorResponse() {
    Buffer buf{};
    generateErrorResponse(buf);
    return buf;
}



