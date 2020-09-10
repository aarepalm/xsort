#ifndef XSORT_H
#define XSORT_H

#define INPUT_ARRAY_MIN_SIZE (0)
#define INPUT_ARRAY_MAX_SIZE (50000)
/**
 * @brief Outputs numbers from input array in ascending order to standard output.
 * Input values outside of range INPUT_ARRAY_MIN_SIZE and INPUT_ARRAY_MAX_SIZE are skipped.
 * Duplicates don't break the function either, these are handled by merging.
 *
 * This function implements bitvector, where each value in input array sets a bit in
 * bitmap. When bitmap is iterated from start then all bits set to 1 represent valus from input
 * array in ascending order.
 *
 * @param Input array, caller remains the owner of memory.
 * @param Number of element in the input array. If value is over INPUT_ARRAY_MAX_SIZE then tail is cut.
 */
void xsort(int *input, int count);

#endif /* XSORT_H */
