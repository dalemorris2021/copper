#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include "core.h"

typedef bool (*Test)(void);

bool always_pass(void);
bool array_get_test(void);

int main(void) {
    bool has_prev_test_passed = true;
    uint32_t num_tests_failed = 0;
    bool all_passed = true;

    Test tests[] = { &always_pass, &array_get_test };
    uint32_t num_tests = 2;

    for (size_t i = 0; i < num_tests; i++) {
        has_prev_test_passed = tests[i]();
        all_passed = all_passed && has_prev_test_passed;

        if (!has_prev_test_passed) {
            printf("Test %d failed\n", (int)i);
            num_tests_failed++;
        }
    }

    if (all_passed) {
        printf("All tests passed\n");
    } else {
        printf("%d tests failed\n", num_tests_failed);
    }

    return EXIT_SUCCESS;
}

bool always_pass(void) {
    return true;
}

bool array_get_test(void) {
    i32 nums[] = {-2, 0, 1, 5, 8};
    usize length = 5;
    Array arr = Array_new(nums, length);
    usize index = 3;
    i32 expected = 5;

    i32 actual = ARRAY_GET(i32, arr, index);

    return actual == expected;
}
