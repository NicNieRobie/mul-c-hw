/*--------------------------- name_generation.c ---------------------------
 * Contains a definition of a function for generating a random name and
 *   surname pair.
 *-------------------------------------------------------------------------*/

#include <stdlib.h>
#include <stdio.h>

#include "name_generation.h"

// Names used for generation.
char *names[] = {
        "Sam", "Hugh", "John", "Sally", "Albert", "Anna", "Alice", "Joseph"
};

// Surnames used for generation.
char *surnames[] = {
        "Hetfield", "Redmond", "Willis", "Smith", "Kraft", "Rosenberg"
};

//-------------------------------------------------------------------------
/// Generates a random name + surname pair using a predefined set.
/// @return A random name + surname pair.
char *GenerateName() {
    // Randomly selecting a name.
    int name_index = rand() % 8;
    // Randomly selecting a surname.
    int surname_index = rand() % 6;

    // Forming the output.
    char *output = malloc(256);
    snprintf(output, 256, "%s %s", names[name_index], surnames[surname_index]);
    return output;
}