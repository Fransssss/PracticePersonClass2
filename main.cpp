// Title: Practice part of code Person Class later will be use to create phone book
// Purpose: dynamically create a block of memory, set value to an object type class, deallocate allocated block of memory
// Author: Fransiskus Agapa
// Have fun = Enjoy the process - Practices make improvement

#include <iostream>
#include "Person.h"
#include <cctype>

using std::cout;
using std::endl;
using std::cin;
using std::getline;
using std::isdigit;
using std::cerr;


int main()
{
    string name,phone;
    int level = 0;
    int invalidCounter = 0;
    cout << endl << "Input data of a person \n-Name\n-Phone Number\n-Level (rate how close you with the person 1 out of 10)" << endl;
    cout << endl << "Name: ";
    getline(cin,name);
    cout << endl << "Phone number: ";
    cin >> phone;
    cout << endl << "Level: ";
    cin >> level;
    cout << endl;

    if(phone.length() != 10)
    {
        ++invalidCounter;
    }

    for(size_t i = 0; i < phone.length();++i)
    {
        if(!isdigit(phone[i]))
        {
            ++invalidCounter;
        }
    }

    if(invalidCounter > 0)
    {
        cerr << "[Data is invalid]" << endl;
        return -1;
    } else
    {
        Person fPerson(name.c_str(),phone.c_str(),level);           // user c_str() cause data member type is set as char
        cout << "Data of the person: " << endl;
        cout << "-Name: " << fPerson.GetName() << endl;
        cout << "-Phone: " << fPerson.GetPhone() << endl;
        cout << "-Level: " << fPerson.GetLevel() << endl;
        cout << "-String Format | " << fPerson.ToString() << endl;
        cout << "-Json Format   | " << fPerson.ToJson() << endl;
    }

  return 0;
}