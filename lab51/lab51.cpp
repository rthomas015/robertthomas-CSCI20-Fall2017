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
    //create an integer called nameLength and initializes it to zero
    int nameLength = 0;
    //create a pointer variable named 'name' that points to a char array object
    //this generates an error because you cannot have an array of an undefined length
    char * name = new char[];
    
    //prints out text
    cout << "Please enter a 10 letter word or less" << endl;
    //client inputs a 10 letter word and it is assigned to the 'name' variable
    cin >> name;

    //create a pointer called head that points to a c string variable/char array 'name'
    char * head  = name;
    //create a pointer called tail that points to a c string variable/char array 'name'
    char * tail = name;
    //attempts to assign the length of the pointer variable 'name' to the integer nameLength
    //the pointer has no length it is just holding the memory location of name
    //use strlen(name) instead
    nameLength = strlen(*name);

    //prints out the variable firststr which is not defined and doesn't show up anywhere else
    cout << "Your word is " << firststr << endl;

    //if nameLength is less than 10 execute the following code
    if (nameLength<10)
    {
        //deferenced pointer head 
         while (*head != '\0')
         {
                cout << *head;
                head++;
         }
     }
     else
     {
          cout << "WARNING WORD TOO BIG TO DISPLAY!!" << endl;
     }

     cout << endl;

     tail = &name[strlen(name) - 1];

     if (nameLength < 10)
     {
          while (tail != name)
          {
                 cout << *tail;
                 tail--;
          }
     }
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