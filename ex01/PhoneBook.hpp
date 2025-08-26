#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

const int MAX_CONTACTS = 8;

// Forward declaration and type alias
template <int N, typename T>
class PhoneBook;
typedef PhoneBook<MAX_CONTACTS, ContactType> PhoneBookType;

//-----------------------------------------------------------------
// PhoneBook Class Template Definition

template <int N, typename T>
class PhoneBook {
   public:
    PhoneBook();

    void addContact(T const &contact);
    const T *getContact(int index) const;

   private:
    T _contacts[N];
    int _registeredContactSize;
    void _shiftArray(T *arr);
};

//-----------------------------------------------------------------
// class public methods

template <int N, typename T>
PhoneBook<N, T>::PhoneBook() : _registeredContactSize(0) {}

template <int N, typename T>
void PhoneBook<N, T>::addContact(T const &contact) {
    if (_registeredContactSize >= N) {
        _shiftArray(_contacts);
        _contacts[N - 1] = contact;
    } else {
        _contacts[_registeredContactSize] = contact;
        ++_registeredContactSize;
    }
}

template <int N, typename T>
const T *PhoneBook<N, T>::getContact(int index) const {
    if (index < 0 || index >= _registeredContactSize) {
        return NULL;
    }
    return &_contacts[index];
}

//-----------------------------------------------------------------
// class private methods

template <int N, typename T>
void PhoneBook<N, T>::_shiftArray(T *arr) {
    for (int i = 1; i < N; ++i) {
        arr[i - 1] = arr[i];
    }
}

#endif /* PHONEBOOK_HPP */