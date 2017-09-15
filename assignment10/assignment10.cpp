/*Assignment 1.0
  Weekly Paystub Generator
  By: Robert Thomas
  Date: 9/12/2017
  Description: This program will take information from the user for an employee (first name, last name, hours worked per week, hourly wage,
  mileage start and finish and health insurance premium) to generate an employee's weekly pay stub
*/

//Preprocessor Directives
#include <iostream>
#include <string>
using namespace std;

//Employee Paystub Struct with variables that are specific to each employee instance
struct employee_paystub {
    
    string employee_first_name,
           employee_last_name;
           
    double hours_worked_in_week,
           hourly_wage,
           odometer_start,
           odometer_end,
           insurance_premium;
};

int main () {
    
    //declare and initialize variables
    double net_income = 0.0,
           gross_income = 0.0, 
           reimbursement_income = 0.0,
           total_pay = 0.0; 
    //Mileage reimbursement rate is 35 cents per mile
    //Tax Rate is 17%
    const double MILEAGE_REIMBURSEMENT_RATE = 0.35,
                 TAX_RATE = 0.17;
    
    employee_paystub employee_1;
    
    //Get input from user
    
    cout << "Weekly Paystub Generator"
         << endl
         << "------------------------"
         << endl;
         
    cout << "Please input employee's first name: ";
    cin >> employee_1.employee_first_name;
    cout << endl << "Please input employee's last name: ";
    cin >> employee_1.employee_last_name;
    cout << endl << "Please input hours worked in the week: ";
    cin >> employee_1.hours_worked_in_week;
    cout << endl << "Please input hourly wage: ";
    cin >> employee_1.hourly_wage;
    cout << endl << "Please input (weekly) health insurance premium: ";
    cin >> employee_1.insurance_premium;
    cout << endl << "Please input the starting odometer reading: ";
    cin >> employee_1.odometer_start;
    cout << endl << "Please input the ending odometer reading: ";
    cin >> employee_1.odometer_end;
    
    
    //Calculate gross income, reimbursement amount, net income, and the total pay
    //Note: equations don't account for invalid values or input
    gross_income = employee_1.hourly_wage * employee_1.hours_worked_in_week;
    reimbursement_income = MILEAGE_REIMBURSEMENT_RATE * (employee_1.odometer_end - employee_1.odometer_start);
    net_income = gross_income - (TAX_RATE * (gross_income - employee_1.insurance_premium));
    total_pay = (net_income + reimbursement_income) - employee_1.insurance_premium;
    
    
    //Output paystub format to client
    cout << endl << endl << endl;
    cout << endl << "Employee Name     Hours Worked     Hourly Wage     Gross Wages     Net Income (less taxes)    Reimbursement       Ins Premium      Total Pay";
    cout << endl << "--------------------------------------------------------------------------------------------------------------------------------------------";
    cout << endl 
         << employee_1.employee_first_name << " " << employee_1.employee_last_name
         << "            "
         << employee_1.hours_worked_in_week
         << "            "
         << employee_1.hourly_wage
         << "             "
         << gross_income
         << "              "
         << net_income
         << "                 "
         << reimbursement_income
         << "               "
         << employee_1.insurance_premium
         << "            "
         << total_pay;
    /*
    Program outputs the following information:
    
    Employee Name     Hours Worked     Hourly Wage     Gross Wages     Net Income (less taxes)    Reimbursement       Ins Premium      Total Pay
    --------------------------------------------------------------------------------------------------------------------------------------------
    Sofia Cameron            40            23.57             942.8              812.894              310.1               178.65            944.344
    Richard Watson           29            11.5             333.5              335.382                328.3               344.57            319.112
    Heather Hunt             35            60               2100              1781.21                 0                 224.75              1556.46
    Eddy Hall                40            8.25             330              304.546                 79.45               180.27            203.726
    */
    
    return 0;
}