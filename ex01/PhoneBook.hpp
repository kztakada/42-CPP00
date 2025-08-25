#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include "Settings.hpp"

class PhoneBook {
   public:
    PhoneBook();

    void addContact(Contact<CONTACT_FORM_SIZE> const &contact);
    const Contact<CONTACT_FORM_SIZE> *getContact(int index) const;

   private:
    Contact<CONTACT_FORM_SIZE> _contacts[MAX_CONTACTS];
    int _contactSize;
};

#endif /* PHONEBOOK_HPP */