#include "../libft.h"
#include "constants.h"

typedef struct s_test
{
    char *desc;
    const char *input;
} t_test;

int run_tests(t_test *tests, int count);

int main(void)
{
    t_test tests[] = {
		{.desc = "Positive number", .input = "123"
		},
		{.desc = "Negative number", .input = "-123"
		},
		{.desc = "Number with leading spaces", .input = "   123"
		},
		{.desc = "Number with leading + sign", .input = "+123"
		},
		{.desc = "Zero", .input = "0"
		},
		{.desc = "Number with trailing spaces", .input = "123   "
		},
		{.desc = "Mixed with non-numeric characters", .input = "123abc"
		},
		{.desc = "Only non-numeric characters", .input = "abc"
		},
		{.desc = "Empty string", .input = ""
		},
		{.desc = "Number outside positive range", .input = "9223372036854775807"
		},
		{.desc = "Number outside negative range", .input = "-9223372036854775808"
		},
		{.desc = "INT_MAX", .input = "2147483647"
		},
		{.desc = "INT_MIN", .input = "-2147483648"
		},
		{.desc = "Overflow above INT_MAX", .input = "2147483648"
		},
		{.desc = "Underflow below INT_MIN", .input = "-2147483649"
		}
	};
	
	int count = sizeof(tests) / sizeof(tests[0]);
    return (run_tests(tests, count));
}

int run_tests(t_test *tests, int count)
{
    int i;
    int errors = 0;
    int ft_result;
    int expected;

    for (i = 0; i < count; i++)
    {
        ft_result = ft_atoi(tests[i].input);
        expected = atoi(tests[i].input);
        
        if (ft_result != expected)
        {
            printf("    " RED "[ %d ] %s - Expected \"%d\", got \"%d\"\n", i + 1, tests[i].desc, expected, ft_result);
            errors++;
        }
        else
        {
            printf("  " GREEN CHECKMARK GREY " [ %d ] %s - output \"%d\" as expected\n", i + 1, tests[i].desc, ft_result);
        }
    }
    return errors;
}