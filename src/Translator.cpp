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

Translator::Translator(std::vector<MeaningUnit> t, std::string l, std::string e)
{
	text = t;
	DAL = l;
	DAE = e;
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

