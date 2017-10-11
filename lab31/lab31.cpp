/*Lab 3.1 - Lab - Conditions
  By: Robert Thomas
  Date: 10/07/2017
  Description: 
  The purpose of Lab 3.1 is to create a program that evaluates which cell phone provider is the best (cheapest)
  for a person/family based on the user's input: the number of smart phones, dump phones, amount of cell phone
  data needed, and if they have a discount (corporate discount). The program uses conditional statements
  to determine which plan is the cheapest for that set of criteria.
*/

//preprocessor directives
#include <iostream>
#include <string>

using namespace std;

//ATT Unlimited Plus Plan - this function computes the price of the plan using the following figures:
//$90/mo for the first line, $145/mo for 2 lines, an additional $20/mo up to 10 max for phones, $10/mo per tablet
//No Data Limit
double ATTUnlimitedPlus(int num_of_lines, int num_of_tablets) {
    double total_price = 0.0;
    
    //conditional statement to determine price equation to use based on number of phone lines
    //if 1 line is selected
    if (num_of_lines == 1) {
       total_price = 90.00 + (10.00 * num_of_tablets);
    }
    //if 2 lines are selected
    else if (num_of_lines == 2) {
       total_price = 145.00 + (10.00 * num_of_tablets);
    }
    //if more than two lines are selected
    else {
        total_price = 145.00 + (10.00 * num_of_tablets) + (20.00 * (num_of_lines - 2));
    }
    return total_price;
}

//ATT Unlimited Choice
//$60/mo for the first line, $115/mo for 2 lines, an additional $20/mo up to 10 max for phones, $10/mo per tablet.
//No Data Limit
double ATTUnlimitedChoice(int num_of_lines, int num_of_tablets) {
    double total_price = 0.0;
    
    //conditional statement to determine price equation to use based on number of phone lines
    //if 1 line is selected
    if (num_of_lines == 1) {
        total_price = 60.00 + (10.00 * num_of_tablets);
    }
    //if two lines are selected
    else if (num_of_lines == 2) {
        total_price = 115.00 + (10.00 * num_of_tablets);
    }
    //if more than two lines are selected (or 0)
    else {
        total_price = 115.00 + (10.00 * num_of_tablets) + (20.00 * (num_of_lines - 2));
    }
    
    return total_price;
}

//ATT Family Plan
//$20 per phone, $10 per tablet, plus data based on conditional statement below
double ATTFamilyPlan(int num_of_lines, int num_of_tablets, int data_needed_in_GB) {
    double total_price = 0.0,
           data_price = 0.0;
           
    //conditional statement to determine price of plan based on the data required
    //Each tier of data is a different price
    if (data_needed_in_GB <= 1)
        data_price = 30.00;
    else if (data_needed_in_GB <= 3)
        data_price = 40.00;
    else if (data_needed_in_GB <= 6)
        data_price = 60.00;
    else if (data_needed_in_GB <= 10)
        data_price = 80.00;
    else if (data_needed_in_GB <= 16)
        data_price = 90.00;
    else 
        data_price = 110.00;
        
    //after determining data rate, determine the total price of the plan
    total_price = (20.00 * num_of_lines) + (10.00 * num_of_tablets) + data_price;
    return total_price;   
}

//Verizon Unlimited
//$80 for the first line, $110 for more than 1 line, $20 per phone starting at the first, $10 per tablet
//No data limit
//Unsure of equation - used $20 for each additional phone line after 2 (similar to ATT plans)
double VerizonUnlimited (int num_of_lines, int num_of_tablets) {
    double total_price = 0.0;
    
    
    //conditional statement to determine price equation to use based on number of phone lines
    //if 1 line is selected
    if (num_of_lines == 1) {
        total_price = 80.00 + (10.00 * num_of_tablets);
    }
    //if 2 line is selected
    else if (num_of_lines == 2) {
        total_price = 110.00 + (10.00 * num_of_tablets);
    }
    //if more than 2 lines are selected
    else {
        total_price = 110.00 + (10.00 * num_of_tablets) + (20.00 * (num_of_lines - 2));
    }
    
    return total_price;
}

//Sprint Unlimited
//$60 for the 1st line, $40 for the second line, Additional $30/mo per line
double SprintUnlimited (int num_of_lines) {
    double total_price = 0.0;
    
    //conditional statement to determine price equation to use based on number of phone lines
    //if one line is choosen
    if (num_of_lines == 1) {
        total_price = 60.00;
    }
    //if two lines are choosen
    else if (num_of_lines == 2) {
        total_price = 100.00;
    }
    //if more than two lines are choosen
    else {
        total_price = 100.00 + (30.00 * (num_of_lines - 2));
    }
    
    return total_price;
}

//Sprint 2GB
//$40 per month per line
double Sprint2GB (int num_of_lines) {
    //equation to calculate plan price based on the number of lines choosen
    double total_price = 40.00 * num_of_lines;
    return total_price;
}

//Start of program
int main () {
    //initialize following variables:
    /*  num_of_smartphones, num_of_dumbphones, and num_of_tablets are all the number of smartphones,
        dumbphones and tablets the user wants
        data_needed_in_GB = the amount of data user needs in gigabytes
      
        index_num_saved = stores the index of the lowest priced plan during for loop iteration later
        in program
        
        array_of_plan_prices = a list of the prices of each plan, only some functions are called
           based on user's input and if certain criteria is met (like if the plan allows what they want)
           so the array will show 0.0 for plans that were not computed, and a non zero value for 
           computed prices
    
        array_of_plan_names = a list of the plan names that corresponds to the array_of_plan_prices
    */
    int num_of_smartphones = 0,
        num_of_dumbphones = 0,
        num_of_tablets = 0,
        data_needed_in_GB = 0;

    int index_num_saved = 0;

    double array_of_plan_prices[6] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
    string array_of_plan_names[6] = {"ATT Family Plan", "ATT Unlimited Choice", "ATT Unlimited Plus", "Sprint 2GB", "Sprint Unlimited", "Verizon Unlimited"};

           
    //Request information from user for: number of smartphones, number of dumbphones, number of tablets, and data needed in GB
    cout << "Calculator for Cell Phone Plans: " << endl
         << "Please enter the number of smartphones: ";
    cin >> num_of_smartphones;
    cout << endl
         << "Please enter the number of dumb phones: ";
    cin >> num_of_dumbphones;
    cout << endl
         << "Please enter the number of tablets: ";
    cin >> num_of_tablets;
    cout << endl
         << "Please enter the amount of data needed (in GB): ";
    cin >> data_needed_in_GB;
    
    //Distinction in plans not made for smartphones vs dumbphones
    //so they are both totalled to determine the number of total lines requested
    int num_of_lines = num_of_smartphones + num_of_dumbphones;
    
    //Restrict comparisons only to those plans that meet the user's needs
    //Compare each one at a time:
         
        //The ATT Family Plan data doesn't exceed 25 GB in data, so only calculate  
        //the price for the plan if the user requires less than that
        if(data_needed_in_GB <= 25)
            array_of_plan_prices[0] = ATTFamilyPlan (num_of_lines, num_of_tablets, data_needed_in_GB);
        
        //Calculate price of all ATT unlimited plans, unless num_of_lines is over ten
        if (num_of_lines < 10) {
            array_of_plan_prices[1] = ATTUnlimitedChoice(num_of_lines, num_of_tablets);
            array_of_plan_prices[2] = ATTUnlimitedPlus(num_of_lines, num_of_tablets);
        }
        
        //include sprint 2G if 0 tablets needed and data need is 2 or under
        //as tablets are seemingly not supported
        if((num_of_tablets == 0) && (data_needed_in_GB <= 2))
            array_of_plan_prices[3] = Sprint2GB(num_of_lines);
        
        //Add Sprint Unlimited to comparison if tablets needed is 0, otherwise exclude
        //as tablets are seemingly not supported
        if(num_of_tablets == 0) 
            array_of_plan_prices[4] = SprintUnlimited(num_of_lines);
        
        //Always calculate Verizon Unlimited price, as nothing precludes it
        array_of_plan_prices[5] = VerizonUnlimited(num_of_lines, num_of_tablets);
        
        //create a variable named lowest_price and set it to the first value in the
        //array_of_plan_prices array, this will be used to cycle through values and test
        //for lowest price. It will hold the lowest price found during the iteration.
        double lowest_price = array_of_plan_prices[0];

        //Output list of plans and list of prices for each plan
        cout << endl << "List of Plans and Price ($0 /mo. means plan did not meet your specifications):" << endl;
        
        for (int i=0; i<=5; i++) {
            cout << array_of_plan_names[i] << ": $" << array_of_plan_prices[i] << "/mo." << endl;
        }
         
        //Search for cheapest price by iterating through all values in the price array
        for (int i=0; i<=5; i++) {
            //test if next value in array is less than newer value, and that lowest_price isn't 0
            if ((array_of_plan_prices[i] - lowest_price < 0.0001) && (lowest_price > 0.0001)){
                lowest_price = array_of_plan_prices[i];
                index_num_saved = i;
            }
            //if lowest_price is 0, set the value to the current figure, since 0 is not a valid price
            else if (lowest_price < 0.0001) {
                lowest_price = array_of_plan_prices[i];
                index_num_saved = i;
            }
        }
        
        cout << endl << "The cheapest plan is the " << array_of_plan_names[index_num_saved] << " plan and it costs $" << lowest_price << " /mo.";
        
        /* Program Output:
        
        User #1
        List of Plans and Price ($0 means plan did not meet your specifications:
        ATT Family Plan: $100/mo.
        ATT Unlimited Choice: $115/mo.
        ATT Unlimited Plus: $145/mo.
        Sprint 2GB: $0/mo.
        Sprint Unlimited: $100/mo.
        Verizon Unlimited: $110/mo.

        The cheapest plan is the Sprint Unlimited plan and it costs $100 /mo.
        
        User #2
        List of Plans and Price ($0 /mo. means plan did not meet your specifications):
        ATT Family Plan: $160/mo.
        ATT Unlimited Choice: $145/mo.
        ATT Unlimited Plus: $175/mo.
        Sprint 2GB: $0/mo.
        Sprint Unlimited: $0/mo.
        Verizon Unlimited: $140/mo.

        The cheapest plan is the Verizon Unlimited plan and it costs $140 /mo.
        
        User #3
        List of Plans and Price ($0 /mo. means plan did not meet your specifications):
        ATT Family Plan: $50/mo.
        ATT Unlimited Choice: $60/mo.
        ATT Unlimited Plus: $90/mo.
        Sprint 2GB: $40/mo.
        Sprint Unlimited: $60/mo.
        Verizon Unlimited: $80/mo.

        The cheapest plan is the Sprint 2GB plan and it costs $40 /mo.
        
        
        
        
        
        
        
        */
    return 0;
}