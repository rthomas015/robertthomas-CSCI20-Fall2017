/*Lab 4.1 - Single Arrays
  By: Robert Thomas
  Date: 10/30/2017
  Description: Create a class that stores a single array and has a set of functions that can be used 
  with that array: printing the members of the array, finding the location of the minimum value, 
  finding the maximum value, finding the sum of the values of the array, finding the number of even numbers, 
  finding the number of odd numbers in the array, searching the array and checking to see if the array is 
  sorted in ascending order.
*/

//preprocessor directives
#include <iostream>

using namespace std;


//Start of class ArrayTools
class ArrayTools {
    private:
        //create an array that holds ten values
        int array_[10];
        
    public: 
        //Set the class array based on the values held in myArray
        ArrayTools (int myArray[], int size) {
            
            for (int i=0;i<10;i++) {
               array_[i] = myArray[i];   
            }
            /*for (int i=0;i<10;i++) {
                cout << endl << "Enter #" << i << ":";
                cin >> array_[i];
            }*/
        }
        
        //Prints all values in the array
        const void Print() {
            //for loop that loops through each location of the array
            for (int i=0; i<10; i++){
                cout << endl << array_[i];
            }
        }
        
        //function to find the minimum value held in the array and return its location
        const int Find_min (int start, int stop) {
            //set the minimum to the value held in the array at the starting point
            //and set the location to the starting point
            int minimum = array_[start],
                location = start;
            
            //loop through to test if the next value is smaller than the current
            for (int i=start; i<stop; i++) {
                if (minimum > array_[i]) {
                    minimum = array_[i];
                    location = i;
                }
            }
            return location;
        }
        
        //function to find the maximum value held in the array and return its location
        const int Find_max (int start, int stop) {
            //set the maximum to the value held in the array at the starting point
            //and set the location to the starting point
            int maximum = array_[start],
                location = start;
            
            //loop through to test if the next value is smaller than the current
            for (int i=start; i<stop; i++) {
                if (maximum < array_[i]) {
                    maximum = array_[i];
                    location = i;
                }
            }
            return location;
        }
        
        //function to sum all values in the array and then return the sum
        const int Find_sum () {
            int sum = 0;
            
            //iterate through the array and add each to the value of sum
            for (int i=0; i <10; i++) {
                sum = sum + array_[i];
            }
            return sum;
        }
        
        //count number of even numbers in array
        const int Num_even () {
            int even = 0;
            
            //iterate through the array and add a one to the even counter every time
            //that there is an even number
            for (int i=0; i<10;i++) {
                if (array_[i] % 2)
                    even += 1;
            }
            
            return even;
        }
        //count number of odd numbers in the array
        const int Num_odd () {
            int odd = 0;
            
            //iterate through the array and add one to the odd counter every time
            //that there is an odd number (or in this case not an even number)
            for (int i=0; i<10;i++) {
                if (!(array_[i] % 2))
                    odd += 1;
            }
            
            return odd;
        }
        
        //search for a specified value and return its location otherwise return -1 if not found
        //if multiple values match specified_value, then it returns only one location value
        //the one that is closest to the end of the array
        const int Search (int specified_value) {
            int location = -1;
            
            //iterate through the array and if the value is found set the location to its location in the array
            for (int i=0; i<10; i++) {
                if (array_[i] == specified_value)
                    location = i;
            }
            
            return location;
        }
        
        //function to check whether the array is sorted in ascending order
        const bool Is_sorted () {
            bool Is_sorted = true;
            
            //iterate through the array and test to see each value is larger than the last
            for (int i=0;i<10;i++) {
                if ((i != 0) && (array_[i] < array_[(i-1)]))
                    Is_sorted = false;
            }
            
            return Is_sorted;
        }
};

//Start of program
int main () {
    //Create variables: 
    /*
      constant SIZE set to 10
      create an array of ints called myArray of size SIZE
      
    */
    const int SIZE = 10;
    int myArray[SIZE];
    
    //initalize array to 0 in all indexes
    for(int i = 0; i<SIZE;i++){
        myArray[i] = 0;
    }
    
    //take input from user to populate the array
    for(int i = 0; i<SIZE;i++){
        cout << endl << "Enter #" << i << ":";
        cin >> myArray[i];
    }
    
    //create an ArrayTools object named 'a' and upon creation pass the array by reference and pass the 
    //size by value to the constructor function of the object
    ArrayTools a(myArray,SIZE);
    cout << endl;
    
    //print out all the values held in the array of object a
    a.Print();
    
    //find the location of the minimum value between location 0 and 4
    cout<< endl << "Min: "<<a.Find_min(0, 4)<<endl;
    
    //find the location of the maximum value between location 5 and 10
    cout<< endl << "Max: "<<a.Find_max(5, 10)<<endl;
    
    //find the sum of all the values in the array
    cout<<endl << "Sum = "<<a.Find_sum()<<endl;
    
    //search the array for the number 10
    cout<<endl << "Search 10: "<<a.Search(10)<<endl;
    
    //test to see if the array is sorted
    if (a.Is_sorted()) {
        cout << "Sorted? Yes" << endl;
    } else {
        cout << "Sorted? No" << endl;
    }
    
    //Output:
    /*

Enter #0:1

Enter #1:10

Enter #2:3

Enter #3:2

Enter #4:4

Enter #5:5

Enter #6:8

Enter #7:19

Enter #8:20

Enter #9:20


1
10
3
2
4
5
8
19
20
20
Min: 0

Max: 8

Sum = 92

Search 10: 1
Sorted? No
    
    */
    return 0;
}