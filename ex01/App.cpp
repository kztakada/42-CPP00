#include <cstdlib>
#include <iostream>
#include <string>

#include "Display.hpp"
#include "PhoneBook.hpp"
#include "Receptionist.hpp"

int main(int argc, char* argv[]) {
    PhoneBook phoneBook;
    Receptionist receptionist(&phoneBook);
    std::cout << argc << std::endl;
    if (argc > 1) {
        bool isEchoMode = false;
        bool hasStrictFlag = false;
        for (int i = 1; i < argc; ++i) {
            std::string arg_i(argv[i]);
            if (arg_i == "--echo") {
                isEchoMode = true;
            }
            if (arg_i == "--strict") {
                hasStrictFlag = true;
            }
        }
        receptionist = Receptionist(&phoneBook, isEchoMode, hasStrictFlag);
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