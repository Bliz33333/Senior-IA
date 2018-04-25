/*
 * Translator.cpp
 *
 *  Created on: Nov 9, 2017
 *      Author: s105308
 */
#include "Translator.h"

Translator::Translator(std::vector<MeaningUnit> t) :
		text(t), DAL(""), DAE(""), englishCounter(-1), latinCounter(-1), cutPercent(33), cutLength(3)
{
}

void Translator::nextLatin()
{
	latinCounter++;
	DAL += text.at(latinCounter).latin + "\n";
}

void Translator::nextWCLatin()
{
	latinCounter++;

	std::string copyText = "";
	copyText += text.at(latinCounter).latin;

	std::string cutText = "";

	while (copyText != "")
	{
		std::string line;
		std::getline(copyText, line);

		if(line.at(0) == "\t")
		{
			cutText += "\t";
		}

		std::istringstream iss(line);
		std::string word;
		while (iss >> word)
		{
			if(rand() % 100 > cutPercent || word.length() <= cutLength)
			{
				cutText += " " + word + " ";
			}
		}
		cutText += "\n";
	}

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

