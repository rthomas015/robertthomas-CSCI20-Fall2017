/*Lab 2.2 - Lab - Writing Functions
  By: Robert Thomas
  Date: 9/21/2017
  Description: This program will generate a pseudorandom number between 1 and 100
  and output that information to the screen
*/

//preprocessor directives
#include <iostream>
#include <ctime>
using namespace std;

//Function to generate a random number between 1 and 100 and output the information
int GenerateRandomNumber() {
    int random_number = 0;
    
    //call time and use that value for the seed
    srand(time(0));
    random_number = (rand () % 100) + 1;
    
    //output information to user
    cout << "Your random number is " << random_number << ".";
    return 0;
}

int main () {
    //call random number generating function
    GenerateRandomNumber();
    
    //program output:
    //Your random number is 82
    return 0;
}