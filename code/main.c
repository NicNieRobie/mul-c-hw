/*--------------------------------- main.c --------------------------------
 * Program entry point and error messages.
 *-------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

#include "container.h"

//-------------------------------------------------------------------------
/// Prints the argument number error.
void ArgNumError() {
    fprintf(stderr, "Incorrect number of arguments in the command line!\n"
                    "  Expected:\n"
                    "     processname talker_count(int) max_call_duration(int) run_duration(int)\n");
}

//-------------------------------------------------------------------------
/// Prints the size error.
void SizeError(const size_t size) {
    fprintf(stderr, "Size %li exceeds 20 or is less or equal to 0.\n"
                    "Enter a value: 0 < value <= 20\n", size);
}

//-------------------------------------------------------------------------
/// Prints the call duration error.
void CallDurationError(const int max_call_duration) {
    fprintf(stderr, "Max call duration %d exceeds 60 seconds or is less or equal to 0 seconds.\n"
                    "Enter a value: 0 < value <= 60\n", max_call_duration);
}

//-------------------------------------------------------------------------
/// Prints the run duration error.
void RunDurationError(const int run_duration) {
    fprintf(stderr, "Run duration %d exceeds 5 minutes or is less or equal to max call duration.\n"
                    "Enter a value: max_call_duration < value <= 300\n", run_duration);
}

//-------------------------------------------------------------------------
/// Program entry point.
int main(int argc, char *argv[]) {
    time_t start;
    time(&start);

    // Checking if the argument count is correct.
    if (argc != 4) {
        ArgNumError();
        exit(EXIT_FAILURE);
    }

    // Checking if the specified size is valid.
    size_t size = atol(argv[1]);
    if((size < 1) || (size > 20)) {
        SizeError(size);
        exit(EXIT_FAILURE);
    }

    /*
     * Talkers container used to generate
     *   and run the simulation.
     */
    container_st container;

    // Setting the seed for random generation on main thread.
    srand(time(NULL));

    // Initializing the container.
    Initialize(&container);

    // Generating the specified amount of talkers in container.
    GenerateContainer(&container, size);

    // Printing generated talkers.
    Print(&container);

    // Reading duration settings.
    int max_call_duration = atoi(argv[2]);
    int run_duration = atoi(argv[3]);

    // Checking if max call duration is valid.
    if((max_call_duration < 1) || (max_call_duration > 60)) {
        CallDurationError(max_call_duration);
        exit(EXIT_FAILURE);
    }

    // Checking if thread run duration is valid.
    if((run_duration < max_call_duration + 1) || (run_duration > 300)) {
        RunDurationError(run_duration);
        exit(EXIT_FAILURE);
    }

    // Running the simulation.
    printf("\n---------------------------------------------------------\n");
    printf("Running the simulation...\n\n");
    Run(&container, max_call_duration, run_duration);

    // Printing runtime duration.
    time_t end;
    time(&end);
    printf("\nRuntime duration: %.6f seconds", difftime(end, start));

    return 0;
}