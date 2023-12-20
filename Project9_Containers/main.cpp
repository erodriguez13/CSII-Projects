//
//  main.cpp
//  RodriguezEProj9
//  Created by Eduardo Rodriguez on 4/25/23.
//
#include "HiScore.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

int main() {
    vector <HiScore> high_scores; // create vector container to hold HiScore objects
    // set up five HiScores that are not arranged in order
    // E__ (5th highest)l, D__ (4th), B___(2nd), A__(1st) , C__ (3rd)
    HiScore H1( "Elm", 500); // creates H1 object of type HiScore
    high_scores.push_back(H1); // adds H1 to high_scores
    
    HiScore H2 ("Dan", 1000);
    high_scores.push_back(H2);
    
    HiScore H3 ("Ben", 1500);
    high_scores.push_back(H3);
    
    HiScore H4 ("Ace", 2000);
    high_scores.push_back(H4);
    
    HiScore H5 ("Carl", 1200);
    high_scores.push_back(H5);
    
    cout << "WELCOME\n \n";
    
    char choice= '1';
    while (choice != '3' )// loop to allow user to repeat the use of function
    {
        
        print_menu();// prints 3 choices
        string raw_choice;
        cin >> raw_choice;// gets string
        choice= raw_choice.at(0);// grabs first char from string and discard the rest
        
        
        
        switch (choice)
        {
            case '0':
                cout << endl;
                break;
                
            case '1':
            {cout << "You have chosen to add a high score" << endl << endl;
                
                cout << "Enter your NAME: " <<endl;
                           
                cin.ignore();
                string new_name; // allow user to input name
                //cin >> new_name;
                getline(cin, new_name);
                cin.ignore();// source for fix to issue https://youtu.be/gj2JClHEUvQ
                // initially the program read mutliple strings at once when inputted into one line
                cout << "\nEnter your SCORE (100 to 10000):" << endl;
                
                string new_score_amount;// allow user to input new score as a string so that exception can be thrown if not correct format
                cin >> new_score_amount;
                
                
         
                    try{
                verify_new_score(new_score_amount);// throws an score_ mistake exception if score is not a number or is not within 100 and 10,000
                
                HiScore  new_score(new_name, stoi(new_score_amount)); // skipped if there is a score_mistake
               // creates new HiScore with entered parameters
                        
                high_scores.push_back(new_score);// skipped if there is a score_mistake
                // adds new HiScore to container high_scores
                
                cout << "You have entered:" << high_scores[high_scores.size()-1]<< endl;
                  }catch(Score_Mistake) // catches score_mistake
                  {cout << "***Please enter a valid score between 100 and 10000" << endl << endl;}
                
                break;
            }
                
           case '2':// print scores descending order
                //from A__(the highest) to D___ (the lowest)with the new score in between
                cout << "\nYou have chosen to list the high scores:" << endl << endl;
                
                print_scores(high_scores);
                
                break;
                
            case '3': // ends program
                cout << "Thank you! Good bye! " << endl;
                
                break;
                
            default:
                cout<< endl<< endl;
                cout<< choice << " is not a valid choice. Try inputting '1', '2' or '3\'" << endl;
                cout<< endl<< endl;
                break;
            
                
        }
         
        
    }
 
    cout << endl<< endl;
    
    
    cout << "Good Bye World" << endl; // end of program (successfuly)
}
