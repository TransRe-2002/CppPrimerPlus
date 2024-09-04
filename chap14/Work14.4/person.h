#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

using namespace std;

class Person
{
private:
    string fname;
    string lname;
public:
    Person() : fname("no name"), lname("no name") {};
    Person(string f, string l);
    virtual ~Person() {};
    virtual void Show() const;
};

class Gunslinger : virtual public Person {
private:
    int nick;
public:
    Gunslinger() : Person(), nick(0) {};
    Gunslinger(string f, string l, int n);
    ~Gunslinger() {};
    double Draw();
    void Show() const;
};

struct Card
{
    enum SUITE {SPADE, HEART, DIAMOND, CLUB};
    SUITE suite;
    int number;
};

class PockerPlayer : virtual public Person
{
public:
    ~PockerPlayer() {};
    Card Draw() const;
};

class BadDude : public Gunslinger, public PockerPlayer
{
public:
    double GDraw() const;
    int CDraw() const;
    void Show() const;
};

#endif
