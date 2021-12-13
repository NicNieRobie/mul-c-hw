#ifndef MUL_C_HW_TALKER_H
#define MUL_C_HW_TALKER_H

/*-------------------------------- talker.h -------------------------------
 * Contains a definition of talker data type and its behaviour.
 *-------------------------------------------------------------------------*/

#include <pthread.h>

// Mutual exclusion semaphore used for
//   talker threads data access synchronization.
pthread_mutex_t talker_mutex;

//------------------------- talker type definition ------------------------
/// Talker data type that holds basic information on the talker.
typedef struct talker {
    // Talker name.
    char *name;
    // The other talker that this talker's currently talking to.
    struct talker *companion;
} talker_st;

//----------------------- talk_args type definition -----------------------
/// Data type that acts as a wrapper for talker's behaviour function arguments.
typedef struct talk_args {
    /// Talker's index in the talkers pool array.
    size_t talker_index;
    /// Talkers pool array.
    talker_st **talker_arr;
    /// Talkers pool array size.
    size_t talker_arr_size;
    /// Maximum duration of calls between talkers.
    int max_call_duration;
    /// Duration of talker simulation run.
    int run_duration;
} talk_args_st;

//----------------------- talker type functionality -----------------------
/// Simulates talker's behaviour for a set amount of time.
/// @param talk_args_ptr talk_args_st arguments wrapper.
/// @see talk_args_st
void* talk(void *talk_args_ptr);

#endif //MUL_C_HW_TALKER_H
