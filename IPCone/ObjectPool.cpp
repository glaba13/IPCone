//
// Created by Guri on 13/07/2018.
//

#include "ObjectPool.h"


int ObjectPool::registerObject(void * obj) {
    this->poolObj[index++] = obj;
    return index;
}

void * ObjectPool::getObject(int id) {
    return this->poolObj[id];
}
