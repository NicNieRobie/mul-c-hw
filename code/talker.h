#ifndef MUL_C_HW_TALKER_H
#define MUL_C_HW_TALKER_H

#include <pthread.h>

pthread_mutex_t talker_mutex;

typedef struct Talker {
    char *name;
    struct Talker *companion;
} Talker;

typedef struct TalkArgs {
    size_t talker_index;
    Talker **talker_arr;
    size_t talker_arr_size;
} TalkArgs;

void* talk(void *talk_args_ptr);

#endif //MUL_C_HW_TALKER_H
