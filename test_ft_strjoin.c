#include "../libft.h"
#include "constants.h"

typedef struct s_test {
    char *desc;
    char const *s1;
    char const *s2;
    const char *expected;
} t_test;

int run_tests(t_test *tests, int count);

int main(void)
{
    t_test tests[] = {
        {
            .desc = "ft_strjoin - concatenate two non-empty strings",
            .s1 = "Hello, ",
            .s2 = "World!",
            .expected = "Hello, World!"
        },
        {
            .desc = "ft_strjoin - concatenate empty string with non-empty string",
            .s1 = "",
            .s2 = "World!",
            .expected = "World!"
        },
        {
            .desc = "ft_strjoin - concatenate non-empty string with empty string",
            .s1 = "Hello, ",
            .s2 = "",
            .expected = "Hello, "
        },
        {
            .desc = "ft_strjoin - concatenate two empty strings",
            .s1 = "",
            .s2 = "",
            .expected = ""
        },
        {
            .desc = "ft_strjoin - concatenate string with itself",
            .s1 = "Repeat",
            .s2 = "Repeat",
            .expected = "RepeatRepeat"
        },
        {
            .desc = "ft_strjoin - concatenate special characters",
            .s1 = "@#$",
            .s2 = "&*()",
            .expected = "@#$&*()"
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
        ft_result = ft_strjoin(tests[i].s1, tests[i].s2);

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
