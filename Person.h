//
// Created by zeyad on 10/31/24.
//

#ifndef PERSON_H
#define PERSON_H

#include <string>
#include "Address.h"
using namespace std;

class Person {
private:
    string fName, sName, phoneNumber, classification;
    bool fav ;
    Address address;

public:
    Person();
    Person(string &f, string &s, string &p, string &cl, Address &a, bool &ff);
    Person& operator=(const Person &other);
    string getFName() const;
    string getSName() const;
    string getPhoneNum() const;
    string getClassification() const;
    bool getFav() const;
    Address getAddress() const;
    void setFName(const string &f);
    void setSName(const string &s);
    void setPhoneNum(const string &p);
    void setClassification(const string &cl);
    void setFav(const bool &f);
    void setPerson(const Person &p);
};

#endif
