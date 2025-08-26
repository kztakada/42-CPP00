#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

const int CONTACT_FORM_SIZE = 5;

// Forward declaration and type alias
template <int N>
class Contact;
typedef Contact<CONTACT_FORM_SIZE> ContactType;

//-----------------------------------------------------------------
// Contact Class Template Definition

template <int N>
class Contact {
   public:
    Contact();
    Contact(const Contact<N> &other);
    Contact<N> &operator=(const Contact<N> &other);
    ~Contact();

    const std::string *getField(const int field_index) const;
    bool setField(const int field_index, const std::string &value);

   private:
    std::string _field[N];
    const int _fieldSize;
    bool _isValidField(const int field_index) const;
};

//-----------------------------------------------------------------
// class public methods

template <int N>
Contact<N>::Contact() : _fieldSize(N) {
    for (int i = 0; i < N; ++i) {
        _field[i] = "";
    }
}

template <int N>
Contact<N>::Contact(const Contact<N> &other) {
    for (int i = 0; i < N; ++i) {
        _field[i] = other._field[i];
    }
}

template <int N>
Contact<N> &Contact<N>::operator=(const Contact<N> &other) {
    if (this != &other) {
        for (int i = 0; i < N; ++i) {
            _field[i] = other._field[i];
        }
    }
    return *this;
}

template <int N>
Contact<N>::~Contact() {}

template <int N>
const std::string *Contact<N>::getField(const int field_index) const {
    if (_isValidField(field_index)) {
        return &_field[field_index];
    }
    return NULL;
}

template <int N>
bool Contact<N>::setField(const int field_index, const std::string &value) {
    if (!_isValidField(field_index)) {
        return false;
    }
    _field[field_index] = value;
    return true;
}

//-----------------------------------------------------------------
// class private methods

template <int N>
bool Contact<N>::_isValidField(const int field_index) const {
    return field_index >= 0 && field_index < _fieldSize;
}

#endif /* CONTACT_HPP */