/*
 * Translator.cpp
 *
 *  Created on: Nov 9, 2017
 *      Author: s105308
 */
#include "Translator.h"

Translator::Translator(std::vector<MeaningUnit> t)
{
	text = t;
	DAL = "";
	DAE = "";
	englishCounter = -1;
	latinCounter = -1;
}

void Translator::nextLatin()
{
	latinCounter++;
	text[latinCounter].latinActive = true;
	draw();
}

Translator::Translator()
{
	text = std::vector<MeaningUnit>();
	DAL = "";
	DAE = "";
	englishCounter = -1;
	latinCounter = -1;
}

void Translator::nextEnglish()
{
	englishCounter++;
	text[englishCounter].englishActive = true;
	draw();
}

void Translator::draw()
{
	for(unsigned int i = 0; i < text.size(); i++)
	{
		if(text[i].latinActive)
		{
			DAL += text.at(i).latin + "\n";
		}
		if(text[i].englishActive)
		{
			DAE += text.at(i).english + "\n";
		}
	}
}

std::string Translator::intoString()
{
	std::string s = "";

	for(unsigned int i = 0; i < text.size(); i++)
	{
		s += text.at(i).intoString() + "\n";
	}

	return s;
}

