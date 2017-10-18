/*Lab 3.3 - Loops
  By: Robert Thomas
  Date: 10/17/2017
  Description: 
  The purpose of Lab 3.3 is to create a program that takes in a number from a user (a guess)
  and also generates a random number.  It then compares the number they guessed to the random number
  and if it is too low tells them its too low or if its too high it tells them its too high - they
  then guess again, and continually guess until they guess the correct number.
  
  The program also has a for loop that prints down from 5 to 1 to make the user wait to see if their
  guess was correct or not.
*/

//preprocessor directives
#include <iostream>
#include <ctime>

using namespace std;

//start of main program
int main() {
    //declare and initalize variables needed in program
    //random_num = the random number that the computer generates
    //guessed_num = the number that the user guesses
    int random_num = 0,
        guessed_num = 0;
    
    //seed the random number generator, and generate a random number between 1 and 50
    srand(time(0));
    random_num = (rand() % 50) + 1;
    
    //Request information from user: a guess between 1 and 50
    cout << "Please guess a number between 1 and 50: ";
    cin >> guessed_num;
    //loop that makes sure the guessed number is not outside the appropriate range.
    //if it is outside that range then it prompts the user to guess again until its correct
    while ((guessed_num < 1) || (guessed_num > 50)) {
        cout << endl << "Try inputting another number this time in the correct range (1 to 50): ";
        cin >> guessed_num;
    }
    cout << endl;
    
    //While loop that will run until the user guesses the correct number
    while (guessed_num != random_num) {
        //for loop to iterate from 5 to 1 and print the number out to the screen to create
        //suspense for the user before revealing if their guess was correct
        for (int i=5; i>=1; i--) {
            cout << i << "...";
        }
        
        //test to see if the guessed number is too high or too low
        if (guessed_num < random_num)
            cout << endl << "too low";
        else if (guessed_num >> random_num)
            cout << endl << "too high";
        
        //prompt user for another guess
        cout << endl
             << "Please input another guess: ";
        cin >> guessed_num;
        
        //test to see if guess is within the appropriate range using the same test
        //as earlier
        while ((guessed_num < 1) || (guessed_num > 50)) {
            cout << endl << "Try inputting another number this time in the correct range (1 to 50): ";
            cin >> guessed_num;
        }
        
    }
    
    //once the user guesses the correct number the while loop will terminate
    //and then prints out 'just right'
    cout << endl << "Just right" << endl;
}
