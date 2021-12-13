#ifndef MUL_C_HW_CONTAINER_H
#define MUL_C_HW_CONTAINER_H

/*------------------------------ container.h ------------------------------
 * Data type acting as a talker pool container.
 *-------------------------------------------------------------------------*/

#include "talker.h"

//---------------------------- type definition ----------------------------
/// Basic container data type holding an array of a talkers (20 talkers max).
/// Also holds a pool of POSIX threads used for running each talker's
///   talk simulation for a set amount of time.
typedef struct {
    enum {MAX_SIZE = 20};
    unsigned int count;
    talker_st *talker_data[MAX_SIZE];
    pthread_t pthreads[MAX_SIZE];
} container_st;

//-------------------------- type functionality ---------------------------
/// Initializes the container.
/// @param container The container.
void Initialize(container_st *container);

/// Generates the phone talker pool container.
/// @param container The container.
/// @param size Amount of talkers to be generated.
void GenerateContainer(container_st *container, size_t size);

/// Runs the talkers simulation on automatically designated POSIX threads.
/// @param container The talkers pool container.
/// @param call_duration Max duration of a call between two talkers.
/// @param run_duration Duration of each thread's run.
void Run(container_st *container, int call_duration, int run_duration);

/// Prints information about the container's talker data to stdout.
/// @param container The talkers pool container.
void Print(container_st *container);

#endif //MUL_C_HW_CONTAINER_H
