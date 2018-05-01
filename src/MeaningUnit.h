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
#include <assert.h> //TODO remove

/**
 *  \brief An object that holds a 'unit' of Latin (a sentence, line, couplet, etc.), as well as its English translation.
 */
class MeaningUnit
{
public:
	/**
	 *  \brief The string that holds the Latin.
	 */
	std::string latin;

	/**
	 *  \brief The string that holds the English.
	 */
	std::string english;

	/**
	 *  \brief The constructor, simply copies latinInput to latin and englishInput to english.
	 *
	 *  \param latinInput The latin.
	 *  \param englishInput The english.
	 */
	MeaningUnit(std::string latinInput, std::string englishInput);

	MeaningUnit();

	/** \brief A method that converts the MeaningUnit into a string.
	 *
	 *  The methods creates the string by joining the latin string, a blank line, the english string, and another blank line.
	 */
	std::string intoString();
};

#endif /* SRC_MEANINGUNIT_H_ */
