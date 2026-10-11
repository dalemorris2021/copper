#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include "lib.h"

typedef bool (*Test)(void);

bool add_test_one(void);
bool add_test_two(void);
bool add_test_three(void);

int main(void) {
    bool has_prev_test_passed = true;
    uint32_t num_tests_failed = 0;
    bool all_passed = true;

    Test tests[] = { &add_test_one, &add_test_two, &add_test_three };

    for (size_t i = 0; i < 3; i++) {
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

bool add_test_one(void) {
    int32_t x = 3;
    int32_t y = 5;
    int32_t expected = 8;

    int32_t actual = add(x, y);

    return actual == expected;
}

bool add_test_two(void) {
    int32_t x = 0;
    int32_t y = 0;
    int32_t expected = 0;

    int32_t actual = add(x, y);

    return actual == expected;
}

bool add_test_three(void) {
    int32_t x = -5;
    int32_t y = 3;
    int32_t expected = -2;

    int32_t actual = add(x, y);

    return actual == expected;
}
