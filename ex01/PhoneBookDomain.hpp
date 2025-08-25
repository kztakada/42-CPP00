#ifndef PHONEBOOK_DOMAIN_HPP
#define PHONEBOOK_DOMAIN_HPP

//-----------------------------------------------------------------
// Contact Domain Definitions
const int CONTACT_FORM_SIZE = 5;

// Forward declaration and type alias
template <int N>
class Contact;
typedef Contact<CONTACT_FORM_SIZE> ContactType;

//-----------------------------------------------------------------
// Contact Field Validation Rules
enum ContactValidationType {
    VALIDATION_NONE = 0,
    VALIDATION_NAME = 1,
    VALIDATION_PHONE_NUMBER = 2
};

struct ContactFieldInfo {
    const char* name;
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
// PhoneBook Business Rules
const int MAX_CONTACTS = 8;

#endif /* PHONEBOOK_DOMAIN_HPP */
