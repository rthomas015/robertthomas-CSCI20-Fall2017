/*Lab 3.2 - Lab - Switch Case
  By: Robert Thomas
  Date: 10/11/2017
  Description: 
  The purpose of Lab 3.2 to create a program that will calculate income tax for an individual (amount owed or refund) based on 
  their: gross wages, filing status (single or married), name and tax withheld. 
*/

//preprocessor directives
#include <iostream>
#include <string>

using namespace std;

//Function to calculate taxes for a single individual
double CalculateTaxesSingle(double gross_wages) {
    double tax_owed = 0.0;
    
    
    //if/else statement to determine which bracket the individuals earnings will fall in to
    //and then use the appropriate equation to calculate the taxes owed
    if (gross_wages <= 9325.00) {
        tax_owed = gross_wages * .10;
    }
    else if ((gross_wages >= 9326.00) && (gross_wages <= 37950.00)) {
        tax_owed = 932.50 + ((gross_wages - 9325.00) * .15);
    }
    else if ((gross_wages >= 37951.00) && (gross_wages <= 91900.00)) {
        tax_owed = 5226.25 + ((gross_wages - 37950.00) * .25);
  	}
	else if ((gross_wages >= 91901.00) && (gross_wages <= 191650.00)) {
	    tax_owed = 18713.75 + ((gross_wages - 91900.00) * .28);
    }
	else if ((gross_wages >= 191651.00) && (gross_wages <= 416700.00)) {
	    tax_owed = 46643.75 + ((gross_wages - 191650.00) * .33);
    }
	else if (gross_wages >= 416701.00) {
	    tax_owed = 120910.25 + ((gross_wages - 416700.00) * .396);
    }

   return tax_owed;
}


//function to calculate taxes for a married couple
double CalculateTaxesMarried(double gross_wages) {
    double tax_owed = 0.0;
    
    //if/else statement to determine which bracket the individuals earnings will fall in to
    //and then use the appropriate equation to calculate the taxes owed
    if (gross_wages <= 18650.00) {
        tax_owed = gross_wages * .10;
    }
   	else if ((gross_wages >= 18651.00) && (gross_wages <= 75900.00)) {
   	    tax_owed = 1865.00 + ((gross_wages - 18650.00) * .15);
    }
  	else if ((gross_wages >= 75901.00) && (gross_wages <= 153100.00)) {
        tax_owed = 10452.50 + ((gross_wages - 75900.00) * .25);
    }
	else if ((gross_wages >= 153101.00) && (gross_wages <= 233350.00)) {
        tax_owed = 29752.50 + ((gross_wages - 153100.00) * .28);
    }
	else if ((gross_wages >= 233351.00) && (gross_wages <= 416700.00)) {
        tax_owed = 52222.50 + ((gross_wages - 233350.00) * .33);
    }
	else if (gross_wages >= 416701.00) {
        tax_owed = 112728.00 + ((gross_wages - 470700.00) * .396);
    }

   return tax_owed;
}

//Start of main program
int main () {
   //variable declaration
   /*
    gross_wages = individual's gross wages for the year
    tax_withheld = the individual's taxes withheld already for the year
    full_name = the string that holds the individuals full name
    married = char [y]es or [n]o which holds input from user on if they are married or not
    net_taxes = the amount of tax either as a refund or owed by the individual after all calculations are complete
   */ 
   double gross_wages = 0.0,
	  tax_withheld = 0.0,
	  tax_owed = 0.0,
	  net_taxes = 0.0;
   string full_name = "";
   char married = 'n';

   //prompt user and retrieve input from user
   cout << "Please input your name (first and last name separated by underscores): ";
   cin >> full_name;
   cout << endl
        << "please input your marital status [married: y / single: n]: ";
   cin >> married;
   cout << endl
        << "Please input your gross wages: ";
   cin >> gross_wages;
   cout << endl
        << "Please input the amount of taxes withheld: ";
   cin >> tax_withheld;

   //switch statement based on if they are single or married
   //each case calls a separate function depending on their marital status
   switch (married) {
    //if married is [y]es then execute this code
	case 'y':
		gross_wages = gross_wages - 16750.00;
		if(gross_wages > 0)
		   tax_owed = CalculateTaxesMarried (gross_wages);
		break;
	//if married is [n]o then execute this code
	case 'n':
		gross_wages = gross_wages - 10400.00;
		if (gross_wages > 0)
		   tax_owed = CalculateTaxesSingle (gross_wages);
		break;
	default:
		cout << "invalid character was input for marital status." << endl;
   }
   
   
    //determine net_taxes (negative amount is a refund and a positive amount is the amount of taxes owed)
    net_taxes = tax_owed - tax_withheld;

    //output information to user
    cout << endl
         << "Name: " << full_name
         << endl
         << "Total Gross Adjusted Income: " << gross_wages
         << endl
         << "Total tax owed: " << tax_owed;

    //if/else statement to determine if the net_taxes are positive or negative
	if(net_taxes >= 0) {
		cout << endl
		     << full_name << " must still pay $" << net_taxes << " in taxes.";
	}
	else if (net_taxes < 0) {
		net_taxes *= -1;
		cout << endl
		     << full_name << " is entitled to a refund of $" << net_taxes;
	}

   return 0;
}