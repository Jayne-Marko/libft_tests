#include "../libft.h"
#include "constants.h"


typedef struct s_test
{
    char *desc;
    char *str;
} t_test;

int run_tests(t_test *tests, int count);

int main(void)
{
    t_test tests[] = {
        {.desc = "ft_strlen(\"\")", .str = ""},
        {.desc = "ft_strlen(\"Hello\")", .str = "Hello"},
        {.desc = "ft_strlen(\"42\")", .str = "42"},
        {.desc = "ft_strlen(\" \")", .str = " "},
        {.desc = "ft_strlen(\"\\n\")", .str = "\n"},
        {.desc = "ft_strlen(\"Lorem ipsum dolor sit amet, consectetur adipiscing elit.\")", .str = "Lorem ipsum dolor sit amet, consectetur adipiscing elit."},
        {.desc = "ft_strlen(\"\\0hidden\")", .str = "\0hidden"},
        {.desc = "ft_strlen(\"\\t\\n\\v\\f\\r\")", .str = "\t\n\v\f\r"}
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
                ft_result = ft_strlen(tests[i].str);
				expected = strlen(tests[i].str);
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