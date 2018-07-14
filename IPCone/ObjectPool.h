//
// Created by Guri on 13/07/2018.
//

#ifndef SERVER_OBJECTPOOL_H
#define SERVER_OBJECTPOOL_H

#include <map>
#include "protocol.h"
#include <mutex>

/**
 *
 */
class ObjectPool {

public:
/**
 * Note it is Thread Safe.
 * Object Registration, Returnes ID as descriptor for future Une
 * @param obj
 * @return
 */
int registerObject(void *obj);
/**
 * Note it is Thread Safe.
 * Returns Object with ID descriptor
 * @param id
 * @return
 */
void *getObject(int id);

private:
/**
 * Some Private Variables
 */
std::map<int, void *> poolObj;
int index = 0;
std::recursive_mutex m_mutex;
};


#endif //SERVER_OBJECTPOOL_H
