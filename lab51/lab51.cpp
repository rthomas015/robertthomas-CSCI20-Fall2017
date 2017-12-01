/*Lab 5.1 - Pointers
  By: Robert Thomas
  Date: 11/28/2017
  Description: This program is pre-written, we are supposed to review the code explain what is occuring
  and why its working that way
*/

//pre-processor directives
#include <iostream> //includes iostream 
#include <iostream> //includes iostream again - not needed
#include <cstring> //includes cstring
using namespace std;   


//start of program/main function
int main() {
    //create an integer called nameLength and initialize it to zero
    int nameLength = 0;
    //create a pointer variable named 'name' that points to a section of
    //memory locations that will hold chars that are logically linked to make it look contiguous, but
    //this generates an error because if you use brackets you must input the amount of
    //char sized memory locations to set aside
    char* name = new char[];
    
    //prints out text
    cout << "Please enter a 10 letter word or less" << endl;
    //client inputs a 10 letter word and it is assigned to the 'name' variable
    cin >> name;

    //create a pointer called head that points to a c string/char array 'name'
    char* head  = name;
    //create a pointer called tail that points to a c string/char array 'name'
    char* tail = name;
    
    //attempts to assign the length of what the pointer variable 'name' is pointing to
    //to the integer nameLength
    //the pointer has no length it is just holding the memory location of name
    //use strlen(name) instead
    nameLength = strlen(*name);

    //prints out the variable firststr which is not defined and doesn't show up anywhere else
    cout << "Your word is " << firststr << endl;

    //if nameLength is less than 10 execute the following code
    if (nameLength<10)
    {
        //while the de-referenced pointer 'head' (so check the actual variable that head is pointing to)
        //does not equal the null termination the continue looping
         while (*head != '\0')
         {
                //print out the char value that the dereferenced 'head' is pointing to
                cout << *head;
                //iterate to the next value in head (not sure how this works exactly, but apparently it does)
                head++;
         }
     }
     //if nameLength is 10 or more execute the following code
     else
     {
          //prints out warning saying the word is too big to display
          cout << "WARNING WORD TOO BIG TO DISPLAY!!" << endl;
     }

     //prints out a new line
     cout << endl;

     //set tail to hold the memory address of name
     tail = &name[strlen(name) - 1];

     //checks to see if namelength is less than ten
     //if so it executes the code
     if (nameLength < 10)
     {
          //loops
          while (tail != name)
          {
                 cout << *tail;
                 tail--;
          }
     }
     //prints out a new line
     cout << endl;

     
     head = name;
     tail = &name[strlen(name) - 1];

     head++;
     tail--;

     if (*head == *tail)
     {
         cout << "It is an palindrome!" << endl;
     }
     else
     {
         cout << "It is not an palindrome" << endl;
     }

     return 0; 
}