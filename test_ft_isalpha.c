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
        {.desc = "ft_isalpha('A')", .c = 'A'},
        {.desc = "ft_isalpha('z')", .c = 'z'},
        {.desc = "ft_isalpha('G')", .c = 'G'},
        {.desc = "ft_isalpha('m')", .c = 'm'},
        {.desc = "ft_isalpha('0')", .c = '0'},
        {.desc = "ft_isalpha('@')", .c = '@'},
        {.desc = "ft_isalpha('[')", .c = '['},
        {.desc = "ft_isalpha('`')", .c = '`'},
        {.desc = "ft_isalpha('{')", .c = '{'},
        {.desc = "ft_isalpha(' ')", .c = ' '},
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
                ft_result = ft_isalpha(tests[i].c);
				expected = isalpha(tests[i].c);
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