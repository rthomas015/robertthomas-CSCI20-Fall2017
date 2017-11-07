/*Lab 4.2 - Parallel Arrays
  By: Robert Thomas
  Date: 10/30/2017
  Description: This program will mimic an online shopping cart and have ten items for sale comprised of a string holding the product
  name, an integer holding the number of that item in stock, and a double value holding the items price
*/

//preprocessor directives
#include <iostream>
#include <string>

using namespace std;

//start of main program
int main () {
    //create a string array with 10 values, holding the names of all the items that the store has to offer
    string inventory_names[10] = {
        "Reese's Peanut Butter Cups",
        "Snickers",
        "Paydays",
        "Kit-kats",
        "Almond Joy",
        "Mounds",
        "Three Musketeers",
        "Nutrageous",
        "Baby Ruth",
        "Peanut M&M's"
    };
    
    //create an integer string that holds the number of a certain item in stock
    int inventory_num_in_stock[10] = {
        3,
        10,
        20,
        14,
        17,
        3,
        4,
        5,
        6,
        9
    };
    
    //create a double array that holds all the item prices for each item in the store
    double inventory_price[10] = {
        2.25,
        1.75,
        1.75,
        3.25,
        2.50,
        4.20,
        1.75,
        2.00,
        3.00,
        1.85
    };
    
    //create an array that functions as the actual shopping cart for the customer:
    //it holds the number of items the user has purchased by increasing the value of the appropriate (i.e. matching)
    //index that corresponds to the index of the item in the shop arrays
    int purchased_products[10] = {0,0,0,0,0,0,0,0,0,0};
    
    //create a variable, menu_option that takes in input from a user allowing them to select the item from the store based
    //on a menu...
    //create a variable total_cost that holds the total cost of all items purchased by the individual
    int menu_option = 0;
    double total_cost = 0.0;
    
    //menu loop that allows a customer to continue buying things until they select the exit option which is -1
    while (menu_option != -1) {
        
        //print out store name
        cout << "     Candy Shop:      " << endl
             << "--------------------- ";
        
        //Print out the list of items that the store has to offer, by iterating through the arrays
        for (int i=0;i<10;i++) {
            cout << endl << "[" << i << "] " << inventory_names[i] << " (num in stock: " << inventory_num_in_stock[i] << "): $" << inventory_price[i];
        }
        
        cout << endl <<  "[-1] Complete Purchase " << endl;
        //take input from user (their menu choice)
        cin >> menu_option;
        
        //check to see if there is enough of that item in stock
        //if there is enough inventory to accomodate the request execute this:
        if ((menu_option != -1) && (inventory_num_in_stock[menu_option] > 0)) {
            //subtract one from the number in stock for the item choosen
            inventory_num_in_stock[menu_option] = inventory_num_in_stock[menu_option] - 1;
            //add one to the cart array at the corresponding index
            purchased_products[menu_option] = purchased_products[menu_option] + 1;
        }
        //if there is no remaining inventory execute this:
        else if ((menu_option != -1) && (inventory_num_in_stock[menu_option] <= 0)) {
            cout << endl << "There are zero remaining in stock. Please choose again..." << endl;
        }
   
    }

    cout << endl << "Thank you for your purchase!"
         << endl;
    
    //iterate through all possible products in the shoping cart    
    for(int i=0;i<10;i++){
        //when the value in the shoping cart is greater than 0 items, print out the name, price etc of that item
        //and add the value of those items to the total_cost variable
        if (purchased_products[i] > 0) {
            cout << "You purchased " << purchased_products[i] << " " << inventory_names[i] << endl;
            total_cost = total_cost + (purchased_products[i] * inventory_price[i]);
        }
    }
    
    //print out the total cost that the user incurred
    cout << endl << "Your total cost: $" << total_cost;
    
    //Output:
    /*
         Candy Shop:      
--------------------- 
[0] Reese's Peanut Butter Cups (num in stock: 3): $2.25
[1] Snickers (num in stock: 10): $1.75
[2] Paydays (num in stock: 20): $1.75
[3] Kit-kats (num in stock: 14): $3.25
[4] Almond Joy (num in stock: 17): $2.5
[5] Mounds (num in stock: 3): $4.2
[6] Three Musketeers (num in stock: 4): $1.75
[7] Nutrageous (num in stock: 5): $2
[8] Baby Ruth (num in stock: 6): $3
[9] Peanut M&M's (num in stock: 9): $1.85
[-1] Complete Purchase 
9
     Candy Shop:      
--------------------- 
[0] Reese's Peanut Butter Cups (num in stock: 3): $2.25
[1] Snickers (num in stock: 10): $1.75
[2] Paydays (num in stock: 20): $1.75
[3] Kit-kats (num in stock: 14): $3.25
[4] Almond Joy (num in stock: 17): $2.5
[5] Mounds (num in stock: 3): $4.2
[6] Three Musketeers (num in stock: 4): $1.75
[7] Nutrageous (num in stock: 5): $2
[8] Baby Ruth (num in stock: 6): $3
[9] Peanut M&M's (num in stock: 8): $1.85
[-1] Complete Purchase 
-1

Thank you for your purchase!
You purchased 1 Peanut M&M's

Your total cost: $1.85
    
    
    */
    return 0;
}