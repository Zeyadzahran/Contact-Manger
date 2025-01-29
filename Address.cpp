//
// Created by zeyad on 10/31/24.
//

#include "Address.h"

Address::Address(string &c, string &ct, string &st, string &num)
    : country(c), city(ct), street(st), homeNumber(num) {}

Address::Address()
    : country("Egypt"), city("Cairo"), street("Omar Ebn El Khtabb"), homeNumber("123") {}

string Address::getCountry() const {
    return country;
}
string Address::getCity() const {
    return city;
}
string Address::getStreet() const {
    return street;
}
string Address::getHomeNumber() const {
    return homeNumber;
}

void Address::setCountry(const string &c) {
    country = c;
}
void Address::setCity(const string &ct) {
    city = ct;
}
void Address::setStreet(const string &st) {
    street = st;
}
void Address::setHomeNumber(const string &num) {
    homeNumber = num;
}
void Address::setAddress(const Address &a) {
    setCountry(a.getCountry());
    setCity(a.getCity());
    setStreet(a.getStreet());
    setHomeNumber(a.getHomeNumber());
}

