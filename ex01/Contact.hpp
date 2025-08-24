#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

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
    const std::string &getFirstName() const;
    const std::string &getLastName() const;
    const std::string &getNickName() const;
    const std::string &getPhoneNumber() const;
    const std::string &getDarkestSecret() const;

    bool setField(ContactField field, const std::string &value);
    bool setFirstName(const std::string &firstName);
    bool setLastName(const std::string &lastName);
    bool setNickName(const std::string &nickName);
    bool setPhoneNumber(const std::string &phoneNumber);
    bool setDarkestSecret(const std::string &darkestSecret);

   private:
    std::string _firstName;
    std::string _lastName;
    std::string _nickname;
    std::string _phoneNumber;
    std::string _darkestSecret;
};

#endif /* CONTACT_HPP */