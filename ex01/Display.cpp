#include "Display.hpp"

Display::Display() {}

void Display::echo(const std::string& message) { std::cout << message; }

void Display::showExplanationHeader() {
    std::cout << "Welcome to the PhoneBook application.\n";
}

void Display::showCursor() {
    std::cout << "Enter the command ADD, SEARCH, or EXIT.\n";
    std::cout << "> ";
}

void Display::showContactList(const PhoneBook& phoneBook) {
    for (int i = 0; i < MAX_CONTACTS; ++i) {
        if (phoneBook.getContact(i) == NULL)
            break;

        const Contact* contact = phoneBook.getContact(i);
        std::cout << i << ": " << contact->firstName() << " "
                  << contact->lastName() << " " << contact->nickname() << "\n";
    }
    std::cout << std::endl;
}

void Display::showContact(const Contact& contact) {
    std::cout << "First Name: " << contact.firstName() << "\n";
    std::cout << "Last Name: " << contact.lastName() << "\n";
    std::cout << "Nickname: " << contact.nickname() << "\n";
    std::cout << "Phone Number: " << contact.phoneNumber() << "\n";
    std::cout << "Darkest Secret: " << contact.darkestSecret() << "\n";
}

void Display::showNoCommandMessage() {
    std::cout << "No command entered. Please try again.\n\n";
}
