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

Translator::Translator():
				text(), DAL(""), DAE(""), englishCounter(-1), latinCounter(-1), cutPercent(33), cutLength(3)
{
	assert(0 == 1);
}

void Translator::nextLatin()
{
	latinCounter++;
	if(latinCounter < text.size())
	{
		DAL += text.at(latinCounter).latin + "\r\n\r\n";
	}
}

void Translator::nextWCEnglish()
{
	englishCounter++;

	std::string copyText = "";
	copyText += text.at(englishCounter).english;

	std::string cutText = "";

	while (copyText != "")
	{
		std::string line;
		std::istringstream iss(line);
		std::string word;

		std::getline(iss, line);

		if (line[0] == '\t')
		{
			cutText += "\t";
		}

		while (iss >> word)
		{
			if ((unsigned int) rand() % 100 > cutPercent || (unsigned int) word.length() <= cutLength)
			{
				cutText += " " + word + " ";
			}
			else
			{
				cutText += " ";
				for (unsigned int i = 0; i < word.length(); i++)
				{
					cutText += "_";
				}
				cutText += " ";
			}
		}
		cutText += "\n";
	}

	DAE += cutText + "\n";

}

void Translator::toCleanEnglish()
{
	int count = englishCounter;
	DAE = "";
	for(englishCounter = -1; englishCounter < count;)
	{
		nextEnglish();
	}
}

void Translator::nextEnglish()
{
	englishCounter++;
	if(latinCounter < text.size())
	{

		DAE += text.at(englishCounter).english + "\r\n\r\n";
	}
}

void Translator::reset()
{
	DAE = "";
	DAL = "";
	englishCounter = -1;
	latinCounter = -1;
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

