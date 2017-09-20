/*Lab 2.1 - Lab - Calling Functions
  Calling Functions
  By: Robert Thomas
  Date: 9/19/2017
  Description: This program will take input from a user (temperature and velocity) and determine the 
  windchill using two methods (an old method and a new method). This information is output to the user.
*/

//preprocessor directives
#include <iostream>
#include <cmath>
using namespace std;

//Function to calculate old style windchill
double old_style_windchill (double temp, double velocity) {
    double windchill = (.081 * ((3.71 * sqrt(velocity)) + 5.81 - (.25 * velocity)) * (temp - 91.4)) + 91.4;
    return windchill;
}

//Function to calculate new style windchill
double new_style_windchill (double temp, double velocity) {
    double windchill = (35.74 + (.6215 * temp) - (35.75 * pow(velocity,.16)) + (.4275 * temp * pow(velocity,.16)));
    return windchill;
}

int main () {
    //initialize variables needed
    double temp = 0.0, velocity = 0.0;
    
    //take input from user on wind speed/velocity and temperature
    cout << "Calculate old style and new style windchill" << endl
         << "-------------------------------------------" << endl;
        
    cout << "Enter temperature (in F): ";
    cin >> temp;
    cout << endl << "Enter wind velocity: ";
    cin >> velocity;
    
    //Output Wind Speed, Old Formula, New Formula, Difference between two styles
    cout << endl << "Wind Speed     Old Formula     New Formula     Difference" 
         << endl << velocity 
         << "              " << old_style_windchill(temp, velocity)
         << "       " << new_style_windchill(temp, velocity)
         << "       " << abs(old_style_windchill(temp, velocity) - new_style_windchill(temp, velocity));
    
    /*Program output
        Wind Speed     Old Formula     New Formula     Difference
            4              30.5753       25.767        4.8083
            10             27.8601       32.713        4.85286
            2              98.7538       105.711       6.95719
    
    */
    
    return 0;
}