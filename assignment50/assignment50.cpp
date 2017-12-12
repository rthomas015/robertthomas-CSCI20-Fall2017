/*Assignment 5.0 - Steganographic demonstration
  By: Robert Thomas
  Date: 12/12/2017
  Description: This program will take a text message from the user, change it into binary
  and then input that information into another image file (output). The program is a basic
  demonstration of the concept of steganography.
*/

//pre-processor directives
#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
#include <limits> 

using namespace std;

//Class that holds the image file, along with the functions that operate on that file
class Image {
    private:
        /*  file objects:
            image_input - the image file we are receiving input from
            image_output - the image file we are outputting to
        */
        ifstream image_input;
        ofstream image_output;
       
       /*   other class variables:
            num_of_lines = counts the number of lines in the image file
            key = the place in the image file where the bit will be altered
                works as a multiple (e.g. key = 10, means everything 10th bit)
            curr_pixel = temporary holds each bit of data of the image file
            image_array = holds the full image in memory
       */
        int num_of_lines,
            key;
        char curr_pixel;
        char* image_array = new char[1300000];
       
    public:
        //constructor
        Image () {
            //set default values of variables
            key = 1000,
            num_of_lines = 0;
            
            image_input.open("duck.ppm");
            if (!image_input.is_open()) {
                cout << "Error reading duck.ppm" << endl;
                return 1;
            }
            
            
            image_output.open("output_generic.ppm");
            if (!image_output.is_open()) {
                cout << "Error reading/opening output_generic" << endl;
                return 1;
            }
            
        }
        
        
        //constructor w/ specific key value
        Image (int key_num) {
            key = key_num;
            num_of_lines = 0;
            
            image_input.open("duck.ppm");
            if (!image_input.is_open()) {
                cout << "Error reading duck.ppm" << endl;
                return 1;
            }
            
            image_output.open("output_special.ppm");
            if (!image_output.is_open()) {
                cout << "Error reading/opening output_generic" << endl;
                return 1;
            }
        }
        
        //deconstructor class
        ~Image () {
            //close files
            image_input.close();
            image_output.close(); 
            delete image_array;
        }
        
        //read from file and input into image_array
        void readImage() {
            //iterate until the end of file
            while (!image_input.eof()) {
                curr_pixel = image_input.get();
       
                //Had to add this test since eof doesn't really function correctly as a while loop
                //test and adds one extra line of information
                if(!image_input.eof()) {
                    image_array[num_of_lines] = curr_pixel;
                    num_of_lines += 1;
                }
            }
        }
        
        //write binary message into the array holding the image
        void writeMessage(string binary_message) {
                //loop until the full message has been input into the image file
                for(int i=0;i<binary_message.length();i++) {
                    //change the number held in the image file at an interval
                    //(interval set by key)
                    image_array[((i+1)*key)] = binary_message.at(i);
                }
                
                //write array to output image file
                for(int i=0;i<num_of_lines;i++) {
                    image_output << image_array[i];
                }
        }
};

int main () {
    
    /*create file object for message.txt
      create image object
      string hidden_message = user input message or input from message.txt
             binary_message = the message converting into binary
    */
    ifstream text_input;
    string hidden_message, binary_message;
    int key;
    
    //user input
    cout << "Input the message you want to hide (or press enter to use message.txt): ";
    getline(cin, hidden_message);
   

    //test to see if line is empty if so use message.txt
    if (hidden_message.empty()) {
        //read in hidden message
        text_input.open("message.txt");
            if (!text_input.is_open()) {
                cout << "Could not open message.txt" << endl;
                return 1;
            }
        while (!text_input.eof()) {
            getline(text_input, hidden_message);
        }
        text_input.close();
    }
    cout << "Input the key (over 100): ";  
    cin >> key;
    cin.clear();

    while (key < 100) {
        cout << endl << "Input a key (over 100): ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
    }   
    
    Image duck_special(key);
    Image duck_generic;
    
    //convert message to binary
    for (int i=0;i<hidden_message.length(); i++) {
        binary_message.append(bitset<8>(hidden_message[i]).to_string());
    }
    
    //create an object with the special key value
    duck_special.readImage();
    duck_special.writeMessage(binary_message);
    
    //create an object with the default key value
    duck_generic.readImage();
    duck_generic.writeMessage(binary_message);
    
    return 0;
}