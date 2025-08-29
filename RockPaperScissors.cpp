#include <iostream>
#include <ctime>
#include<cstdlib> 

struct stResult
{
	int gameRounds;
	int playrOneWins = 0;
	int computerWins = 0;
	int drawTimes = 0;

};

enum enGameChoices {Stone = 1, Paper = 2, Scissor = 3 };

int getRandomNumber(int from, int to) {

	return rand() % (to - from + 1) + from;
}

short numberOfRounds() {

	short numberOfRounds;

	do
	{
		std::cout << "How many rounds from 1 to 10: \n";
		std::cin >> numberOfRounds;


	} while (numberOfRounds <= 0 || numberOfRounds > 10);

	return numberOfRounds;
}

enGameChoices UserChoice(int i) {

	short userChoice;

	std::cout << "Round " << (i) << " Begins: \n\n";
	do
	{
		std::cout << "Your choice: [1]Stone, [2]Paper, [3]Scissor = 3 ? ";
		std::cin >> userChoice;

	} while (userChoice < 1 || userChoice > 3);

	return (enGameChoices)userChoice;
} 

enGameChoices ComputerChoice() {

	return (enGameChoices)getRandomNumber(1, 3);
}

std::string userSelectionInString(enGameChoices enUserChoice) {

	switch (enUserChoice)
	{
	case Stone:
		return "Stone";
		break;
	case Paper:
		return "Paper";
		break;
	case Scissor:
		return "Scissor";
		break;
	default:
		return "";
		break;
	}
}

std::string computerSelectionInString(enGameChoices enComputerChoice) {

	switch (enComputerChoice)
	{
	case Stone:
		return "Stone";
		break;
	case Paper:
		return "Paper";
		break;
	case Scissor:
		return "Scissor";
		break;
	default:
		return "";
		break;
	}
}

std::string winnerOfRound(enGameChoices userChoice, enGameChoices computerChoice, stResult &stResults) {

	if (userChoice == computerChoice)
	{
		system("color 6F");
		stResults.drawTimes++;
		return "[No winner]";
		
	}
	else
	{
		if (userChoice == enGameChoices::Stone && computerChoice == enGameChoices::Paper)
		{
			system("color 4F");
			std::cout << "\a";
			stResults.computerWins++;
			return "Computer";
			
		}
		else if (userChoice == enGameChoices::Stone && computerChoice == enGameChoices::Scissor)
		{
			system("color 2F");
			stResults.playrOneWins++;
			return "Player";

		}
		else if (userChoice == enGameChoices::Paper && computerChoice == enGameChoices::Scissor)
		{
			system("color 4F");
			std::cout << "\a";
			stResults.computerWins++;
			return "Computer";

		}
		else if (userChoice == enGameChoices::Paper && computerChoice == enGameChoices::Stone)
		{
			
			system("color 2F");
			stResults.playrOneWins++;
			return "Player";
		}
		else if (userChoice == enGameChoices::Scissor && computerChoice == enGameChoices::Paper)
		{

			system("color 2F");
			stResults.playrOneWins++;
			return "Player";
		}
		else if (userChoice == enGameChoices::Scissor && computerChoice == enGameChoices::Stone)
		{

			system("color 4F");
			std::cout << "\a";
			stResults.computerWins++;
			return "Computer";
		}
	}

	return "";
}

void resultsForEachRound(short i, enGameChoices userChoice, enGameChoices computerChoice, stResult &stResults) {

	stResults.gameRounds = i;

	std::string playerChoice = userSelectionInString(userChoice);
	std::string computerChoice_ = computerSelectionInString(computerChoice);
	std::string roundWinner = winnerOfRound(userChoice, computerChoice, stResults);

	std::cout << "\n\n---------------------Round[" << (i) << "]---------------------\n";
	std::cout << "Player one choice: " << playerChoice << "\n";
	std::cout << "Computer choice: " << computerChoice_ << "\n";
	std::cout << "Round winner: " << roundWinner << "\n\n";

}

void printGameResults(stResult stResults) {


	std::string finalWinner = "";

	if (stResults.computerWins > stResults.playrOneWins)
	{
		finalWinner = "Computer";
	}
	else if (stResults.computerWins < stResults.playrOneWins) {

		finalWinner = "Player";
	}
	else
	{
		finalWinner = "No winner";
	}



	std::cout << "\t\t-------------------------------------------------------------------------------------\n\n";
	std::cout << "\t\t                            +++ G a m e  O v e r +++                                   \n";
	std::cout << "\t\t-------------------------------------------------------------------------------------\n\n";
	std::cout << "\t\t------------------------------  {Game Results }  ------------------------------------\n\n";
	std::cout << "\t\tGame Rounds                   :" << stResults.gameRounds << "\n";
	std::cout << "\t\tPlayer one won times          :" << stResults.playrOneWins << "\n";
	std::cout << "\t\tComputer won times            :" << stResults.computerWins << "\n";
	std::cout << "\t\tDraw times                    :" << stResults.drawTimes << "\n";
	std::cout << "\t\tFinal winner                  :" << finalWinner << "\n";
	std::cout << "\t\t-------------------------------------------------------------------------------------\n\n";
}

void resetScreen() {

	system("cls");
	system("color 07");
}

void startGame() {

	char completeGame = '\0';
	enGameChoices userChoice_;
	enGameChoices computerChoice_;
	

	do
	{
			
		resetScreen();

		short roundsNumber = numberOfRounds();	
		stResult stShowResults;

		for (int i = 1; i <= roundsNumber ; i++)
		{
			userChoice_ = UserChoice(i);
			computerChoice_ = ComputerChoice();
			resultsForEachRound(i, userChoice_, computerChoice_, stShowResults);
		}

		printGameResults(stShowResults);

		std::cout << "Do you want to play again? Y/N:";
		std::cin >> completeGame;

	} while (completeGame == 'Y' || completeGame == 'y');
}



int main() {

	srand((unsigned)time(NULL));
	startGame();

}