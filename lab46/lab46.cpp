/*Lab 4.6 - File Input/Output
  By: Robert Thomas
  Date: 11/16/2017
  Description: This program will take input from a text file and parse it, and output the information to
  an html file with some minimal formatting to make it readable.
*/

//preprocessor directives
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

//start of main program
int main () {
    //create input file stream object named grade_file
    ifstream grade_file;
    //create an output file stream object named html_output
    ofstream html_output;
    //grade_file_name - holds the grade file's name/location 
    //file_conents - string that holds the information retrieved from the ifstream
    string grade_file_name = "",
           file_contents = "";
    //grade_letter - a char that holds the grade letter of the student retreived from the ifstream
    char grade_letter;
           
    //number_of_classes - integer holding the number of classes
    int number_of_classes = 0,
        total_units = 0,
        number_of_units = 0;
    
    double grade_point_average = 0.0;
    
    html_output.open("index.html");
    
   //Request input file's name  
    cout << "Please enter the name of the grade file: ";
    cin >> grade_file_name;
    
    grade_file.open(grade_file_name);
    
    //Test to make sure the file exists and is open for reading
    while (!grade_file.is_open()) {
        cout << endl << "The file you attempted to open doesn't exist or is not accessible, please input another: ";
        cin >> grade_file_name;
        grade_file.open(grade_file_name);
    }

  
    bool line_is_a_name = true;
    html_output << "<HTML><HEAD><TITLE>List of Grades</TITLE></HEAD><BODY><BR><BR><H1>List of Student Grades</H1>";
    html_output << "<PRE>Name:                  Class #:    Units:    Grade:</PRE>";
   
    while (!grade_file.eof()) {
            //if this part of the file is a name
            if (line_is_a_name == true) {
                getline(grade_file, file_contents);
                html_output << "<PRE>" << file_contents << endl;
                line_is_a_name = false;
            }
            else if (line_is_a_name == false) {
                //then it is the number of classes that person is taking
                //cin.ignore(); //clear stream
                grade_file >> number_of_classes;
                //use the number of classes as a loop and
                //loop through the next line
                    for (int i=1;i<=number_of_classes;i++) {
                        grade_file >> number_of_units;
                        grade_file >> grade_letter;
                        html_output << endl << "<br>                               " << i << "      " << number_of_units << "      " << grade_letter << endl;
                        total_units = total_units + number_of_units;
                        switch (grade_letter) {
                            case 'A':
                                grade_point_average = grade_point_average + ((number_of_units) * 4);
                                break;
                            case 'B':
                                grade_point_average = grade_point_average + ((number_of_units) * 3);
                                break;
                            case 'C':
                                grade_point_average = grade_point_average + ((number_of_units) * 2);
                                break;
                            case 'D':
                                grade_point_average = grade_point_average + ((number_of_units) * 1);
                                break;
                            case 'F':
                                grade_point_average = grade_point_average + ((number_of_units) * 0);
                                break;
                        }

                    }
                grade_point_average = (grade_point_average / total_units);
                html_output << "<br>                                                    GPA: " << grade_point_average << setprecision(3) << "</PRE><BR>";
                grade_point_average = 0.0;
                total_units = 0;
                grade_file.ignore();
                getline(grade_file, file_contents);
                line_is_a_name = true;
            }
    } //reached end of file
    

    
    html_output << "</BODY></HTML>";

    grade_file.close();
    html_output.close();
    
    
    //Output:
    /*
    Program outputs to HTML file:
    
    <HTML><HEAD><TITLE>List of Grades</TITLE></HEAD><BODY><BR><BR><H1>List of Student Grades</H1><PRE>Name:                  Class #:    Units:    Grade:</PRE><PRE>Suzy Cue

<br>                               1      3      A

<br>                               2      3      A

<br>                               3      3      A

<br>                               4      3      B
<br>                                                    GPA: 3.75</PRE><BR><PRE>Joe Joseph

<br>                               1      4      D

<br>                               2      3      C

<br>                               3      3      B

<br>                               4      3      C
<br>                                                    GPA: 1.92</PRE><BR><PRE>Jillian Smith

<br>                               1      4      C

<br>                               2      3      C

<br>                               3      4      C

<br>                               4      3      B

<br>                               5      3      C
<br>                                                    GPA: 2.18</PRE><BR></BODY></HTML>
     */
    
    return 0;
}