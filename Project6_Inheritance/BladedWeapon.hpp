//
//  BladedWeapon.hpp
//  RodriguezEduardoProj6
//
//  Created by Eduardo Rodriguez on 3/19/23.
//

#ifndef BladedWeapon_hpp
#define BladedWeapon_hpp
#include <stdio.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <ctime>

using namespace std;

class BladedWeapon {// base class of blade weapons
    
private:
    string name;// name of weapon
    int cost; // cost to purchase weapon in silver pieces
    string damage;// list the boundaries of how much damage may be possible
//i.e. "short sword"
//i.e. 2 meaning 2 silver pieces
//i.e. "1d6" meaning roll 1 six-sided dice for damage
public:
// constructors
    BladedWeapon();// default constructor for base weapon
    BladedWeapon(string newName, int newCost, string newDamage); // constructor for base weapon requiring name, cost and damage paramaters
// getters and setters
    void setName(string newName); // allows to mutate the private variable name
    void setCost(int newCost); //allows to mutate the private variable cost
    void setDamage(string newDamage); //allows to mutate the private variable damage
    string getName(); // returns the string vaule in private variable name
    int getCost(); // returns the int vaule in private variable cost
    string getDamage();  // returns the string vaule in private variable damage
    virtual int rollDamage(); //using a random number generator, return a value; 1d4 returns 1 thru 4,1d6 returns 1 thru 6 and so on
    
};


class Dagger : public BladedWeapon {
    public:
    virtual int rollDamage();// returns a random number between 1 and 4
    Dagger();// default constructor for derived weapon class Dagger
    Dagger(string newName);//  constructor for derived weapon class Dagger that allows to set the name
    Dagger(string newName, int newCost, string newDamage);//constructor for derived weapon class Dagger that allows to set all three variables
};

class Rapier : public BladedWeapon  {
public:
    virtual int rollDamage();// returns a random number between 1 and 6
    Rapier();// default constructor for derived weapon class Rapier
    Rapier(string newName);//  constructor for derived weapon class Rapier that allows to set the name
    Rapier(string newName, int newCost, string newDamage);//constructor for derived weapon class Rapier that allows to set all three variables
};


class LongSword : public BladedWeapon  {
public:
    virtual int rollDamage();// returns a random number between 1 and 8
    LongSword();// default constructor for derived weapon class LongSword
    LongSword(string newName);//  constructor for derived weapon class LongSword that allows to set the name
    LongSword(string newName, int newCost, string newDamage);//constructor for derived weapon class LongSword that allows to set all three variables
};

void printInfo(BladedWeapon weapon);// prints out the information(name, damage, and cost) of the paramenter BladedWeapon



#endif /* BladedWeapon_hpp */
