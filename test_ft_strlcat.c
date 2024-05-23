#include "../libft.h"
#include "constants.h"

typedef struct s_test {
    char *desc;
    char dest[100];
    const char *src;
    size_t dstsize;
} t_test;

int run_tests(t_test *tests, int count);

int main(void)
{
    t_test tests[] = {
    {
        .desc = "ft_strlcat - append to empty dest",
		.dest = "",
        .src = "test",
        .dstsize = 50
    },
    {
        .desc = "ft_strlcat - append to dest with space left",
        .dest = "original",
        .src = " appended",
        .dstsize = 50
    },
	{
		.desc = "ft_strlcat - append to dest with no space left",
        .dest = "original",
        .src = " appended",
        .dstsize = 8
    },
    {
        .desc = "ft_strlcat - append to dest exactly fitting",
        .dest = "original",
        .src = " append",
        .dstsize = 16
    },
    {
        .desc = "ft_strlcat - append to dest with src larger than space left",
        .dest = "original",
        .src = " and then some",
        .dstsize = 15
    },
    {
        .desc = "ft_strlcat - append empty src to dest",
        .dest = "original",
        .src = "",
        .dstsize = 50
    },
    {
        .desc = "ft_strlcat - append to empty dest with dstsize 0",
        .dest = "",
        .src = "test",
		.dstsize = 0
    },
    {
        .desc = "ft_strlcat - append with src size greater than dstsize",
        .dest = "short",
        .src = "this is a very long source string",
		.dstsize = 10
    }
	};

        int count = sizeof(tests) / sizeof(tests[0]);

        return (run_tests(tests, count));
}

int run_tests(t_test *tests, int count)
{
    int i;
    int error = 0;
	char expected_dest[100];
    size_t ft_result;
	size_t expected_return;

    for (i = 0; i < count; i++) {
        strcpy(expected_dest, tests[i].dest);

        // Apply functions and store the result
        ft_result = ft_strlcat(tests[i].dest, tests[i].src, tests[i].dstsize);
		expected_return = strlcat(expected_dest, tests[i].src, tests[i].dstsize);

        // Check that the return value matches the expected value
        if (ft_result != expected_return) {
            printf("    " RED "[%d] %s Expected return \"%zu\", got \"%zu\"\n", i + 1, tests[i].desc, expected_return, ft_result);
            error++;
        }
        // Check that the destination buffer matches the expected value
        else if (strcmp(tests[i].dest, expected_dest) != 0) {
            printf("    " RED "[%d] %s Expected dest \"%s\", got \"%s\"\n", i + 1, tests[i].desc, expected_dest, tests[i].dest);
            error++;
        } else {
            printf("  " GREEN CHECKMARK GREY " [%d] %s return \"%zu\" and dest \"%s\" as expected\n" DEFAULT, i + 1, tests[i].desc, ft_result, tests[i].dest);
        }
    }
        return (error);
}