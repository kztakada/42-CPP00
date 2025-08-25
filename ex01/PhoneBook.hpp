#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include "PhoneBookDomain.hpp"

class PhoneBook {
   public:
    PhoneBook();

    void addContact(ContactType const &contact);
    const ContactType *getContact(int index) const;

   private:
    ContactType _contacts[MAX_CONTACTS];
    int _contactSize;
};

#endif /* PHONEBOOK_HPP */