#include "../libft.h"
#include "constants.h"

typedef struct s_test {
    char *desc;
    char const *s;
    unsigned int start;
    size_t len;
    const char *expected;
} t_test;

int run_tests(t_test *tests, int count);

int main(void)
{
    t_test tests[] = {
        {
            .desc = "ft_substr - substring from the beginning",
            .s = "Hello, World!",
            .start = 0,
            .len = 5,
            .expected = "Hello"
        },
        {
            .desc = "ft_substr - substring in the middle",
            .s = "Hello, World!",
            .start = 7,
            .len = 5,
            .expected = "World"
        },
        {
            .desc = "ft_substr - substring with len exceeding the string",
            .s = "Hello, World!",
            .start = 7,
            .len = 50,
            .expected = "World!"
        },
        {
            .desc = "ft_substr - start index beyond the string length",
            .s = "Hello",
            .start = 10,
            .len = 5,
            .expected = ""
        },
        {
            .desc = "ft_substr - empty string",
            .s = "",
            .start = 0,
            .len = 5,
            .expected = ""
        },
        {
            .desc = "ft_substr - len is zero",
            .s = "Hello, World!",
            .start = 5,
            .len = 0,
            .expected = ""
        },
        {
            .desc = "ft_substr - start is 0, len is 0",
            .s = "Hello, World!",
            .start = 0,
            .len = 0,
            .expected = ""
        },
        {
            .desc = "ft_substr - entire string",
            .s = "Hello, World!",
            .start = 0,
            .len = 13,
            .expected = "Hello, World!"
        },
        {
            .desc = "ft_substr - substring of single character",
            .s = "Hello, World!",
            .start = 1,
            .len = 1,
            .expected = "e"
        }
    };

    int count = sizeof(tests) / sizeof(tests[0]);

    return (run_tests(tests, count));
}

int run_tests(t_test *tests, int count)
{
    int i;
    int error = 0;
    char *ft_result;

    for (i = 0; i < count; i++) {
        // Apply the function and store the result
        ft_result = ft_substr(tests[i].s, tests[i].start, tests[i].len);

        // Check that the output matches the expected value
        if ((ft_result == NULL && tests[i].expected != NULL) || (ft_result != NULL && strcmp(ft_result, tests[i].expected) != 0)) {
            printf("    " RED "[%d] %s Expected \"%s\", got \"%s\"\n" DEFAULT, i + 1, tests[i].desc, tests[i].expected, ft_result ? ft_result : "NULL");
            error++;
        } else {
            printf("  " GREEN CHECKMARK GREY " [%d] %s output \"%s\" as expected\n" DEFAULT, i + 1, tests[i].desc, ft_result);
        }

        // Free the allocated memory
        free(ft_result);
    }

    return (error);
}
