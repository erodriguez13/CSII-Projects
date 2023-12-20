//  TimeFormatMistake.hpp
//  RodriugezEProject7
//  Created by Eduardo Rodriguez on 4/9/23.

#ifndef TimeFormatMistake_hpp
#define TimeFormatMistake_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

class TimeFormatMistake {};// exception class to be thrown if time is not in 24 hr format

void tfToTwelve (string tf_time); // converts a 24 hour time (HH:MM) to 12 hour format
// if 24 hr time has wrong format or does not exist, exception TimeFormatMistake is thrown

bool out_of_format(string a_string); // takes a string (that shoud be a 24-hr time or HH:MM) as a parameter
//returns true if there is a formatting mistake

#endif /* TimeFormatMistake_hpp */
