#pragma once
#include <string>
#include <vector>
#include "Card.h"
class SetPuzzle
{
	
	std::vector<Card*> CardVect{};
	std::vector<std::vector<Card*>> SETS{};
	std::string name;
	
	public:
#pragma region Constructors/Destructors

	SetPuzzle():CardVect(),name(){}
	SetPuzzle(std::string name):CardVect(),name(name){}
	
	


#pragma endregion
#pragma region FunctionPrototypes
public:
	//removes the specified card from the puzzle named
	void removeCard(){}
	//inserts the specified card into the puzzle named
	void addCard(Card* crd1)
	{
		CardVect.push_back(crd1);
	}
	//displays the card required to form a set with the passed in cards
	void solveCards(Card* Card1, Card* Card2){}
	//displays whether card1, card2, card3, form a set
	void testSet(){}



#pragma endregion 
#pragma region Getters/Setters
	std::string getName(){return name;}
	void setName(std::string Inname){name = Inname;}
	std::vector<Card*> getCardVect(){return CardVect;}
	std::vector<std::vector<Card*>> getSETSVect(){return SETS;}
	void addSet(std::vector<Card*> IN)
	{
		this->SETS.push_back(IN);
	}
#pragma endregion
};

