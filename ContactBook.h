//
// Created by zeyad on 10/31/24.
//

#ifndef CONTACTBOOK_H
#define CONTACTBOOK_H

#include "Person.h"
#include "ZeyadArray.h"
#include <string>
using namespace std;

class ContactBook {
private:
    ZeyadArray<Person> contacts;

public:
    void addNew(const Person &p);
    Person deleteAtIndex(const int &idx);
    Person pop();
    int getSize() const;
    int searchWithPhoneNumber(const string &num) ;
    void printFav();
    int searchWithLastName(const string &lName) ;
    void updateContact(int idx,  Person &p);
    void saveToFile(const string &filename) ;
    void loadFromFile(const string &filename);
    void print() ;
    void printSingleElement(int idx);
    void clearBook();
};

#endif
