//all includes are important to the function of the program
#include <iostream>
#include <fstream> //guess this is the include file that has all the functions that deal with f[ile] input/output streaming
#include <cstdlib>
#include <string>

using namespace std;

//essentially everything i commented i am unsure about or have questions regarding it
int main()
{
   string line;
   ifstream fin; //creates object named 'fin' (file input) of the type ifstream (assuming input file stream)
   ofstream fout; //creates object named 'fout' (file output) of the type ofstream (assuming that means output file stream)
   
   fin.open("read.txt"); //this probably reads in from the file named read.txt and since there's no directory specified the file that exists
    //where the cpp file exists
   fout.open("output.txt"); //this probably outputs information from the program into a file called output.txt in the same directory as read.txt

   while(!fin.eof()) //this loop probably runs while eof is false, and eof is probably end of file, so it loops to the end of the file
   {
      getline(fin, line); //don't remember out getline works, but it probably reads the read.txt file into the string variable line
      fout<<line<<endl; //and this reads line into the fout object
   }

   fin.close(); //this closes the fin object (as in closes the file input stream)
   fout.close(); // this closes the fout object (as in closes the file output stream)

   return 0;
}


//Mark with a //* 3-5 items that are important
//Mark with a //? 3-5 items that are unclear, incorrect, or you have questions about.
//identify which parts you think are related to file input/output.  and what they do.  Guess.