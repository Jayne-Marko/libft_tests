#include "../libft.h"
#include "constants.h"



typedef struct s_test {
    char *desc;
    const char *src;
    const char *expected;
} t_test;

int run_tests(t_test *tests, int count);

int main(void)
{
    t_test tests[] = {
        {
            .desc = "ft_strdup - duplicate empty string",
            .src = "",
            .expected = ""
        },
        {
            .desc = "ft_strdup - duplicate short string",
            .src = "test",
            .expected = "test"
        },
        {
            .desc = "ft_strdup - duplicate longer string",
            .src = "this is a test",
            .expected = "this is a test"
        },
        {
            .desc = "ft_strdup - duplicate string with spaces",
            .src = "   ",
            .expected = "   "
        },
        {
            .desc = "ft_strdup - duplicate string with special characters",
            .src = "hello\nworld\t!",
            .expected = "hello\nworld\t!"
        },
        {
            .desc = "ft_strdup - duplicate string with numbers",
            .src = "1234567890",
            .expected = "1234567890"
        },
        {
            .desc = "ft_strdup - duplicate single character",
            .src = "A",
            .expected = "A"
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
    char *expected;

    for (i = 0; i < count; i++) {
        ft_result = ft_strdup(tests[i].src);
        expected = strdup(tests[i].src);

        if ((ft_result == NULL && expected != NULL) || (ft_result != NULL && expected == NULL) || strcmp(ft_result, expected) != 0) {
            printf("    " RED "[%d] %s Expected \"%s\", got \"%s\"\n" DEFAULT, i + 1, tests[i].desc, expected, ft_result ? ft_result : "NULL");
            error++;
        } else {
            printf("  " GREEN CHECKMARK GREY " [%d] %s output \"%s\" as expected\n" DEFAULT, i + 1, tests[i].desc, ft_result);
        }

        free(ft_result);
        free(expected);
    }

    return (error);
}
