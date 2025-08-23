#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
   public:
    Contact();
    Contact(std::string first_name, std::string last_name, std::string nickname,
        std::string phone_number, std::string darkest_secret);
    //  ~Contact();
    //  Contact(Contact const &other);
    //  Contact &operator=(Contact const &other);

    const std::string &firstName() const;
    const std::string &lastName() const;
    const std::string &nickname() const;
    const std::string &phoneNumber() const;
    const std::string &darkestSecret() const;

   private:
    std::string _first_name;
    std::string _last_name;
    std::string _nickname;
    std::string _phone_number;
    std::string _darkest_secret;
};

#endif /* CONTACT_HPP */