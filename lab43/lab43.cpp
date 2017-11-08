/*Lab 4.3 - Arrays of Objects
  By: Robert Thomas
  Date: 11/6/2017
  Description: This program will mimic an online shopping cart and have ten items for sale comprised of a string holding the product
  name, an integer holding the number of that item in stock, and a double value holding the items price.
  Unlike Lab 4.2 however this program will use an array of objects in lieu of the previously used parallel arrays
*/

//preprocessor directives
#include <iostream>
#include <string>

using namespace std;

//constant integer that holds the number of items in the store (and consequently the number of items in the array)
const int NUM_STORE_ITEMS = 10;

//Store/Shopping Cart Class
class ShoppingCart {
    private:
        int num_purchased_, //total number of the particular item that was purchased or is in cart
            num_in_stock_; //number in stock
        double total_cost_, //total cost of shoping cart
               item_price_; //item price
        string item_name_; //item name


    public:
        //constructor function
        ShoppingCart () {
            num_purchased_ = 0; //set number of purchased items to 0
            total_cost_ = 0.0; //total cost of the item (number of items * item price)
        }
        //function that returns the number of items of that type purchased
        const int GetNumPurchased () {
            return num_purchased_;
        }
        //function that calculates and retuns the total cost of all of that one type of item that is in the cart
        double GetTotalCost () {
            //not sure what the best practice is: if the values of the variables should
            //be accessed directly or by calling the other functions in the class like GetNumPurchased and GetItemPrice()
            total_cost_ = num_purchased_ * item_price_;
            return total_cost_;
        }
        
        //function that returns the items name
        const string GetItemName () {
            return item_name_;
        }
        
        //function that returns the items price
        const double GetItemPrice () {
            return item_price_;
        }
        
        //function that returns the number of items that are in stock
        const int GetNumInStock () {
            return num_in_stock_;
        }
        
        //Setter Functions:
        //function sets the number of items purchased
        void SetNumPurchased (int num_purchased) {
            num_purchased_ = num_purchased;
        }
        
        //function that sets the item name
        //the variable item_name is a string representing the item's name and is a parameter
        void SetItemName (string item_name) {
            item_name_ = item_name;
        }
        
        //function that sets the items price
        //the variable item_price is a double variable representing the item's price and is a parameter
        void SetItemPrice (double item_price) {
            item_price_ = item_price;
        }
        
        //function that sets the number in stock
        //num_in_stock is an integer variable that represents the number of a certain item in stock
        void SetNumInStock (int num_in_stock) {
            num_in_stock_ = num_in_stock;
        }
        
        //function that checks to see if the item is in stock or not (if there is more than 0 items in the store)
        bool CheckInStock () {
            bool item_in_stock = true;
            
            //if there is less than 0 or 0 items in the store set the item_in_stock flag to false
            if (num_in_stock_ <= 0) {
                item_in_stock = false;
            }
            
            return item_in_stock;
        }
        
        //funcion to add an item to the customers cart
        void AddtoCart () {
            //first check to see if the item is in stock
            if (CheckInStock()) {
                //if the item is in stock, reduce the number in stock by one and increase the number purchased by one
                num_in_stock_ = num_in_stock_ - 1;
                num_purchased_ = num_purchased_ + 1;
            }
        }
        
};

//start of main program
int main () {
    
    //create a ShoppingCart object array of 10 items (for each item in store)
    ShoppingCart cart[NUM_STORE_ITEMS];
    //create a variable that holds the menu_option value that the customer will input
    int menu_option = 0;
    //create a double variable that holds the total cart cost
    double total_cart_cost = 0.0;
    
    //update array of objects with each store item name
    cart[0].SetItemName("Reese's Peanut Butter Cups");
    cart[1].SetItemName("Snickers");
    cart[2].SetItemName("Paydays");
    cart[3].SetItemName("Kit-kats");
    cart[4].SetItemName("Almond Joy");
    cart[5].SetItemName("Mounds");
    cart[6].SetItemName("Three Musketeers");
    cart[7].SetItemName("Nutrageous");
    cart[8].SetItemName("Baby Ruth");
    cart[9].SetItemName("Peanut M&M's");
    
    //update array of objects with the number of each item in stock
    cart[0].SetNumInStock(10);
    cart[1].SetNumInStock(10);
    cart[2].SetNumInStock(10);
    cart[3].SetNumInStock(20);
    cart[4].SetNumInStock(15);
    cart[5].SetNumInStock(2);
    cart[6].SetNumInStock(3);
    cart[7].SetNumInStock(5);
    cart[8].SetNumInStock(6);
    cart[9].SetNumInStock(7);
    
    //update array of objects with the price of each items
    cart[0].SetItemPrice(2.75);
    cart[1].SetItemPrice(2.55);
    cart[2].SetItemPrice(3.75);
    cart[3].SetItemPrice(1.75);
    cart[4].SetItemPrice(2.50);
    cart[5].SetItemPrice(2.25);
    cart[6].SetItemPrice(2.25);
    cart[7].SetItemPrice(2.35);
    cart[8].SetItemPrice(1.85);
    cart[9].SetItemPrice(1.95);
    
    //menu loop that allows a customer to continue buying things until they select the exit option which is -1
    while (menu_option != -1) {
        
        //print out store name
        cout << "     Candy Shop:      " << endl
             << "--------------------- ";
        
        //Print out the list of items that the store has to offer, by iterating through the arrays
        for (int i=0;i<NUM_STORE_ITEMS;i++) {
            cout << endl << "[" << i << "] " << cart[i].GetItemName() << " (num in stock: " << cart[i].GetNumInStock() << "): $" << cart[i].GetItemPrice();
        }
        
        cout << endl <<  "[-1] Complete Purchase " << endl << "Enter Choice: ";
        //take input from user (their menu choice)
        cin >> menu_option;
        
        //check to see if there is enough of that item in stock
        //if there is enough inventory to accomodate the request execute this:
        if ((menu_option != -1) && (cart[menu_option].CheckInStock())) {
            cart[menu_option].AddtoCart();
        }
        else if ((menu_option != -1) && (cart[menu_option].CheckInStock() == false)) {
            cout << endl << "There are zero remaining in stock. Please choose again..." << endl;
        }
   
    }
    
    
    cout << endl << "Thank you for your purchase!"
         << endl;
    
    //iterate through all possible products in the shoping cart    
    for(int i=0;i<NUM_STORE_ITEMS;i++){
        //when the value in the shoping cart is greater than 0 items, print out the name, price etc of that item
        //and add the value of those items to the total_cost variable
        if (cart[i].GetNumPurchased() > 0) {
            cout << "You purchased " << cart[i].GetNumPurchased() << " " << cart[i].GetItemName() << endl;
            total_cart_cost = total_cart_cost + (cart[i].GetTotalCost());
        }
    }
    
    //print out the total cost that the user incurred
    cout << endl << "Your total cost: $" << total_cart_cost;
    
    //Output:
    /* ... after purchasing six Baby Ruth...
         Candy Shop:      
--------------------- 
[0] Reese's Peanut Butter Cups (num in stock: 10): $2.75
[1] Snickers (num in stock: 10): $2.55
[2] Paydays (num in stock: 10): $3.75
[3] Kit-kats (num in stock: 20): $1.75
[4] Almond Joy (num in stock: 15): $2.5
[5] Mounds (num in stock: 2): $2.25
[6] Three Musketeers (num in stock: 3): $2.25
[7] Nutrageous (num in stock: 5): $2.35
[8] Baby Ruth (num in stock: 0): $1.85
[9] Peanut M&M's (num in stock: 7): $1.95
[-1] Complete Purchase 
Enter Choice: 8

There are zero remaining in stock. Please choose again...
     Candy Shop:      
--------------------- 
[0] Reese's Peanut Butter Cups (num in stock: 10): $2.75
[1] Snickers (num in stock: 10): $2.55
[2] Paydays (num in stock: 10): $3.75
[3] Kit-kats (num in stock: 20): $1.75
[4] Almond Joy (num in stock: 15): $2.5
[5] Mounds (num in stock: 2): $2.25
[6] Three Musketeers (num in stock: 3): $2.25
[7] Nutrageous (num in stock: 5): $2.35
[8] Baby Ruth (num in stock: 0): $1.85
[9] Peanut M&M's (num in stock: 7): $1.95
[-1] Complete Purchase 
Enter Choice: -1

Thank you for your purchase!
You purchased 6 Baby Ruth

Your total cost: $11.1
    */
    
    return 0;
}