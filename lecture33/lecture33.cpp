#include <iostream>
using namespace std;

int main()
{
    int number = 1; // changed starting number to 1, so following loop iterates through 1-10 (10 inclusive)
    
    //while number is less than or equal to 10 perform the following actions inside the curly braces
    //starting condition: 1 <= 10 (is true so execute statements in loop)
    while (number<=10)
    {
        //print the number
        cout<<number;
        //variable change/condition change: add one to the number so that the loop can properly iterate
        number = number + 1;
        //number is retested again to see if the while condition still evaluates to true
    } // end of while loop
    
    int userNumber = 0, x = 1;
    cout<<"Enter a number: ";
    cin>>userNumber;
    
    //while the number x is less than or equal to number entered perform the following actions inside the curly braces
    //starting condition: 3 < 10 (is true so execute statements in loop... note: 3 is example of user input)
    while(x <= number)
    {
        //test to see if 3 mod 10 equals 0 (it doesn't)
        if (x%10 == 0)
        {
            cout<<x<<endl;;
        }
        //otherwise print the number and add a space rather than a new line
        else 
        {
            cout<<x<<" ";
        }
        //variable change/condition change: add one to the number
        x++;
    } //end of the while loop
}

//The first loop doesn't work.  It should print the nubers from 1 to 10 but it doesn't.
//Identify and correct the problem.
//Comment the code as the pseudocode
//Identify the different parts of the loop.