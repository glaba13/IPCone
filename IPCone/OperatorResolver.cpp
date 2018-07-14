//
// Created by Guri on 13/07/2018.
//

#include <iostream>
#include <iomanip>
#include "OperatorResolver.h"
#include "ObjectPool.h"
#include "Deserilizer.h"
#include "Examples/ExampleFunctions.h"
#include "Examples/Cinema.h"
#include "MessageBuilder.h"
#include "Serilizer.h"

//Object Pool
static ObjectPool pool;

/**
 * Declatarions
 */
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


/**
 * Operator Resolver
 * @param req
 * @return
 */
Buffer resolveOperator(Message req) {
    switch (req.op) {

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

/**
 * Get Movie Resolver
 * @param buffer
 * @return
 */
Buffer resolveGetMovie(Buffer buffer) {

    if (buffer.length != PROTOCOL_FUN_ID_SIZE + PROTOCOL_NUMBER_SIZE) {
        return BuildErrorResponse();
    }
    int value;
    deserilizeInt(value, buffer.data + PROTOCOL_FUN_ID_SIZE);
    Cinema *c = (Cinema *) pool.getObject(value);


    Buffer buff{};
    int length;
    serilizeMovie(&c->mainMovie, buff.data, &length);
    buff.length = static_cast<DWORD>(length);
    Buffer res{};
    generateOKResponse(buff, res);


    return res;
}

/**
 * resolves and hanled get attribute Operation
 * @param buffer
 * @return
 */
Buffer resolveAttrOperator(Buffer buffer) {
    if (buffer.length != PROTOCOL_METH_ID_SIZE + PROTOCOL_OBJ_ID_SIZE) {
        return BuildErrorResponse();
    }
    int num = 0;
    deserilizeInt(num, buffer.data);

    switch (num) {
        case ATT_MOVIE_CINEMA: {
            return resolveGetMovie(buffer);
        }
    }
    return BuildErrorResponse();
}

/**
 * Object Creator Handler
 * @param buffer
 * @return
 */
Buffer resolveCreateObJOperator(Buffer buffer) {
    if (buffer.length < 1) {
        return BuildErrorResponse();
    }

    DATA_TYPES type = (DATA_TYPES) (buffer.data[0]);
    switch (type) {
        case DATA_CINEMA:
            return createCinemaResolver(buffer);


    }

    return BuildErrorResponse();
}

/**
 * Cinema Creator Handler
 * @param buffer
 * @return
 */
Buffer createCinemaResolver(Buffer buffer) {
    Movie *m = new Movie("", 0);
    deserilizeMovie(m, buffer.data + 1);

    Cinema cinema(*m);
    int value = pool.registerObject(m);

    Buffer buff;
    buff.length = PROTOCOL_NUMBER_SIZE;
    int length;
    serilizeInt(value, buff.data, &length);

    Buffer res;
    generateOKResponse(buff, res);
    return res;
}

/**
 * Method Callback Handler
 * @param buffer
 * @return
 */
Buffer resolveMethodOperator(Buffer buffer) {
    if (buffer.length != PROTOCOL_METH_ID_SIZE + PROTOCOL_OBJ_ID_SIZE) {
        return BuildErrorResponse();
    }
    int num = 0;
    deserilizeInt(num, buffer.data);

    switch (num) {
        case METHOD_CINEMA_GET_MOVIE: {
            return resolveCinGetMovie(buffer);
        }
    }
    return BuildErrorResponse();
}

/**
 * Movie Receiver Handler
 * @param buffer
 * @return
 */
Buffer resolveCinGetMovie(Buffer buffer) {
    if (buffer.length != PROTOCOL_FUN_ID_SIZE + PROTOCOL_NUMBER_SIZE) {
        return BuildErrorResponse();
    }
    int value;
    deserilizeInt(value, buffer.data + PROTOCOL_FUN_ID_SIZE);

    Cinema *c = (Cinema *) pool.getObject(value);

    Buffer buff;
    int length;
    Movie m = c->getMainMovie();
    serilizeMovie(&m, buff.data, &length);
    buff.length = length;
    Buffer res;
    generateOKResponse(buff, res);


    return res;
}


/**
 * Function Operator resolver handler
 * @param buffer
 * @return
 */
Buffer resolveFuncOperator(Buffer buffer) {
    if (buffer.length < PROTOCOL_FUN_ID_SIZE + 1) {
        return BuildErrorResponse();
    }
    int num = 0;
    deserilizeInt(num, buffer.data);

    switch (num) {
        case FUN_INCREMENT: {
            return resolveFunIncrement(buffer);
        }
        case FUN_PRINT_TEXT: {
            return resolvePrintText(buffer);
        }
    }
    return BuildErrorResponse();
}

/**
 * Returns Build OK response
 * @return
 */
Buffer BuildOKResponse() {
    Buffer buff;
    buff.length = 0;
    Buffer ress;
    generateOKResponse(buff, ress);
    return ress;
}

/**
 * Print Text Function Resolver
 * @param buffer
 * @return
 */
Buffer resolvePrintText(Buffer buffer) {
    if (buffer.length < PROTOCOL_FUN_ID_SIZE) {
        return BuildErrorResponse();
    }
    string str = deserilizeStr(buffer.data + PROTOCOL_FUN_ID_SIZE);
    printText(str);

    return BuildOKResponse();
}

/**
 * Increment Function Resolver
 * @param buffer
 * @return
 */
Buffer resolveFunIncrement(Buffer buffer) {
    if (buffer.length != PROTOCOL_FUN_ID_SIZE + PROTOCOL_NUMBER_SIZE) {
        return BuildErrorResponse();
    }
    int value;
    deserilizeInt(value, buffer.data + PROTOCOL_FUN_ID_SIZE);
    value = incrementInt(value);

    Buffer buff;
    buff.length = PROTOCOL_NUMBER_SIZE;
    int length = 0;
    serilizeInt(value, buff.data, &length);
    Buffer res;
    generateOKResponse(buff, res);
    return res;
}

/**
 * Data Operator Resolver
 * @param buffer
 * @return
 */
Buffer resolveDataOperator(Buffer buffer) {
    if (buffer.length < PROTOCOL_NUMBER_SIZE + 1) {
        return BuildErrorResponse();
    }
    DATA_TYPES type = (DATA_TYPES) (buffer.data[0]);
    switch (type) {
        case DATA_INT:
            return intDataResolver(buffer);
    }
    return BuildErrorResponse();
}

/**
 * Integer Data Resolver
 * @param buffer
 * @return
 */
Buffer intDataResolver(Buffer buffer) {
    if (buffer.length != 1 + PROTOCOL_NUMBER_SIZE) {
        return BuildErrorResponse();
    }
    int value;
    deserilizeInt(value, buffer.data + 1);
    cout << "\n\n>>>>>>>> Received Int Data: " << value << "\n\n" << endl;
    return BuildOKResponse();
}

/**
 * Error Response Builder
 * @return
 */
Buffer BuildErrorResponse() {
    Buffer buf{};
    generateErrorResponse(buf);
    return buf;
}



