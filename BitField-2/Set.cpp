#include "Set.h"

Set::operator BitField() {
    return BitField(this->_bitfield);
}

Set::Set(const BitField& tmp) : _maxPower(tmp.GetLength()), _bitfield(tmp) {}

Set::Set(const Set& tmp): _maxPower(tmp.GetMaxPow()), _bitfield(tmp._bitfield) {}

Set::Set(const size_t maxPower) : _maxPower(maxPower), _bitfield(maxPower) {}

void Set::InsElem(uint64_t elem) {
    if (elem < _maxPower)
        _bitfield.SetBit(elem);
    else {
        throw "Elem out of range";
    }
}

void Set::DelElem(uint64_t elem) {
    _bitfield.ClrBit(elem);
}

size_t Set::GetMaxPow() const {
    return _maxPower;
}

bool Set::IsMember(uint64_t elem) {
    if (elem < _maxPower && elem >= 0){
        if (_bitfield.GetBit(elem) == 1) return true;
        }
        return false;
}


bool Set::operator==(const Set& tmp) const {
    if (_bitfield == tmp._bitfield)
        return true;
    return false;
}

bool Set::operator!=(const Set& tmp) const{
    if (_bitfield == tmp._bitfield)
        return false;
    return true;
}

Set& Set::operator=(const Set& tmp) {
    _maxPower = tmp._maxPower;
    _bitfield = tmp._bitfield;
    return *this;
}

Set Set::operator+(const Set& tmp) {
    Set result(max(tmp._maxPower, _maxPower));
    result._bitfield = _bitfield | tmp._bitfield;
    return result;
}

void Set::operator+(uint64_t elem) {
    InsElem(elem);
}

void Set::operator-(uint64_t elem) {
    DelElem(elem);
}

Set Set::operator*(const Set& tmp) {
    Set result(max(tmp._maxPower, _maxPower));
    result._bitfield = _bitfield & tmp._bitfield;
    return result;
}

Set Set::operator~() {
    Set result(_maxPower);
    result._bitfield = ~_bitfield;
    return result;
}
