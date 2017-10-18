//preprocessor directives
#include <iostream>
using namespace std;

//start of the program
int main()
{
    //define and initalize variables
    int number = 0, product = 0;
    
    //loop while number is greater than or equal to 0. So it starts executing the loop automatically the first time you run through the program
    //1 times on the run through (number = 0)
    //1 times on the run through (number = 5)
    //1 times on the run through (number = 4)
    //1 times on the run through (number = 3)
    //1 times on the run through (number = 2)
    //1 times on the run through (number = 1)
    //0 times on the run through (number = -1)
    while (number >=0)
    {
        //for loop that iterates:
        //3 times on the run through (number = 0)
        //3 times on the run through (number = 5)
        //3 times on the run through (number = 4)
        //3 times on the run through (number = 3)
        //3 times on the run through (number = 2)
        //3 times on the run through (number = 1)
        //0 times on the run through (number = -1)
        for (int i = 0; i<3; i++)
        { 
            product = number * i;
        }
        cout<<"Please enter a positive integer: ";
        cin >> number;
    }
    cout<<"The product is: "<<product<<endl;
}

//Comment the code as pseudocode
//Determine how many times each loop executes if the numbers input are 5, 4, 3, 2, 1,-1
//What is the value of i at the end of the program?