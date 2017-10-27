/*Assignment 3.0 - Game: Pig
  By: Robert Thomas
  Date: 10/26/2017
  Description: Create a program based on the game of Pig. A computer and a player take turns rolling dice,
  if a 1 is rolled they lose their turn, if they roll a 2,3,4,5 or 6 it is added to their current total.
  They then have the option of rolling again wagering their current total, or holding it, and storing it.
  The first to 100 wins.
*/

//pre-processor directives
#include<iostream>
#include<ctime>

using namespace std;


//Computer Opponent class
class ComputerOpponent {
    private:
        //computer_score_ holds the computer player's score
        int computer_score_;
    public:
        //Class Constructor - sets computer_score_ to 0 upon creation of object
        ComputerOpponent() {
            computer_score_ = 0;
        }
        //Function to determine if the computer should Hold or Roll again
        //This function represents a fairly basic algorithm which maximizes the score of the computer
        //using simple odds per round, but does not maximize its overall score
        char DecideHoldorRoll(int running_total) {
            char decision = 'r';
            if (running_total < 20) {
                decision = 'r';
            }
            else {
                decision = 'h';
            }
            return decision;
        }
        
        //Getter function that returns the computer's score
        const int GetComputerScore() {
            return computer_score_;
        }
        
        //Setter function that sets the computer's score
        void SetComputerScore(int computer_score) {
            computer_score_ = computer_score;
        }
        
};

//Function to roll dice
int DiceRoll (){
   srand(time(0));
   int dice_roll = rand() % 6 + 1;
   return dice_roll;
}

int main () {
    //Create variables
    /*
        choice = a char variable that holds the choice of the user and the computer, either to hold or to roll
        player_points = holds the player's points
        dice_roll = holds the value of the random dice roll
        running_total = holds the the value of all the dice rolls that haven't been held in the round
        round_number = a tally that holds the current round 
        bot = the instance of the ComputerOpponent class
    */
	char choice = 'r';
	int player_points = 0, dice_roll = 0, running_total = 0, round_number = 1;
	ComputerOpponent bot;
	
	//Request user's input
	cout << "Pig" << endl
	     << "=============" << endl
	     << "Its your turn" << endl
	     << "Your total is " << player_points << endl
	     << "Input [r] to roll dice or [h] to hold:";
	cin >> choice;
	
   //While loop for the entire game - that loops until the computer or the player hits 100 points
   while ((player_points < 100) || (bot.GetComputerScore() < 100)) {
        //reset running_total to 0
        running_total = 0;
        
        //While Loop for Player that loops until the player holds or the value 1 occurs
        while (choice != 'h') {
            dice_roll = DiceRoll();
            cout << endl << "You rolled a: "
                 << dice_roll
                 << endl;
                 
            if (dice_roll == 1) {
               //when dice_roll is 1, terminate loop and player loses turn 
               cout << "You lost your turn"
                    << endl;
               running_total = 0;
               choice = 'h';
	        }
	        else {
	            //otherwise continue running until a 1 or player holds
	            running_total = running_total + dice_roll;
   	   	        cout << endl
   	   	        << "Your current round total is: " << running_total
   	   	        << endl
                << "Input [r] to roll dice or [h] to hold:";
                cin >> choice;
	        }
	    }
	    
	    //save running_total for what the player accomplished, reset running_total for the computers turn
	    //and reset choice to roll to start the computers turn
        player_points = running_total;
        running_total = 0;
        choice = 'r';
        
        //While Loop for Computer that loops until the computer holds or the value 1 occurs
	    while (choice != 'h') {
	        dice_roll = DiceRoll();
	        cout << endl << "Computer rolled a: "
            << dice_roll
            << endl;
            
	        if (dice_roll == 1) {
	           //terminate loop and computer loses turn 
	           cout << "Computer loses its turn. ";
	           running_total = 0;
	           choice = 'h';
	        }
	        else {
	            running_total = running_total + dice_roll;
	            choice = bot.DecideHoldorRoll(running_total);
	        }
	    }
	    
	    //save running_total for what the computer accomplished, add one to the round number
	    //and reset choice to roll to start the players turn with a roll (this can be changed
	    // if for some reason the user should be able to hold without even rolling)
	    bot.SetComputerScore(running_total);
	    choice = 'r';
	    round_number += 1;
	    
	    //output displaying the current round, player points, and the computer's points
	    cout << endl << "Current Score by round #" << round_number
             << endl
             << "Player: " << player_points
             << endl
             << "Computer: " << bot.GetComputerScore()
             << endl;
	    
   } //whole game loop ends here

    //Outputs final score
    cout << "Final Score:"
         << endl << "Player: " << player_points
         << endl << "Computer: " << bot.GetComputerScore();
    if (player_points >= 100)
        cout << endl << "Good job you won!";
    if (bot.GetComputerScore() >= 100)
        cout << endl << "The computer won...";

    //Output
    /*
    Pig
    =============
    Its your turn
    Your total is 0
    Input [r] to roll dice or [h] to hold:r

    You rolled a: 4

    Your current round total is: 4
    Input [r] to roll dice or [h] to hold:h

    Computer rolled a: 5

    Computer rolled a: 5

    Computer rolled a: 5

    Computer rolled a: 5

    Current Score by round #2
    Player: 4
    Computer: 20

    You rolled a: 5

    Your current round total is: 5
    Input [r] to roll dice or [h] to hold:
    
    */

	return 0;

}