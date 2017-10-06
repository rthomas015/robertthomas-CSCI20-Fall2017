/*Assignment 2.0
  By: Robert Thomas
  Date: 10/03/2017
  Description: 
  The purpose of this program is to take the price of an item and calculate the sales tax. 
  The program will take into account the state, county, city, and special taxes of five 
  different pre-defined locations. The program will take 10 or more sales and then output 
  how much money will be sent to each state, county, and city.
*/

//preprocessor directives
#include <iostream>
#include <string>

using namespace std;

//Create a class called LocationTax, that stores the tax amounts of certain locations
//This allows for greater scalability and flexibility if you want to create new tax location 
//objects in the future.
class LocationTax {
    private:
        //Create variables for the class:
        //location_name_ is a string that holds the location's name (city, state)
        //The following double variables hold the tax rates in decimals for the location's: state_, city_, county_ and special_
        string location_name_;
        double state_, city_, county_, special_;
        
    public:
        //Setters/Mutators: these functions are all the class functions that can be called to change the values
        //of the class variables. Each is named after the variable it changes
        void SetLocation_Name(string location_name);
        void SetState (double state);
        void SetCity (double city);
        void SetCounty (double county);
        void SetSpecial (double special);
        
        //Getters/Accessors: these functions are all the class functions that can be called to return the values
        //of the various class variables (in this case the tax rate in decimals). Each is named after the corresponding variable it returns.
        string GetLocation_Name () const;
        double GetState () const;
        double GetCity () const;
        double GetCounty () const;
        double GetSpecial () const;
        
        //This class function takes in a double variable (sale) which is the amount of money from the sale that the user inputs
        //It prints out the corresponding state, city, county and special taxes along with the location_name
        void CalculateTaxes (double sale) const;
        
        //Print data function: this function prints out the information stored in each variable of the object
        //in this case the location's name, and tax rate for the state, city, county and special
        void Print () const;
        
};

//Sets location_name_ string variable in the form of (City, State Abbreviation)
void LocationTax::SetLocation_Name(string location_name) {
    location_name_ = location_name;
    return;
}

//Sets double variable state_ with the tax rate for the corresponding state
void LocationTax::SetState (double state) {
    state_ = state;
    return;
}

//Sets double variable city_ with the tax rate for the corresponding city
void LocationTax::SetCity (double city) {
    city_ = city;
    return;
}

//Sets double variable county_ with the tax rate for the corresponding county
void LocationTax::SetCounty (double county) {
    county_ = county;
    return;
}

//Sets double variable special_ with the tax rate for the corresponding special district
void LocationTax::SetSpecial (double special) {
    special_ = special;
    return;
}

//Returns the location_name string for the current object (city, state)
string LocationTax::GetLocation_Name () const {
    return location_name_;
}

//Returns the value stored in the object's state tax rate variable (the state tax for the corresponding state)
double LocationTax::GetState () const {
    return state_;   
}

//Returns the value stored in the object's city tax rate variable (the city tax for the corresponding area)
double LocationTax::GetCity () const {
    return city_;
}

//Returns the value stored in the object's county tax rate variable (the county tax for the corresponding area)
double LocationTax::GetCounty () const {
    return county_;
}

//Returns the value stored in the object's special tax rate variable (the special tax for the corresponding area)
double LocationTax::GetSpecial () const {
    return special_;   
}

//This class function takes in a double variable (sale) which is the amount of money from the sale that the user inputs
//It prints out the corresponding state, city, county and special taxes along with the location_name
void LocationTax::CalculateTaxes (double sale) const {
    //each line of the cout statement shows the sale being multiplied by the corresponding tax rate value to give the amount of money each area
    //generates in taxes from the sale
    cout << endl
         << location_name_ 
         << "  State:   $" << (state_ * sale)
         << "  County:  $" << (county_ * sale)
         << "  City:    $" << (city_ * sale)
         << "  Special: $" << (special_ * sale)
         << endl;
    
    return;
}

//Print data function: this function prints out the information stored in each variable of the object
//in this case the location's name, and tax rate for the state, city, county and special
void LocationTax::Print () const {
    cout << endl
         << " Location Name: " << location_name_
         << " State Taxes:   " << state_
         << " County Taxes:  " << county_
         << " City Taxes:    " << city_
         << " Special Taxes: " << special_
         << endl;
    return;
}

//Start of program (main function)
int main () {
    //Initialize variables needed for program:
    //Create five book objects
    LocationTax chico_ca, paradise_ca, sacramento_ca, las_vegas_nv, phoenix_az;
    //create a double variable called sale, so the user can input the amount for their sale
    double sale = 0.0;
    
    //Create Chico, CA TaxLocation object and set the tax rate charged by each locality
    chico_ca.SetLocation_Name ("Chico, CA");
    chico_ca.SetState (0.06);
    chico_ca.SetCity (0.0);
    chico_ca.SetCounty (0.0025);
    chico_ca.SetSpecial (0.01);
    
    //Create Paradise, CA TaxLocation object and set the tax rate charged by each locality
    paradise_ca.SetLocation_Name ("Paradise, CA");
    paradise_ca.SetState (0.06);
    paradise_ca.SetCity (0.005);
    paradise_ca.SetCounty (0.0025);
    paradise_ca.SetSpecial (0.01);
    
    //Create Sacramento, CA TaxLocation object and set the tax rate charged by each locality
    sacramento_ca.SetLocation_Name ("Sacramento, CA");
    sacramento_ca.SetState (0.06);
    sacramento_ca.SetCity (0.005);
    sacramento_ca.SetCounty (0.0025);
    sacramento_ca.SetSpecial (0.015);
    
    //Create Las Vegas, NV TaxLocation object and set the tax rate charged by each locality
    las_vegas_nv.SetLocation_Name ("Las Vegas, NV");
    las_vegas_nv.SetState (0.046);
    las_vegas_nv.SetCity (0.0);
    las_vegas_nv.SetCounty (0.0365);
    las_vegas_nv.SetSpecial (0.0);
    
    //Create Phoenix, AZ TaxLocation object and set the tax rate charged by each locality
    phoenix_az.SetLocation_Name ("Phoenix, AZ");
    phoenix_az.SetState (0.056);
    phoenix_az.SetCity (0.023);
    phoenix_az.SetCounty (0.007);
    phoenix_az.SetSpecial (0.0);
    
    //Print out to user showing each city's tax rates
    cout << endl << "Here is the corresponding tax rates for each location: " << endl;
    chico_ca.Print();
    paradise_ca.Print();
    phoenix_az.Print();
    las_vegas_nv.Print();
    sacramento_ca.Print();
    
    //This line demonstrates that the get functions work (also it changes the decimal into a percentage rate)
    cout << endl << "And here is Sacramento California's state tax rate: " << (sacramento_ca.GetState() * 100) << endl;
    
    //Get information from user on sales amount
    
    cout << endl << "Please enter the sale amount: ";
    cin >> sale;
    
    
    //Print out information for the sale and the sales tax that would be collected for each location
    cout << "Sale: $" << sale << endl
         << "Taxes (per location):" << endl;
    chico_ca.CalculateTaxes(sale);
    paradise_ca.CalculateTaxes(sale);
    sacramento_ca.CalculateTaxes(sale);
    las_vegas_nv.CalculateTaxes(sale);
    phoenix_az.CalculateTaxes(sale);
    
    //Output:
    //See document submitted with assignment
    
    return 0;
}