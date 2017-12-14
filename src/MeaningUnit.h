/** \file MeaningUnit.h
 *  \brief The header file for the MeaningUnit class.
 *
 */

/** \file MeaningUnit.cpp
 *  \brief The source code file for the MeaningUnit class.
 *
 */

#ifndef SRC_MEANINGUNIT_H_
#define SRC_MEANINGUNIT_H_

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
