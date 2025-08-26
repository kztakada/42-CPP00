#include "Display.hpp"

// Static member definitions
const char* const Display::EXPLANATION_HEADER =
    "Welcome to the PhoneBook application.";
const char* const Display::COMMAND_MESSAGE =
    "Enter the command ADD, SEARCH, or EXIT.\n";
const char* const Display::CURSOR = "> ";
const char* const Display::LIST_SELECT_MESSAGE =
    "Enter the index of the contact to view details:\n";
const char* const Display::INVALID_INDEX_MESSAGE =
    "Invalid index entered. Sorry.\n";
const char* const Display::NO_CONTACTS_MESSAGE = "No contacts available.\n";
const char* const Display::RUNTIME_ERROR_MESSAGE =
    "An error occurred while running the PhoneBook application.\n";

void Display::show(const std::string& message) {
    std::cout << message << std::endl;
}

void Display::show(const char* message) {
    if (message != NULL) {
        std::cout << message << std::endl;
    }
}

void Display::prompt(const std::string& message) {
    std::cout << message << std::flush;
}

void Display::error(const std::string& message) {
    std::cerr << message << std::endl;
}

std::string Display::getCommandCursor() {
    return std::string(COMMAND_MESSAGE) + CURSOR;
}

std::string Display::getListSelectCursor() {
    return std::string(LIST_SELECT_MESSAGE) + CURSOR;
}
