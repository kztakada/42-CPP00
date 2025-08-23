#ifndef RECEPTIONIST_HPP
#define RECEPTIONIST_HPP

#include <iostream>

#include "Display.hpp"
#include "PhoneBook.hpp"



class Receptionist {
   public:
    Receptionist(PhoneBook &phoneBook);
    // ~Receptionist();
    // Receptionist(Receptionist const &other);
    // Receptionist &operator=(Receptionist const &other);

    void serve();

   private:
    PhoneBook &_phoneBook;
    void listenToUserInput(std::string &input);
    void handleAddContact();
    void handleSearchContact();
    void handleNoCommand();
};

#endif /* RECEPTIONIST_HPP */