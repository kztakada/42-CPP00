#include "Receptionist.hpp"

Receptionist::Receptionist(PhoneBook *phoneBook)
    : _phoneBook(phoneBook), _isStrictMode(false) {}
Receptionist::Receptionist(PhoneBook *phoneBook, bool isStrictMode)
    : _phoneBook(phoneBook), _isStrictMode(isStrictMode) {}

void Receptionist::serve() {
    Display::show(ExplanationHeader);
    while (true) {
        std::string command;
        Display::prompt(CommandCursor);
        _listenToUserInput(command);

        if (command.empty())
            continue;

        if (command == "ADD")
            _handleAddContact();
        else if (command == "SEARCH")
            _handleSearchContact();
        else if (command == "EXIT")
            return;
        else
            _handleNoCommand();
    }
}

void Receptionist::_listenToUserInput(std::string &input) {
    if (std::getline(std::cin, input) == false) {
        if (std::cin.eof()) {
            throw std::ios_base::failure("EOF detected");
        } else {
            throw std::string("Failed to read input");
        }
    }
}

void Receptionist::_handleAddContact() {
    std::string answer = "";
    Contact contact;

    if (_isStrictMode)  // TODO: FIX it
        return;

    for (int i = 0; i < FIELD_COUNT; ++i) {
        bool couldSetField = false;
        while (!couldSetField) {
            while (answer.empty()) {
                Display::prompt(CONTACT_PROMPTS[i]);
                _listenToUserInput(answer);
            }
            couldSetField =
                contact.setField(static_cast<ContactField>(i), answer);
            answer.clear();
        }
    }

    _phoneBook->addContact(contact);
}

void Receptionist::_handleSearchContact() {
    if (_phoneBook->getContact(0) == NULL) {
        Display::show(NoContactsMessage);
        return;
    }
    std::string contactList = _makeContactList();
    Display::show(contactList);

    Display::prompt(ListSelectCursor);
    std::string select_index = "";
    _listenToUserInput(select_index);

    std::stringstream ss(select_index);
    int index;
    if (!(ss >> index)) {
        Display::show(InvalidIndexMessage);
        return;
    }

    const Contact *contact = _phoneBook->getContact(index);
    if (contact != NULL) {
        std::string contactDetails = _makeContactDetails(contact);
        Display::show(contactDetails);
    } else {
        Display::show(InvalidIndexMessage);
    }
}

void Receptionist::_handleNoCommand() { Display::show(NoCommandMessage); }

static std::string makeContactPreview(
    const Contact *contact, int fieldViewCount) {
    std::stringstream ssContact;
    for (int i = 0; i < fieldViewCount; ++i) {
        const std::string *field =
            contact->getField(static_cast<ContactField>(i));
        if (field != NULL) {
            ssContact << "|" << std::setw(COL_WIDTH) << *field;
        }
    }
    return ssContact.str();
}

std::string Receptionist::_makeContactList() {
    std::stringstream ssList;
    for (int i = 0; i < MAX_CONTACTS; ++i) {
        if (_phoneBook->getContact(i) == NULL)
            break;
        const Contact *contact = _phoneBook->getContact(i);
        ssList << std::setw(COL_WIDTH) << i << makeContactPreview(contact, 3)
               << "\n";
    }
    return ssList.str();
}

std::string Receptionist::_makeContactDetails(const Contact *contact) {
    std::stringstream ss;
    for (int i = 0; i < FIELD_COUNT; ++i) {
        const std::string *field =
            contact->getField(static_cast<ContactField>(i));
        if (field != NULL) {
            ss << CONTACT_PROMPTS[i] << *field << "\n";
        }
    }
    return ss.str();
}
