

#ifndef LAB3_STUDENT_H
#define LAB3_STUDENT_H

#pragma once
#include <iostream>
#include <istream>
#include <ostream>
#include <string>

using namespace std;

class Student {
private:
    string firstName;
    string middleName;
    string lastName;
    int age;
public:
    Student() {
        age = 0;
        firstName = "Ivan";
        middleName = "Ivanov";
        lastName = "Ivanovich";
    }

    Student(int age, string firstName, string middleName, string lastName) {
        this->age = age;
        this->firstName = firstName;
        this->middleName = middleName;
        this->lastName = lastName;
    }



    friend ostream& operator << (ostream& os, const Student& student) {
        return os << student.firstName << " " << student.middleName << " " << student.lastName << " " << student.age;
    }

    friend istream& operator >>(istream& in, Student& student) {
        return in >> student.firstName >> student.middleName >> student.lastName >> student.age;
    }

    void operator = (const class Student student) {
        firstName = student.firstName;
        middleName = student.middleName;
        lastName = student.lastName;
        age = student.age;
    }

    bool operator > (const class Student student) {
        if (age > student.age) {
            return true;
        }
        return false;
    }

    bool operator < (const class Student student) {
        if (age < student.age) {
            return true;
        }
        return false;
    }

    bool operator == (const class Student student) {
        if ((age == student.age) && (firstName == student.firstName) && (middleName == student.middleName) && (lastName == student.lastName)) {
            return true;
        }
        return false;
    }

    bool operator != (const class Student student) {
        if ((age != student.age) && (firstName != student.firstName) && (middleName != student.middleName) && (lastName != student.lastName)) {
            return true;
        }
        return false;
    }
};


#endif //LAB3_STUDENT_H
