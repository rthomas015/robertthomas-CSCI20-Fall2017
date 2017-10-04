/*Lab 2.5 - Lab - Classes and Mutator Functions
  By: Robert Thomas
  Date: 10/03/2017
  Description: 
  The purpose of Lab 2.5 is to create a program that creates a book class and five book objects
  which holds user input data such as: title, author and copyright year of book.
  The program will use the book object's set function to set the data, the get function to 
  output the data after each piece of information is input by the user. 
  Then the print function of the object to print out all the information at the end of the program.
*/

//preprocessor directives
#include <iostream>
#include <string>

using namespace std;

//Create a class called book, that stores user input information regarding actual books
class book {
    private:
        //create a book_title and book_author string variable, and an integer variable called book_copyright_year
        //book_title holds the book's title as a string
        //book_author holds the book's author as a string
        //book_copyright_year holds the book's copyright year as an integer
        string book_title,
               book_author;
        int book_copyright_year;
        
    public:
        //declare public functions of the book class
        
        //Setters: SetTitle sets the book_title variable of the book object
        //         SetAuthor sets the book_author variable of the book object
        //         SetCopyright_Year sets the book_copyright_year varible of the book object
     
        void SetTitle (string title);
        void SetAuthor (string author);
        void SetCopyright_Year (int copyright_year);
        
        //Getters: GetTitle returns the book object's title held in the book_title variable
        //         GetAuthor returns the book object's author held in the book_author variable
        //         GetCopyright_Year returns the book object's copyright year held in the book_copyright_year variable
        
        string GetTitle () const;
        string GetAuthor () const;
        int GetCopyright_Year () const;
        
        //Print function which outputs all the information relating to the current book object (its book author, title and copyright_year)
        void Print () const;
};

//SetTitle sets the book_title variable of the book object
void book::SetTitle (string title) {
    book_title = title;
    return;
};

//SetAuthor sets the book_author variable of the book object
void book::SetAuthor (string author) {
    book_author = author;
    return;
};

//SetCopyright_Year sets the book_copyright_year varible of the book object
void book::SetCopyright_Year (int copyright_year) {
    book_copyright_year = copyright_year;
    return;    
};

//GetTitle returns the book object's title held in the book_title variable
string book::GetTitle() const {
    return book_title;
};

//GetAuthor returns the book object's author held in the book_author variable
string book::GetAuthor () const {
    return book_author;
};

// GetCopyright_Year returns the book object's copyright year held in the book_copyright_year variable
int book::GetCopyright_Year () const {
    return book_copyright_year;
};

void book::Print() const{
    //print book's title
    cout << endl << book_title << "            ";
    //print book's author
    cout << book_author << "            ";
    //print book's copyright_year
    cout << book_copyright_year;
    return;
}

//Start of program (main function)

int main () {
    //Initialize variables needed for program:
    //Create five book objects
    book number_1, number_2, number_3, number_4, number_5;
    //Create a title string, an author string, and a copyright year integer that are accessible in the scope of the main function
    string title = "",
           author = "";
    int copyright_year = 0;
    
    
    /* Program steps
      1.) Request input from user regarding title, author and copyright year
      2.) Call mutator function of each book object to set the private variables of those 
          book objects
      3.) Call accessor function of each book object to return the information just set
      4.) Then after taking all information from user, output the information for each book at the end of the program
    */
    
    
    
    //Get information from user for Book 1 and output information as the user provides it
    //*************
    //Get book title/author/copyright_year, set book title/author/copyright_year and display book title/author/copyright_year
    cout << "Enter title of book (with underscores not spaces): ";
    cin >> title;
    number_1.SetTitle(title);
    
    cout << endl << "You entered " << number_1.GetTitle() << " as the book title."
         << endl << endl << "Enter author of book (with underscores not spaces): ";
    cin >> author;
    number_1.SetAuthor(author);
    cout << endl << "You entered " << number_1.GetAuthor() << " as the book's author."
         << endl << endl << "Enter copyright year of book: ";
    cin >> copyright_year;
    number_1.SetCopyright_Year(copyright_year);
    cout << endl << "You entered " << number_1.GetCopyright_Year() << " as the copyright year for the book."
         << endl;
    
    
    
    
    //Get information from user for Book 2 and output information as the user provides it
    //*************
    //Get book title/author/copyright_year, set book title/author/copyright_year and display book title/author/copyright_year
    cout << "Enter title of book (with underscores not spaces): ";
    cin >> title;
    number_2.SetTitle(title);
    
    cout << endl << "You entered " << number_2.GetTitle() << " as the book title."
         << endl << endl << "Enter author of book (with underscores not spaces): ";
    cin >> author;
    number_2.SetAuthor(author);
    cout << endl << "You entered " << number_2.GetAuthor() << " as the book's author."
         << endl << endl << "Enter copyright year of book: ";
    cin >> copyright_year;
    number_2.SetCopyright_Year(copyright_year);
    cout << endl << "You entered " << number_2.GetCopyright_Year() << " as the copyright year for the book."
         << endl;
    
    
    
    
    //Get information from user for Book 3 and output information as the user provides it
    //*************
    //Get book title/author/copyright_year, set book title/author/copyright_year and display book title/author/copyright_year
    cout << "Enter title of book (with underscores not spaces): ";
    cin >> title;
    number_3.SetTitle(title);
    
    cout << endl << "You entered " << number_3.GetTitle() << " as the book title."
         << endl << endl << "Enter author of book (with underscores not spaces): ";
    cin >> author;
    number_3.SetAuthor(author);
    cout << endl << "You entered " << number_3.GetAuthor() << " as the book's author."
         << endl << endl << "Enter copyright year of book: ";
    cin >> copyright_year;
    number_3.SetCopyright_Year(copyright_year);
    cout << endl << "You entered " << number_3.GetCopyright_Year() << " as the copyright year for the book."
         << endl;
    
    
    
    //Get information from user for Book 4 and output information as the user provides it
    //*************
    //Get book title/author/copyright_year, set book title/author/copyright_year and display book title/author/copyright_year
    cout << "Enter title of book (with underscores not spaces): ";
    cin >> title;
    number_4.SetTitle(title);
    
    cout << endl << "You entered " << number_4.GetTitle() << " as the book title."
         << endl << endl << "Enter author of book (with underscores not spaces): ";
    cin >> author;
    number_4.SetAuthor(author);
    cout << endl << "You entered " << number_4.GetAuthor() << " as the book's author."
         << endl << endl << "Enter copyright year of book: ";
    cin >> copyright_year;
    number_4.SetCopyright_Year(copyright_year);
    cout << endl << "You entered " << number_4.GetCopyright_Year() << " as the copyright year for the book."
         << endl;
    
    
    
    
    //Get information from user for Book 5 and output information as the user provides it
    //*************
    //Get book title/author/copyright_year, set book title/author/copyright_year and display book title/author/copyright_year
    cout << "Enter title of book (with underscores not spaces): ";
    cin >> title;
    number_5.SetTitle(title);
    
    cout << endl << "You entered " << number_5.GetTitle() << " as the book title."
         << endl << endl << "Enter author of book (with underscores not spaces): ";
    cin >> author;
    number_5.SetAuthor(author);
    cout << endl << "You entered " << number_5.GetAuthor() << " as the book's author."
         << endl << endl << "Enter copyright year of book: ";
    cin >> copyright_year;
    number_5.SetCopyright_Year(copyright_year);
    cout << endl << "You entered " << number_5.GetCopyright_Year() << " as the copyright year for the book."
         << endl;
    


    
    //Output information to user regadring each book object: title, author and copyright_year
    cout << endl << endl << endl << "Title:                                    Author:         Copyright Year:";
    cout << endl << "-------------------------------------------------------------------------";
    number_1.Print();
    number_2.Print();
    number_3.Print();
    number_4.Print();
    number_5.Print();
    
    //program output: (note: adjusted to line up better)
    /*  
    Title:                                    Author:         Copyright Year:
    -------------------------------------------------------------------------
    Hitchhiker's_Guide_to_the_Galaxy         Douglas_Adams            1979
    Dirk_Gently's_Holistic_Detective_Agency  Douglas_Adams            1987
    Catcher_in_the_Rye                       JD_Salinger              1951
    1984                                     George_Orwell            1949
    Pride_and_Prejudice                      Jane_Austen              1813
    */
    
    return 0;
}