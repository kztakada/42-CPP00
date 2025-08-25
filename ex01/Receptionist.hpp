#ifndef RECEPTIONIST_HPP
#define RECEPTIONIST_HPP

#include <climits>
#include <iomanip>
#include <iostream>
#include <sstream>

#include "Contact.hpp"
#include "Display.hpp"
#include "PhoneBook.hpp"
#include "PhoneBookDomain.hpp"

class Receptionist {
   public:
    Receptionist(PhoneBook *phoneBook, bool isEchoMode, bool isStrictMode);

    void serve();

   private:
    PhoneBook *_phoneBook;
    bool _isEchoMode;
    bool _isStrictMode;
    void _handleAddContact();
    void _handleSearchContact();
    void _handleNoCommand();
    std::string _makeContactList();
};

#endif /* RECEPTIONIST_HPP */