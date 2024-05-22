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
        {.desc = "ft_isdigit('0')", .c = '0'},
        {.desc = "ft_isdigit('1')", .c = '1'},
        {.desc = "ft_isdigit('5')", .c = '5'},
        {.desc = "ft_isdigit('9')", .c = '9'},
        {.desc = "ft_isdigit('a')", .c = 'a'},
        {.desc = "ft_isdigit('Z')", .c = 'Z'},
        {.desc = "ft_isdigit(' ') ", .c = ' '},
        {.desc = "ft_isdigit('@')", .c = '@'},
        {.desc = "ft_isdigit('/')", .c = '/'},
        {.desc = "ft_isdigit(':')", .c = ':'}
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
                ft_result = ft_isdigit(tests[i].c);
				expected = isdigit(tests[i].c);
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