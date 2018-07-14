//
// Created by Guri on 13/07/2018.
//


#include "ObjectPool.h"

/**
 * Thread Safe Approach
 */
#define synchronized(m) \
    for(std::unique_lock<std::recursive_mutex> lk(m); lk; lk.unlock())


/**
 * Object Registration: returned ID descriptor
 * @param obj
 * @return
 */
int ObjectPool::registerObject(void *obj) {
    int indVal = 0;
    synchronized(m_mutex) {
        this->poolObj[index++] = obj;
        indVal = index;
    }
    return indVal;
}

/**
 * Returns object with the associated ID
 * @param id
 * @return
 */
void *ObjectPool::getObject(int id) {
    void *res = nullptr;
    synchronized(m_mutex) {
        res = this->poolObj[id];

    }
    return res;
}
