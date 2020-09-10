#include <stdio.h>
#include <stdlib.h>
#include<time.h>

#include "xsort.h"

int main (void) {

    // Generating test data!
    // NB! This testdata can create duplicates, but xsort can handle these, OK for testing.
    const int SIZE = 20;
    const int RANGE = INPUT_ARRAY_MAX_SIZE + 200; // The '+ 200' is to test skipping out of range values.
    int *random_data = (int *)malloc(SIZE * sizeof(int));
    if (!random_data) {
            printf("ERR: memory allocation failed!\n");
            return 1;
    }
    srand(time(0));
    for (int i = 0; i < SIZE; ++i) {
        *(random_data + i) = rand() % RANGE;
    }

    // Sort and print to standard output.
    xsort(random_data, SIZE);

    free(random_data);
    return 0;
}
