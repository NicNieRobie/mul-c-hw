/*-------------------------------- talker.c -------------------------------
 * Contains a definition of talker's simulation (talk) function.
 *-------------------------------------------------------------------------*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>

#include "talker.h"

//-------------------------------------------------------------------------
/// Simulates talker's behaviour for a set amount of time.
/// @param talk_args_ptr talk_args_st arguments wrapper.
/// @see talk_args_st
void* talk(void *talk_args_ptr) {
    // Getting the talk_args_st pointer.
    talk_args_st *talk_args = (talk_args_st*)talk_args_ptr;

    // Unwrapping the arguments.
    size_t talker_index = talk_args->talker_index;
    talker_st **talker_arr = talk_args->talker_arr;
    size_t talker_arr_size = talk_args->talker_arr_size;
    int max_call_duration = talk_args->max_call_duration;
    int run_duration = talk_args->run_duration;

    // Setting the seed for random generation on this thread.
    srand(time(NULL));

    // Saving the start time.
    time_t start;
    time(&start);

    // Variable used to monitor the amount of time elapsed since start.
    time_t curr_time;
    time(&curr_time);

    // (locking the mutex when accessing the name field)
    pthread_mutex_lock(&talker_mutex);
    printf("START: %s begins making calls for %d seconds\n",
           talker_arr[talker_index]->name, run_duration);
    pthread_mutex_unlock(&talker_mutex);

    // Running until the duration cap is reached.
    while (difftime(curr_time, start) < run_duration) {
        /*
         * Flag that indicates if talker could find an available
         *   companion on this iteration.
         */
        bool could_find_companion = false;

        // Saving elapsed time.
        time(&curr_time);

        // Skipping the iteration if the talker's talking with someone.
        // (locking the mutex when accessing the companion field)
        pthread_mutex_lock(&talker_mutex);
        if (talker_arr[talker_index]->companion) {
            pthread_mutex_unlock(&talker_mutex);
            continue;
        }
        pthread_mutex_unlock(&talker_mutex);

        // (locking the mutex when accessing the name field)
        pthread_mutex_lock(&talker_mutex);
        printf("%s is trying to call someone\n", talker_arr[talker_index]->name);
        pthread_mutex_unlock(&talker_mutex);

        // Trying to find an available talker - five attempts.
        int counter = 0;
        while (counter < 5) {
            size_t rand_index;

            // Randomly picking other talker's index.
            do {
                rand_index = rand() % talker_arr_size;
            } while (rand_index == talker_index);

            // If talker's available.
            if (talker_arr[rand_index] && !talker_arr[rand_index]->companion) {
                // Locking the mutex for data access.
                pthread_mutex_lock(&talker_mutex);

                // Setting a new companion.
                talker_arr[talker_index]->companion = talker_arr[rand_index];
                talker_arr[rand_index]->companion = talker_arr[talker_index];
                printf("%s is talking with %s\n",
                       talker_arr[talker_index]->name, talker_arr[rand_index]->name);

                // Unlocking the mutex after data access.
                pthread_mutex_unlock(&talker_mutex);

                // Saving the call start time.
                time_t call_start;
                time(&call_start);

                // Checking if the available companion was "hijacked" by another caller.
                if (talker_arr[rand_index]->companion != talker_arr[talker_index]) {
                    counter++;
                    continue;
                }

                // Picking the call duration and "calling" the talker.
                int call_duration = rand() % max_call_duration + 1;
                sleep(call_duration);

                // Saving the call end time.
                time_t call_end;
                time(&call_end);

                // Locking the mutex for data access.
                pthread_mutex_lock(&talker_mutex);

                // "Freeing" the talkers by nullifying companion references.
                talker_arr[talker_index]->companion = NULL;
                talker_arr[rand_index]->companion = NULL;
                printf("%s stopped talking with %s after %.0f secs\n",
                       talker_arr[talker_index]->name, talker_arr[rand_index]->name,
                       difftime(call_end, call_start));

                // Unlocking the mutex after data access.
                pthread_mutex_unlock(&talker_mutex);

                // Setting the flag.
                could_find_companion = true;
                break;
            }

            // If picked talker was unavailable - continue trying.
            counter++;
        }

        // Locking the mutex for name field access.
        pthread_mutex_lock(&talker_mutex);

        // Printing info on the talker waiting for calls.
        if (could_find_companion) {
            printf("After finishing the call, %s is waiting for calls\n",
                   talker_arr[talker_index]->name);
        } else {
            printf("After failing to find someone to call, %s is waiting for calls\n",
                   talker_arr[talker_index]->name);
        }

        // Unlocking the mutex.
        pthread_mutex_unlock(&talker_mutex);

        // Waiting for calls.
        sleep(20);
    }

    // Locking the mutex for name field access.
    pthread_mutex_lock(&talker_mutex);

    // Printing message on POSIX process thread interrupt.
    printf("INTERRUPT: %s finished phone calls after %d seconds\n",
           talker_arr[talker_index]->name, run_duration);

    // Unlocking the mutex.
    pthread_mutex_unlock(&talker_mutex);
}