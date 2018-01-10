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

/** Inclusion of the STD string class to hold the Latin and English, as well as for use by classes that depend on this file.
 *
 */
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

	/**
	 *
	 */
	std::string intoString();
};



#endif /* SRC_MEANINGUNIT_H_ */
