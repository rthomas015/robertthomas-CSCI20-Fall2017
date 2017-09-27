/*Lab 2.3 - Lab - Function Input
  By: Robert Thomas
  Date: 9/21/2017
  Description: This program will take two numbers from a user and then swap the values then output a random number 
  inbetween the numbers provided by the user.
*/

//preprocessor directives
#include <iostream>
#include <ctime>

using namespace std;

//Function to swap values of number_1 and number_2
void SwapNumbers(int &number_1, int &number_2) {
    //create an integer to hold the value of the numbers during the switch 
    int place_holder = number_1;
    
    //change number_1 to the value held in number_2, and number_2's value to the value of number_1
    number_1 = number_2;
    number_2 = place_holder;
    return;
}

//Function to generate a random number between number_1 and number_2 and output the information
int GenerateRandomNumber(int number_1, int number_2) {
    int random_number = 0;
    
    SwapNumbers(number_1, number_2);
    //call time and use that value for the seed
    srand(time(0));
    random_number = (rand () % number_1) + number_2;
    
    //output information to user
    cout << "A random number between " << number_2 << " and " << number_1 << " is " << random_number << ".";
    return 0;
}

int main () {
    int number_1 = 0, number_2 = 0;
    
    //Ask for input from user (two integers)
    cout << "Please enter first number: ";
    cin >> number_1;
    cout << endl << "Please enter second number: ";
    cin >> number_2;
    
    //call random number generating function
    GenerateRandomNumber(number_1, number_2);
    
    //program output:
    //A random number between 1 and 10 is 9.
    //A random number between 5 and 82 is 43.
    //A random number between 22 and 73 is 56.
    
    return 0;
}