/*Lab 1.3 - Integers
* By: Robert Thomas
* Date: 8/31/2017
* 
* This program will take an integer from a user (the number of years)
* and estimate what the US population will be in that many years. The program
* utilizes the birth rate and death rate, but not the 'net rate' listed on
* US Census website
*/


//Preprocessor directives
#include <iostream>
using namespace std;


//Start of program

int main () {
    
    int total_future_population = 0, current_population = 0, number_of_years_to_sim = 0, seconds_between_deaths = 0, seconds_between_births = 0, seconds_in_a_year = 31536000, simulation_year = 0, current_year = 0;
    
    
    cout << "-Future U.S. Population Estimator-" << endl
         << "----------------------------------" << endl << endl;
    
    //Gather information from user
    cout << "Please enter a number of years for simulation to run: ";
    cin >> number_of_years_to_sim;
    
    cout << endl << "Please enter the current population of the United States: ";
    cin >> current_population;
    
    cout << endl << "Please enter the current year (e.g. 2017): ";
    cin >> current_year;
    
    cout << endl << "Please enter the number of seconds between births: ";
    cin >> seconds_between_births;
    
    cout << endl << "Please enter the number of seconds between deaths: ";
    cin >> seconds_between_deaths;
    
    //calculate total future population
    total_future_population = current_population + (((seconds_in_a_year / seconds_between_births) - (seconds_in_a_year / seconds_between_deaths)) * number_of_years_to_sim);
    
    //calculate the simulation year
    simulation_year = current_year + number_of_years_to_sim;
    
    cout << endl << "The total future population in the year " << simulation_year << " is estimated to be " << total_future_population << "." << endl;
    
    return 0;
}