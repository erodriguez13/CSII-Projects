//  main.cpp
//  RodriugezEProject7
//  Created by Eduardo Rodriguez on 4/8/23.
//

#include <iostream>
#include <string>
using namespace std;
#include "TimeFormatMistake.hpp"

int main() {
    string usersTime;
    char choice= 'y';
    while (choice== 'y' || choice== 'Y')// loop to allow user to repeat the use of function
    {
        try
        { cout<< "Enter time in 24-Hour notation (\"HH:MM\"): "<< endl;
        cin>> usersTime;
            tfToTwelve (usersTime);
        }
        catch (TimeFormatMistake) {
            cout<< "\n There is no such time as  "<< usersTime << endl;
        }
        
        cout<< "Again? (y/n)"<< endl;
        string choiceS;
        cin>>choiceS;
        choice= choiceS.at(0);
        cout<< endl;
    }
    
    cout<< "End of progam"<< endl;
    
}
