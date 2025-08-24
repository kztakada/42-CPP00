#include "Contact.hpp"

Contact::Contact() {}

static bool isValidField(ContactField field) {
    return field >= 0 && field < FIELD_COUNT;
}

const std::string *Contact::getField(ContactField field) const {
    if (isValidField(field)) {
        return &_field[field];
    }
    return NULL;
}

bool Contact::setField(ContactField field, const std::string &value) {
    if (!isValidField(field)) {
        return false;
    }
    _field[field] = value;
    return true;
}

// bool Contact::setPhoneNumber(const std::string &phoneNumber) {
//     // if (phoneNumber.length() < 10 || phoneNumber.length() > 15)
//     //     return false;
//     // for (size_t i = 0; i < phoneNumber.length(); ++i) {
//     //     if (i == 0 && phoneNumber[i] == '+')
//     //         continue;
//     //     char c = phoneNumber[i];
//     //     if (!std::isdigit(c) && c != '-') {
//     //         return false;
//     //     }
//     // }
//     _phoneNumber = phoneNumber;
//     return true;
// }
