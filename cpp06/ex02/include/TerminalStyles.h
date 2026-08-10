#ifndef TERMINALSTYLES_H
# define TERMINALSTYLES_H
# include <string>
# include <iostream>
# include <exception>
# include <iomanip>
# include <cstdlib>
# include <cerrno>
# include <limits>
# include <cmath>

// Styles
# ifndef BOLD_TYPE
#  define BOLD_TYPE "\033[1m"
# endif
# ifndef DIMMED
#  define DIMMED "\033[2m"
# endif
# ifndef CURSIVE
#  define CURSIVE "\033[3m"
# endif

// Colors
# ifndef RED
#  define RED "\033[31m"
# endif
# ifndef GREEN
#  define GREEN "\033[32m"
# endif
# ifndef YELLOW
#  define YELLOW "\033[33m"
# endif
# ifndef WHITE
#  define WHITE "\033[37m"
# endif
# ifndef VLT
#  define VLT "\033[95m"
# endif
# ifndef MAGENT
#  define MAGENT "\033[96m"
# endif
# ifndef BLUE
#  define BLUE "\033[34m"
# endif
# ifndef YELLOW_EPA
#  define YELLOW_EPA "\033[38;2;255;255;0m"
# endif
# ifndef BROWN
#  define BROWN "\033[38;2;139;69;19m"
# endif
# ifndef BABY_BLUE
#  define BABY_BLUE "\033[38;2;135;206;235m"
# endif
# ifndef ORANGE
#  define ORANGE "\033[38;2;255;165;0m"
# endif
# ifndef MALVA
#  define MALVA "\033[38;2;224;176;255m"
# endif
# ifndef BABY_GREEN
#  define BABY_GREEN "\033[38;2;144;238;144m"
# endif
# ifndef RST
#  define RST "\033[0m"
# endif

#endif
