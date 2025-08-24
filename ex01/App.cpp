#include <cstdlib>
#include <iostream>

#include "Display.hpp"
#include "PhoneBook.hpp"
#include "Receptionist.hpp"

int main(int argc, char* argv[]) {
    PhoneBook phoneBook;
    Receptionist receptionist(&phoneBook);

    if (argc == 2 && std::string(argv[1]) == "--strict") {
        Receptionist receptionist(&phoneBook, true);
    }

    try {
        receptionist.serve();
    } catch (const std::ios_base::failure& e) {
        return (EXIT_SUCCESS);
    } catch (...) {
        Display::showRuntimeError();
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}