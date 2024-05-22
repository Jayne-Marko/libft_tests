#include "../libft.h"
#include "constants.h"


typedef struct s_test {
    char *desc;
    char dest[100];
    char src[100];
    size_t n;
    char expected[100];
} t_test;

int run_tests(t_test *tests, int count);

int main(void)
{
    t_test tests[] = {
        {
            .desc = "ft_memcpy - copy empty string",
            .dest = "original",
            .src = "",
            .n = 0,
            .expected = "original"
        },
        {
            .desc = "ft_memcpy - copy string of length 1",
            .dest = "original",
            .src = "A",
            .n = 1,
            .expected = "original"
        },
        {
            .desc = "ft_memcpy - copy string of length 4",
            .dest = "original",
            .src = "test",
            .n = 4,
            .expected = "original"
        },
        {
            .desc = "ft_memcpy - copy string of length 9",
            .dest = "original",
            .src = "complete",
            .n = 9,
            .expected = "original"
        },
		{
            .desc = "ft_memcpy - overlapping regions dest < src",
            .dest = "1234567890",
            .src = "234567890",
            .n = 5,
            .expected = "1234567890"
        },
        {
            .desc = "ft_memcpy - overlapping regions dest > src",
            .dest = "234567890",
            .src = "1234567890",
            .n = 5,
            .expected = "234567890"
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

        for (i = 0; i < count; i++)
        {
            ft_result = ft_memcpy(tests[i].dest, tests[i].src, tests[i].n);
			expected = memcpy(tests[i].expected, tests[i].src, tests[i].n);

        	// Check that the output matches the expected value
        	if (strcmp(ft_result, expected) != 0)
            {
                printf("    " RED "[%d] %s Expected \"%s\", got \"%s\"\n", i + 1, tests[i].desc, expected, ft_result);
            	error++;
            }
            else
                printf("  " GREEN CHECKMARK GREY " [%d] %s output \"%s\" as expected\n" DEFAULT, i + 1, tests[i].desc, ft_result);
        }
        return (error);
}