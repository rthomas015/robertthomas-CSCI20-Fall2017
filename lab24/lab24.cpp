/*Lab 2.4 - Lab - Function Returns
  By: Robert Thomas
  Date: 9/28/2017
  Description: This program will have four functions: a swap number function, a random number generator, a pounds to kilograms 
  and a kilograms to pounds function. A user will input two integers, the numbers will be swapped by SwapNumbers(), then 
  a random number will be generated between those two figures, then the random number will be converted to Kilograms, then the value
  that results from that computation will be converted back into pounds with another function.
  Then it will test if the random number is the same as the final conversion back to pounds.
*/

//preprocessor directives
#include <iostream>
#include <ctime>

//initialize & declare a variable that is a global constant usable in all functions
const double RATIO_OF_POUNDS_TO_KILOGRAMS = 2.20462;

using namespace std;

//Function to swap values of two numbers
//Note: you can remove the need for passing by reference by just adding this function to the random
//number generator function
void SwapNumbers(int &number_1, int &number_2) {
    //initialize & declare a variable that is local to SwapNumbers
    //( an integer to hold the value of the numbers during the switch )
    int place_holder = number_1;
    
    //change number_1 to the value held in number_2, and number_2's value to the value of number_1
    number_1 = number_2;
    number_2 = place_holder;
    return;
}

//Function to generate a random number between number_1 and number_2 and output the information
int GenerateRandomNumber(int number_1, int number_2) {
    //initialize & declare a variable that is local to GenerateRandomNumber
    int random_number = 0;

    //swap the two numbers
    SwapNumbers(number_1, number_2);

    //call time and use that value for the seed
    srand(time(0));
    random_number = (rand () % (number_1 - number_2 + 1)) + number_2;
    
    return random_number;
}

//Convert pounds to kilograms
double PoundsToKilograms(double pounds) {
    //initialize & declare variable that is local to PoundsToKilograms()
    double kilograms = pounds / RATIO_OF_POUNDS_TO_KILOGRAMS;
    return kilograms;
}

//Convert kilograms to pounds
double KilogramsToPounds(double kilograms) {
    //initialize & declare variable that is local to KilogramsToPounds()
    double pounds = kilograms * RATIO_OF_POUNDS_TO_KILOGRAMS;
    return pounds;
}

int main () {
    //initialize & declare variables that are local to main()
    int number_1 = 0, number_2 = 0, random_number = 0;
    double kilograms = 0.0, pounds = 0.0;
    
    //Ask for input from user (two integers)
    cout << "Please enter first number: ";
    cin >> number_1;
    cout << endl << "Please enter second number: ";
    cin >> number_2;
    
    random_number = GenerateRandomNumber(number_1, number_2);
    cout << endl << "Your random number is " << random_number;
    
    kilograms = PoundsToKilograms(static_cast<double>(random_number));
    
    cout << endl << "Your kilograms are : " << kilograms;
    
    pounds = KilogramsToPounds(kilograms);
    
    cout << endl << "Your pounds are: " << pounds;

    if (random_number == pounds)
        cout << endl << "The random number and final resulting pounds are equal.";
    else
        cout << endl << "The random number and final resulting pounds are not equal.";
        
    //program output:
    /*  Please enter first number: 1
        Please enter second number: 10

        Your random number is 1
        Your kilograms are : 0.453593
        Your pounds are: 1
        The random number and final resulting pounds are equal.
    */
    
    return 0;
}