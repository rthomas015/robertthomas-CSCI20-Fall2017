/*Lab 1.6 - Lab - Objects
  Stock Portfolio
  By: Robert Thomas
  Date: 9/12/2017
  Description: This program will receive input from a user regarding stock data and output information based on that input, such as total portfolio value
  and each individual stock's information including individual values
*/

//preprocessor directives
#include <iostream>
#include <string>
using namespace std;

//struct that contains the information needed for each stock
struct stock {
    string name;
    char sector;
    double share_price;
    int shares_owned;
};

int main () {
    //create four generic stock objects
    stock stock_1, 
          stock_2,
          stock_3,
          stock_4;
    //create four double values to total up each stock's values
    //and one to calculate portfolio value
    double total_value_1 = 0.0,
           total_value_2 = 0.00, 
           total_value_3 = 0.00, 
           total_value_4 = 0.00, 
           total_portfolio = 0.00;
    
    
    //Request input from user
    cout << "----Stock Portfolio Calculator----";
    
    cout << endl << "Please input stock name: ";
    cin >> stock_1.name;
    cout << endl << "Please input sector: ";
    cin >> stock_1.sector;
    cout << endl << "Please input share price: ";
    cin >> stock_1.share_price;
    cout << endl << "Please input shares owned: ";
    cin >> stock_1.shares_owned;
    
    cout << endl << "Please input stock name: ";
    cin >> stock_2.name;
    cout << endl << "Please input sector: ";
    cin >> stock_2.sector;
    cout << endl << "Please input share price: ";
    cin >> stock_2.share_price;
    cout << endl << "Please input shares owned: ";
    cin >> stock_2.shares_owned;
    
    cout << endl << "Please input stock name: ";
    cin >> stock_3.name;
    cout << endl << "Please input sector: ";
    cin >> stock_3.sector;
    cout << endl << "Please input share price: ";
    cin >> stock_3.share_price;
    cout << endl << "Please input shares owned: ";
    cin >> stock_3.shares_owned;
    
    cout << endl << "Please input stock name: ";
    cin >> stock_4.name;
    cout << endl << "Please input sector: ";
    cin >> stock_4.sector;
    cout << endl << "Please input share price: ";
    cin >> stock_4.share_price;
    cout << endl << "Please input shares owned: ";
    cin >> stock_4.shares_owned;
    
    //calculate values for each set of shares individually and the total portfolio value
    total_value_1 = stock_1.shares_owned * stock_1.share_price;
    total_value_2 = stock_2.shares_owned * stock_2.share_price;
    total_value_3 = stock_3.shares_owned * stock_3.share_price;
    total_value_4 = stock_4.shares_owned * stock_4.share_price;
    total_portfolio = total_value_1 + total_value_2 + total_value_3 + total_value_4;
    
    
    //output calculations and input data to user
    cout << "Stock Name      No of Shares     Current Value    Total Value"
         << endl
         << "-------------------------------------------------------------"
         << endl;
         
    cout << stock_1.name << "              " << stock_1.shares_owned  << "             " << stock_1.share_price << "              " << total_value_1;
    cout << endl;
    cout << stock_2.name << "              " << stock_2.shares_owned  << "             " << stock_2.share_price << "              " << total_value_2;
    cout << endl;
    cout << stock_3.name << "              " << stock_3.shares_owned  << "             " << stock_3.share_price << "              " << total_value_3;
    cout << endl;
    cout << stock_4.name << "              " << stock_4.shares_owned  << "             " << stock_4.share_price << "              " << total_value_4;
    cout << endl;
    cout << "Total Portfolio: $" << total_portfolio;
    
    /* Information output
     Stock Name      No of Shares     Current Value    Total Value
    -------------------------------------------------------------
    FordM              87             18.76              1632.12
    Albertsn              542             34.39              18639.4
    AAPL              5             145.91              729.55
    TSLA              50             375.64              18782
    Total Portfolio: $39783.1
    
    */
    
    return 0;
}