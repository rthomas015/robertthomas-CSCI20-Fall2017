/*Lab 5.1 - Pointers
  By: Robert Thomas
  Date: 11/28/2017
  Description: This program is pre-written, we are supposed to review the code explain what is occuring and why
*/

//pre-processor directives
#include <iostream> //includes iostream 
#include <iostream> //includes iostream again - not needed
#include <cstring> //includes cstring
using namespace std;   

/*name  is the first memory location of c string name

name is the full c string char array

*head is the first memory location of c string name

*tail is the first memory location of c string name
*/


//start of program/main function
int main() {
    //create an integer called nameLength and initializes it to zero
    int nameLength = 0;
    //create a pointer variable named 'name' that points to a char array object
    //this generates an error because you cannot have an array of an undefined length
    char* name = new char[0];
    
    //prints out text
    cout << "Please enter a 10 letter word or less" << endl;
    //client inputs a 10 letter word and it is assigned to the 'name' variable
    cin >> name;

    //create a pointer called head that points to a c string variable/char array 'name'
    char * head  = name;
    //create a pointer called tail that points to a c string variable/char array 'name'
    char * tail = name;
    //attempts to assign the length of the c string variable 'name' to the integer nameLength
    nameLength = strlen(name);

    //prints out the variable firststr which is not defined
    cout << "Your length is " << nameLength << endl;
    
    cout << "heres an answer: " << name << endl;
    
    //if nameLength is less than 10 execute the following code:
    if (nameLength<10)
    {
        //while the p
         while (*head != '\0')
         {
                cout << head
                     << endl;
                cout << *head;
                head++;
         }
     }
     //if nameLength is more than 10 excute the following code:
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