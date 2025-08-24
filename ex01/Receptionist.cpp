#include "Receptionist.hpp"

Receptionist::Receptionist(PhoneBook *phoneBook)
    : _phoneBook(phoneBook), _isStrictMode(false) {}
Receptionist::Receptionist(PhoneBook *phoneBook, bool isStrictMode)
    : _phoneBook(phoneBook), _isStrictMode(isStrictMode) {}

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
    if (std::getline(std::cin, input) == false) {
        if (std::cin.eof()) {
            throw std::ios_base::failure("EOF detected");
        } else {
            throw std::runtime_error("Failed to read input");
        }
    }
}

void Receptionist::handleAddContact() {
    std::string answer = "";
    Contact contact;

    if (_isStrictMode)  // TODO: FIX it
        return;

    for (int i = 0; i < 5; ++i) {
        bool couldSetField = false;
        while (!couldSetField) {
            while (answer.empty()) {
                Display::echo(CONTACT_PROMPTS[i]);
                listenToUserInput(answer);
            }
            couldSetField =
                contact.setField(static_cast<ContactField>(i), answer);
            answer.clear();
        }
    }

    _phoneBook->addContact(contact);
}

void Receptionist::handleSearchContact() {
    std::string select_index = "";
    Display::showContactList(*_phoneBook);
    Display::showListSelectMessage();
    listenToUserInput(select_index);

    std::stringstream ss(select_index);
    int index;
    if (!(ss >> index)) {
        Display::showInvalidIndexMessage();
        return;
    }

    const Contact *contact = _phoneBook->getContact(index);
    if (contact != NULL) {
        Display::showContact(*contact);
    } else {
        Display::showInvalidIndexMessage();
    }
}

void Receptionist::handleNoCommand() { Display::showNoCommandMessage(); }
