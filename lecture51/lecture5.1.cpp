#include<iostream>
using namespace std;

void SwapNumbers(double& x, double& y) {
    double temp = x;
    x = y;
    y = temp;
}

int main(){
    double x = 5.5;
    double y = 7.7;
    
    SwapNumbers(x,y);
    
    cout<<x<<"     "<<y<<endl;
}

//Does this swap the values?
    // It doesn't swap the values it replaces the value of x with y, and then the value of y with x (which happens to be equal to what y was)
    
//How would you fix it so it does swap the values?
    //You need to add another variable
//Create a swap function.
//What challenges did you have?
    //None