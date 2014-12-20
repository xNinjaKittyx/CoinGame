// Program #4A. Using a menu and using while loops.
// The program will consist of a Menu to choose either 2 program or Exit from the program.
 

#include <ctime> 
#include <iostream>  //inclusion of support for doing input & output
using namespace std; //declare access to standard stuff like cin, cout

 
// Beginning of main function

int main()             
{
	//Seed Randoms used later with current time.
	srand( (unsigned int)time ( NULL ) );

	// Define Variables
	int coins;
	int perturn;

	//What is the max amount of coins that is 
	cout << "Loading..." << endl
		 << "Done." << endl
		 << "Let's play a game." << endl << endl
		 << "This is the game where You and I will take coins from a pile of coins." << endl;


	//SECTION A : USER INPUT ON RULES

	//Bools for fools. Reject nonlogical numbers. LV means "LegitVariable"
	bool LV = false;

	//How many coins are in the piles?(n)
	//Is N a legit number?
	while (LV == false)
	{
		cout << "How many coins should be in the piles?" << endl;
		cin >> coins;
		cout << endl;

		//Using 1 would be pointless because the m has to be n-1.
		if (coins <= 1)
		{
			cout << "There has to be more than 1 coin." << endl;
		}
		else
		{
			LV = true;
		}
	}	

	//Reset bool
	LV = false;
	//Max amount of coins that a player can take per turn.
	//Check if m is a legitamate number.
	while (LV == false)
	{
		cout << "What is the maximum amount of coins that can be taken per turn?" << endl;
		cin >> perturn;
		cout << endl;

		if (perturn <= (coins-1))
		{
			if (perturn > 0)
			{
				LV = true;
			}
			else
			{
				cout << "You cannot use a negative number." << endl;
			}
		}
		else
		{
			cout << "This number is too big." << endl
				 << "The number must be between 1 and " << coins-1 << "." << endl;
		}
	}

	//Ask user if obtaining last coin is win or lose.
	char isLastWin;
	char const W = 'W';
	char const L = 'L';

	//bool stating if user typed in correct character.
	LV = false;
	while (LV == false)
	{
		cout << "Is obtaining the last coin a WIN or a LOSE? (W or L)" << endl;
		cin >> isLastWin;
		cout << endl;
		if (isLastWin == W||L)
		{
			LV = true;
		}
		else
		{
			cout << "That is not a valid answer" << endl;
		}
	}

	//Ask who goes first.
	char whosTurn;
	char const U = 'U';
	char const C = 'C';
	//Checks user input.
	LV = false;
	while (LV == false)
	{
		cout << "Who goes first? Computer or User? (C or U)" << endl;
		cin >> whosTurn;
		cout << endl; 
		if (whosTurn == C||U)
		{
			LV = true;
		}
		else
		{
			cout << "That is not a valid answer" << endl;
		}
	}

	

	//Ask how many moves user is allowed to undo
	int undo;
	int undoused = 0;
	LV = false;
	while (LV == false)
	{
		cout << "How many times are you allowed to undo your move?" << endl;
		cin >> undo;
		cout << endl;
		if (undo >= 0)
		{
			LV = true;
		}
		else
		{
			cout << "That's not a vaild number." << endl;
		}
	}


	//Ask the user about maximum number of random moves they can request the computer to take.
	int crand;
	int crandused = 0;
	LV = false;
	while (LV == false)
	{
		cout << "What is the maximum number of randoom moves" << endl << "that you can request to computer to make a random move?" << endl;
		cin >> crand;
		cout << endl;
		if (crand >= 0)
		{
			LV = true;
		}
		else
		{
			cout << "That's not a valid number." << endl;
		}
	}


	cout << "Alright, Let's play!" << endl;


	//SECTION B : THE GAME ITSELF

	//In the case where Taking the last coin is a win.
	//SECTION B0 : Defining More Variables
	//How much user takes
	int take;
	//How much computer takes
	int comptake;
	//What is the optimal move for the user.
	int optimalmove;
	//Assume no repeat for undo unless specified.
	bool undo1 = false;
	//Undo : Yes or No
	char undoyn;
	//Computer Random Move : Yes or No
	char crandyn;
	//Char Const
	const char Y = 'Y';
	const char N = 'N';


	//SECTION B1 : LAST COIN = WIN
	if (isLastWin == W)
	{
		while (coins > 0)
		{
			//Computer's Turn
			if (whosTurn == C)
			{
				cout << "There are " << coins << " coins left." << endl;
				
				//If the user still has random moves left, ask the user if they would want the computer to make a random move.
				if (crandused < crand)
				{
					cout << "You have " << crand - crandused << " random moves left. Would you like me to make a random move? (Y or N)" << endl;
					cin >> crandyn;
					cout << endl;
					if (crandyn == Y)
					{
						comptake = rand() % perturn + 1;
						crandused++;
					}
					//If they don't want to use it, proceed as usual.
					else
					{
						do
						{
							if (coins % (perturn + 1) == 0)
							{				
								comptake = rand() % perturn + 1;
							}
							else
							{
								comptake = coins % (perturn + 1);
							}
						}
						while (comptake > coins);
					}
				}
				//and if they don't have any random moves left, proceed as usual.  
				else
				{
					do
					{
						if (coins % (perturn + 1) == 0)
						{				
							comptake = rand() % perturn + 1;
						}
						else
						{
							comptake = coins % (perturn + 1);
						}
					}
					while (comptake > coins);
				}

				//Subtract, Display how many coins taken, and switch turns.
				coins = coins - comptake;
				cout << "I take " << comptake << " coins." << endl << endl;
				whosTurn = U;
			}

			//User's Turn
			else if (whosTurn == U)
			{
				
				do
				{
					//Undo1 is for the undo function. Determines whether or not to undo or not.
					undo1 = false;

					//User's Input on coins.
					cout << "There are " << coins << " coins left." << endl;
					cout << "How many coins will you take?" << endl;
					cin >> take;
					
					//Check if the user's input is a valid move.
					if (take > 0 && take <= perturn && take <= coins)
					{

						//Check if the user did a optimal move.
						if (coins % (perturn + 1) != 0)
						{				
							optimalmove = coins % (perturn + 1);
						
							//if the move is non-optimal
							if (optimalmove != take)
							{
								cout << "You took a non-optimal move." << endl << endl;
								if (undoused < undo)
								{
									//If the user took an non-optimal move, Then ask if they want to undo it or not.
									cout << "Would you like to take back your move? (Y or N)" << endl;
									cin >> undoyn;
									cout << endl;
									if (undoyn == Y)
									{
										undo1 = true;
										undoused++;
									}
									else
									{
										undo1 = false;
									}
								}
							}
						}
						else
						{
							undo1 = false;
						}

						//if the user is not gonna take an undo or the move is optimal. Switch the turn here since we don't want
						//the turn to switch if an invalid move is given.
						if (undo1 == false)
						{		
						whosTurn = C;
						coins = coins - take;
						cout << "You take " << take << " coins." << endl;
						}
					}

					//If the user doesn't put a valid answer, tell them to try again.
					else
					{
						cout << "Invalid Move! Try again!" << endl << endl;
					}
				}
				while(undo1 == true);



			}
		}
		//Win / Lose Messages
		if (whosTurn == U)
		{
			cout << endl
				 << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl
				 << "Aww man, You won! Good Game, Well Played" << endl
				 << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
		}
		if (whosTurn == C)
		{
			cout << "Yay! I win :) Good Game, Well Played!" << endl;
		}
	}




	//SECTION B2 : LAST COIN = LOSE
	else if (isLastWin == L)
	{
		while (coins > 0)
		{
		
			//Computer's Turn
			if (whosTurn == C)
			{
				cout << "There are " << coins << " coins left." << endl;
				
				if (crandused < crand)
				{
					cout << "You have " << crand - crandused << " random moves left. Would you like me to make a random move? (Y or N)" << endl;
					cin >> crandyn;
					cout << endl;
					if (crandyn == Y)
					{
						comptake = rand() % perturn + 1;
						crandused++;
					}
					else
					{
						do
						{
							if ((coins - 1) % (perturn + 1) == 0)
							{
								comptake = rand() % perturn + 1;
							}
							else
							{
								comptake = (coins - 1) % (perturn + 1);
							}
						}
						while (comptake > coins);
					}
				}
				else
				{
					do
					{
						if ((coins - 1) % (perturn + 1) == 0)
						{
							comptake = rand() % perturn + 1;
						}
						else
						{
							comptake = (coins - 1) % (perturn + 1);
						}
					}
					while (comptake > coins);
				}

				coins = coins - comptake;
				cout << "I take " << comptake << " coins." << endl << endl;
				whosTurn = U;
			}
			else if (whosTurn == U)
			{
				
				do
				{
					//Undo1 is for the undo function. Determines whether or not to undo or not.
					undo1 = false;

					//User's Input on coins.
					cout << "There are " << coins << " coins left." << endl;
					cout << "How many coins will you take?" << endl;
					cin >> take;
					
					//Check if the user's input is a valid move.
					if (take > 0 && take <= perturn && take <= coins)
					{

						//Check if the user did a optimal move.
						if ((coins-1) % (perturn + 1) != 0)
						{				
							optimalmove = (coins - 1) % (perturn + 1);
						
							//if the move is non-optimal
							if (optimalmove != take)
							{
								cout << "You took a non-optimal move." << endl << endl;
								if (undoused < undo)
								{
									//If the user took an non-optimal move, Then ask if they want to undo it or not.
									cout << "Would you like to take back your move? (Y or N)" << endl << endl;
									cin >> undoyn;
									if (undoyn == Y)
									{
										undo1 = true;
										undoused++;
									}
									else
									{
										undo1 = false;
									}
								}
							}
						}
						else
						{
							undo1 = false;
						}
						//if the user is not gonna take an undo or the move is optimal. Switch the turn here since we don't want
						//the turn to switch if an invalid move is given.
						if (undo1 == false)
						{		
						whosTurn = C;
						coins = coins - take;
						cout << "You take " << take << " coins." << endl;
						}
					}

					//If the user doesn't put a valid answer, tell them to try again.
					else
					{
						cout << "Invalid Move! Try again!" << endl << endl;
					}
				}
				while(undo1 == true);


			}
		}
		//Win / Lose Messages
		if (whosTurn == U)
		{
			cout << endl
				 << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl
				 << "Aww man, You won! Good Game, Well Played" << endl
				 << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
		}
		if (whosTurn == C)
		{
			cout << "Yay! I win :) Good Game, Well Played!" << endl;
		}
	}


	//Ending Message.
	cout << endl << "Thanks for Playing!" << endl
		 << "This is Coin Game by Daniel Ahn." << endl
		 << "CSCI 105 Midterm" << endl << endl
		 << "Type any character and an enter to close the program." << endl;

	char exit;
	cin >> exit;

	return 0;
}
//End of the main function.