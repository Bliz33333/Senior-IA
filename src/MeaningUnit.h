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
 *
 */
class MeaningUnit
{
public:
	/**
	 *
	 */
	std::string latin, english;

	/**
	 *
	 */
	bool latinActive, englishActive;

	/**
	 *
	 */
	MeaningUnit(std::string latinInput, std::string englishInput);

	/** \brief A method that converts the MeaningUnit into a string.
	 *
	 *  The methods creates the string by joining the latin string, a newline, the english string, and another newline.
	 */
	std::string intoString();
};

#endif /* SRC_MEANINGUNIT_H_ */
