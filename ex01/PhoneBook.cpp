#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _contactSize(0) {}

// PhoneBook::~PhoneBook() {}

// PhoneBook::PhoneBook(PhoneBook const &other) { *this = other; }

// PhoneBook &PhoneBook::operator=(PhoneBook const &other) {
//     if (this != &other) {
//         for (int i = 0; i < MAX_CONTACTS; ++i) {
//             _contacts[i] = other._contacts[i];
//         }
//         _contactCount = other._contactCount;
//     }
//     return *this;
// }

static void shiftArray(Contact *arr, int size) {
    for (int i = 1; i < size; ++i) {
        arr[i - 1] = arr[i];
    }
}

void PhoneBook::addContact(Contact const &contact) {
    if (_contactSize >= MAX_CONTACTS) {
        shiftArray(_contacts, MAX_CONTACTS);
        _contacts[MAX_CONTACTS - 1] = contact;
    } else {
        _contacts[_contactSize] = contact;
        ++_contactSize;
    }
}

const Contact *PhoneBook::getContact(int index) const {
    if (index < 0 || index >= _contactSize) {
        return NULL;
    }
    return &_contacts[index];
}
