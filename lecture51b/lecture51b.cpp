#include <iostream>
using namespace std;

int main()
{
int alpha = 5; //creating a variable, a place in memory that holds the value 5
int beta = 20; //creating a variable, a place in memory that holds the value 20

int * alphaPtr = &alpha; //creating a variable alphaptr, that holds the memory address of alpha
int * betaPtr = &beta;  //creating a variable betaptr, that holds the memory address of beta

cout<<*alphaPtr<<endl; //outputs the memory address of alpha
cout<<*betaPtr<<endl; //outputs the memory address of beta

*alphaPtr += 5; // no idea
betaPtr = alphaPtr; //no idea

cout<<*alphaPtr<<endl; //outputs what ever value is in alphaptr
cout<<*betaPtr<<endl;  //outputs what ever value is betaptr
}

//Comment each line of code.  Explain what it is doing.  What value is held there.
//Why is it doing what it is doing?