#include <string>
#include <iostream>
#include "BaseCharacter.h"

using namespace std;

class Hero : public Base
{
public:
    Hero();

protected:

private:
    short Age{};
    short Lifespan{};
};