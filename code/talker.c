#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

#include "talker.h"

void* talk(void *talk_args_ptr) {
    time_t start;
    time(&start);

    time_t curr_time;
    time(&curr_time);
    while (difftime(curr_time, start) < 30.0) {
        TalkArgs *talk_args = (TalkArgs*)talk_args_ptr;
        size_t talker_index = talk_args->talker_index;
        Talker **talker_arr = talk_args->talker_arr;
        size_t talker_arr_size = talk_args->talker_arr_size;

        time(&curr_time);

        pthread_mutex_lock(&talker_mutex);
        if (talker_arr[talker_index]->companion) {
            pthread_mutex_unlock(&talker_mutex);
            continue;
        }
        pthread_mutex_unlock(&talker_mutex);

        int counter = 0;
        while (counter < 5) {
            size_t rand_index;

            do {
                rand_index = rand() % talker_arr_size;
            } while (rand_index == talker_index);

            if (talker_arr[rand_index] && !talker_arr[rand_index]->companion) {
                pthread_mutex_lock(&talker_mutex);

                if (talker_arr[rand_index]->companion) {
                    pthread_mutex_unlock(&talker_mutex);
                    counter++;
                    continue;
                }

                talker_arr[talker_index]->companion = talker_arr[rand_index];
                talker_arr[rand_index]->companion = talker_arr[talker_index];
                printf("%s talking with %s\n",
                       talker_arr[talker_index]->name, talker_arr[rand_index]->name);
                pthread_mutex_unlock(&talker_mutex);

                time_t call_start;
                time(&call_start);

                if (talker_arr[rand_index]->companion != talker_arr[talker_index]) {
                    counter++;
                    continue;
                }

                sleep(3);

                time_t call_end;
                time(&call_end);

                pthread_mutex_lock(&talker_mutex);
                talker_arr[talker_index]->companion = NULL;
                talker_arr[rand_index]->companion = NULL;
                printf("%s stopped talking with %s after %.3f secs\n",
                       talker_arr[talker_index]->name, talker_arr[rand_index]->name,
                       difftime(call_end, call_start));
                pthread_mutex_unlock(&talker_mutex);
                break;
            }

            counter++;
        }

        pthread_mutex_lock(&talker_mutex);
        printf("%s going to sleep\n", talker_arr[talker_index]->name);
        pthread_mutex_unlock(&talker_mutex);
        sleep(20);
    }
}