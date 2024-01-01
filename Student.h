#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>
#include "BaseCharacter.h"

using namespace std;

class Student : public Base
{
public:
     virtual void greeting() override; 
     /*Derived classes inherit the vptr from the Base class
     and creates its own vtable. Override sets the ptr to a new instance of the function;
     not overriding sets the derived ptr to the original Base class function*/

protected:

private:

};

#endif