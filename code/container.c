/*------------------------------ container.c ------------------------------
 * Talker pool container data type functionality.
 *-------------------------------------------------------------------------*/

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

#include "container.h"
#include "name_generation.h"

//-------------------------------------------------------------------------
/// Initializes the container.
/// @param container The container.
void Initialize(container_st *container) {
    pthread_mutex_init(&talker_mutex, NULL);
    container->count = 0;
}

//-------------------------------------------------------------------------
/// Generates the phone talker pool container.
/// @param container The container.
/// @param size Amount of talkers to be generated.
void GenerateContainer(container_st *container, const size_t size) {
    // Generating talkers.
    for (int i = 0; i < size; ++i) {
        // Allocating memory for talker.
        container->talker_data[i] = malloc(sizeof(talker_st));

        // Generating talker name.
        container->talker_data[i]->name = malloc(20);
        char *generated_name = GenerateName();
        snprintf(container->talker_data[i]->name, 60, "%s (ID: %d)", generated_name, i + 1);

        // Talker has no companion on start.
        container->talker_data[i]->companion = NULL;
    }

    container->count = size;
}

//-------------------------------------------------------------------------
/// Runs the talkers simulation on automatically designated POSIX threads.
/// @param container The talkers pool container.
/// @param call_duration Max duration of a call between two talkers.
/// @param run_duration Duration of each thread's run.
void Run(container_st *container, const int call_duration, const int run_duration) {
    // Arguments array for thread processes.
    talk_args_st talk_args[container->count];

    // Creating threads.
    for (int i = 0; i < container->count; ++i) {
        // Filling the argument struct.
        talk_args[i].talker_arr_size = container->count;
        talk_args[i].talker_arr = container->talker_data;
        talk_args[i].talker_index = i;
        talk_args[i].max_call_duration = call_duration;
        talk_args[i].run_duration = run_duration;

        // Creating the thread and launching the talk process for talker_data[i].
        pthread_create(&(container->pthreads[i]), NULL, talk, (void*)&talk_args[i]);
    }

    // Waiting for all threads to finish their work.
    for (int i = 0; i < container->count; ++i) {
        pthread_join(container->pthreads[i], NULL);
    }
}

//-------------------------------------------------------------------------
/// Prints information about the container's talker data to stdout.
/// @param container The talkers pool container.
void Print(container_st *container) {
    // Printing info.
    printf("Phone talker pool contains %d talkers:\n", container->count);
    for (int i = 0; i < container->count; ++i) {
        printf("%s\n", container->talker_data[i]->name);
    }
}