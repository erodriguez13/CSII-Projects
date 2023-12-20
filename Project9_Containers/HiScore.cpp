//
//  HiScore.cpp
//  RodriguezEProj9
//
//  Created by Eduardo Rodriguez on 4/25/23.
//

#include "HiScore.hpp"
HiScore::HiScore(){// default constructor
    name = "Anonymous";
    score = 0;
}

HiScore::HiScore(string new_name, int new_score){// constructor for HiScore with name and score parameters and current local time
    name= new_name;
    score= new_score;
   time_t tim= time(0);// date/ time stamps HiScore
    
    date = localtime(&tim);
    
    // source for snippet of getting local date: https://youtu.be/i1MeXMciy6Q
}

string HiScore::get_name(){ // returns name of HiScore object
    return name;
}

int HiScore::get_score(){ // returns score of HiScore object
    return score;
}

 bool operator < (const HiScore& H1, const HiScore& H2) // return true if H1 is less than H2
{
    if (H1.score < H2.score) return true;
    else return false;
    
}

 bool operator > (const HiScore& H1, const HiScore& H2) // return true if H1 is greater than H2
{
    if (H1.score > H2.score) return true;
    else return false;
}
/*
 bool operator == (const HiScore& H1, const HiScore& H2) // return true if H1 is equal than H2
{
    if (H1.score == H2.score) return true;
    else return false;
}

 bool operator != (const HiScore& H1, const HiScore& H2) // return true if H1 is not equal than H2
{
    if (H1.score != H2.score) return true;
    else return false;
}
*/

ostream& operator << (ostream& out, HiScore& H1){ // outputs name, score value and standard date of H1 high score
    
    out << "Name: " <<  H1.name << " " ; // prints name
    out << "Score: " << H1.score << " " ; // prints score
    out << "Date: " << H1.date->tm_mon << " / " <<H1.date->tm_mday << " / " << H1.date->tm_year % 100 << " " ;// prints date of object
    out << H1.date->tm_hour << ":" << H1.date->tm_min  << endl << endl;
    return out; // and lastly we print time of object
    
}
/*
istream& operator >> (istream& in, HiScore& H1) // inputs name, score value and time stamps high score
{
    try{
        cout<< "Enter new name" << endl;
        
        in >> H1.name;
        
        cout<< "Enter new score" << endl;
        string raw_score;
        in >> raw_score;
        verify_new_score(raw_score);
        H1.score =stoi(raw_score);
        
        time_t tim= time(0);
        H1.date = localtime(&tim);
    }  catch(Score_Mistake)
    {cout << "***Please enter a valid score between 100 and 10000" << endl << endl;}
    
    return in;
}
*/

void print_menu(){ // prints menu for user
    cout << "**************** MENU ****************" << endl << endl;
    cout<< " Please enter the number for your option" << endl;
    cout << "1   Add HiScore" << endl;

    cout << "2   List HiScores" << endl;

    cout << "3   Quit" << endl<< endl;
    
    cout << "**************** End of MENU ****************" << endl << endl;
    cout << "Enter your CHOICE: " ;
}

void print_scores(vector<HiScore> v)// prints vector containe in descending order
{int place = 1;
    sort (v.begin(), v.end());
   vector<HiScore>:: reverse_iterator rp;// set up to reverse iterater to print out descending objects
    for (rp = v.rbegin(); rp !=v.rend(); rp++) // functin goes from last to first
    {
        cout << place << ": " << *rp << endl;
        place ++;
    }
}

void verify_new_score(string new_score)// function throws exception if new_score is not in correct format
{if (!is_correct_format(new_score))
     {throw Score_Mistake();}
else {cout<< "Score received & verified!" << endl;}
}
     

bool is_correct_format(string new_score){// returns true if new_score is a string between 100 and 10000
    for (int i=0; i<new_score.size(); i++ )
    {
        if (!(isdigit(new_score.at(i))))// check to see if each char in new_score is a digit
            return false;
    }
    
    if ((stoi(new_score)< 100)||(stoi(new_score) >10000))// check to see if new_score is within range
        return false;
    
    else {
        return true;}
      
    }
