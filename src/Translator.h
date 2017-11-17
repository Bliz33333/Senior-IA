/*
 * Translator.h
 *
 *  Created on: Nov 17, 2017
 *      Author: s105308
 */

#ifndef SRC_TRANSLATOR_H_
#define SRC_TRANSLATOR_H_


#include <iostream>
#include "MeaningUnit.h"
#include <vector>

class Translator
{
public:
	std::vector<MeaningUnit> text;
	std::string DAL;
	std::string DAE;
	int counter = -1;
	Translator(std::vector<MeaningUnit> t, std::string l, std::string);
	void nextLatin();
	void nextEnglish();
};




#endif /* SRC_TRANSLATOR_H_ */
