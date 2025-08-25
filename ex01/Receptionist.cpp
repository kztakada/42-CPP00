#include "Receptionist.hpp"

// class use file static funcs prototypes
static void listenToUserInput(std::string &input);
static bool isValidContactField(const std::string &field);
static bool isPhoneNumberValid(const std::string &field);
static bool hasNoSpaces(const std::string &field);
static bool isStrictValidContactField(
    const std::string &field, ContactValidationType type);
static std::string fitColWidth(const std::string &str);
static std::string getTitleLine(int fieldViewCount);
static std::string makeContactPreview(
    const Contact<CONTACT_FORM_SIZE> *contact, int fieldViewCount);
static std::string makeContactDetails(
    const Contact<CONTACT_FORM_SIZE> *contact);

//-----------------------------------------------------------------
// class public methods

Receptionist::Receptionist(PhoneBook *phoneBook)
    : _phoneBook(phoneBook), _isEchoMode(false), _isStrictMode(false) {}
Receptionist::Receptionist(
    PhoneBook *phoneBook, bool isEchoMode, bool isStrictMode)
    : _phoneBook(phoneBook),
      _isEchoMode(isEchoMode),
      _isStrictMode(isStrictMode) {}

void Receptionist::serve() {
    Display::show(ExplanationHeader);
    while (true) {
        std::string command;
        Display::prompt(CommandCursor);
        listenToUserInput(command);
        if (_isEchoMode)
            Display::show(command);
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

//-----------------------------------------------------------------
// class private methods

void Receptionist::_handleAddContact() {
    std::string answer = "";
    Contact<CONTACT_FORM_SIZE> contact;

    for (int i = 0; i < CONTACT_FORM_SIZE; ++i) {
        bool couldSetField = false;
        while (!couldSetField) {
            std::string prompt = CONTACT_FORM[i];
            prompt += ": ";
            Display::prompt(prompt);
            listenToUserInput(answer);
            if (_isEchoMode)
                Display::show(answer);

            bool isValid = false;
            if (_isStrictMode)
                isValid = isStrictValidContactField(answer,
                    static_cast<ContactValidationType>(CONTACT_FORM_RULES[i]));
            else
                isValid = isValidContactField(answer);

            if (isValid)
                couldSetField = contact.setField(i, answer);
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
    listenToUserInput(select_index);
    if (_isEchoMode)
        Display::show(select_index);

    std::stringstream ss(select_index);
    int index;
    if (!(ss >> index)) {
        Display::show(InvalidIndexMessage);
        return;
    }

    const Contact<CONTACT_FORM_SIZE> *contact = _phoneBook->getContact(index);
    if (contact != NULL) {
        std::string contactDetails = makeContactDetails(contact);
        Display::show(contactDetails);
    } else {
        Display::show(InvalidIndexMessage);
    }
}

void Receptionist::_handleNoCommand() { Display::show(NoCommandMessage); }

std::string Receptionist::_makeContactList() {
    std::stringstream ssList;
    ssList << getTitleLine(PREVIEW_SIZE);
    for (int i = 0; i < MAX_CONTACTS; ++i) {
        if (_phoneBook->getContact(i) == NULL)
            break;
        const Contact<CONTACT_FORM_SIZE> *contact = _phoneBook->getContact(i);
        ssList << std::setw(COL_WIDTH) << i
               << makeContactPreview(contact, PREVIEW_SIZE) << "\n";
    }
    return ssList.str();
}

//-----------------------------------------------------------------
// class use file static funcs implementations

static void listenToUserInput(std::string &input) {
    if (std::getline(std::cin, input) == false) {
        if (std::cin.eof()) {
            throw std::ios_base::failure("EOF detected");
        } else {
            throw std::string("Failed to read input");
        }
    }
}

static bool isValidContactField(const std::string &field) {
    if (field.size() > INT_MAX) {
        Display::show("Input is too long");
        return false;
    }
    if (field.empty()) {
        Display::show("Please enter something");
        return false;
    }
    return true;
}

static bool isPhoneNumberValid(const std::string &field) {
    std::string checked = field;
    if (field[0] == '+')
        checked = field.substr(1);
    for (int i = 0; i < (int)checked.length(); ++i) {
        if (!isdigit(checked[i]) && checked[i] != '-') {
            Display::show("Phone number can contain only digits, and hyphens");
            return false;
        }
    }
    return true;
}

static bool hasNoSpaces(const std::string &field) {
    if (field.find(' ') != std::string::npos) {
        Display::show("Field must not contain spaces");
        return false;
    }
    return true;
}

static bool isStrictValidContactField(
    const std::string &field, ContactValidationType type) {
    if (!isValidContactField(field))
        return false;
    switch (type) {
        case NAME:
            return hasNoSpaces(field);
        case PHONE_NUMBER:
            return isPhoneNumberValid(field);
        case NONE:
            return true;
    }
    return false;
}

static std::string fitColWidth(const std::string &str) {
    if ((int)str.length() > COL_WIDTH) {
        return str.substr(0, COL_WIDTH - 1) + ".";
    }
    return str;
}

static std::string getTitleLine(int fieldViewCount) {
    std::stringstream ssTitle;
    ssTitle << std::setw(COL_WIDTH) << "Index";
    for (int i = 0; i < fieldViewCount; ++i) {
        std::string title = CONTACT_FORM[i];
        ssTitle << "|" << std::setw(COL_WIDTH) << fitColWidth(title);
    }
    ssTitle << "\n";
    return ssTitle.str();
}

static std::string makeContactPreview(
    const Contact<CONTACT_FORM_SIZE> *contact, int fieldViewCount) {
    std::stringstream ssContact;
    for (int i = 0; i < fieldViewCount; ++i) {
        const std::string *field = contact->getField(i);

        if (field != NULL) {
            ssContact << "|" << std::setw(COL_WIDTH) << fitColWidth(*field);
        }
    }
    return ssContact.str();
}

static std::string makeContactDetails(
    const Contact<CONTACT_FORM_SIZE> *contact) {
    std::stringstream ss;
    for (int i = 0; i < CONTACT_FORM_SIZE; ++i) {
        const std::string *field = contact->getField(i);
        if (field != NULL) {
            std::string title = CONTACT_FORM[i];
            title += ": ";
            ss << std::setw(TITLE_WIDTH) << title << *field << "\n";
        }
    }
    return ss.str();
}
