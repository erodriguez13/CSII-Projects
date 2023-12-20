//
//  BladedWeapon.cpp
//  RodriguezEduardoBladedWeapon6
//
//  Created by Eduardo Rodriguez on 3/19/23.
//

#include "BladedWeapon.hpp"

BladedWeapon::BladedWeapon(){
    name= "Short Sword";
    cost=2;// 2 silver pieceds
    damage= "1d6";// roll 1 six-sided dice for damage
    }

BladedWeapon::BladedWeapon(string newName, int newCost, string newDamage){
    name= newName;
    cost= newCost;// 2 silver pieceds
    damage= newDamage;// roll 1 six-sided dice for damage
}
// getters and setters
void BladedWeapon::setName(string newName){
    name=newName;}

void BladedWeapon::setCost(int newCost){
    cost=newCost;}

void BladedWeapon::setDamage(string newDamage){
    damage=newDamage;}

string BladedWeapon::getName(){return name;}

int BladedWeapon::getCost(){return cost;}

string BladedWeapon::getDamage(){return damage;}

 int  BladedWeapon::rollDamage(){
     damage= getDamage();
     char lowerC= damage[0];
     char upperC= damage[2];
      
     int lowerNumber = (int)(lowerC-48);
     int upperNumber = (int)(upperC-48);
     srand(time(0));
    int die= (rand() %upperNumber) + lowerNumber;
     return die;
    }

//Dagger  Member Functions

 int Dagger :: rollDamage(){
    int die= (rand() %4) + 1;
     return die;
}
Dagger :: Dagger(): BladedWeapon("Dagger", 2, "1d4"){}

Dagger :: Dagger(string name): BladedWeapon(name, 2, "1d4"){}

Dagger:: Dagger(string newName, int newCost, string newDamage):  BladedWeapon(newName, newCost, newDamage){}

// Rapier Member Functions

int Rapier :: rollDamage(){
   int die= (rand() %6) + 1;
    return die;
}
Rapier :: Rapier(): BladedWeapon("Rapier", 20, "1d6"){}

Rapier :: Rapier(string name): BladedWeapon(name, 20, "1d6"){}

Rapier:: Rapier(string newName, int newCost, string newDamage): BladedWeapon(newName, newCost, newDamage){}

// LongSword Member Functions

int LongSword :: rollDamage(){
   int die= (rand() %8) + 1;
    return die;
}

LongSword :: LongSword(): BladedWeapon("LongSword", 10, "1d8"){}

LongSword :: LongSword(string name): BladedWeapon(name, 10, "1d8"){}

LongSword :: LongSword(string newName, int newCost, string newDamage):  BladedWeapon(newName, newCost, newDamage){}

void printInfo(BladedWeapon weapon){
    cout << "The name of this blade is: "<< weapon.getName()<<endl;
    cout << "Cost: "<< weapon.getCost()<<endl;
    cout << "Damage: "<< weapon.getDamage()<< endl;
}
