#include "types.h"
#include "stat.h"
#include "user.h"

void worker(void *arg);
int
main() {
    int pid = fork();
    if (pid == 0) {
        int arg = 3;
        printf(1, "tid:%d\n",clone(worker, (void *)&arg));
        //join();
        exit();
    }
    wait();
    exit();
}

void worker(void *arg) {
    printf(1, "startign worker\n");
    while (*(int *)arg < 100) {
        *(int *)arg = *(int *)arg + 1;
        printf(1, "arg : %d\n", *(int *)arg);
    }
}


