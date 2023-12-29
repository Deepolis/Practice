/* BaseCharacter could be called multiple time. The follows lines state that if it is not
defined(which it wont be when called the first time), then define it, else do not define again*/
#ifndef BASE_CHARACTER_H 
#define BASE_CHARACTER_H

#include <string>
#include <iostream>

using namespace std;

class Base
{
public: //can be used anywhere in the program
    Base(int Age, int gradeValue); //sets up the class. initializes varibles and performs tasks we assign.
 
    Base(const string NickName, short Age);

    /*creates a deep copy. deep copy pointers point to their own original
    elements therefore dereferencing a deep copy element will not create a remaining 
    dangling pointer.*/
    Base(const Base& BaseCopy);
    
    Base(Base&& MoveBase); //Move constructor

    ~Base(); //deals with freeing memory and closing files and/or connection.

    Base& operator=(const Base& Other) // assignment operator typically a member function
    {
        if (this != &Other) // if this(pointer) does not point to the address of the copy
        {
            this->height = Other.height; //assign the height of Other into "this" object
        }
        return *this;
    }

    Base& operator=(const Base&& Other); //overload move assignment

    short getAge() { return Age; }
    short getLifespan() {return Lifespan; }
    short height;
    int* grade{};
    static int GetBaseCount() {return BaseCount;}

protected:
    
private: //can only be accessed by People
    short Age{};
    const short Lifespan{};
    string NickName{};
    inline static int BaseCount{0}; // static can only be declared in the class.

};

#endif
