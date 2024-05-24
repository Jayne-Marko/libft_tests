#include "../libft.h"
#include "constants.h"

typedef struct {
    const char *desc;
    const void *s;
    int c;
    size_t n;
} t_test;

int run_tests(t_test *tests, int count);

int main(void) {
    t_test tests[] = {
        {.desc = "Search 'o' in 'Hello World'", .s = "Hello World", .c = 'o', .n = 11},
        {.desc = "Search 'l' in 'Hello World'", .s = "Hello World", .c = 'l', .n = 11},
        {.desc = "Search 'x' in 'Hello World'", .s = "Hello World", .c = 'x', .n = 11},
        {.desc = "Search 'o' in 'Hello World' with limit", .s = "Hello World", .c = 'o', .n = 5},
        {.desc = "Search 'l' in 'Hello World' with limit", .s = "Hello World", .c = 'l', .n = 5},
        {.desc = "Search 'x' in 'Hello World' with limit", .s = "Hello World", .c = 'x', .n = 5},
        {.desc = "Search 'H' in 'Hello World'", .s = "Hello World", .c = 'H', .n = 11},
        {.desc = "Search 'H' in 'Hello World' with limit", .s = "Hello World", .c = 'H', .n = 5},
    };

    int count = sizeof(tests) / sizeof(tests[0]);
    return (run_tests(tests, count));
}
int run_tests(t_test *tests, int count) {
    int i;
    int error = 0;
    const void *ft_result;
    const void *expected;

    for (i = 0; i < count; i++) {
    	ft_result = ft_memchr(tests[i].s, tests[i].c, tests[i].n);
        expected = memchr(tests[i].s, tests[i].c, tests[i].n);

        // Check that the output matches the expected value
        if (ft_result != expected) {
            printf("    " RED "[%d] %s Expected \"%s\", got \"%s\"\n", i + 1, tests[i].desc, (const char *)expected, (const char *)ft_result);
            error -= 1;
        } else {
            printf("  " GREEN CHECKMARK GREY " [%d] %s output \"%s\" as expected\n" DEFAULT, i + 1, tests[i].desc, (const char *)ft_result);
        }
    }
    return (error);
}	