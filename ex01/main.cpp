#include <cstdlib>
#include <iostream>
#include <string>

#include "Display.hpp"
#include "PhoneBook.hpp"
#include "Receptionist.hpp"

int main(int argc, char* argv[]) {
    PhoneBookType phoneBook;

    bool isEchoMode = false;
    bool isStrictMode = false;
    for (int i = 1; i < argc; ++i) {
        std::string arg_i(argv[i]);
        if (arg_i == "--echo") {
            isEchoMode = true;
        } else if (arg_i == "--strict") {
            isStrictMode = true;
        }
    }

    Receptionist receptionist(&phoneBook, isEchoMode, isStrictMode);
    try {
        receptionist.serve();
    } catch (const std::ios_base::failure& e) {
        return (EXIT_SUCCESS);
    } catch (const std::string& e) {
        Display::error(e);
        return (EXIT_FAILURE);
    } catch (...) {
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}