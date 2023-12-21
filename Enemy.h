#ifndef HERO_H
#define HERO_H

#include <string>
#include <iostream>
#include "BaseCharacter.h"
#include "Hero.h"

using namespace std;

class Enemy : public Base
{
public:
    Enemy();
    friend class Hero; // friend class can access protected and private members,

protected:

private:
};

#endif