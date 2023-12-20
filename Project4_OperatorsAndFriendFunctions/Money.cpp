//  Money.cpp
//  RodriguezEduardoProj4
//  Created by Eduardo Rodriguez on 2/28/23.

#include "Money.hpp"

int digitToInt(char c) { return (static_cast<int>(c) - static_cast<int>('0')); }

Money operator+(const Money &amount1, const Money &amount2) {
  Money temp;
  temp.allCents = amount1.allCents + amount2.allCents;
  return temp;
}

Money operator-(const Money &amount1, const Money &amount2) {
  Money temp;
  temp.allCents = amount1.allCents - amount2.allCents;
  return temp;
}

Money operator*(const Money &amount1, const double decimal) {
  Money temp;
  temp.allCents = amount1.allCents * decimal;
  return temp;
}

Money operator-(const Money &amount) {
  Money temp;
  temp.allCents = -amount.allCents;
  return temp;
}

bool operator==(const Money &amount1, const Money &amount2) {
  return amount1.allCents == amount2.allCents;
}

bool operator<(const Money &amount1, const Money &amount2) {
  return amount1.allCents < amount2.allCents;
}

bool operator>(const Money &amount1, const Money &amount2) {
  return amount1.allCents > amount2.allCents;
}

bool operator<=(const Money &amount1, const Money &amount2) {
  return amount1.allCents <= amount2.allCents;
}

bool operator>=(const Money &amount1, const Money &amount2) {
  return amount1.allCents >= amount2.allCents;
}

Money::Money(long dollars, int cents) {
  if (dollars * cents < 0) // If one is negative and the other positive
  {
    cout << "Illegal values for dollars and cents.\n";
    exit(1);
  }
  allCents = dollars * 100 + cents;
}

Money::Money(long dollars) { allCents = dollars * 100; }

Money::Money() { allCents = 0; }

double Money::getValue() const { return allCents * 0.01; }

istream &operator>>(istream &ins, Money &amount) {
  // Overloads the >> operator so it can be used to input values of type Money.
  // Notation for inputting negative amounts is as in −$100.00.
  // Precondition: If ins is a file input stream, then ins has already been
  // connected to a file.
  char oneChar, decimalPoint, digit1, digit2; // digits for the amount of cents
  long dollars;
  int cents;
  bool negative; // set to true if input is negative
  ins >> oneChar;
  if (oneChar == '-') {
    negative = true;
    ins >> oneChar; // read'$'
  } else
    negative = false;
  // input is legal, then onceChar == '$'
  ins >> dollars >> decimalPoint >> digit1 >> digit2;
  if (oneChar != '$' || decimalPoint != '.' || !isdigit(digit1) ||
      !isdigit(digit2)) {
    cout << "Error illegal form for money input\n";
    exit(1);
  }
  cents = digitToInt(digit1) * 10 + digitToInt(digit2);
  amount.allCents = dollars * 100 + cents;
  if (negative)
    amount.allCents = -amount.allCents;
  return ins;
}

ostream &operator<<(ostream &outs, const Money &amount) {
  // Overloads the << operator so it can be used to output values of type Money.
  // Precedes each output value of type Money with a dollar sign.
  // Precondition: If outs is a file output stream,
  // then outs has already been connected to a file.
  long positive_cents, dollars, cents;
  positive_cents = labs(amount.allCents);
  dollars = positive_cents / 100;
  cents = positive_cents % 100;
  if (amount.allCents < 0)
    outs << "− $" << dollars << '.';
  else
    outs << "$" << dollars << '.';
  if (cents < 10)
    outs << '0';
  outs << cents;
  return outs;
}

Money Money::percent(int percentFigure) const {
  // returns a percentage of the money amount in the calling object
  Money temp;
  temp = this->allCents;

  return ((temp) * (double)percentFigure * .01);
}
