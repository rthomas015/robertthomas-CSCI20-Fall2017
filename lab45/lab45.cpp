/*Lab 4.5 - String
  By: Robert Thomas
  Date: 11/14/2017
  Description: This program will help create user names for a website. It will take user input (first name max 10 characters, and a second name
  max 20 characters). After checking to see if the names are the same (and outputting a warning) and checking to see if the name supplied is larger than
  the max allowable. This program uses strings.
*/

//preprocessor directives
#include <iostream>
#include <string>
 
using namespace std;

//start of main program
int main () {
    
    //create five string variables
    /*
        first_name = holds the first name input by the user
        second_name = holds the second name input by the user
        generated_string_1 = holds the first generated string
        generated_string_2 = holds the second generated string
        generated_string_3 = holds the third generated string
    */
    
    string first_name = "",
           second_name = "",
           generated_string_1 = "",
           generated_string_2 = "",
           generated_string_3 = "";
    
    //request input from user
    cout << "Website Name Generator" << endl
         << "======================" << endl
         << "Input a first name: ";
    cin >> first_name;
    //test to see if the first name is larger than ten characters, if so keep looping until the user inputs a value that is 10 or less characters
        while (first_name.size() > 10) {
            cout << endl << "The first name provided exceeds 10 characters. Input another name: ";
            cin >> first_name;
        }
        
    cout << endl << "Input a second name: ";
    cin >> second_name;
    //test to see if the second name is larger than twenty characters, if so keep looping until the user inputs a value that is 20 or less characters
        while (second_name.size() > 20) {
            cout << endl << "The second name provided exceeds 20 characters. Input another name: ";
            cin >> second_name;
        }
    
    //test to see if the strings are equal to each other and if they are issue the warning
    if (second_name == first_name)
        cout << endl << "Warning: These names are the same." << endl;

    //generate each individual string based on the example output in lab information
    //first generated string you replace everything after the first two characters in the string with the second user provided string
    generated_string_1 = first_name;
    generated_string_1.replace(2,(generated_string_1.size()- 2), second_name);
 
    //second generated string you append the second user provided string to the end of the first user provided string   
    generated_string_2 = first_name;
    generated_string_2.append(second_name);
    
    //third generated string you replace everything after the first character in the string with the second user provided string
    generated_string_3 = first_name;
    generated_string_3.replace(1,(generated_string_3.size() - 1), second_name);

    //change generated_string_1 to lower case
    //loop through each character
    for (int i=0; i<(generated_string_1.size()); i++) {
        //and then test if the value at that string location is capitalized, if it is convert it to a lower case character
        if((static_cast<char>(generated_string_1.at(i)) >= 'A' ) && (static_cast<char>(generated_string_1.at(i)) <= 'Z')) {
            generated_string_1.at(i) = static_cast<char>(generated_string_1.at(i)) + 32;
        }
    }
 
    //change generated_string_2 to lower case
    //loop through each character
    for (int i=0; i<(generated_string_2.size()); i++) {
        //and then test if the value at that string location is capitalized, if it is convert it to a lower case character
        if((static_cast<char>(generated_string_2.at(i)) >= 'A' ) && (static_cast<char>(generated_string_2.at(i)) <= 'Z')) {
            generated_string_2.at(i) = static_cast<char>(generated_string_2.at(i)) + 32;
        }
    }
    
    //change generated_string_3 to lower case
    //loop through each character
    for (int i=0; i<(generated_string_3.size()); i++) {
        //and then test if the value at that string location is capitalized, if it is convert it to a lower case character
        if((static_cast<char>(generated_string_3.at(i)) >= 'A' ) && (static_cast<char>(generated_string_3.at(i)) <= 'Z')) {
            generated_string_3.at(i) = static_cast<char>(generated_string_3.at(i)) + 32;
        }
    }
    
    //Output information to user of program (all three generated names)
    cout << endl << "--Generated Name Options--" << endl
         << generated_string_1 << endl
         << generated_string_2 << endl
         << generated_string_3;
    
    //Output:
    /*
    
1.)    Website Name Generator
======================
Input a first name: Robert 

Input a second name: Thomas

--Generated Name Options--
rothomas
robertthomas
rthomas

2.) Website Name Generator
======================
Input a first name: April

Input a second name: Browne

--Generated Name Options--
apbrowne
aprilbrowne
abrowne

3.) Website Name Generator
======================
Input a first name: AnaElizabeth

The first name provided exceeds 10 characters. Input another name: Ana

Input a second name: Hazeltine-Smith

--Generated Name Options--
anhazeltine-smith
anahazeltine-smith
ahazeltine-smith

4.) Website Name Generator
======================
Input a first name: James

Input a second name: James

Warning: These names are the same.

--Generated Name Options--
jajames
jamesjames
jjames
    
    */
    
    return 0;
}