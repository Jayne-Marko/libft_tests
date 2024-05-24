#include "../libft.h"
#include "constants.h"
#include <stdio.h>
#include <string.h> 

typedef struct s_test {
    char *desc;
    char *str;
    int c;
} t_test;

int run_tests(t_test *tests, int count);

int main(void) {
    t_test tests[] = {
        {.desc = "ft_strchr('hello', 'l')", .str = "hello", .c = 'l'},
        {.desc = "ft_strchr('world', 'o')", .str = "world", .c = 'o'},
        {.desc = "ft_strchr('test', 't')", .str = "test", .c = 't'},
        {.desc = "ft_strchr('123456789', '5')", .str = "123456789", .c = '5'},
        {.desc = "ft_strchr('abcdef', 'g')", .str = "abcdef", .c = 'g'},
        {.desc = "ft_strchr('!@#$%^', '$')", .str = "!@#$%^", .c = '$'},
        {.desc = "ft_strchr('repeat', 'e')", .str = "repeat", .c = 'e'},
        {.desc = "ft_strchr('no match', 'z')", .str = "no match", .c = 'z'},
        {.desc = "ft_strchr('end with null', '\\0')", .str = "end with null", .c = '\0'},
        {.desc = "ft_strchr('', 'a')", .str = "", .c = 'a'},
    };

    int count = sizeof(tests) / sizeof(tests[0]);

    return (run_tests(tests, count));
}

int run_tests(t_test *tests, int count) {
    int i;
    int error = 0;
    char *ft_result;
    char *expected;

    for (i = 0; i < count; i++) {
        ft_result = ft_strrchr(tests[i].str, tests[i].c);
        expected = strrchr(tests[i].str, tests[i].c);

        // Check that the output matches the expected value
        if (ft_result != expected) {
            printf("    " RED "[%d] %s Expected \"%s\", got \"%s\"\n", i + 1, tests[i].desc, expected, ft_result);
            error -= 1;
        } else {
            printf("  " GREEN CHECKMARK GREY " [%d] %s output \"%s\" as expected\n" DEFAULT, i + 1, tests[i].desc, ft_result);
        }
    }
    return (error);
}
