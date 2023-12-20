//
//  main.cpp
//  RodriguezEduardoProj6
//  Created by Eduardo Rodriguez on 3/19/23.
//Last Update 3/31/23

#include <iostream>
#include "BladedWeapon.hpp"
using namespace std;

int main() {
    // Testing default constructor of base class
    BladedWeapon weapon1;
    cout<<"Object Type: "<< typeid(weapon1).name()<< endl;
    printInfo(weapon1);
    
    cout<< "\n Testing random damage of " << weapon1.getName() << " with " <<weapon1.getName()<<" ";
    cout<< weapon1.rollDamage()<< endl<<endl;
    
    // Testing 3 parameter constructor of base class
    string bladeName = " Steak Knife";
    int costAmount= 7;
    string damageAmount= "1d5";
    BladedWeapon weapon2(bladeName, costAmount, damageAmount);
    cout<< "Object Type: "<< typeid(weapon2).name()<< endl;
    printInfo(weapon2);
    cout<< "Example damage: "<< weapon2.rollDamage()<< endl<<endl;

    // Testing default constructor of Dagger
    string daggerName="Medieval Dagger";
    Dagger weapon3(daggerName);
    cout<< "Object Type: "<< typeid(weapon3).name()<< endl;
    printInfo(weapon3);
    cout<< "Example damage: "<< weapon3.rollDamage()<< endl<<endl;
    
    // Testing default constructor of Rapier
    string rapierName = "R.A.P";
    Rapier weapon4(rapierName);
    cout<< "Object Type: "<< typeid(weapon4).name()<< endl;
    printInfo(weapon4);
    cout<< "Example damage: "<< weapon4.rollDamage()<< endl<<endl;
    

    // Testing default constructor of Longsword
    string longswordName = "Claymore";
    LongSword weapon5(longswordName);
    cout<< "Object Type: "<< typeid(weapon5).name()<< endl;
    printInfo(weapon5);
    cout<< "Example damage: "<< weapon5.rollDamage()<< endl<<endl;
    
    
    // User creates blades and names them
 
   
    char choice = 'y';
    
    cout<< "\nWould would you like to name your BladedWeapon: ";
    cin>> choice;

    if(choice=='y' ||choice=='Y')
    {
        cout<< "\nEnter your Bladed Weapon Name: ";
        string userWpName;
        cin>> userWpName;
        
        BladedWeapon UserName1(userWpName, 2, "1d6");
        printInfo(UserName1);
    }
    else{BladedWeapon UserName1;
        printInfo(UserName1);
    }
   
    

    // Testing constructor of Rapier
    cout<< "\nWould would you like to name your Rapier: ";
    cin>> choice;

    if(choice=='y' ||choice=='Y')
    {
        cout<< "\nEnter your Rapier  Name: ";
        string userRpName;
        cin>> userRpName;
        
        Rapier UserName2(userRpName, 20, "1d6");
        printInfo(UserName2);
    }
    else{Rapier UserName2;
        printInfo(UserName2);
    }
    
    // Testing constructor of Dagger
    cout<< "\nWould would you like to name your Dagger: ";
    cin>> choice;

    if(choice=='y' ||choice=='Y')
    {
        cout<< "\nEnter your Dagger  Name: ";
        string userRpName;
        cin>> userRpName;
        
        Dagger UserName3(userRpName, 20, "1d6");
        printInfo(UserName3);
    }
    else{Dagger UserName3;
        printInfo(UserName3);
    }
    
    // Testing constructor of Longsword
    cout<< "\nWould would you like to name your LongSword: ";
    cin>> choice;

    if(choice=='y' ||choice=='Y')
    {
        cout<< "\nEnter your LongSword  Name: ";
        string userLSName;
        cin>> userLSName;
        
        LongSword UserName4(userLSName, 20, "1d6");
        printInfo(UserName4);
    }
    else{LongSword UserName4;
        printInfo(UserName4);
    }
    
}
