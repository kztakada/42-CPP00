#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

const int MAX_CONTACTS = 8;

class PhoneBook {
   public:
    PhoneBook();

    void addContact(Contact const &contact);
    const Contact *getContact(int index) const;

   private:
    Contact _contacts[MAX_CONTACTS];
    int _contactSize;
};

#endif /* PHONEBOOK_HPP */