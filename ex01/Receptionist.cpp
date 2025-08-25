#include "Receptionist.hpp"

// class use file static funcs prototypes
static void listenToUserInput(std::string &input);
static const char *validateContactField(
    const std::string &field, bool isStrictMode, ContactValidationType type);
static const char *validateBasicField(const std::string &field);
static const char *validatePhoneNumber(const std::string &field);
static const char *validateNameField(const std::string &field);
static std::string fitColWidth(const std::string &str);
static std::string getTitleLine(int fieldViewCount);
static std::string makeContactPreview(
    const ContactType *contact, int fieldViewCount);
static std::string makeContactDetails(const ContactType *contact);

//-----------------------------------------------------------------
// class public methods

Receptionist::Receptionist(
    PhoneBook *phoneBook, bool isEchoMode = false, bool isStrictMode = false)
    : _phoneBook(phoneBook),
      _isEchoMode(isEchoMode),
      _isStrictMode(isStrictMode) {}

void Receptionist::serve() {
    Display::show(Display::EXPLANATION_HEADER);
    while (true) {
        std::string command;
        Display::prompt(Display::getCommandCursor());
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
    ContactType contact;

    for (int i = 0; i < CONTACT_FORM_SIZE; ++i) {
        bool couldSetField = false;
        while (!couldSetField) {
            std::string prompt = CONTACT_FIELD_INFO[i].name;
            prompt += ": ";
            Display::prompt(prompt);
            listenToUserInput(answer);
            if (_isEchoMode)
                Display::show(answer);

            const char *errorMessage = validateContactField(
                answer, _isStrictMode, CONTACT_FIELD_INFO[i].validationType);

            if (errorMessage == NULL) {
                couldSetField = contact.setField(i, answer);
            } else {
                Display::show(errorMessage);
            }
            answer.clear();
        }
    }

    _phoneBook->addContact(contact);
}

void Receptionist::_handleSearchContact() {
    if (_phoneBook->getContact(0) == NULL) {
        Display::show(Display::NO_CONTACTS_MESSAGE);
        return;
    }
    std::string contactList = _makeContactList();
    Display::show(contactList);

    Display::prompt(Display::getListSelectCursor());
    std::string select_index = "";
    listenToUserInput(select_index);
    if (_isEchoMode)
        Display::show(select_index);

    std::stringstream ss(select_index);
    int index;
    if (!(ss >> index)) {
        Display::show(Display::INVALID_INDEX_MESSAGE);
        return;
    }

    const ContactType *contact = _phoneBook->getContact(index);
    if (contact != NULL) {
        std::string contactDetails = makeContactDetails(contact);
        Display::show(contactDetails);
    } else {
        Display::show(Display::INVALID_INDEX_MESSAGE);
    }
}

void Receptionist::_handleNoCommand() {
    Display::show(Display::NO_COMMAND_MESSAGE);
}

std::string Receptionist::_makeContactList() {
    std::stringstream ssList;
    ssList << getTitleLine(PREVIEW_SIZE);
    for (int i = 0; i < MAX_CONTACTS; ++i) {
        if (_phoneBook->getContact(i) == NULL)
            break;
        const ContactType *contact = _phoneBook->getContact(i);
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

static const char *validateBasicField(const std::string &field) {
    if (field.size() > static_cast<size_t>(INT_MAX)) {
        return "Input is too long";
    }
    if (field.empty()) {
        return "Please enter something";
    }
    return NULL;
}

static const char *validateNameField(const std::string &field) {
    if (field.find(' ') != std::string::npos) {
        return "Field must not contain spaces";
    }
    return NULL;
}

static const char *validatePhoneNumber(const std::string &field) {
    std::string checked = field;
    if (!field.empty() && field[0] == '+') {
        checked = field.substr(1);
    }
    for (size_t i = 0; i < checked.length(); ++i) {
        if (!isdigit(checked[i]) && checked[i] != '-') {
            return "Phone number can contain only digits, and hyphens";
        }
    }
    return NULL;
}

static const char *validateContactField(
    const std::string &field, bool isStrictMode, ContactValidationType type) {
    const char *basicError = validateBasicField(field);
    if (basicError != NULL) {
        return basicError;
    }

    if (!isStrictMode) {
        return NULL;
    }

    switch (type) {
        case VALIDATION_NAME:
            return validateNameField(field);
        case VALIDATION_PHONE_NUMBER:
            return validatePhoneNumber(field);
        case VALIDATION_NONE:
            return NULL;
        default:
            return NULL;
    }
}

static std::string fitColWidth(const std::string &str) {
    if (static_cast<int>(str.length()) > COL_WIDTH) {
        return str.substr(0, static_cast<size_t>(COL_WIDTH - 1)) + ".";
    }
    return str;
}

static std::string getTitleLine(int fieldViewCount) {
    std::stringstream ssTitle;
    ssTitle << std::setw(COL_WIDTH) << "Index";
    for (int i = 0; i < fieldViewCount && i < CONTACT_FORM_SIZE; ++i) {
        std::string title = CONTACT_FIELD_INFO[i].name;
        ssTitle << "|" << std::setw(COL_WIDTH) << fitColWidth(title);
    }
    ssTitle << "\n";
    return ssTitle.str();
}

static std::string makeContactPreview(
    const ContactType *contact, int fieldViewCount) {
    std::stringstream ssContact;
    for (int i = 0; i < fieldViewCount; ++i) {
        const std::string *field = contact->getField(i);

        if (field != NULL) {
            ssContact << "|" << std::setw(COL_WIDTH) << fitColWidth(*field);
        }
    }
    return ssContact.str();
}

static std::string makeContactDetails(const ContactType *contact) {
    std::stringstream ss;
    for (int i = 0; i < CONTACT_FORM_SIZE; ++i) {
        const std::string *field = contact->getField(i);
        if (field != NULL) {
            std::string title = CONTACT_FIELD_INFO[i].name;
            title += ": ";
            ss << std::setw(TITLE_WIDTH) << title << *field << "\n";
        }
    }
    return ss.str();
}
