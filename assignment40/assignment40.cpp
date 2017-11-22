/*Assignment 4.0 - Test Grader
  By: Robert Thomas
  Date: 11/20/2017
  Description: This program will take input from a file (each student's test answers) then compare those answers to the answer key.
    Correct answers get 1 point, incorrect answers get negative 1/4 point, and abstaining from answering is 0 points. It will output
    to both the screen and to a file: the student's name, the list of missed questions, and the overall grade on the exam.
*/

//pre-processor directives
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//constant variables:
//NUMBER_OF_TEST_QUESTIONS holds the number of questions on the test
//NUMBER_OF_STUDENTS holds the number of students in the class/in the file
const int NUMBER_OF_TEST_QUESTIONS = 21;
const int NUMBER_OF_STUDENTS = 6;

//class TestGrader
class TestGrader {
    private:
        /*student_answers_file = the input file stream document that holds the students answers
          answer_key_file = the input file stream documment that holds the answer key
          test_score_file = the output file that holds the test scores from each individual
          answer_key_array = an array that holds all the values from the answer key file
          student_answer_array = a multidimensional array that holds the students answers for each student
          student_scores = an array that holds the test score of each student
        */
        
        ifstream student_answers_file;
        ifstream answer_key_file;
        ofstream test_score_file;
        string answer_key_array[NUMBER_OF_TEST_QUESTIONS];
        string student_answer_array[NUMBER_OF_STUDENTS][(NUMBER_OF_TEST_QUESTIONS+2)];
        double student_scores[NUMBER_OF_STUDENTS];
        
    public:
        //default constructor
        TestGrader (){
            //open these files by default
            student_answers_file.open ("studentanswers.txt");
            answer_key_file.open ("answerkey.txt");
            test_score_file.open ("testscore.txt");

            //read answer key into answer key array
            for (int i=0;i<NUMBER_OF_TEST_QUESTIONS;i++) {
                answer_key_file >> answer_key_array[i];
            }
            
            //read student's names and test answers into a multidimensional array
            for (int i=0;i<NUMBER_OF_STUDENTS;i++) {
                for (int j=0;j<(NUMBER_OF_TEST_QUESTIONS+2); j++) {
                    //!!!!add check for incorrect spacing in student answers document!!!
                    student_answers_file >> student_answer_array[i][j];
                }
            }
            
        }
        //overloaded constructor - probably not needed
        /*TestGrader (string input_file, string output_file) {
            student_answers_file.open (input_file);
            answer_key_file.open (output_file);
            
        }*/
        
        //generates the test scores for each student, by comparing their answers to the answer key
        void setTestScore (){
            
            //loops through each student
            for (int i=0;i<(NUMBER_OF_STUDENTS);i++) {
                //loops through each test question
                for (int j=0;j<(NUMBER_OF_TEST_QUESTIONS); j++) {
                    //tests to see if the answer is correct and awards a point
                    if (student_answer_array[i][(j+2)] == answer_key_array[j]) {
                        student_scores[i] = student_scores[i] + 1.0;
                    }
                    //tests to see if the answer is atleast attempted and wasn't left blank, if so add .75
                    else if ((student_answer_array[i][(j+2)] != answer_key_array[j]) && (student_answer_array[i][(j+2)] != "?")) {
                        student_scores[i] = student_scores[i] + 0.75;
                    }
                }
            }
            
        }
        
        //Prints to the screen and outputs to file
        void Print() {
            for (int i=0;i<(NUMBER_OF_STUDENTS);i++) {
                cout << student_answer_array[i][0] << " " << student_answer_array[i][1] << "  -- Score: " << student_scores[i] << endl;
                test_score_file << student_answer_array[i][0] << " " << student_answer_array[i][1] << "  -- Score: " << student_scores[i] << endl;
            }
        }
        
        //void 

        //close streams at end of program
        void closeStreams(){
            student_answers_file.close();
            answer_key_file.close();
        }
};

int main (){
    //string input_file,
    TestGrader newTest;
    
    newTest.setTestScore();
    newTest.Print();
    newTest.closeStreams();
    
    return 0;
}