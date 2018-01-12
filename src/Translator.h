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

#include "MeaningUnit.h"

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

	/** \brief A method that converts the Translator into a string.
	 *
	 *  The methods creates the string by joining the result of calling the intoString() method for each MeaningUnit in the Translator.
	 *
	 *  \see std::string MeaningUnit::intoString()
	 */
	std::string intoString();
};




#endif /* SRC_TRANSLATOR_H_ */
