#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

const int MAX_CONTACTS = 8;

class PhoneBook {
   public:
    PhoneBook();
    //  ~PhoneBook();
    //  PhoneBook(PhoneBook const &other);
    //  PhoneBook &operator=(PhoneBook const &other);

    void addContact(Contact const &contact);
    const Contact *getContact(int index) const;

   private:
    Contact _contacts[MAX_CONTACTS];
    int _contactSize;
};

#endif /* PHONEBOOK_HPP */