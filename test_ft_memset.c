#include "../libft.h"
#include "constants.h"


typedef struct s_test
{
    char *desc;
    char buffer[100];
    int c;
    size_t n;
    char expected[100];
} t_test;

int run_tests(t_test *tests, int count);

int main(void)
{
    t_test tests[] = {
        {
			.desc = "ft_memset(buffer, 'A', 5)", 
			.buffer = "Hello, World!", 
			.c = 'A', 
			.n = 5, 
			.expected = "Hello, World!"
		},
        {
			.desc = "ft_memset(buffer, 'B', 0)", 
			.buffer = "Hello, World!", 
			.c = 'B', 
			.n = 0, 
			.expected = "Hello, World!"
		},
        {
			.desc = "ft_memset(buffer, 'C', 13)", 
			.buffer = "Hello, World!", 
			.c = 'C', 
			.n = 13, 
			.expected = "Hello, World!"
		},
        {
			.desc = "ft_memset(buffer, 'D', 1)", 
			.buffer = "Hello, World!", 
			.c = 'D', 
			.n = 1, 
			.expected = "Hello, World!"
		},
        {
			.desc = "ft_memset(buffer, 'E', 7)", 
			.buffer = "Hello", 
			.c = 'E', 
			.n = 7, 
			.expected = "Hello"}
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
        	ft_result = ft_memset(tests[i].buffer, tests[i].c, tests[i].n);
			expected = memset(tests[i].expected,tests[i].c, tests[i].n);

        	// Check that the output matches the expected value
        	if (memcmp(ft_result, expected, tests[i].n) != 0)
            {
                printf("    " RED "[%d] %s Expected \"%s\", got \"%s\"\n", i + 1, tests[i].desc, expected, ft_result);
            	error++;
            }
            else
                printf("  " GREEN CHECKMARK GREY " [%d] %s output \"%s\" as expected\n" DEFAULT, i + 1, tests[i].desc, ft_result);
    }
        return (error);
}