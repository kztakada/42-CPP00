#ifndef SETTINGS_HPP
#define SETTINGS_HPP

// for Contact settings
const int CONTACT_FORM_SIZE = 5;

//-----------------------------------------------------------------
// for Receptionist settings
const char *const CONTACT_FORM[] = {
    "First Name", "Last Name", "Nickname", "Phone Number", "Darkest Secret"};
enum ContactValidationType { NAME, PHONE_NUMBER, NONE };
const int CONTACT_FORM_RULES[] = {
    /* First Name */ NAME,
    /* Last Name */ NAME,
    /* Nickname */ NAME,
    /* Phone Number */ PHONE_NUMBER,
    /* Darkest Secret */ NONE};

const int PREVIEW_SIZE = 3;
const int COL_WIDTH = 10;
const int TITLE_WIDTH = 16;

//-----------------------------------------------------------------
// for PhoneBook settings
const int MAX_CONTACTS = 8;

#endif /* SETTINGS_HPP */