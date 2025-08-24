#include "Contact.hpp"

Contact::Contact()
    : _firstName(""),
      _lastName(""),
      _nickname(""),
      _phoneNumber(""),
      _darkestSecret("") {}

const std::string *Contact::getField(ContactField field) const {
    switch (field) {
        case FIRST_NAME:
            return &_firstName;
        case LAST_NAME:
            return &_lastName;
        case NICKNAME:
            return &_nickname;
        case PHONE_NUMBER:
            return &_phoneNumber;
        case DARKEST_SECRET:
            return &_darkestSecret;
        default:
            return NULL;
    }
}

const std::string &Contact::getFirstName() const { return _firstName; }

const std::string &Contact::getLastName() const { return _lastName; }

const std::string &Contact::getNickName() const { return _nickname; }

const std::string &Contact::getPhoneNumber() const { return _phoneNumber; }

const std::string &Contact::getDarkestSecret() const { return _darkestSecret; }

bool Contact::setField(ContactField field, const std::string &value) {
    switch (field) {
        case FIRST_NAME:
            return setFirstName(value);
            break;
        case LAST_NAME:
            return setLastName(value);
            break;
        case NICKNAME:
            return setNickName(value);
            break;
        case PHONE_NUMBER:
            return setPhoneNumber(value);
            break;
        case DARKEST_SECRET:
            return setDarkestSecret(value);
            break;
        default:
            return false;
    }
    return true;
}

bool Contact::setFirstName(const std::string &firstName) {
    _firstName = firstName;
    return true;
}

bool Contact::setLastName(const std::string &lastName) {
    _lastName = lastName;
    return true;
}

bool Contact::setNickName(const std::string &nickName) {
    _nickname = nickName;
    return true;
}

bool Contact::setPhoneNumber(const std::string &phoneNumber) {
    // if (phoneNumber.length() < 10 || phoneNumber.length() > 15)
    //     return false;
    // for (size_t i = 0; i < phoneNumber.length(); ++i) {
    //     if (i == 0 && phoneNumber[i] == '+')
    //         continue;
    //     char c = phoneNumber[i];
    //     if (!std::isdigit(c) && c != '-') {
    //         return false;
    //     }
    // }
    _phoneNumber = phoneNumber;
    return true;
}

bool Contact::setDarkestSecret(const std::string &darkestSecret) {
    _darkestSecret = darkestSecret;
    return true;
}
