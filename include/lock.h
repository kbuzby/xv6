#ifndef _LOCK_H_
#define _LOCK_H_

#include "types.h"

typedef uint lock_t;

typedef struct {
    int cond;
} cond_t;

typedef struct {
    uint value;
    lock_t lock;
    cond_t cond;
} sem_t;

int cv_init(cond_t*);

int cv_wait(cond_t*, lock_t*);

int cv_signal(cond_t*);

#endif