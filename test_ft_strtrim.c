#include "../libft.h"
#include "constants.h"

typedef struct s_test {
    char *desc;
    char const *s1;
    char const *set;
    const char *expected;
} t_test;

int run_tests(t_test *tests, int count);

int main(void)
{
    t_test tests[] = {
        {
            .desc = "ft_strtrim - trim characters from both ends",
            .s1 = "  Hello, World!  ",
            .set = " ",
            .expected = "Hello, World!"
        },
        {
            .desc = "ft_strtrim - trim characters from the beginning only",
            .s1 = "###StartTrim",
            .set = "#",
            .expected = "StartTrim"
        },
        {
            .desc = "ft_strtrim - trim characters from the end only",
            .s1 = "EndTrim###",
            .set = "#",
            .expected = "EndTrim"
        },
        {
            .desc = "ft_strtrim - trim characters from both ends with mixed set",
            .s1 = "***Hello, World***",
            .set = "*",
            .expected = "Hello, World"
        },
        {
            .desc = "ft_strtrim - no characters to trim",
            .s1 = "NoTrim",
            .set = "#",
            .expected = "NoTrim"
        },
        {
            .desc = "ft_strtrim - trim empty string",
            .s1 = "",
            .set = "#",
            .expected = ""
        },
        {
            .desc = "ft_strtrim - set contains all characters in string",
            .s1 = "abc",
            .set = "abc",
            .expected = ""
        },
        {
            .desc = "ft_strtrim - set is empty",
            .s1 = "NoChange",
            .set = "",
            .expected = "NoChange"
        },
        {
            .desc = "ft_strtrim - partial set",
            .s1 = "cbaSome Stringaaaaaa",
            .set = "abc",
            .expected = "Some String"
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
        ft_result = ft_strtrim(tests[i].s1, tests[i].set);

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
