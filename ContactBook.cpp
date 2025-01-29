//
// Created by zeyad on 10/31/24.
//
#include "ContactBook.h"
#include <iostream>
#include <fstream>
#include <iomanip>
void ContactBook::addNew(const Person &p) {
    contacts.append(p);
}

Person ContactBook::deleteAtIndex(const int &idx) {
    Person p = contacts[idx];
    contacts.deleteAtIndex(idx);
    return p;
}

Person ContactBook::pop() {
    Person p = contacts[contacts.SIZE() - 1];
    contacts.remove();
    return p;
}

int ContactBook::getSize() const {
    return contacts.SIZE();
}

int ContactBook::searchWithPhoneNumber(const string &num)  {
    for (int i = 0; i < contacts.SIZE(); i++) {
        if (contacts[i].getPhoneNum() == num) {
            return i;
        }
    }
    return -1;
}

int ContactBook::searchWithLastName(const string &lName)  {
    for (int i = 0; i < contacts.SIZE(); i++) {
        if (contacts[i].getSName() == lName) {
            return i;
        }
    }
    return -1;
}

void ContactBook::updateContact(int idx,  Person &p) {
    contacts[idx] = p;
}

void ContactBook::saveToFile(const string &filename)  {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Error opening file for saving.\n";
        return;
    }
    for (int i = 0; i < contacts.SIZE(); i++) {
         Person p = contacts[i];
         Address a = p.getAddress();
        file << p.getFName() << "\n"
             << p.getSName() << "\n"
             << p.getPhoneNum() << "\n"
             << p.getClassification() << "\n"
             << p.getFav()<<"\n"
             << a.getCountry() << "\n"
             << a.getCity() << "\n"
             << a.getStreet() << "\n"
             << a.getHomeNumber() << "\n";
    }
    file.close();
    cout << "Contacts saved to " << filename << " successfully.\n";
}

void ContactBook::loadFromFile(const string &filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error opening file for loading.\n";
        return;
    }
    clearBook();
    string fname, sname, phone, classification, country, city, street, homeNumber;
    bool fav;
    while (file >> fname >> sname >> phone >> classification >> fav >> country >> city >> street >> homeNumber) {
        Address address(country, city, street, homeNumber);
        Person person(fname, sname, phone, classification,address,fav);
        addNew(person);
    }
    file.close();
    cout << "Contacts loaded successfully from " << filename << ".\n";
}
void ContactBook::print(){
    const int firstNameWidth = 15;
    const int lastNameWidth = 15;
    const int cityWidth = 15;
    const int countryWidth = 15;
    const int streetWidth = 15;
    const int homeNumberWidth = 15;
    const int phoneWidth = 15;
    const int classificationWidth = 15;

    const int totalWidth = firstNameWidth + lastNameWidth + cityWidth + countryWidth + streetWidth + homeNumberWidth + phoneWidth + classificationWidth+21;
    cout << "┌" << string(totalWidth, '-') << "┐" << endl;
    cout << "|" << left << setw(firstNameWidth) << "First Name" << "ɔ: "
         << setw(lastNameWidth) << "Last Name" << "ɔ: "
         << setw(cityWidth) << "City" << "ɔ: "
         << setw(countryWidth) << "Country" << "ɔ: "
         << setw(streetWidth) << "Street" << "ɔ: "
         << setw(homeNumberWidth) << "Home Number" << "ɔ: "
         << setw(phoneWidth) << "Phone Number" << "ɔ: "
         << setw(classificationWidth) << "Classification" << "| " << endl;

    cout << "├" << string(totalWidth, '-') << "┤" << endl;
    int n = contacts.SIZE();

    for (int i = 0; i < n; i++) {
        Person p = contacts[i];
        Address a = p.getAddress();

        cout << "|" << left << setw(firstNameWidth) << p.getFName() << "ɔ: "
             << setw(lastNameWidth) << p.getSName() << "ɔ: "
             << setw(cityWidth) << a.getCity() << "ɔ: "
             << setw(countryWidth) << a.getCountry() << "ɔ: "
             << setw(streetWidth) << a.getStreet() << "ɔ: "
             << setw(homeNumberWidth) << a.getHomeNumber() << "ɔ: "
             << setw(phoneWidth) << p.getPhoneNum() << "ɔ: "
             << setw(classificationWidth) << p.getClassification() << "| " << endl;

        if (i == n - 1) {
            cout << "└" << string(totalWidth, '-') << "┘" << endl;
        } else {
            cout << "├" << string(totalWidth, '-') << "┤" << endl;
        }
    }
}
void ContactBook::printFav(){
    const int firstNameWidth = 15;
    const int lastNameWidth = 15;
    const int cityWidth = 15;
    const int countryWidth = 15;
    const int streetWidth = 15;
    const int homeNumberWidth = 15;
    const int phoneWidth = 15;
    const int classificationWidth = 15;

    const int totalWidth = firstNameWidth + lastNameWidth + cityWidth + countryWidth + streetWidth + homeNumberWidth + phoneWidth + classificationWidth+21;
    cout << "┌" << string(totalWidth, '-') << "┐" << endl;
    cout << "|" << left << setw(firstNameWidth) << "First Name" << "ɔ: "
         << setw(lastNameWidth) << "Last Name" << "ɔ: "
         << setw(cityWidth) << "City" << "ɔ: "
         << setw(countryWidth) << "Country" << "ɔ: "
         << setw(streetWidth) << "Street" << "ɔ: "
         << setw(homeNumberWidth) << "Home Number" << "ɔ: "
         << setw(phoneWidth) << "Phone Number" << "ɔ: "
         << setw(classificationWidth) << "Classification " << "| " << endl;

    cout << "├" << string(totalWidth, '-') << "┤" << endl;
    int n = contacts.SIZE();

    for (int i = 0; i < n; i++) {

        Person p = contacts[i];
        Address a = p.getAddress();
        if(p.getFav() == 1) {
            cout << "|" << left << setw(firstNameWidth) << p.getFName() << "ɔ: "
                 << setw(lastNameWidth) << p.getSName() << "ɔ: "
                 << setw(cityWidth) << a.getCity() << "ɔ: "
                 << setw(countryWidth) << a.getCountry() << "ɔ: "
                 << setw(streetWidth) << a.getStreet() << "ɔ: "
                 << setw(homeNumberWidth) << a.getHomeNumber() << "ɔ: "
                 << setw(phoneWidth) << p.getPhoneNum() << "ɔ: "
                 << setw(classificationWidth) << p.getClassification() << "| " << endl;
            if (i == n - 1) {
                cout << "└" << string(totalWidth, '-') << "┘" << endl;
            } else {
                cout << "├" << string(totalWidth, '-') << "┤" << endl;
            }
        }
    }
}
void ContactBook::printSingleElement(int i){
    const int firstNameWidth = 15;
    const int lastNameWidth = 15;
    const int cityWidth = 15;
    const int countryWidth = 15;
    const int streetWidth = 15;
    const int homeNumberWidth = 15;
    const int phoneWidth = 15;
    const int classificationWidth = 15;
    const int totalWidth = firstNameWidth + lastNameWidth + cityWidth + countryWidth + streetWidth + homeNumberWidth + phoneWidth + classificationWidth+14;
    cout << "┌" << string(totalWidth, '-') << "┐" << endl;
    cout << "|" << left << setw(firstNameWidth) << "First Name" << "| "
         << setw(lastNameWidth) << "Last Name" << "| "
         << setw(cityWidth) << "City" << "| "
         << setw(countryWidth) << "Country" << "| "
         << setw(streetWidth) << "Street" << "| "
         << setw(homeNumberWidth) << "Home Number" << "| "
         << setw(phoneWidth) << "Phone Number" << "| "
         << setw(classificationWidth) << "Classification" << "| " << endl;
    cout << "├" << string(totalWidth, '-') << "┤" << endl;
    Person p = contacts[i];
    Address a = p.getAddress();
    cout << "|" << left << setw(firstNameWidth) << p.getFName() << "| "
         << setw(lastNameWidth) << p.getSName() << "| "
         << setw(cityWidth) << a.getCity() << "| "
         << setw(countryWidth) << a.getCountry() << "| "
         << setw(streetWidth) << a.getStreet() << "| "
         << setw(homeNumberWidth) << a.getHomeNumber() << "| "
         << setw(phoneWidth) << p.getPhoneNum() << "| "
         << setw(classificationWidth) << p.getClassification() << "| " << endl;
    cout << "└" << string(totalWidth, '-') << "┘" << endl;

}

void ContactBook::clearBook() {
    while (!contacts.isEmpty()) {
        contacts.remove();
    }
    cout << "Contact book cleared.\n";
}
