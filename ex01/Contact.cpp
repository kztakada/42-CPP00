#include "Contact.hpp"

Contact::Contact()
    : _first_name(""),
      _last_name(""),
      _nickname(""),
      _phone_number(""),
      _darkest_secret("") {}

Contact::Contact(std::string first_name, std::string last_name,
    std::string nickname, std::string phone_number, std::string darkest_secret)
    : _first_name(first_name),
      _last_name(last_name),
      _nickname(nickname),
      _phone_number(phone_number),
      _darkest_secret(darkest_secret) {}

const std::string &Contact::firstName() const { return _first_name; }

const std::string &Contact::lastName() const { return _last_name; }

const std::string &Contact::nickname() const { return _nickname; }

const std::string &Contact::phoneNumber() const { return _phone_number; }

const std::string &Contact::darkestSecret() const { return _darkest_secret; }

// Contact::~Contact() {}

// Contact::Contact(Contact const &other) { *this = other; }

// Contact &Contact::operator=(Contact const &other) {
//     if (this != &other) {
//     }
//     return *this;
// }