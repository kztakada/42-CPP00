#ifndef RECEPTIONIST_HPP
#define RECEPTIONIST_HPP

#include <iostream>
#include <sstream>

#include "Display.hpp"
#include "PhoneBook.hpp"

class Receptionist {
   public:
    Receptionist(PhoneBook *phoneBook);
    Receptionist(PhoneBook *phoneBook, bool isStrictMode);

    void serve();

   private:
    PhoneBook *_phoneBook;
    bool _isStrictMode;
    void _listenToUserInput(std::string &input);
    void _handleAddContact();
    void _handleSearchContact();
    void _handleNoCommand();
    std::string _makeContactList();
    std::string _makeContactDetails(const Contact *contact);
};

#endif /* RECEPTIONIST_HPP */