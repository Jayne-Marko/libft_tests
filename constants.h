#ifndef CONSTANTS_H
#define CONSTANTS_H

# include <ctype.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <stdint.h>
# include <malloc.h>

# ifdef __unix__
#  include <malloc.h>
# endif
# ifdef __APPLE__
#  include <stdlib.h>
#  include <malloc/malloc.h>
# endif

#define GREEN "\033[38;5;84m"
#define RED "\033[38;5;197m"
#define BLUE "\033[38;5;45m"
#define PURPLE "\033[38;5;63m"
#define PINK "\033[38;5;207m"
#define BLACK "\033[38;5;0m"
#define BG_GREEN "\033[48;5;84m"
#define BG_RED "\033[48;5;197m"
#define BOLD "\033[1m"
#define CHECKMARK "\xE2\x9C\x93"
#define GREY "\033[38;5;8m"
#define DEFAULT "\033[0m"

#endif 