#include "../libft.h"
#include "constants.h"


typedef struct s_test
{
        char *desc;
        char c;
} t_test;

int run_tests(t_test *tests, int count);

int main(void)
{
    t_test tests[] = {
        {.desc = "ft_isprint('A')", .c = 'A'},
        {.desc = "ft_isprint('z')", .c = 'z'},
        {.desc = "ft_isprint('0')", .c = '0'},
        {.desc = "ft_isprint(' ')", .c = ' '},
        {.desc = "ft_isprint('~')", .c = '~'},
        {.desc = "ft_isprint('!')", .c = '!'},
        {.desc = "ft_isprint('@')", .c = '@'},
        {.desc = "ft_isprint('\\t')", .c = '\t'},  // Non-printable character
        {.desc = "ft_isprint('\\n')", .c = '\n'},  // Non-printable character
        {.desc = "ft_isprint('\\x7F')", .c = 127}  // Non-printable character (DEL)
    };
        int count = sizeof(tests) / sizeof(tests[0]);

        return (run_tests(tests, count));
}

int run_tests(t_test *tests, int count)
{
        int i;
        int error = 0;
		int ft_result;
		int expected;

        for (i = 0; i < count; i++)
        {
                ft_result = ft_isprint(tests[i].c);
				expected = isprint(tests[i].c);
				// Check that the output matches the expected value
                if (ft_result != expected)
                {
                        printf("    " RED "[%d] %s Expected \"%d\", got \"%d\"\n", i + 1, tests[i].desc, expected, ft_result);
                        error -= 1;
                }
                else
                        printf("  " GREEN CHECKMARK GREY " [%d] %s output \"%d\" as expected\n" DEFAULT, i + 1, tests[i].desc, ft_result);
        }
        return (error);
}