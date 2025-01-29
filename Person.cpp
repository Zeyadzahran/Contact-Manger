//
// Created by zeyad on 10/31/24.
//

#include "Person.h"

Person::Person() : fName("..."), sName("..."), phoneNumber("..."), classification("...."), address(),fav(0) {}

Person::Person(string &f, string &s, string &p, string &cl, Address &a, bool &ff)
    : fName(f), sName(s), phoneNumber(p), classification(cl), address(a),fav(ff) {}

string Person::getFName() const {
    return fName;
}
string Person::getSName() const {
    return sName;
}
string Person::getPhoneNum() const {
    return phoneNumber;
}
string Person::getClassification() const {
    return classification;
}
bool Person::getFav() const {
    return fav ;
}

Address Person::getAddress() const {
    return address;
}

void Person::setFName(const string &f) {
    fName = f;
}
void Person::setSName(const string &s) {
    sName = s;
}
void Person::setPhoneNum(const string &p) {
    phoneNumber = p;
}
void Person::setClassification(const string &cl) {
    classification = cl;
}

void Person::setFav(const bool &ff) {
   fav = ff ;
}
Person& Person::operator=(const Person &other) {
    if (this == &other)
        return *this;

    fName = other.fName;
    sName = other.sName;
    phoneNumber = other.phoneNumber;
    classification = other.classification;
    fav = other.fav;
    address = other.address;

    return *this;
}
void Person::setPerson(const Person &z) {
    setFName(z.getFName());
    setSName(z.getSName());
    setClassification(z.getClassification());
    setPhoneNum(z.getPhoneNum());
    setFav(z.getFav());
    address.setAddress(z.getAddress());
}

