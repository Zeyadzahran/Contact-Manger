#include <iostream>
#include "ContactBook.h"
#include "Person.h"
#include "Address.h"
using namespace std;

bool isNumeric(const string &str);
void addContact(ContactBook &arr);
void updateContact(ContactBook &arr , int &idx);
void startMenu();
int main() {


    string username = "Zeyad";
    int password = 1111;

    string s;
    int pass;
    do {
        startMenu();
        cin >> option;
    cout << "Enter User Name\n";
    cin >> s;
    cout << "Enter password\n";
    cin >> pass;

    if (s != username || pass != password)
    {
        do
        {
            cout << "User name or password inValied\n";
            cout << "Enter User Name\n";
            cin >> s;
            cout << "Enter password\n";
            cin >> pass;
        } while (s != username || pass != password);
    }


    ContactBook contactBook;
    int option;

        switch (option) {
            case 1:
                addContact(contactBook);
            break;

            case 2: {
                cout << "The Contact That you Delete:\n";
                contactBook.printSingleElement(contactBook.getSize() - 1);
                Person p = contactBook.pop();
                break;
            }

            case 3: {
                int idx;
                cout << "Enter index to remove: ";
                cin >> idx;
                int n = contactBook.getSize();
                if (idx >= n || idx < 0) {
                    cout << "Invalid index\n";
                } else {
                    cout << "The Element That you  Delete:\n";
                    contactBook.printSingleElement(idx);
                    Person p = contactBook.deleteAtIndex(idx);
                }
                break;
            }

            case 4: {
                string phoneNumber;
                cout << "Enter phone number to search: ";
                cin >> phoneNumber;
                int res = contactBook.searchWithPhoneNumber(phoneNumber);
                if (res == -1) {
                    cout << "Not Found\n";
                } else {
                    contactBook.printSingleElement(res);
                }
                break;
            }


            case 5: {
                string lastName;
                cout << "Enter last name to search: ";
                cin >> lastName;
                int res = contactBook.searchWithLastName(lastName);
                if (res == -1) {
                    cout << "Not Found\n";
                } else {
                    contactBook.printSingleElement(res);
                }
                break;

            }

            case 6: {
                int idx;
                cout << "Enter index to get contact: ";
                cin >> idx;
                int n = contactBook.getSize();
                if (idx >= n || idx < 0) {
                    cout << "Invalid index\n";
                } else {
                    contactBook.printSingleElement(idx);
                }
                break;
            }


            case 7: {
                string lastName;
                cout << "Enter Last Name For The Contact You Want To Update : ";
                cin >> lastName;
                int idx = contactBook.searchWithLastName(lastName);
                if (idx == -1) {
                    cout << "Not Found\n";
                } else {
                    updateContact(contactBook , idx);
                }

                break;
            }

            case 8:
                contactBook.print();
            break;
            case 9: {
                contactBook.printFav();
                break;
            }
            case 10 : {
                cout<<"DO YOU WANT TO DELETE CONTACT BOOK !\n";
                char ans ; cin >> ans  ;
                ans = tolower(ans);
                if(ans == 'y') {
                    contactBook.clearBook();
                    cout<<"Contact Book Deleted Successfully :)\n";
                }
                else {
                    cout<<"Don't worry, No Contact Has been Deleted\nGoodBye";
                }
                break;
            }
               case 11: {
                cout << "Saving contacts and exiting.\n";
                contactBook.saveToFile("contacts.txt");
                cout << "Goodbye!\n";
                break;
            }
            case 12: {
                    cout << "Loading contacts from file will overwrite current contacts.\n";
                    cout << "Are you sure you want to continue? (y/n): ";
                    char confirm;
                    cin >> confirm;
                    if (tolower(confirm) == 'y') {
                        contactBook.loadFromFile("contacts.txt");
                        cout << "Contacts loaded from file successfully.\n";
                    } else {
                        cout << "Load Operation Canceled.\n";
                    }
                    break;
                }

            case 13:
                cout << "Goodbye!\n";
                break;

            default:
                cout << "Invalid option. Please try again.\n";
        }
    } while (option != 13);

    return 0;
}
bool isNumeric(const string &str)
{

    for (char c : str)
    {
        if (!isdigit(c))
        {
            return false;
        }
    }
    return true;
}
void addContact(ContactBook &arr) {
    string fname, sname, number, country, city, street, homeNum, classification;
    bool fav;

    cout << "Enter First Name: "; cin >> fname;
    cout << "Enter Last Name: "; cin >> sname;
    cout << "Enter Phone Number: ";
    while (true) {
        cin >> number;
        if (isNumeric(number)) break;
        cout << "Invalid input. Please enter only numbers.\n";
    }
    cout << "Enter classification (Friend , work , family ,other) : "; cin >> classification;
    cout<<"Is it Fav yes[1] no [0] "; cin>>fav;
    cout << "Enter Country: "; cin >> country;
    cout << "Enter City: "; cin >> city;
    cout << "Enter Street: "; cin >> street;
    cout << "Enter Home Number: ";
    while (true) {
        cin >> homeNum;
        if (isNumeric(homeNum)) break;
        cout << "Invalid input. Please enter only numbers.\n";
    }

    Address a(country, city, street, homeNum);
    Person p(fname, sname, number, classification, a,fav);
    arr.addNew(p);
}
void updateContact(ContactBook &arr , int &idx) {
    string fname, sname, number, country, city, street, homeNum, classification;
    bool fav ;
    cout<<"Enter The New Details for the Contact To Be Updated\n";

    cout << "Enter First Name: "; cin >> fname;
    cout << "Enter Last Name: "; cin >> sname;
    cout << "Enter Phone Number: ";
    while (true) {
        cin >> number;
        if (isNumeric(number)) break;
        cout << "Invalid input. Please enter only numbers.\n";
    }
    cout << "Enter classification (Friend , work , family ,other) "; cin >> classification;
    cout<<"Is it Fav yes[1] no [0] "; cin>>fav;
    cout << "Enter Country: "; cin >> country;
    cout << "Enter City: "; cin >> city;
    cout << "Enter Street: "; cin >> street;
    cout << "Enter Home Number: ";
    while (true) {
        cin >> homeNum;
        if (isNumeric(homeNum)) break;
        cout << "Invalid input. Please enter only numbers.\n";
    }

    Address a(country, city, street, homeNum);
    Person p(fname, sname, number, classification, a,fav);
    arr.updateContact(idx ,p);
}
void startMenu() {
    cout << "\nChoose an operation:\n";
    cout << "1 - Add New Contact\n"
         << "2 - Remove Contact\n"
         << "3 - Delete Contact at Index\n"
         << "4 - Search by Phone Number\n"
         << "5 - Search by Last Name\n"
         << "6 - View Contact Details\n"
         << "7 - Update Contact\n"
         << "8 - Display All Contacts\n"
         << "9 - PrintFav\n"
         << "10 - Delete Contact Book\n"
         << "11 - Save Contacts To File\n"
         << "12 - Load Contacts To File\n"
         << "13 - Exit\n";
}

