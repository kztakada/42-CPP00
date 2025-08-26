#ifndef RECEPTIONIST_HPP
#define RECEPTIONIST_HPP

#include <climits>
#include <iomanip>
#include <iostream>
#include <sstream>

#include "Contact.hpp"
#include "Display.hpp"
#include "PhoneBook.hpp"

//-----------------------------------------------------------------
// Contact Field Info and Validation Rules

enum ContactValidationType {
    VALIDATION_NONE = 0,
    VALIDATION_NAME = 1,
    VALIDATION_PHONE_NUMBER = 2
};

struct ContactFieldInfo {
    const char *name;
    ContactValidationType validationType;
};

const ContactFieldInfo CONTACT_FIELD_INFO[CONTACT_FORM_SIZE] = {
    {"First Name", VALIDATION_NAME}, {"Last Name", VALIDATION_NAME},
    {"Nickname", VALIDATION_NAME}, {"Phone Number", VALIDATION_PHONE_NUMBER},
    {"Darkest Secret", VALIDATION_NONE}};

//-----------------------------------------------------------------
// Display Configuration

const int PREVIEW_SIZE = 3;
const int COL_WIDTH = 10;
const int TITLE_WIDTH = 16;

//-----------------------------------------------------------------
// Receptionist Class Definition

class Receptionist {
   public:
    Receptionist(PhoneBookType *phoneBook, bool isEchoMode, bool isStrictMode);

    void serve();

   private:
    PhoneBookType *_phoneBook;
    bool _isEchoMode;
    bool _isStrictMode;
    void _handleAddContact();
    void _handleSearchContact();
    void _handleNoCommand();
    std::string _makeContactList();
};

#endif /* RECEPTIONIST_HPP */