//
// Created by Guri on 13/07/2018.
//

#ifndef SERVER_OBJECTPOOL_H
#define SERVER_OBJECTPOOL_H

#include <map>
#include "protocol.h"

class ObjectPool {

public:
    int registerObject(void * obj);

    void * getObject(int id);
private:

    std::map<int, void *> poolObj;
    std::map<int, DATA_TYPES> poolType;
    int index = 0;
};



#endif //SERVER_OBJECTPOOL_H
