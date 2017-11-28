/*
 * Translator.cpp
 *
 *  Created on: Nov 9, 2017
 *      Author: s105308
 */
#include <iostream>
#include "MeaningUnit.h"
#include <vector>
#include "Translator.h"

Translator::Translator(std::vector<MeaningUnit> t)
{
	text = t;
	DAL = "";
	DAE = "";
	counter = -1;
}

Translator::Translator()
{
	text = std::vector<MeaningUnit>();
	DAL = "";
	DAE= "";
	counter = -1;
}

void Translator::nextLatin()
{
	counter++;
	DAL += "\n\n" + text[counter].latin;
}

void Translator::nextEnglish()
{
	counter++;
	DAE += "\n\n" + text[counter].english;
}

