#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

const int FIELD_COUNT = 5;

enum ContactField {
    FIRST_NAME,
    LAST_NAME,
    NICKNAME,
    PHONE_NUMBER,
    DARKEST_SECRET
};

class Contact {
   public:
    Contact();

    const std::string *getField(ContactField field) const;
    bool setField(ContactField field, const std::string &value);

   private:
    std::string _field[FIELD_COUNT];
};

#endif /* CONTACT_HPP */