/*Lab 4.4 - C Strings
  By: Robert Thomas
  Date: 11/14/2017
  Description: This program will help create user names for a website. It will take user input (first name max 10 characters, and a second name
  max 20 characters). After checking to see if the names are the same (and outputting a warning) and checking to see if the name supplied is larger than
  the max allowable. This program uses C strings.
*/

//preprocessor directives
#include <iostream>
#include <cstring>

using namespace std;

//start of main program
int main () {
    
    //create five C string variables
    /*
        first_name = holds the first name input by the user
        second_name = holds the second name input by the user
        generated_string_1 = holds the first generated string
        generated_string_2 = holds the second generated string
        generated_string_3 = holds the third generated string
    */
    
    char first_name [10] = "",
           second_name [20] = "",
           generated_string_1[30] = "",
           generated_string_2[30] = "",
           generated_string_3[30] = "";


    //request input from user
    cout << "Website Name Generator" << endl
         << "======================" << endl
         << "Input a first name: ";
    cin >> first_name;
    //test to see if the first name is larger than ten characters, if so keep looping until the user inputs a value that is 10 or less characters
        while ((strlen(first_name)) > 10) {
            cout << endl << "The first name provided exceeds 10 characters. Input another name: ";
            cin >> first_name;
        }
        
    cout << endl << "Input a second name: ";
    cin >> second_name;
    //test to see if the second name is larger than twenty characters, if so keep looping until the user inputs a value that is 20 or less characters
        while ((strlen(second_name)) > 20) {
            cout << endl << "The second name provided exceeds 20 characters. Input another name: ";
            cin >> second_name;
        }
    
    //test to see if the strings are equal to each other and if they are issue the warning
    if (!(strcmp(first_name,second_name)))
        cout << endl << "Warning: These names are the same." << endl;

    //generate each individual string based on the example output in lab information
    //Set each generated_string to the first_name
    for (int i=0; i<(strlen(first_name)); i++) {
       generated_string_1[i] = first_name[i];
       generated_string_2[i] = first_name[i];
       generated_string_3[i] = first_name[i];
    }
    
    //first generated string you replace everything after the first two characters in the string with the second user provided string
    for (int i=0; i<=(strlen(second_name)); i++) {
        //generated_string_1.replace(2,(generated_string_1.size()- 2), second_name);
        generated_string_1[i+2] = second_name[i];
    }

    //second generated string you append the second user provided string to the end of the first user provided string   
    for (int i=0; i<(strlen(second_name)); i++) {
        //generated_string_2.append(second_name);
        int x = (i+(strlen(first_name)));
        generated_string_2[x] = second_name[i];
    }

    
    //third generated string you replace everything after the first character in the string with the second user provided string
    for (int i=0; i<=(strlen(second_name)); i++) {
        //generated_string_3.replace(1,(generated_string_3.size() - 1), second_name);
        generated_string_3[i+1] = second_name[i];
    }
    

    //change generated_string_1 to lower case
    //loop through each character
    for (int i=0; i<(strlen(generated_string_1)); i++) {
        //convert it to a lower case character
        generated_string_1[i] = tolower(generated_string_1[i]);
    }
    //change generated_string_2 to lower case
    //loop through each character
    for (int i=0; i<(strlen(generated_string_2)); i++) {
        //convert it to a lower case character
        generated_string_2[i] = tolower(generated_string_2[i]);
    }
    
    //change generated_string_3 to lower case
    //loop through each character
    for (int i=0; i<(strlen(generated_string_3)); i++) {
        //convert it to a lower case character
        generated_string_3[i] = tolower(generated_string_3[i]);
    }
    
    //Output information to user of program (all three generated names)
    cout << endl << "--Generated Name Options--" << endl
         << generated_string_1 << endl
         << generated_string_2 << endl
         << generated_string_3;
    
    //Output:
    /*
    1.) Website Name Generator
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