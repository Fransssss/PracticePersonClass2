// Declaration of Person Class

#ifndef PRACTICEPERSONCLASS2_PERSON_H
#define PRACTICEPERSONCLASS2_PERSON_H

#include <iostream>
#include <sstream>
using std::string;
using std::istream;
using std::ostream;

class Person
{
private:
    char* _name;                            // the length of name is unknown
    char _phone[11];                        // U.S. phone format 10 digit but the 11th for null char
    int _level;                             // for fun rating how close someone is 1 out of 10
public:
    Person(const char* nm, const char* ph, int level =  0);
    Person(const Person& person);                                // copy constructor
    const Person& operator=(const Person& person);               // copy assignment operator=
    ~Person();                                                   // destrcutor
    string GetName() const;
    string GetPhone() const;
    int GetLevel() const;
    string ToJson() const;
    string ToString() const;
    istream& Read(istream& input);
    ostream& Write(ostream& output);
};


#endif //PRACTICEPERSONCLASS2_PERSON_H
