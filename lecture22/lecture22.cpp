//preprocessor directives
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//function declaration
//? Purpose of declaring the function and then writing it after the main function, rather than just having the function appear prior to the 
//main function
void guessingGame ();

int main()
{
    //body of main function
    cout<<"We are going to play the guessing game 3 times"<<endl;
    
    //function calls (3 separate function calls in a row)
    guessingGame();
    guessingGame();
    guessingGame();
    //? no return statement
}

//function definition
void guessingGame ()
{
    //body of guessingGame function
    
    //calls function time with argument 0, and then calls srand function with time (0) as the argument 
    //*
    srand(time(0));
    
    //calls function rand() and gets input from user
    //*
    int randomNumber = rand() % 10 + 1;
    int userNumber = 0;
    
    //retrieves information from user
    cout<<"Please choose a number between 1 and 10";
    cin>>userNumber;

    //outputs information to user
    cout<<"You picked: "<<userNumber<<"  The number was: "<<randomNumber<<endl;
    
    //? no return statement
}