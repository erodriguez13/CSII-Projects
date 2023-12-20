//
//  Money.hpp
//  RodriguezEduardoProj4
//
//  Created by Eduardo Rodriguez on 2/28/23.
//
#include <iostream>
#ifndef Money_hpp
#define Money_hpp
using namespace std;

#include <stdio.h>

int digitToInt(char c);
// Used in the definition of the overloaded input operator>>
class Money{
public:
//public variables
    

//Constructors
    Money (long dollars, int cents);
    Money (long dollars);
    Money ();// default constructors
      
//Friend Functions
    friend Money operator +(const Money& amount1, const Money& amount2);// adds two amounts of Type Money
    
    friend Money operator * (const Money& amount1, const double decimal);// multiplies an all cents from object of type Money and a number of type double

    friend Money operator -(const Money& amount1, const Money& amount2);//subtracts two amounts of Type Money
    
    friend Money operator -(const Money& amount);//returns the negative value of an amount of type Money
    
    friend bool operator ==(const Money& amount1, const Money& amount2);// returns true if two amounts of type Money are equal
    
    friend bool operator <(const Money& amount1, const Money& amount2);// returns true if first amount is less than second amount of type Money
    
    friend bool operator >(const Money& amount1, const Money& amount2);// returns true if first amount is more than second amount of type Money
        
    friend bool operator <=(const Money& amount1, const Money& amount2);// returns true if first amount is less than or equal to second amount of type Money
    
    friend bool operator >=(const Money& amount1, const Money& amount2);// returns true if first amount is greater than or equal to second amount of type Money
   
    friend istream& operator >> (istream & ins, Money& amount);
    //Overloads the >> operator so it can be used to input values of type Money.
    //Notation for inputting negative amounts is as in −$100.00.
    //Precondition: If ins is a file input stream, then ins has already been
    //connected to a file.
    
    friend ostream& operator<<(ostream& outs, const Money& amount);
    //Overloads the << operator so it can be used to output values of type Money.
    //Precedes each output value of type Money with a dollar sign.
    //Precondition: If outs is a file output stream, then outs has already been connected to a file.
   
//Functions
    double getValue() const;// returns the amount of money recorded in the object of type Money
    
    Money percent (int percentFigure) const;
    // returns a percentage of the money amount in the calling object
  
    
private:
    long allCents;
};


#endif /* Money_hpp */
