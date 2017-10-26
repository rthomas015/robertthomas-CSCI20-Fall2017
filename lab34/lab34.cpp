// This program reads in a letter and reports whether
// it is an uppercase letter, a lowercase letter, or neither.
// it should continue reading in values until the user enters a -1.

//pre-processor directives (CHANGED to one line for readability)
//CHANGED - added string
#include <iostream> 
#include <string>
using namespace std; 

//start of program
int main() {
        //CHANGED ch from a char to a string, because a string needs to be entered to terminate the while loop
        string ch;
        cout << "Please enter a character: ";
        cin  >> ch;
         
        //check -- is it a letter??
        //CHANGED - combined nested if statements in to one statement for readability
        //ADDED - while loop since the program is actually supposed to run until a negative -1 is entered

        while (ch != "-1") {
            
            //CHANGED - combined nested if statements in to one statement for readability and so it actually works
            if ((ch >= "A") && (ch <= "Z")) {
                   cout << "Yes, that is a uppercase letter." << endl;
            }
        
            else if ((ch >= "a") && (ch <= "z")) {
                   cout << "Yes, that is a lowercase letter" << endl;
            }
        
            else {
                cout << "Not a letter" << endl;
            }
            
            cout << "Please enter a character: ";
            cin >> ch;
        
        }
        
        
        //OUTPUT:
        /*
            Running /home/ubuntu/workspace/lab34/lab34.cpp
            Please enter a character: F
            Yes, that is a uppercase letter.
            Please enter a character: f
            Yes, that is a lowercase letter
            Please enter a character: Z
            Yes, that is a uppercase letter.
            Please enter a character: 3
            Not a letter
            Please enter a character: -1
            
            Process exited with code: 0
        */
    return 0;
}
