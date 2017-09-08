/*Lab 1.5 - Madlibs
  Madlibs
  By: Robert Thomas
  Date: 9/7/2017
  Description: This program involves writing a madlib - a paragraph with five or more variables
  in the paragraph that can be changed such as adjectives, nouns, etc.
*/

//Pre-processor directives
#include <iostream>
using namespace std;

//Start of Program
int main () {
    string adjective_0 = "fourteen",
           adjective_1 = "four",
           adjective_2 = "splendid",
           adjective_3 = "zero",
           noun_0 = "chicken breast",
           noun_1 = "way too expensive kibble";
          
    cout << "Enter four adjectives (separated by a space): ";
    cin >> adjective_0 >> adjective_1 >> adjective_2 >> adjective_3;
    cout << endl << "Enter two nouns (separated by a space): ";
    cin >> noun_0 >> noun_1;
           
    cout << "I wish my life was like my dog Layla's. I would get to sleep "
         << adjective_0 << " hours a day. Every day I would get to eat " 
         << adjective_1 << " large meals of "
         << noun_0 << " (and " << noun_1 << "). I wouldn't have to work ten hours a day and have to put up with such " 
         << adjective_2 << " clients and coworkers. I could sit and watch daytime television and wear "
         << adjective_3 << " pairs of pants.";
         
    return 0;
}