/*
 * MeaningUnit.cpp
 *
 *  Created on: Nov 9, 2017
 *      Author: s105308
 */
#include <iostream>
#include "MeaningUnit.h"

MeaningUnit::MeaningUnit(std::string latinInput, std::string englishInput) :
		latin(latinInput), english(englishInput)
{
}

MeaningUnit::MeaningUnit()
{
	assert(0 == 1);
}

std::string MeaningUnit::intoString()
{
	return latin + "\n" + english + "\n";
}
