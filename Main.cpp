/*
Student Name: Robert Ward
Student NetID: rww189
Compiler Used: Visual Studio
Program Description:
A program to solve the puzzles in the Card game SET
*/
#pragma once
#include<iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include<chrono>
#include "SetPuzzle.h"



#pragma region GlobalVars
	
std::string input;
std::string token;


std::vector<SetPuzzle*> ListOfPuzzles;



bool isRunning{ true };

#pragma endregion




//find function to search the vector for the puzzle with the given name
SetPuzzle* findPuzzle(std::string puzzName)
{
	

	for(int i = 0;i<ListOfPuzzles.size();i++)
	{
		if(puzzName == ListOfPuzzles.at(i)->getName())
		{

			return ListOfPuzzles.at(i);
		}

	}
}
//exits the program
void exit()
{
	std::cout << "GOODBYE!";
	
	std::exit(0);
}
//reads a file containing a list of cards and stores them in the specified puzzle. Creates new puzzle if necessary
SetPuzzle* loadFileAsPuzzle(std::string fileToLoad,std::string nameOfPuzz)
{
	std::string textFileLines;
	std::stringstream textlinesStream;
	std::fstream file;
	file.open(fileToLoad);
	SetPuzzle* newPuzzle = new SetPuzzle(nameOfPuzz);
	if(file.is_open())
	{
		std::cout << "File opened successfully!" << std::endl;
		while(getline(file,textFileLines))
		{
			textlinesStream << textFileLines<<' ';
			
		}
		
		while(getline(textlinesStream, textFileLines,' '))
		{
			Card* newCard = new Card(textFileLines);
			newPuzzle->addCard(newCard);
		}
	}
	else
	{
		std::cerr << "File could not be opened or located"<<std::endl;
		
	}
	textlinesStream.str("");
	textFileLines = "";
	
	return newPuzzle;
}
//parse the contents of the file as if they were entered from the cmd line
std::string loadFile(std::string fileToLoad)
{
	std::fstream file;
	std::string textFileLines;
	std::stringstream textlinesStream;

	file.open(fileToLoad);
	if(file.is_open())
	{		
		std::cout << "File opened successfully!" << std::endl;
		while(getline(file,textFileLines))
		{
			textlinesStream << textFileLines<<' ';
		}
		file.close();
	}
	else
	{
		std::cerr << "File could not be opened or located" << std::endl;
	}
	return textlinesStream.str();
}
//displays the list of created puzzles
void displayAllPuzzles()
{
		int index = 0;
	for(auto k = ListOfPuzzles.begin(); k < ListOfPuzzles.end(); k++)
	{
		std::cout << '\t' << ListOfPuzzles.at(index)->getName() << std::endl;
		index++;
	}
	/*	int index = 0;
	for(auto& i = ListOfPuzzles.begin(); i < ListOfPuzzles.end(); i++)
	{
		SetPuzzle* PuzzleToDisplay = ListOfPuzzles.at(index);
		std::vector<Card*> CardVectToDisplay = PuzzleToDisplay->getCardVect();
		std::cout << PuzzleToDisplay->getName() << " contains these Cards:" << std::endl;
			int cardVectIdx = 0;
		for(auto& j =CardVectToDisplay.begin(); j < CardVectToDisplay.end(); j++)
		{
			
		}
		
	}*/

}
//displays the cards stored in the specified puzzle
void displayPuzzleContents(std::string Puzzle)
{
	SetPuzzle* Puzz = findPuzzle(Puzzle);
	std::cout <<Puzzle<<" contains:"<< std::endl;
	for(int i = 0; i < Puzz->getCardVect().size(); i++)
	{
		std::cout<<"\t"<<Puzz->getCardVect().at(i)->Attributes<<"-"<<Puzz->getCardVect().at(i)->NumOfSymbols<<" ";
		switch(Puzz->getCardVect().at(i)->colorInt)
		{
		case 1:
			std::cout << "Red ";
			break;
		case 2:
			std::cout << "Green ";
			break;
		case 3:
			std::cout << "Purple ";
			break;
		default:
			break;
		}
		switch(Puzz->getCardVect().at(i)->shadingInt)
		{
		case 1:
			std::cout << " Filled ";
			break;
		case 2:
			std::cout << " Open ";
			break;
		case 3:
			std::cout << " Striped ";
			break;
		default:
			break;
		}
		switch(Puzz->getCardVect().at(i)->shapeInt)
		{

			case 1: 
				std::cout << " Diamond(s) " << std::endl;
				break;
			case 2:
				std::cout << " Oval(s) " << std::endl;
				break;
			case 3:
				std::cout << " Squiggle(s) " << std::endl;
				break;
			default:
				break;
		
		}
	}
	
	
	
	
}
//creates an empty puzzle with the given name
void createNewPuzzle(std::string InName)
{
	SetPuzzle* newPuzz = new SetPuzzle(InName);
	ListOfPuzzles.push_back(newPuzz);
}
//Removes the specified puzzle from the list
void removePuzzle(std::vector<SetPuzzle*>& ListToRemoveFrom, std::string nameOfPuzz)
{
	
	for(auto i = ListToRemoveFrom.begin(); i != ListToRemoveFrom.end(); i)
	{
		int index = 0;
		if(ListToRemoveFrom.at(index)->getName() == nameOfPuzz)
		{
			ListToRemoveFrom.at(index--)->~SetPuzzle();
			i = ListToRemoveFrom.erase(i);

		}
	}
}



bool isACard(SetPuzzle* puzzle, std::string card)
{
		int index = 0;
	for(auto i = puzzle->getCardVect().begin(); i < puzzle->getCardVect().end(); i++)
	{
		if(card == puzzle->getCardVect().at(index)->Attributes)
		{
			return true;
		}
		else
		{
			continue;
		}
		return false;
	}
}
bool isAPuzzle(std::string puzzName)
{
	for(int i = 0; i < ListOfPuzzles.size(); i++)
	{
		if(puzzName == ListOfPuzzles.at(i)->getName())
		{
			return true;
		}
		else
		{
			continue;
		}
	}
	return false;
}
#pragma region SetCheckingFuncitons
template<typename T>
bool areAllEqual(T val1, T val2,T val3)
{
	return val1 == val2 && val2 == val3;
}
template<typename T>
bool areAllEqual(T val1, T val2 )
{
	return val1 == val2 ;
}
template<typename T>
bool areAllDifferent(T val1,T val2, T val3)
{
	return val1 !=val2 && val2!=val3 && val1 != val3;
}
template<typename T>
bool areAllDifferent(T val1, T val2)
{
	return val1 != val2 ;
}
bool isAset(Card* crd1, Card* crd2, Card* crd3)
{
	if(!areAllEqual(crd1->NumOfSymbols, crd2->NumOfSymbols, crd3->NumOfSymbols)&& !areAllDifferent(crd1->NumOfSymbols, crd2->NumOfSymbols, crd3->NumOfSymbols))
	{		
		return false;	
	}
	if(!areAllEqual(crd1->colorChar, crd2->colorChar, crd3->colorChar) && !areAllDifferent(crd1->colorChar, crd2->colorChar, crd3->colorChar))
	{	
		return false;	
	}
	if(!areAllEqual(crd1->shadingChar, crd2->shadingChar, crd3->shadingChar) && !areAllDifferent(crd1->shadingChar, crd2->shadingChar, crd3->shadingChar))
	{
		return false;
	}
	if(!areAllEqual(crd1->shapeChar, crd2->shapeChar, crd3->shapeChar) && !areAllDifferent(crd1->shapeChar, crd2->shapeChar, crd3->shapeChar))
	{
		return false;
	}
	return true;
}
bool isASet(Card* crd1, Card* crd2)
{
	if(!areAllEqual(crd1->NumOfSymbols, crd2->NumOfSymbols) && !areAllDifferent(crd1->NumOfSymbols, crd2->NumOfSymbols))
	{
		return false;
	}
	if(!areAllEqual(crd1->colorChar, crd2->colorChar) && !areAllDifferent(crd1->colorChar, crd2->colorChar))
	{
		return false;
	}
	if(!areAllEqual(crd1->shadingChar, crd2->shadingChar) && !areAllDifferent(crd1->shadingChar, crd2->shadingChar))
	{
		return false;
	}
	if(!areAllEqual(crd1->shapeChar, crd2->shapeChar) && !areAllDifferent(crd1->shapeChar, crd2->shapeChar))
	{
		return false;
	}

	return true;
	
}
#pragma endregion
Card* SolveCards(Card* crd1, Card* crd2)
{
		Card* crd3 = new Card();
		switch(crd1->NumOfSymbols)
		{
			case 1:
				switch(crd2->NumOfSymbols)
				{
				case 1:
					crd3->NumOfSymbols = 1;
					crd3->Attributes += std::to_string(crd3->NumOfSymbols);
					break;
				case 2:
					crd3->NumOfSymbols = 3;
					crd3->Attributes += std::to_string(crd3->NumOfSymbols);
					break;
				case 3:
					crd3->NumOfSymbols = 2;
					crd3->Attributes += std::to_string(crd3->NumOfSymbols);
					break;
				default:
					break;
				}
				break;
			case 2:
				switch(crd2->NumOfSymbols)
				{
				case 1:
					crd3->NumOfSymbols = 3;
					crd3->Attributes += std::to_string(crd3->NumOfSymbols);

					break;
				case 2:
					crd3->NumOfSymbols = 2;
					crd3->Attributes += std::to_string(crd3->NumOfSymbols);
					break;
				case 3:
					crd3->NumOfSymbols = 1;
					crd3->Attributes += std::to_string(crd3->NumOfSymbols);

					break;
				default:
					break;
				}
				break;
			case 3:
				switch(crd2->NumOfSymbols)
				{
				case 1:
					crd3->NumOfSymbols = 2;
					crd3->Attributes += std::to_string(crd3->NumOfSymbols);

					break;
				case 2:
					crd3->NumOfSymbols = 1;
					crd3->Attributes += std::to_string(crd3->NumOfSymbols);

					break;
				case 3:
					crd3->NumOfSymbols = 3;
					crd3->Attributes += std::to_string(crd3->NumOfSymbols);

					break;
				default:
					break;
				}
				break;
			
			default:
			break;
		
		}
		switch(crd1->colorInt)
		{
			case 1:
				switch(crd2->colorInt)
				{
				case 1:
					crd3->colorInt = 1;
					crd3->colorChar = 'R';
					crd3->Attributes.push_back('R');

					break;
				case 2:
					crd3->colorInt = 3;
					crd3->colorChar = 'P';
					crd3->Attributes.push_back('P');

					break;
				case 3:
					crd3->colorInt = 2;
					crd3->colorChar = 'G';
					crd3->Attributes.push_back('G');

					break;
				}
				break;
			case 2:
				switch(crd2->colorInt)
				{
				case 1:
					crd3->colorInt = 3;
					crd3->colorChar = 'P';
					crd3->Attributes.push_back('P');

					break;
				case 2:
					crd3->colorInt = 2;
					crd3->colorChar = 'G';
					crd3->Attributes.push_back('G');

					break;
				case 3:
					crd3->colorInt = 1;
					crd3->colorChar = 'R';
					crd3->Attributes.push_back('R');

					break;
				default:
					break;
				}
				break;
			case 3:
				switch(crd2->colorInt)
				{
				case 1: 
					crd3->colorInt = 2;
					crd3->colorChar = 'G';
					crd3->Attributes.push_back('G');

					break;
				case 2:
					crd3->colorInt = 1;
					crd3->colorChar = 'R';
					crd3->Attributes.push_back('R');

					break;
				case 3:
					crd3->colorInt = 3;
					crd3->colorChar = 'P';
					crd3->Attributes.push_back('P');

					break;
				}		
				break;
			default:
				break;
		}
		switch(crd1->shadingInt)
		{
			case 1:
				switch(crd2->shadingInt)
				{
				case 1:
					crd3->shadingInt = 1;
					crd3->shadingChar = 'F';
					crd3->Attributes.push_back('F');

					break;
				case 2:
					crd3->shadingInt = 3;
					crd3->shadingChar = 'S';
					crd3->Attributes.push_back('S');

					break;
				case 3:
					crd3->shadingInt = 2;
					crd3->shadingChar = 'O';
					crd3->Attributes.push_back('O');

					break;
				}
				break;
			case 2:
				switch(crd2->shadingInt)
				{
				case 1:
					crd3->shadingInt = 3;
					crd3->shadingChar = 'S';
					crd3->Attributes.push_back('S');


					break;
				case 2:
					crd3->shadingInt = 2;
					crd3->shadingChar = 'O';
					crd3->Attributes.push_back('O');


					break;
				case 3:
					crd3->shadingInt = 1;
					crd3->shadingChar = 'F';
					crd3->Attributes.push_back('F');

					break;
				default:
					break;
				}
				break;
			case 3:
				switch(crd2->shadingInt)
				{
				case 1:
					crd3->shadingInt = 2;
					crd3->shadingChar = 'O';
					crd3->Attributes.push_back('O');


					break;
				case 2:
					crd3->shadingInt = 1;
					crd3->shadingChar = 'F';
					crd3->Attributes.push_back('F');


					break;
				case 3:
					crd3->shadingInt= 3;
					crd3->shadingChar = 'S';
					crd3->Attributes.push_back('S');


					break;
				}
				break;
			default:
				break;
		}
		switch(crd1->shapeInt)
		{
			case 1:
				switch(crd2->shapeInt)
				{
				case 1:
					crd3->shapeInt = 1;
					crd3->shapeChar = 'D';
					crd3->Attributes.push_back('D');

					break;
				case 2:
					crd3->shapeInt = 3;
					crd3->shapeChar = 'S';
					crd3->Attributes.push_back('S');
					break;
				case 3:
					crd3->shapeInt = 2;
					crd3->shapeChar = 'O';
					crd3->Attributes.push_back('O');

					break;
				}
				break;
			case 2:
				switch(crd2->shapeInt)
				{
				case 1:
					crd3->shapeInt = 3;
					crd3->shapeChar = 'S';
					crd3->Attributes.push_back('S');


					break;
				case 2:
					crd3->shapeInt = 2;
					crd3->shapeChar = 'O';
					crd3->Attributes.push_back('O');
					break;
				case 3:
					crd3->shapeInt = 1;
					crd3->shapeChar = 'D';
					crd3->Attributes.push_back('D');
					break;
				default:
					break;
				}
				break;
			case 3:
				switch(crd2->shapeInt)
				{
				case 1:
					crd3->shapeInt = 2;
					crd3->shapeChar = 'O';
					crd3->Attributes.push_back('O');
					break;
				case 2:
					crd3->shapeInt = 1;
					crd3->shapeChar = 'D';
					crd3->Attributes.push_back('D');
					break;
				case 3:
					crd3->shapeInt = 3;
					crd3->shapeChar = 'S';
					crd3->Attributes.push_back('S');
					break;
				}
				break;
			default:
				break;
		}
		
		return crd3;
}
bool isAreadyAset(std::vector<std::vector<Card*>> tmp,Card* crd1,Card* crd2,Card* crd3)
{
	//loops through the sets
	for(int i = 0; i < tmp.size(); i++)
	{
		//loop through the cards in the set
		for(int j = 0; j < tmp.at(i).size(); j++)
		{
			//if crd1 is equal to any card in the first set 
					//jth card in the ith set						//jth+1 card in the ith set						//jth+2 card in the ith set
			if(crd1->Attributes == tmp.at(i).at(j)->Attributes || crd1->Attributes == tmp.at(i).at(j + 1)->Attributes || crd1->Attributes == tmp.at(i).at(j + 2)->Attributes)
			{
				//check if crd2 is equal to any card in the first set and if it is
				if(crd2->Attributes == tmp.at(i).at(j)->Attributes || crd2->Attributes == tmp.at(i).at(j + 1)->Attributes || crd2->Attributes == tmp.at(i).at(j + 2)->Attributes && crd2->Attributes!= crd1->Attributes)
				{
					//then 2/3 cards have already been used and therefore the final card will also have to already have been used because any two cards have only 1 card that make a set 
					return true;
				}
				else
				{
					//if crd2 isnt in the checked set the break out of that set an check the next set
					break;
				}
			}
			else
			{
				break;
			}
		}
	}
	return false;
}
//Solves the passed in puzzle if able
void SolvePuzzle(SetPuzzle* InPuzzle)
{
	std::cout << InPuzzle->getName()<<" solution is as follows:"<<std::endl;

	//starts at the first card
	for(int i = 0; i < InPuzzle->getCardVect().size(); i++)
	{
		Card* crdtmp1 = InPuzzle->getCardVect().at(i);
		//starts at the second card
		for(int j = i+1; j<InPuzzle->getCardVect().size();j++)
		{
			Card* crdtmp2 = InPuzzle->getCardVect().at(j);
			//solves the two cards
			Card* crdtmpsol = SolveCards(crdtmp1, crdtmp2);
			//loops through the whole puzzle again to find the card that matches
			for(int k = 0; k < InPuzzle->getCardVect().size(); k++)
			{
				if(crdtmpsol->Attributes == InPuzzle->getCardVect().at(k)->Attributes)
				{
					if(isAreadyAset(InPuzzle->getSETSVect(), crdtmp1, crdtmp2, crdtmpsol))
					{
						break;
					}
					else
					{
						std::cout <<"\t"<< crdtmpsol->Attributes <<" solves "<< InPuzzle->getCardVect().at(i)->Attributes<<" and "<< InPuzzle->getCardVect().at(j)->Attributes<<std::endl;
						std::vector<Card*> newSet{ crdtmp1,crdtmp2,crdtmpsol };
						InPuzzle->addSet(newSet);
					}
					

					break;
				}
				else
				{
					continue;
				}
			}
		}
	}
}
//Parse String of text and decide what should be done
void parse(std::string inputCmd)
{
	std::stringstream ss2(inputCmd);
	//ss2 << inputCmd;
	while(getline(ss2, token, ' '))
	{

		if(token == "")
		{
			std::cout << "Invalid command entered" << std::endl;
		}
		else if(token == "exit")
		{
			exit();
		}
		else if(token == "load")
		{
			//gets the name of the file to load
			getline(ss2, token, ' ');
			//stores it locally
			std::string fileName = token;
			//gets the next keyword to check format
			getline(ss2, token, ' ');
			//if next word is as then we are loading a text file as a puzzle
			if(token == "as")
			{
				getline(ss2, token, ' ');
				ListOfPuzzles.push_back(loadFileAsPuzzle(fileName, token));
				displayAllPuzzles();
					
			}
			//else load file normally
			else
			{
				parse(loadFile(fileName));
			}
		}
		else if(token == "display")
		{
			if(ss2.str() == "display")
			{
				displayAllPuzzles();
			}
			else
			{
				getline(ss2, token, ' ');
				if(isAPuzzle(token))
				{
					displayPuzzleContents(token);
				}
			}
		}
		else if(token == "new")
		{
			getline(ss2, token, ' ');
			if(isAPuzzle(token))
			{
				std::cout << "Puzzle with name exsits";

			}
			else
			{
				createNewPuzzle(token);
			}
		}
		else if(token == "remove")
		{


			getline(ss2, token, ' ');
			if(isAPuzzle(token))
			{
				removePuzzle(ListOfPuzzles, token);
			}
		}
		else if(token == "add")
		{
			getline(ss2, token, ' ');
			Card* newCard = new Card(token);
			getline(ss2, token, ' ');
			if(token == "to")
			{
				getline(ss2, token, ' ');
				if(isAPuzzle(token))
				{
					findPuzzle(token)->addCard(newCard);
				}
			}
		}
		else if(token == "test")
		{
			getline(ss2, token, ' ');
			Card* newCard = new Card(token);
			getline(ss2, token, ' ');
			Card* newCard2 = new Card(token);
			getline(ss2, token, ' ');
			if(token == newCard2->Attributes)
			{
				if(isASet(newCard, newCard2))
				{
					std::cout << newCard->Attributes << "," << newCard2->Attributes << "," << " Form a set" << std::endl;
				}
				else
				{
					std::cout << newCard->Attributes << "," << newCard2->Attributes << "," << " Do not form a set" << std::endl;
				}

				}
			else
			{
				Card* newCard3 = new Card(token);
				if(isAset(newCard, newCard2, newCard3))
				{
					std::cout << newCard->Attributes << "," << newCard2->Attributes << "," << newCard3->Attributes << " Form a set" << std::endl;
				}
				else
				{
					std::cout << newCard->Attributes << "," << newCard2->Attributes << "," << newCard3->Attributes << " Do not form a set" << std::endl;

				}
			}
		}
		else if(token == "solve")
		{

			getline(ss2, token, ' ');
			if(isAPuzzle(token))
			{
				SolvePuzzle(findPuzzle(token));
			}
			else
			{
				Card* newCard = new Card(token);
				getline(ss2, token, ' ');
				Card* newCard2 = new Card(token);
				Card* crd3 = SolveCards(newCard, newCard2);
				//crd3->Attributes += std::to_string(crd3->NumOfSymbols);
				//crd3->Attributes.push_back(crd3->colorChar);
				//crd3->Attributes.push_back(crd3->shadingChar);
				//crd3->Attributes.push_back(crd3->shapeChar);
				std::cout << crd3->Attributes << " forms a set with " << newCard->Attributes << " and " << newCard2->Attributes<<std::endl;
			}
			
		}
	}
}


int main()
{
	
	while(isRunning)
	{
		
		
		
		std::cout << ">>";
		getline(std::cin, input);
		std::stringstream ss;

		ss << input;
		parse(ss.str());
		
	}
	

	
	
}