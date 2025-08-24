#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <iostream>

#include "Contact.hpp"
#include "PhoneBook.hpp"

const char *const CONTACT_PROMPTS[] = {"First Name: ", "Last Name: ",
    "Nickname: ", "Phone Number: ", "Darkest Secret: "};

class Display {
   public:
    static void echo(const std::string &message);
    static void showExplanationHeader();
    static void showCursor();
    static void showContactList(const PhoneBook &phoneBook);
    static void showListSelectMessage();
    static void showContact(const Contact &contact);

    static void showNoCommandMessage();
    static void showInvalidIndexMessage();
    static void showRuntimeError();

   private:
    Display();
};

#endif /* DISPLAY_HPP */