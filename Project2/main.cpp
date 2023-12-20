//Author: Eduardo Rodriguez
//Version: Feb 5, 2023
// Project 2: Computer Science II

#include "Student.h"
#include <iostream>
#include <string>
#include <cstdlib>

//new line
#define N 5
#include <vector>
using namespace std;

int main() {
    cout << "Welcome to Project 2 \n";


    cout << "___________________________\n" << "Testing Default constructor:\n";
    cout << "___________________________\n";
    Student student0;
    student0.printStudentInfo();
    cout << "___________________________\n" << "Testing 5-Parameter constructor:\n";
    cout << "___________________________\n";

    int id1 = 1001;
    string firstName1 = "Dirk";
    string lastName1 = "Nowitzky";
    string major1 = "Engineering";
    double gpa1 = 3.95;
    /*
    Student student1(id1, firstName1, lastName1, major1, gpa1);
    Student student2(1002, "Jason", "Kidd", "Education", 3.0);
    Student student3(1003, "Shawn", "Marrion", "History", 3.1);
    Student student4(1004, "Jason E.", "Terry", "Computer Science", 3.5);
    Student student5(1005, "Tyson", "Chandler", "Mathematics", 3.7);
     */
    /* Student arr[] = {
     Student student1(id1, firstName1, lastName1, major1, gpa1),
     Student student2(1002, "Jason", "Kidd", "Education", 3.0),
     Student student3(1003, "Shawn", "Marrion", "History", 3.1),
     Student student4(1004, "Jason E.", "Terry", "Computer Science", 3.5),
     Student student5(1005, "Tyson", "Chandler", "Mathematics", 3.7)
 }; */
    student1.printStudentInfo();
    student2.printStudentInfo();
    student3.printStudentInfo();
    student4.printStudentInfo();
    student5.printStudentInfo();
    cout<< "___________________________\n"<< "Testing Change of major:\n";
    cout<< "___________________________\n";
    cout<< student4.getFirstName()<< "'s and "<<student5.getFirstName()<<"'s majors are (respectively): \n";
    cout <<student4.getMajor()<<endl;
    cout <<student5.getMajor()<<endl<<endl;

    student4.setMajor("Biolgy");
    student5.setMajor("Biolgy");
    cout<<" After Covid started, the two switched majors to Biology. \nTheir information is as follows: \n";
    cout<< endl;
    student4.printStudentInfo();
    student5.printStudentInfo();

    cout<< "___________________________\n"<< "Testing Change of GPA:\n";
    cout<< "___________________________\n";
    cout<< student2.getFirstName()<< "'s and "<<student3.getFirstName()<<"'s GPAs are(respectively): \n";
    cout <<student2.getGpa()<<endl;
    cout <<student3.getGpa()<<endl<<endl;

    student2.setGpa(2.8);
    student3.setGpa(3.63);
    cout<<"After another year, their GPAs changed. Here's their information: \n";
    student2.printStudentInfo();
    student3.printStudentInfo();
    // new line
    for (int i = 0; i < sizeof(arr); i++) {arr[i].printStudentInfo();}
}

