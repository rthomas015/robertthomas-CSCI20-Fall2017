// This program reads in a letter and reports whether
// it is an uppercase letter, a lowercase letter, or neither.
// it should continue reading in values until the user enters a -1.

//pre-processor directives (CHANGED to one line for readability)
#include <iostream> 
using namespace std; 

//start of program
int main() {
        //Read a character in
        char ch;
        cout << "Please enter a character: ";
        cin  >> ch;
         
        //check -- is it a letter??
        //CHANGED - combined nested if statements in to one statement for readability
        if ((ch >= 'A') && (ch <= 'Z')) {
               cout << "Yes, that is a uppercase letter." << endl;
        }
        
        //CHANGED - combined nested if statements in to one statement for readability
        else if ((ch >= 'a') && (ch <= 'z')) {
               cout << "Yes, that is a lowercase letter" << endl;
        }
        
        else {
            cout << "Not a letter" << endl;
        }
        

    return 0;
}
