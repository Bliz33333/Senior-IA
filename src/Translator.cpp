/*
 * Translator.cpp
 *
 *  Created on: Nov 9, 2017
 *      Author: s105308
 */
#include "Translator.h"

Translator::Translator(std::vector<MeaningUnit> t) :
		text(t), DAL(""), DAE(""), englishCounter(-1), latinCounter(-1)
{
}

void Translator::nextLatin()
{
	latinCounter++;
	DAL += text.at(latinCounter).latin + "\n";
}

void Translator::nextEnglish()
{
	latinCounter++;
	DAL += text.at(latinCounter).latin + "\n";
}

std::string Translator::intoString()
{
	std::string s = "";

	for (unsigned int i = 0; i < text.size(); i++)
	{
		s += text.at(i).intoString() + "\n";
	}

	return s;
}

