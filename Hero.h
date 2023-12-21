#ifndef HERO_H
#define HERO_H

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

#endif