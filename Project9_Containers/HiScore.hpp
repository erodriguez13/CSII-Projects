//
//  HiScore.hpp
//  RodriguezEProj9
//
//  Created by Eduardo Rodriguez on 4/25/23.
//

#ifndef HiScore_hpp
#define HiScore_hpp

#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <ctime>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

class HiScore{
private:
    string name;// stores the name of the person with highest score
    int score; // stores high score
    tm *date; // source of snippet https://www.youtube.com/watch?v=M1E3roUNTMY
    
public:
    string get_name(); // returns name of high scorer
    
    int get_score(); // returns high score of object
    
    HiScore(); // default constructor
    
    HiScore(string new_name, int new_score);// constructor for HiScore with name and score parameters and current local time
    
    friend bool operator < (const HiScore& H1, const HiScore& H2); // return true if H1 is less than H2
    
    friend bool operator > (const HiScore& H1, const HiScore& H2); // return true if H1 is greater than H2
    
    //friend bool operator == (const HiScore& H1, const HiScore& H2); // return true if H1 is equal than H2
    
    //friend bool operator != (const HiScore& H1, const HiScore& H2); // return true if H1 is not equal than H2

    friend ostream& operator << (ostream& out, HiScore& H1); // outputs name, score value and standard date of H1 high score

    friend istream& operator >> (istream& in, HiScore& H1); // inputs name, score value and time stamps high score
    friend void verify_new_score(HiScore new_score);
};

class Score_Mistake{};//exception class to be thrown if the score is not between 100 and 10000

void print_menu(); // prints menu for user

void verify_new_score(string new_score); // if score is not between 100 and 10000 or an int, excpetion is thrown

bool is_correct_format(string new_score); // return true if new_score is between 100 and 10000, false otherwise

void print_scores(vector<HiScore> v); // prints vector containe in descending order


#endif /* HiScore_hpp */
