/*Lab 1.4 - Floating Point
  Cointstar Machine - Exact Change
  By: Robert Thomas
  Date: 9/5/2017
  Description: This program will emulate a CoinStar style machine it determines your 
  change (in quarters, nickles, dimes and pennies) based on the total amount of change in cents deposited. Then outputs a voucher for that amount.
*/

//Pre-processor directives
#include <iostream>
using namespace std;

//start of program
int main () {
    
    int cents_deposited = 0, total_quarters = 0, total_dimes = 0, total_nickles = 0, total_pennies = 0, total_dollars_before_fee = 0, total_cents_before_fee = 0, total_dollars_after_fee = 0, total_cents_after_fee = 0;
    double total_after_fee = 0.0, total_before_fee = 0.0;
    double const usage_fee = 0.109; 

    //Query information from client
    cout << "-Faux Coinstar Machine-" << endl;
    cout << "-----------------------" << endl;
    cout << "Please input the amount of cents you have deposited: ";
    cin >> cents_deposited;
   
    //Calculate exact change in quarters, dimes, nickles, and pennies
    total_quarters = cents_deposited / 25;
    total_dimes = (cents_deposited % 25) / 10;
    total_nickles = ((cents_deposited % 25) % 10) / 5;
    total_pennies = ((cents_deposited % 25) % 10) % 5;
    
    /*Calculate the amount in dollars/cents after fee is applied
      Questionable way to round, since it doesn't account for actual rounding rules, just truncates, which 
      is why TD Bank is paying out money from a lawsuit for its coin counting machines
    */
    
    total_dollars_before_fee = cents_deposited / 100;
    total_cents_before_fee = cents_deposited;
    total_cents_before_fee = cents_deposited % 100;
    
    total_dollars_after_fee = (cents_deposited - (cents_deposited * usage_fee)) / 100;
    total_cents_after_fee = cents_deposited - (cents_deposited * usage_fee);
    total_cents_after_fee = total_cents_after_fee % 100;
   
    /*These equations work the same, but didn't utilize modulo:
      total_dimes = (total_cents_deposited - (total_quarters * 25)) / 10;
      total_nickles = (total_cents_deposited - ((total_quarters * 25) + (total_dimes * 10))) / 5;
      total_pennies = total_cents_deposited - ((total_quarters * 25) + (total_dimes * 10) + (total_nickles * 5));
    */
    
    //Output information to user
    cout << endl 
    << "You deposited " << total_quarters << " quarters,"
    << " " << total_dimes << " dimes,"
    << " " << total_nickles << " nickles, "
    << "and " << total_pennies << " pennies." << endl;
    
    cout << endl << "The total amount deposited: $" << total_dollars_before_fee << "." << total_cents_before_fee << endl;
    cout << endl << "Total cash after fee: $" << total_dollars_after_fee << "." << total_cents_after_fee << endl;
    
    cout << "Please print this screen to use as a voucher.";
    
    return 0;
}