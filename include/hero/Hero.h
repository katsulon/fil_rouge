#pragma once

#include <iostream>
#include "../../src/hero/weapon/Weapon.cpp"

using namespace std;

namespace He_ARC::rpg
{
    class Hero 
    {
    protected:
        int strength;
        int agility;
        int intelligence;
        double hp;
        string name;
        Weapon *weapon = nullptr;
    public:
        Hero();
        Hero(int,int,int,double,string, Weapon *weapon);
        //Hero(const Hero&); //not necessary
        virtual void interact(const Hero&);
        void show() const;
        friend ostream& operator<<(ostream&, const Hero&);
        //virtual ~Hero();
    };
}