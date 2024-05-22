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
            .desc = "ft_strlcpy - copy empty string",
            .dest = "original",
            .src = "",
            .dstsize = 100
        },
        {
            .desc = "ft_strlcpy - copy to buffer larger than src",
            .dest = "original",
            .src = "test",
            .dstsize =100
        },
        {
            .desc = "ft_strlcpy - copy to buffer smaller than src",
            .dest = "original",
            .src = "this is a test",
            .dstsize = 5
        },
		{
            .desc = "ft_strlcpy - copy to buffer exactly fitting src",
            .dest = "original",
            .src = "exact fit",
            .dstsize = 10
        },
        {
            .desc = "ft_strlcpy - copy to buffer size 0",
            .dest = "original",
            .src = "test",
            .dstsize = 0
        },
        {
            .desc = "ft_strlcpy - src larger than dest with truncation",
            .dest = "original",
            .src = "1234567890",
            .dstsize = 6
        },
		 {
            .desc = "ft_strlcpy - dest and src are the same",
            .dest = "same buffer",
            .src = "same buffer",
            .dstsize = 100
        },
        {
            .desc = "ft_strlcpy - src empty, dest non-empty",
            .dest = "not empty",
            .src = "",
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
        // Prepare destination buffer with the initial value
        strcpy(expected_dest, tests[i].dest);

        // Apply functions and store the result
        ft_result = ft_strlcpy(tests[i].dest, tests[i].src, tests[i].dstsize);
		expected_return = strlcpy(expected_dest, tests[i].src, tests[i].dstsize);

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