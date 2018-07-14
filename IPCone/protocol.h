//
// Created by Guri on 13/07/2018.
//

#ifndef SERVER_PROTOCOL_H
#define SERVER_PROTOCOL_H


/**
 * MAIN PROTOCOL For Pipe Communication
 */

/*
 * Supported OperationEnum with Descriptors
 */
enum OPERATIONS {
    OP_DATA = 0x01,
    OP_FUNCTION = 0x02,
    OP_METHOD = 0x03,
    OP_CREATE_OBJ = 0x04,
    OP_GET_ATTRIBUTE = 0x05,
    OP_RESPONSE = 0x06,
};

/**
 * Supported ATTRIBUTES enum with Descriptors
 */
enum ATTRIBUTES {
    ATT_CINAMA_NAME = 0x00010001, // classNum + attNum
    ATT_CINAMA_RATING = 0x00010002, // classNum + attNum
    ATT_MOVIE_CINEMA = 0x00020001, // classNum + attNum
};

/**
 * Error Types Enum
 */
enum ERROR_TYPES {
    GENERIC_ERROR,
    UNSUPPORTED_OPERATION,
};


/**
 * Defined value for internal use
 */
#define SYNCH_START   (0xEF)    //start Synchronisation
#define SYNCH_END  (0xFC)        //end Synchronisation

//Length definition fot types
#define PROTOCOL_NUMBER_SIZE  (4)
#define PROTOCOL_OBJ_ID_SIZE  (4)
#define PROTOCOL_FUN_ID_SIZE  (4)
#define PROTOCOL_METH_ID_SIZE  (4)
#define PROTOCOL_ATTR_ID_SIZE  (4)


/**
 * Supported FunctionS ENUM
 */
enum FUNCTIONS {
    FUN_INCREMENT = 0x01,
    FUN_PRINT_TEXT = 0x02,

};

/**
 * Supported METHODS ENUM
 */
enum METHODS {
    METHOD_CINEMA_GET_MOVIE = 0x00010001, // classNum + MethodNum
};

enum DATA_TYPES {
    DATA_CHAR = 0x01,
    DATA_BOOL,
    DATA_SHORT,
    DATA_INT,
    DATA_DOUBLE,
    DATA_STRING,

    DATA_CINEMA,
    DATA_MOVIE,

};

/**
 * Supported Response status enum
 */

enum RESPONSE_STATUS {
    OK_RESPONSE = 0x00,
    ERROR_RESPONSE = 0x01,
};
#endif //SERVER_PROTOCOL_H
