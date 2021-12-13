#include <stdio.h>
#include <stdlib.h>

#include "talker.h"

int main(int argc, char *argv[]) {
    size_t size;
    scanf("%li", &size);
    pthread_mutex_init(&talker_mutex, NULL);

    pthread_t pthreads[size];
    Talker *talkers[size];
    for (int i = 0; i < size; ++i) {
        talkers[i] = malloc(sizeof(Talker));
        talkers[i]->name = malloc(20);
        sprintf(talkers[i]->name, "Talker %d", i);
        talkers[i]->companion = NULL;
    }

    TalkArgs talkArgs[size];

    for (int i = 0; i < size; ++i) {
        talkArgs[i].talker_arr_size = size;
        talkArgs[i].talker_arr = talkers;
        talkArgs[i].talker_index = i;
        pthread_create(&pthreads[i], NULL, talk, (void*)&talkArgs[i]);
    }

    for (int i = 0; i < size; ++i) {
        pthread_join(pthreads[i], NULL);
    }
    return 0;
}