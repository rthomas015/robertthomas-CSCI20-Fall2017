/*Lab 3.5 - Lab - Classes and Constructors
  By: Robert Thomas
  Date: 10/24/2017
  Description: 
  The purpose of Lab 3.5 is to create a class that converts temperatures from
  fahrenheit, celsius or kelvin in to kelvin, and converts the kelvin value in
  to fahrenheit or celsius. The class uses a default constructor and an overloaded
  constructor as well, which set the value of the kelvin_ variable of the class appropriately.
*/

//pre-processor directives
#include<iostream>
using namespace std;

//TemperatureConverter class 
//This class holds all the temperature conversion functions required for the program
class TemperatureConverter {
    //create a private variable kelvin_ that holds the temperature in kelvin
	private:
		double kelvin_;
	//section holding all the public functions of the TemperatureConverter class
	public:
		//Constructor function of the class
		//Sets the value of kelvin_ to 0.0
		TemperatureConverter() {
			kelvin_ = 0.0;
		}

		//Overloaded constructor function of the class
		//to be used when there is already a value for kelvin that needs to be used
		//If kelvin is less than zero, which is impossible, the function sets kelvin_ to 0.0
		TemperatureConverter(double kelvin) {
			if (kelvin > 0) {
				kelvin_ = kelvin;
			}
			else {
				kelvin_ = 0.0;
			}
		}

		//Sets the private variable kelvin to the value supplied
		//If kelvin is less than zero however which is impossible, the function sets kelvin_ to 0.0
		void SetTempFromKelvin (double kelvin) {
			if (kelvin > 0) {
				kelvin_ = kelvin;
			}
			else {
				kelvin_ = 0.0;
			}
		}
        //function that takes in a value in degrees celsius and converts it to kelvin
        //then sets the variable kelvin_ to that value. The function like those above checks
        //to make sure that the value passed to it is not a temperature less than absolute zero
		void SetTempFromCelsius(double celsius){
            if (celsius > -273.15) {
                kelvin_ = celsius + 273.15;
            }
            else {
                kelvin_ = 0.0;
            }
		}
		//function that takes in a value in degrees fahrenheit and converts it to kelvin
        //then sets the variable kelvin_ to that value. The function like those above checks
        //to make sure that the value passed to it is not a temperature less than absolute zero
		void SetTempFromFahrenheit(double fahrenheit){
            if (fahrenheit > -459.67) {
                kelvin_ = (5 * (fahrenheit - 32)/9) + 273.15;
            }
            else {
                kelvin_ = 0.0;
            }
		}
        //returns the value in kelvin
		const double GetTempFromKelvin(){
            return kelvin_;
		}
        //returns the value held in variable kelvin_ in degrees celsius
		const double GetTempAsCelsius() {
		    return (kelvin_ - 273.15);
		}
        //returns the value held in variable kelvin_ in degrees fahrenheit
		const double GetTempAsFahrenheit (){
		    return (((kelvin_ - 273.15)*9)/5 + 32);
		}
        //print function of the class that outputs the value held in kelvin_
        //as fahrenheit, celsius and kelvin
		const void PrintTemperatures (){
            cout << endl << "Fahrenheit: " << GetTempAsFahrenheit()
                 << endl << "Celsius: " << GetTempAsCelsius()
                 << endl << "Kelvin: " << GetTempFromKelvin();
		}

};

//start of main program
int main ()
{
    //create temp1 and temp2 instance of TemperatureConverter class
    //one using default constructor and the other using the overloaded constructor
    TemperatureConverter temp1; //testing default constructor
    TemperatureConverter temp2(274); //testing overloaded constructor

    //print out the values of the object temp1 and temp2
    temp1.PrintTemperatures();
    temp2.PrintTemperatures();

    temp1.SetTempFromKelvin(400.15); //testing mutator function
    cout<<temp1.GetTempFromKelvin()<<endl;//testing accessor function
    temp1.PrintTemperatures();

    temp2.SetTempFromCelsius(32); //testing other functions
    cout<<temp2.GetTempAsCelsius()<<endl;
    temp2.PrintTemperatures();

    temp2.SetTempFromFahrenheit(32); //testing fahrenheit function
    cout<<temp2.GetTempAsFahrenheit()<<endl;
    temp2.PrintTemperatures();

    return 0;
}
