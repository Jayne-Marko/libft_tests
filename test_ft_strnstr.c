#include "../libft.h"
#include "constants.h"

typedef struct s_test
{
    char *desc;
    char *haystack;
    char *needle;
    size_t len;
    char *expected;
} t_test;

int run_tests(t_test *tests, int count);

int main()
{
	t_test tests[] = {
		{.desc = "Substring in the middle", .haystack = "Hello, World!", .needle = "World", .len = 13, .expected = "World!"},
		{.desc = "Substring at the start", .haystack = "Hello, World!", .needle = "Hello", .len = 5, .expected = "Hello"},
		{.desc = "Substring not present", .haystack = "Hello, World!", .needle = "42", .len = 13, .expected = NULL},
		{.desc = "Empty needle", .haystack = "Hello, World!", .needle = "", .len = 13, .expected = "Hello, World!"},
		{.desc = "Empty haystack", .haystack = "", .needle = "Hello", .len = 5, .expected = NULL},
		{.desc = "Substring beyond length", .haystack = "Hello, World!", .needle = "World", .len = 5, .expected = NULL},
		{.desc = "Needle longer than haystack", .haystack = "Hello", .needle = "Hello, World!", .len = 13, .expected = NULL},
		{.desc = "Length zero", .haystack = "Hello, World!", .needle = "World", .len = 0, .expected = NULL},
		{.desc = "Needle at end of haystack", .haystack = "Hello, World!", .needle = "World!", .len = 13, .expected = "World!"},
		{.desc = "Haystack shorter than length", .haystack = "Hello", .needle = "lo", .len = 10, .expected = "lo"},
	};
	int count = sizeof(tests) / sizeof(tests[0]);
    return (run_tests(tests, count));
}

int run_tests(t_test *tests, int count)
{
    int i;
    int errors = 0;
    char *ft_result;
	char *expected;

    for (i = 0; i < count; i++)
    {
        ft_result = ft_strnstr(tests[i].haystack, tests[i].needle, tests[i].len);
		expected = strnstr(tests[i].haystack, tests[i].needle, tests[i].len);
        
        if (ft_result != expected)
        {
            if (ft_result == NULL || expected == NULL)
            {
                if (ft_result != expected)
                {
                    printf("    " RED "[ %d ] %s - Expected \"%s\", got \"%s\"\n", i + 1, tests[i].desc, expected, ft_result);
                    errors++;
                }
            }
            else if (strcmp(ft_result, expected) != 0)
            {
                printf("    " RED "[ %d ] %s - Expected \"%s\", got \"%s\"\n", i + 1, tests[i].desc, expected, ft_result);
                errors++;
            }
        }
        else
        {
            printf("  " GREEN CHECKMARK GREY " [ %d ] %s - output \"%s\" as expected\n", i + 1, tests[i].desc, ft_result);
        }
    }
    return errors;
}
