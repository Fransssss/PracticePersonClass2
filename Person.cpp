//
// Created by XaveF on 5/27/2022.
//

#include "Person.h"
#include <cstring>                                       // dealing with c-string
#include <sstream>
using std::stringstream;

Person::Person(const char *nm, const char *ph, int level)
{
    _name = new char[strlen(nm)+1];                   // dynamically set a block of memroy before assign a value
    strcpy(_name, nm);                        // use copy since its char type
    strcpy(_phone,ph);                        // _phone is fixed size
    _level = level;
}

Person::Person(const Person &person)
{
    _name = new char[strlen(person._name)+1];        // dynamically set a block of memory before assign a value
    strcpy(_name, person._name);             // use copy since its char type
    strcpy(_phone,person._phone);
    _level = person._level;
}

const Person& Person::operator=(const Person &person)
        {
            if(strlen(_name) != strlen(person._name))
            {
                delete[] _name;                                      // clean old data
                _name = new char[strlen(person._name)+1];        // // dynamically set a block of memroy before assign a value
            }
            strcpy(_name, person._name);
            strcpy(_phone,person._phone);
            _level = person._level;
            return *this;
        }

Person::~Person()
{
    delete[] _name;                                       // _name is dynamically created as an array so we put brackets []
}

string Person::GetName() const
{
    return string(_name);
}

string Person::GetPhone() const
{
    return string(_phone);
}

int Person::GetLevel() const
{
    return _level;
}

string Person::ToJson() const
{
    stringstream sj;
    sj << "{\"Name\": \"" << _name << ", \"Phone\": " << _phone << ", \"Level\":" << _level << "}";
    return sj.str();
}

string Person::ToString() const
{
    stringstream ss;
    ss << "Name: " << _name << ", Phone: " << _phone << ", Level: " << _level;
    return ss.str();
}

istream& Person::Read(istream &input)                              // the idea -  data is separated by space
{
    string name, phone;                                            // to extract data from input so create new variables
    int level = 0;
    input >> name >> phone >> level;
    return input;
}

ostream& Person::Write(ostream& output)
{
    output << _name << " " << _phone << " " << _level;
    return output;
}
