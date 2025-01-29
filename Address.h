//
// Created by zeyad on 10/31/24.
//
#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>
using namespace std;

class Address {
private:
    string country;
    string city;
    string street;
    string homeNumber;

public:
    Address(string &c, string &ct, string &st, string &num);
    Address();


    string getCountry() const;
    string getCity() const;
    string getStreet() const;
    string getHomeNumber() const;


    void setCountry(const string &c);
    void setCity(const string &ct);
    void setStreet(const string &st);
    void setHomeNumber(const string &num);
    void setAddress(const Address &a);

    ~Address() {}
};

#endif
