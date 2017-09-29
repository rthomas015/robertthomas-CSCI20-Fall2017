#include <iostream>
using namespace std;

//The salary class contains an annual salary variable (double), and three functions that allow you to set the annual salary, to get the annual salary
//and finally to print out the annual salary to the console.
class Salary
{
    private:
        double annual_; //Data field...?
    public:
        //Mutator function
        void SetAnnualSalary(double salary)
        {
            annual_ = salary;
        }
        //Accessor function
        double GetAnnualSalary()
        {
            return annual_;
        }
        //Print value out to screen
        void Print()
        {
             cout<<"$"<<annual_<<endl;
        }
};

int main () {
    //Create salary object named fake_salary_obj
    Salary fake_salary_obj;
    
    //set annual salary, get annual salary, and the run print command
    fake_salary_obj.SetAnnualSalary(100000.00);
    fake_salary_obj.GetAnnualSalary();
    fake_salary_obj.Print();
    
    return 0;
}

//Comment the class per the class style guide
//Identify the following parts of the class
//      data field
//      mutator function
//      accessor function
//Create a main function that creates an object and runs all of the functions in order