#include <string>
#include <iostream>
#include "BaseCharacter.h"

using namespace std;

Base::Base(const string NickName, short Age) // A function called Base(constructor) from inside the Base class scope.
{
    cout << "My nickname is " << NickName << " and I am " << Age << " years old" << endl;
    this->NickName = NickName; //this is a pointer for the current object.
    this->Age = Age;
    BaseCount++;
}

Base::Base(int Age, int gradeValue) // A function called Base(constructor) from inside the Base class scope.
{
    cout << "I am " << Age << " years old." << endl;
    grade = new int; // dynamically allocate new memory for grade containing 16.
    *grade = gradeValue; //dereference grade then dereference grade because its a pointer
    cout << gradeValue << endl;
    BaseCount++;
}

Base::Base(Base&& MoveBase) : grade{MoveBase.grade} // copying the address of grade
{
    /*We initialize the move constructor grade to null ptr because you dont want to 
    delete the main grade from Base*/
    MoveBase.grade = nullptr; 
}

Base::Base(const Base& BaseCopy)
{
    grade = new int{16}; // dynamically allocate new memory for grade containing 16.
    *grade = *BaseCopy.grade; //dereference grade then dereference grade because its a pointer
    cout << grade << endl;
    BaseCount++;
}

Base::~Base()
{
    delete grade;
    BaseCount--;
}
