
//  TimeFormatMistake.cpp
//  RodriugezEProject7
//  Created by Eduardo Rodriguez on 4/9/23.


#include "TimeFormatMistake.hpp"


void tfToTwelve (string tf_time) {
   if (out_of_format(tf_time))
    {throw TimeFormatMistake();}
    
    int hours = stoi (tf_time.substr(0,2));// retrieve hours from string by typecasting
    int minutes = stoi (tf_time.substr(3,4)); // retrieve minutes from string by typecasting
    string AMoPM; // string variable that assigns A.M or P.M 
    
    if (hours >= 12) AMoPM = " P.M" ; //set AM or PM acc
    else AMoPM = " A.M.";
    
    if (hours >= 13) hours -= 12; // subtracts 12 from afteroon hours greater than 12 turning 13 hrs, 14 hrs etc to 1pm, 2pm etc
    if (hours == 0) hours += 12; //turns "00" hour to 12am
    cout << "\nThat is the same as ";
    cout << hours << ":" << tf_time.substr(3,4) << AMoPM << endl; // returns time in "hh:mm"
    
    //cout.setf(ios::fixed);
    //cout.setf(ios::right);
   // cout << " " <<hours << ":" << setw(2) << setfill('0')<< minutes << AMoPM << endl; // returns time in "hh:mm" // uses and manipulates minutes rather than simply retrieving minutes as string from input
}

bool out_of_format(string a_string){ // returns true if there's a formatting mistake
    if (!(a_string.length()==5)) // check for correct length
        return true;
    if (!(isdigit(a_string.at(0))) || !(isdigit(a_string.at(1))) ||
        !(isdigit(a_string.at(3))) || !(isdigit(a_string.at(4)))) //check to that user inputed digits
        return true;
    int hours = stoi (a_string.substr(0,2));// retrieve hours from user's string by typecasting
    int minutes = stoi (a_string.substr(3,4)); // retrieve minutes from user's string by typecasting
    if  ((a_string.at(2) != ':') || !(hours >= 0 && hours <24 ) || !(minutes >= 0 && minutes <=59 ))
        // check for hours and minutes being in the correct range and presene of ":" as the 3rd char
        return true;
    else return false;
}
