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
    Base(int Age);
    short getAge() { return Age; }
    short getLifespan() {return Lifespan; }
protected:
    
private: //can only be accessed by People
    short Age{};
    short Lifespan{};

};

#endif
