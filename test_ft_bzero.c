#include "../libft.h"
#include "constants.h"


typedef struct s_test
{
    char *desc;
    char buffer[100];
    size_t n;
    char expected[100];
} t_test;

int run_tests(t_test *tests, int count);

int main(void)
{
     t_test tests[] = {
        {.desc = "ft_bzero(buffer, 5)", .buffer = "Hello, World!", .n = 5, .expected = "\0\0\0\0\0, World!"},
        {.desc = "ft_bzero(buffer, 0)", .buffer = "Hello, World!", .n = 0, .expected = "Hello, World!"},
        {.desc = "ft_bzero(buffer, 13)", .buffer = "Hello, World!", .n = 13, .expected = "\0\0\0\0\0\0\0\0\0\0\0\0\0!"},
        {.desc = "ft_bzero(buffer, 1)", .buffer = "Hello, World!", .n = 1, .expected = "\0ello, World!"},
        {.desc = "ft_bzero(buffer, 7)", .buffer = "Hello", .n = 7, .expected = "\0\0\0\0\0\0\0"}
    };
        int count = sizeof(tests) / sizeof(tests[0]);

        return (run_tests(tests, count));
}

int run_tests(t_test *tests, int count)
{
        int i;
        int error = 0;
    	char buffer_copy[100];

        for (i = 0; i < count; i++)
        {
            strcpy(buffer_copy, tests[i].buffer);
        	ft_bzero(buffer_copy, tests[i].n);

        // Check that the output matches the expected value
        	if (memcmp(buffer_copy, tests[i].expected, strlen(tests[i].buffer)) != 0)
            {
                printf("    " RED "[%d] %s Expected \"%s\", got \"%s\"\n", i + 1, tests[i].desc, tests[i].expected, buffer_copy);
            	error++;
            }
            else
                printf("  " GREEN CHECKMARK GREY " [%d] %s output \"%s\" as expected\n" DEFAULT, i + 1, tests[i].desc, buffer_copy);
    }
        return (error);
}