//Pre-processor directives
#include <iostream>
using namespace std;

//class name
class Salary
{
    private: 
        double annual_;
    public:
        //this is the constructor function of the class: Salary()
        Salary()
        {
            annual_ = 0;    
        }
        //this function is overloaded constructor function of the class: Salary()
        Salary(double salary)
        {
            annual_ = salary;
        }
        //this is the setter/mutator function that sets the private variable annual_
        void SetAnnualSalary(double salary)
        {
            if (salary > 0){
                annual_ = salary;
            }
            else
                annual_ = 0;
        }
        //this is the getter/accessor that gets the value held in the private variable annual_
        double GetAnnualSalary()
        {
            return annual_;
        }
        //this function prints out the value held in annual_ variable
        void Print()
        {
             cout<<"$"<<annual_<<endl;
        }
};

int main () {
    //create three different instances of Salary class, and pass -20 value to farmhand constructor function
    // and 300000 to bricklayer's constructor function
    Salary carpenter;
    Salary farmhand(-20.00);
    Salary bricklayer(30000.00);
    
    //call print function for each instance of salary
    carpenter.Print();
    farmhand.Print();
    bricklayer.Print();
    
    return 0;
}

//Comment the class per the class style guide
//Identify the following parts of the class
//      constructor
//      overload the constructor to accept an input for salary 
//      and set the salary to the input
//Create a main function that creates an object with no input
//  creates an object with input that is negative
//  and creates an object with input that is appropriate.
//and outputs the salary for each object.