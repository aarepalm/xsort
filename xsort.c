#include <stdio.h>
#include <limits.h>

#include "xsort.h"

#define BITS_IN_INT (sizeof(int)*(__CHAR_BIT__))
#define BITMAP_SIZE (((INPUT_ARRAY_MAX_SIZE)/(BITS_IN_INT)) + 1) /* the +1 is to be sure to get the ceiling */

void xsort(int *input, int count) {
    if (!input) {
        printf("ERR: nullptr received.\n");
        return;
    }
    if (count > INPUT_ARRAY_MAX_SIZE) {
        printf("WARN: Input array size out of range, nof items dropped: %d \n", (count - INPUT_ARRAY_MAX_SIZE));
    }

    int bitmap[BITMAP_SIZE] = {0};

    /* Push to bitmap, this automatically allows sorted readout. */
    printf("Unsorted values: \n");
    for (int i = 0; i < count; ++i) {
        int value = *(input + i);
        if ((value < INPUT_ARRAY_MIN_SIZE) || (value > INPUT_ARRAY_MAX_SIZE)) {
            printf("[WARN: element %d out of range, skipping] ", value);
            continue;
        }
        printf("%d ", value);
        // Select the integer slot in bitmap and store the bitvalue.
        bitmap[value / BITS_IN_INT] |=  (1 << (value % BITS_IN_INT));
    }

    /* Printout. Iterate over all possible values and print out if relevant bit is set. */
    printf("\nSorted values: \n");
    for (int i = 0; i < (BITMAP_SIZE*BITS_IN_INT); ++i) {
        if (bitmap[i / BITS_IN_INT] & (1 << (i % BITS_IN_INT))) {
            printf("%d ", i);
        }
    }
    printf("\n");
}
