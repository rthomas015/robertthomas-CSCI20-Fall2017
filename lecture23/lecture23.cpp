
//preprocessor directives
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/* Compute Sphere uses the equation to calculate the volume of a sphere based on radius.
   Input: Accepts a single integer for radius.
   Output: None */
   
//function declarations
void ComputeSphere(int);

void ComputeBox(int, int, int);

void ComputePyramid(int, int);


//start of program/main function
int main()
{
    //variable declarations
    int length = 1;
    int width = 1;
    int height = 1;
    
    //function calls to different functions to compute sphere volume, rectangular box volume and volume of a
    //pyramid. Utilizing different arguments.
    ComputeSphere(length);
    ComputeBox(length, width, height);
    ComputePyramid(length, height);

    //receive input from user on length, width and height
    cin>>length>>width>>height;
    
    //function calls same as before, but with new updated variable values
    ComputeSphere(length);
    ComputeBox(length, width, height);
    ComputePyramid(length, height);
}

//function definition to compute volume of a sphere
//accepts length values
void ComputeSphere(int l){
    //calculate volume
    double v = (4.0/3) * 3.14 * (l * l * l);
    //prints out volume
    cout<<"The volume of a sphere is "<<v<<endl;
}

//function definition to compute volume of rectangular box
//accepts length, width, and height values
void ComputeBox(int l, int w, int h){
    //calculate volume
    double v = l * w * h;
    //prints out volume
    cout<<"The volume of a rectangular box is "<<v<<endl;
}

//function definition to compute volume of a pyramid
//accepts length and height values
void ComputePyramid(int l, int h){
    //calculate volume
    double v = (1.0/3) * l * h;
    //prints out volume 
    cout<<"The volume of a pyramid is "<<v<<endl;
} 

//Appropriately comment all of the functions.  Make a note to identify the paramters and input.
//Comment the main function as if it was pseudocode.
//   make note of where the functions are called and the arguments.
