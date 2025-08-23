#include "PhoneBook.hpp"
#include "Receptionist.hpp"

const int SUCCESS_EXIT = 0;
const int FAILURE_EXIT = 1;

int main(int argc, char **argv) {
    PhoneBook phoneBook;
    Receptionist receptionist(phoneBook);

    (void)argc;
    (void)argv;
    try {
        receptionist.serve();
    } catch (...) {
        std::cerr
            << "An error occurred while running the PhoneBook application.\n";
        return (FAILURE_EXIT);
    }
    return (SUCCESS_EXIT);
}