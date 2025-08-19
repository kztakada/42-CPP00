/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 18:24:16 by katakada          #+#    #+#             */
/*   Updated: 2025/08/19 16:45:22 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
