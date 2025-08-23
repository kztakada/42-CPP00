#include "Receptionist.hpp"

Receptionist::Receptionist(PhoneBook &phoneBook) : _phoneBook(phoneBook) {}

// Receptionist::~Receptionist() {}

// Receptionist::Receptionist(Receptionist const &other)
//     : _phoneBook(other._phoneBook) {}

// Receptionist &Receptionist::operator=(Receptionist const &other) {
//     if (this != &other) {
//         _phoneBook = other._phoneBook;
//     }
//     return *this;
// }

void Receptionist::serve() {
    Display::showExplanationHeader();
    while (true) {
        std::string command;
        Display::showCursor();
        listenToUserInput(command);

        if (command.empty())
            continue;

        if (command == "ADD")
            handleAddContact();
        else if (command == "SEARCH")
            handleSearchContact();
        else if (command == "EXIT")
            return;
        else
            handleNoCommand();
    }
}

void Receptionist::listenToUserInput(std::string &input) {
    if (std::getline(std::cin, input) == false)
        throw;
    if (std::cin.fail() || std::cin.eof())
        throw;
}

void Receptionist::handleAddContact() {
    std::string answer = "";
    std::string c[5];

    for (int i = 0; i < 5; ++i) {
        while (answer.empty()) {
            Display::echo(CONTACT_PROMPTS[i]);
            listenToUserInput(answer);
        }
        c[i] = answer;
        answer.clear();
    }

    _phoneBook.addContact(Contact(c[0], c[1], c[2], c[3], c[4]));
}

void Receptionist::handleSearchContact() {
    Display::showContactList(_phoneBook);
}

void Receptionist::handleNoCommand() { Display::showNoCommandMessage(); }
