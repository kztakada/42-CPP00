#include <cctype>
#include <iostream>

#define STR_WHEN_ARGS_EMPTY "* LOUD AND UNBEARABLE FEEDBACK NOISE *"

void print_toupper_str(const char *str) {
    while (*str != '\0') {
        std::cout << static_cast<char>(std::toupper(*str));
        ++str;
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cout << STR_WHEN_ARGS_EMPTY << std::endl;
        return (0);
    }

    for (int i = 1; i < argc; ++i) {
        print_toupper_str(argv[i]);
    }
    std::cout << std::endl;

    return (0);
}
