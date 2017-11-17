/*Lab 4.6 - File Input/Output
  By: Robert Thomas
  Date: 11/16/2017
  Description: This
*/

//preprocessor directives
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//start of main program
int main () {
    ifstream grade_file;
    ofstream html_output;
    string grade_file_name = "",
           file_contents = "";
    char grade_letter;
           
    int number_of_classes = 0,
        total_units = 0,
        number_of_units = 0;
    
    double grade_point_average = 0.0;
    
    html_output.open("index.html");
    
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
    html_output << "<HTML><HEAD><TITLE>List of Grades</TITLE></HEAD><BODY><BR><BR><H1>List of Student Grades:</H1>" << endl;
   
    while (!grade_file.eof()) {
            if (line_is_a_name == true) {
                getline(grade_file, file_contents);
                //then its a name
                html_output << "Name: " << file_contents << "<BR>" << endl;
                line_is_a_name = false;
            }
            else if (line_is_a_name == false) {
                //then it is the number of classes
                cin.ignore();
                grade_file >> number_of_classes;
                //use the number of classes as a loop and
                //loop through the next line
                    for (int i=1;i<=number_of_classes;i++) {
                        grade_file >> number_of_units;
                        grade_file >> grade_letter;
                        cout << endl << "<br>" << "Class #" << i << ": " << grade_letter << endl
                             << "<br> Number of Units: " << number_of_units;
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
                cout << "GPA: " << grade_point_average;
                //grade_point_average = 0;
                grade_file >> file_contents;
                line_is_a_name = true;
            }
    }
    

    
    /*
 html_output << file_contents << endl;
    html_output << "</BODY></HTML>";
    */
    grade_file.close();
    html_output.close();
    
    
    //Output:
    /*
     */
    
    return 0;
}