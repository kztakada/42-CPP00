#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _contactSize(0) {}

static void shiftArray(ContactType *arr, int size) {
    for (int i = 1; i < size; ++i) {
        arr[i - 1] = arr[i];
    }
}

void PhoneBook::addContact(ContactType const &contact) {
    if (_contactSize >= MAX_CONTACTS) {
        shiftArray(_contacts, MAX_CONTACTS);
        _contacts[MAX_CONTACTS - 1] = contact;
    } else {
        _contacts[_contactSize] = contact;
        ++_contactSize;
    }
}

const ContactType *PhoneBook::getContact(int index) const {
    if (index < 0 || index >= _contactSize) {
        return NULL;
    }
    return &_contacts[index];
}
