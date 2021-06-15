#pragma once
#include<string>
#include<sstream>
struct Card
{
	enum color
	{
		Red = 1, Green = 2, Purple = 3
	};
	enum shading
	{
		Filled = 1, Open = 2, Striped = 3
	};
	enum shape
	{
		Diamond = 1, Oval = 2, Squiggle = 3
	};

	std::stringstream CardStream;
	std::string Attributes;
	int NumOfSymbols{ 0 };
	char colorChar, shadingChar, shapeChar{};
	int colorInt, shadingInt, shapeInt{0};
#pragma region Constructors/Destructors
	Card() :Attributes(""), NumOfSymbols(), colorChar(), shadingChar(), shapeChar(),colorInt(),shadingInt(),shapeInt(){}
	Card(std::string In) :Attributes(In),colorInt(0),shadingInt(0),shapeInt(0)
	{
		CardStream << Attributes;
		CardStream >> NumOfSymbols;

		CardStream >> colorChar;
		switch(colorChar)
		{
		case 'R':
			colorInt = Red;
			break;
		case 'G':
			colorInt = Green;
			break;
		case 'P':
			colorInt = Purple;
			break;
		default:
			break;
		}
		CardStream >> shadingChar;
		switch(shadingChar)
		{
		case'F':
			shadingInt = Filled;
			break;
		case 'O':
			shadingInt = Open;
			break;
		case'S':
			 shadingInt = Striped;
		default:
			break;
		}
		CardStream >> shapeChar;
		switch(shapeChar)
		{
		case 'D':
			shapeInt = 1;
			break;
		case'O':
			shapeInt = 2;
			break;
		case'S':
			shapeInt = 3;
			break;
		default:
			break;
		}

	}
	//Card(int Num, int color, int shading, int shape) :NumOfSymbols(Num), colorStr(color),shadingStr(shading),shapeChar(shape){}
#pragma endregion

};

