#include <iostream>
#include <cstdlib>
#include <ctime>
#include "person.h"

Person::Person(string f, string l) : fname(f), lname(l)
{
}

void Person::Show() const
{
    cout << fname << "." << lname << endl;
}

Gunslinger::Gunslinger::Gunslinger(string f, string l, int n) : Person(f, l), nick(n)
{
}

double Gunslinger::Draw()
{
    srand(time(0));
    return rand() % 60;
}

void Gunslinger::Show() const
{
    Person::Show();
    cout << "Nick: " << nick << endl;
}

Card PockerPlayer::Draw() const
{
    Card temp;
    srand(time(0));
    temp.number = rand() % 52;
    temp.suite = Card::SUITE(rand() % 4);
    return temp;
}



