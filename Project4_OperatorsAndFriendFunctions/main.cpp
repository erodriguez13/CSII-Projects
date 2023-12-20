//  main.cpp
//  RodriguezEduardoProj4
//  Created by Eduardo Rodriguez on 2/28/23.

#include "Money.hpp"
#include <cctype>
#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;

int main() {
  cout << "******** Testing (<<), (>>) ********" << endl;

  Money amount;
  ifstream inStream;
  ofstream outStream;

  inStream.open("infile.txt");
  if (inStream.fail()) {
    cout << "Input file opening failed.\n";
    exit(1);
  }
  outStream.open("outfile.txt");
  if (outStream.fail()) {
    cout << "Output file opening failed.\n";
    exit(1);
  }
  inStream >> amount;
  outStream << amount << " copied from the file infile.txt.\n";
  cout << amount << " copied from the file in file.txt.\n";
  cout << endl << endl;
  inStream.close();
  outStream.close();

  // Test: Constructor
  cout << "******** Testing Constructors ********" << endl;
  Money constructor_dol_cen(100, 10);
  Money constructor_dol(3500000);
  Money constructor_default;
  Money neg_money(-115);

  cout << "The value of the First Constructor with dollars and cents (100, "
          "10)is: "
       << constructor_dol_cen << endl;
  cout << "The value of constructor with dollars(3500000) is: "
       << constructor_dol << endl;
  cout << "The value of defualt constructor is: " << constructor_default << endl
       << endl;

  cout << "******** Testing getValue() and percent() ********" << endl;
  cout << "The value of the First Constructor with dollars and cents (100, "
          "10)is: $"
       << constructor_dol_cen.getValue() << endl;
  cout << "7% of value of constructor with dollars and cents (100, 10) is: "
       << constructor_dol_cen.percent(7) << endl;
  cout << "10% of value of constructor with dollars and cents (100, 10) is: "
       << constructor_dol_cen.percent(10) << endl;
  cout << "200% of value of constructor with dollars and cents (100, 10) is: "
       << constructor_dol_cen.percent(200) << endl;

  cout << "7% of value of constructor with dollars (3500000) is: "
       << constructor_dol.percent(7) << endl;
  cout << "10% of value of constructor with dollars (3500000) is: "
       << constructor_dol.percent(10) << endl;
  cout << "15% of value of constructor with dollars and cents (3500000) is: "
       << constructor_dol.percent(15) << endl
       << endl
       << endl;

  // Test: operators
  cout << "******** Testing (+), (-),(-//negative) ********" << endl;
  Money michael_s(100, 99);
  cout << "Michael has " << michael_s << " in his wallet." << endl;
  cout << "The value of the sum of the first Constructor's amount($100.10) and "
          "Michael's money ($100.99) is: "
       << constructor_dol_cen + michael_s << endl;
  cout << "The value of the difference of the first Constructor's "
          "amount($100.10) and Michael's ($100.99) is: "
       << constructor_dol_cen - michael_s << endl;
  cout << "The negative value of the first Constructor's amount($100.10) is: "
       << -constructor_dol_cen << endl;
  cout << "The negative  value of the neg_money amount(-$115) is: "
       << -(neg_money) << endl
       << endl
       << endl;

  // Test : Equality and Inequality functions
  cout << "******** Testing (==) ********" << endl;
  Money constructor_equal(100, 10);
  Money constructor_less(85);
  Money constructor_more(220);

  cout << "(First Constructor's money($100.10) == Constructor_equal's money "
          "($100.10)): ";
  if (constructor_dol_cen == constructor_equal) {
    cout << "True" << endl;
  } else
    cout << "False" << endl;

  cout << "(First Constructor's money($100.10) == Constructor_less's money "
          "($85)): ";
  if (constructor_dol_cen == constructor_less) {
    cout << "True" << endl;
  } else {
    cout << "False" << endl;
  }

  cout << "(First Constructor's money($100.10) == Constructor_more's money "
          "($220)): ";
  if (constructor_dol_cen == constructor_more) {
    cout << "True" << endl;
  } else {
    cout << "False" << endl << endl << endl;
  }

  // less than
  cout << "******** Testing (<) ********" << endl;

  cout << "(First Constructor's money ($100.10) < Constructor_equal's money "
          "($100.10)): ";
  if (constructor_dol_cen < constructor_equal) {
    cout << "True" << endl;
  } else
    cout << "False" << endl;

  cout << "(First Constructor's money ($100.10) < Constructor_less's money "
          "($85)): ";
  if (constructor_dol_cen < constructor_less) {
    cout << "True" << endl;
  } else {
    cout << "False" << endl;
  }

  cout << "(First Constructor's money ($100.10) < Constructor_more's money "
          "($220)): ";
  if (constructor_dol_cen < constructor_more) {
    cout << "True" << endl << endl << endl;
  } else {
    cout << "False" << endl << endl << endl;
  }

  // less than or equal to
  cout << "******** Testing (<=) ********" << endl;

  cout << "(First Constructor's money ($100.10) <= Constructor_equal's money "
          "($100.10)): ";
  if (constructor_dol_cen <= constructor_equal) {
    cout << "True" << endl;
  } else
    cout << "False" << endl;

  cout << "(First Constructor's money ($100.10) <= Constructor_less's money "
          "($85)): ";
  if (constructor_dol_cen <= constructor_less) {
    cout << "True" << endl;
  } else {
    cout << "False" << endl;
  }

  cout << "(First Constructor's money ($100.10) <= Constructor_more's money "
          "($220)): ";
  if (constructor_dol_cen <= constructor_more) {
    cout << "True" << endl << endl << endl;
  } else {
    cout << "False" << endl << endl << endl;
  }

  // greater than**********************
  cout << "******** Testing (>) ********" << endl;
  cout << "(First Constructor's money ($100.10) > Constructor_equal's money "
          "($100.10)): ";
  if (constructor_dol_cen > constructor_equal) {
    cout << "True" << endl;
  } else
    cout << "False" << endl;

  cout << "(First Constructor's money ($100.10) > Constructor_less's money "
          "($85)): ";
  if (constructor_dol_cen > constructor_less) {
    cout << "True" << endl;
  } else {
    cout << "False" << endl;
  }

  cout << "(First Constructor's money ($100.10) > Constructor_more's money "
          "($220)): ";
  if (constructor_dol_cen > constructor_more) {
    cout << "True" << endl << endl;
  } else {
    cout << "False" << endl << endl << endl;
  }

  // greater than or equal to **********************
  cout << "******** Testing (>=) ********" << endl;

  cout << "(First Constructor's money($100.10) >= Constructor_equal's money "
          "($100.10)): ";
  if (constructor_dol_cen >= constructor_equal) {
    cout << "True" << endl;
  } else
    cout << "False" << endl;

  cout << "(First Constructor's money($100.10) >= Constructor_less's money "
          "($85)): ";
  if (constructor_dol_cen >= constructor_less) {
    cout << "True" << endl;
  } else {
    cout << "False" << endl;
  }

  cout << "(First Constructor's money($100.10) >= Constructor_more's money "
          "($220)): ";
  if (constructor_dol_cen >= constructor_more) {
    cout << "True" << endl << endl << endl;
  } else {
    cout << "False" << endl << endl << endl;
  }

  return 0;
}
