#include "../libft.h"
#include "constants.h"

typedef struct s_test {
    char *desc;
    size_t num;
    size_t size;
    int expect_null;
} t_test;

int run_tests(t_test *tests, int count);

int main(void) {
    t_test tests[] = {
        {.desc = "Allocate array of 5 ints", 
         .num = 5, 
         .size = sizeof(int), 
         .expect_null = 0},
        {.desc = "Allocate array of 10 chars", 
         .num = 10, 
         .size = sizeof(char), 
         .expect_null = 0},
        {.desc = "Allocate large array of 0 elements", 
         .num = 0, 
         .size = sizeof(int), 
         .expect_null = 0},
        {.desc = "Allocate large array of 0 size elements", 
         .num = 10, 
         .size = 0, 
         .expect_null = 0},
        {.desc = "Test large allocation (expect failure)", 
         .num = SIZE_MAX, 
         .size = SIZE_MAX, 
         .expect_null = 1},
        {.desc = "Test negative num and size", 
         .num = (size_t)-5, 
         .size = (size_t)-5, 
         .expect_null = 1}
    };

    int count = sizeof(tests) / sizeof(tests[0]);

    return (run_tests(tests, count));
}

int run_tests(t_test *tests, int count) {
    int i;
    int errors = 0;

    for (i = 0; i < count; i++) {
        void *result = ft_calloc(tests[i].num, tests[i].size);

        if ((result == NULL && !tests[i].expect_null) || (result != NULL && tests[i].expect_null)) {
            printf("    " RED "[%d] %s Expected %s, got %s\n",
                   i + 1, 
                   tests[i].desc,
                   tests[i].expect_null ? "NULL" : "non-NULL",
                   result == NULL ? "NULL" : "non-NULL");
            errors++;
        } else {
            printf("  " GREEN CHECKMARK GREY " %s\n", tests[i].desc);
        }

        // If memory was successfully allocated, verify that it is zero-initialized and the correct size
        if (result != NULL) {
            size_t total_size = tests[i].num * tests[i].size;
            size_t usable_size = malloc_usable_size(result);
            if (usable_size < total_size) {
                printf("    " RED "[%d] %s Allocated size (%zu) is less than expected (%zu)\n", 
                       i + 1, tests[i].desc, usable_size, total_size);
                errors++;
            }

            char *char_result = (char *)result;
            for (size_t j = 0; j < total_size; j++) {
                if (char_result[j] != 0) {
                    printf("    " RED "[%d] %s Memory not zero-initialized at index %zu\n", 
                           i + 1, tests[i].desc, j);
                    errors++;
                    break;
                }
            }
            free(result);
        }
    }
    return (errors);
}
