#include "../libft.h"
#include "constants.h"

// int	ft_strncmp(const char *s1, const char *s2, size_t n)
// {
// 	while (*s1 == *s2 && --n)
// 	{
// 		s1++;
// 		s2++;
// 		// n--;
// 	}
// 	return (*s1 - *s2);
// }

typedef struct s_test {
     char *desc;
    char *s1;
    char *s2;
    size_t n;
} t_test;

int run_tests(t_test *tests, int count);

int main(void)
{
    t_test tests[] = {
        {.desc = "Both strings are empty", .s1 = "", .s2 = "", .n = 0},
        {.desc = "Both strings are identical", .s1 = "hello", .s2 = "hello", .n = 5},
        {.desc = "First string is shorter than second", .s1 = "hello", .s2 = "hello world", .n = 5},
        {.desc = "First string is longer than second", .s1 = "hello world", .s2 = "hello", .n = 5},
        {.desc = "Strings are different, but equal up to n characters", .s1 = "hello", .s2 = "hallo", .n = 3},
        {.desc = "Strings are different, first string is greater", .s1 = "world", .s2 = "hello", .n = 5},
        {.desc = "Strings are different, second string is greater", .s1 = "hello", .s2 = "world", .n = 5},
        {.desc = "Strings are different, first string is greater in ASCII", .s1 = "world", .s2 = "Hello", .n = 5},
        {.desc = "Strings are different, second string is greater in ASCII", .s1 = "Hello", .s2 = "world", .n = 5},
        {.desc = "Strings are different, but equal up to n characters", .s1 = "hello", .s2 = "hallo", .n = 3},
        {.desc = "Comparison up to null-terminator in first string", .s1 = "hello", .s2 = "hello world", .n = 0},
        {.desc = "Comparison up to null-terminator in second string", .s1 = "hello world", .s2 = "hello", .n = 0},
        {.desc = "Comparison of non-null-terminated strings", .s1 = "hello", .s2 = "hello world", .n = 100}
    };

        int count = sizeof(tests) / sizeof(tests[0]);

        return (run_tests(tests, count));
}

int run_tests(t_test *tests, int count)
{
    int i;
    int error = 0;
    int ft_result;
	int expected_return;

    for (i = 0; i < count; i++) {
        // Apply functions and store the result
        ft_result = ft_strncmp(tests[i].s1, tests[i].s2, tests[i].n);
		expected_return = strncmp(tests[i].s1, tests[i].s2, tests[i].n);

        // Check that the return value matches the expected value
        if (ft_result != expected_return) {
            printf("    " RED "[%d] %s for s1: \"%s\" and s2: \"%s\". Expected return \"%d\", got \"%d\"\n", i + 1, tests[i].desc, tests[i].s1, tests[i].s2, expected_return, ft_result);
            error++;
        } else {
            printf("  " GREEN CHECKMARK GREY " [%d] %s for s1: \"%s\" and s2: \"%s\" return \"%d\" as expected\n" DEFAULT, i + 1, tests[i].desc, tests[i].s1, tests[i].s2, ft_result);
        }
    }
        return (error);
}