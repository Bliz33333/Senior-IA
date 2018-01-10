/** \file Translator.h
 *  \brief The header file for the Translator class.
 *
 *	\see Translator
 */

/** \file Translator.cpp
 *  \brief The source code file for the Translator class.
 *
 *  \see Translator
 */

#ifndef SRC_TRANSLATOR_H_
#define SRC_TRANSLATOR_H_

/**
 *
 */
#include "MeaningUnit.h"

/**
 *
 */
#include <vector>

class Translator
{
public:
	std::vector<MeaningUnit> text;
	std::string DAL;
	std::string DAE;
	int latinCounter, englishCounter;
	Translator(std::vector<MeaningUnit> t);
	Translator();
	void nextLatin();
	void draw();
	void nextEnglish();
	std::string intoString();
};




#endif /* SRC_TRANSLATOR_H_ */
