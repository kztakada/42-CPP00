#include "Display.hpp"

Display::Display() {}

void Display::echo(const std::string& message) { std::cout << message; }

void Display::showExplanationHeader() {
    std::cout << "Welcome to the PhoneBook application.\n";
}

void Display::showCursor() {
    std::cout << "Enter the command ADD, SEARCH, or EXIT.\n";
    std::cout << "> " << std::flush;
}

void Display::showContactList(const PhoneBook& phoneBook) {
    for (int i = 0; i < MAX_CONTACTS; ++i) {
        if (phoneBook.getContact(i) == NULL)
            break;
        std::cout << i << ": ";
        const Contact* contact = phoneBook.getContact(i);
        for (int j = 0; j < 3; ++j) {
            const std::string* field =
                contact->getField(static_cast<ContactField>(j));
            if (field != NULL) {
                std::cout << *field << " ";
            }
        }
        std::cout << "\n";
    }
    std::cout << std::endl;
}

void Display::showContact(const Contact& contact) {
    for (int i = 0; i < MAX_CONTACTS; ++i) {
        const std::string* field =
            contact.getField(static_cast<ContactField>(i));
        if (field != NULL) {
            std::cout << CONTACT_PROMPTS[i] << *field << "\n";
        }
    }
    std::cout << std::endl;
}

void Display::showListSelectMessage() {
    std::cout << "Enter the index of the contact to view details:\n> ";
}

void Display::showNoCommandMessage() {
    std::cout << "No command entered. Please try again.\n\n";
}

void Display::showInvalidIndexMessage() {
    std::cout << "Sorry, Invalid index.\n\n";
}

void Display::showRuntimeError() {
    std::cerr << "An error occurred while running the PhoneBook application.\n";
}