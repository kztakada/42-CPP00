#include <cstdlib>
#include <iostream>
#include <string>

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
        exit(EXIT_SUCCESS);
    } catch (const std::string& e) {
        Display::error(e);
        exit(EXIT_FAILURE);
    } catch (...) {
        exit(EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}