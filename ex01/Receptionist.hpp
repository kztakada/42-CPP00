#ifndef RECEPTIONIST_HPP
#define RECEPTIONIST_HPP

// #include <cstdlib>
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
    void listenToUserInput(std::string &input);
    void handleAddContact();
    void handleSearchContact();
    void handleNoCommand();
};

#endif /* RECEPTIONIST_HPP */