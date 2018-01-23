/** \file MeaningUnit.h
 *  \brief The header file for the MeaningUnit class.
 *
 *	\see MeaningUnit
 */

/** \file MeaningUnit.cpp
 *  \brief The source code file for the MeaningUnit class.
 *
 *  \see MeaningUnit
 */

#ifndef SRC_MEANINGUNIT_H_
#define SRC_MEANINGUNIT_H_

#include <string>

/**
 *  An object that holds a 'unit' of Latin (a sentence, line, or couplet), as well as its English translation.
 */
class MeaningUnit
{
public:
	/**
	 *  The string that holds the Latin.
	 */
	std::string latin;

	/**
	 *  The string that holds the English.
	 */
	std::string english;

	/**
	 *  The constructor, simply copies latinInput to latin and englishInput to english.
	 *
	 *  \param latinInput The latin.
	 *  \param englishInput The english.
	 */
	MeaningUnit(std::string latinInput, std::string englishInput);

	/** \brief A method that converts the MeaningUnit into a string.
	 *
	 *  The methods creates the string by joining the latin string, a newline, the english string, and another newline.
	 */
	std::string intoString();
};

#endif /* SRC_MEANINGUNIT_H_ */
