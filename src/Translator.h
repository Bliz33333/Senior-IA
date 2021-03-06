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
#include <sstream>

/**
 *  \brief The object that deals with displaying and keeping track of the Latin/English for a literature.
 */
class Translator
{
public:
	/**
	 *  \brief An object that stores all of the Latin and English of this Literature in order in the form of MeaningUnits.
	 */
	std::vector<MeaningUnit> text;

	/**
	 *  \brief Stands for "Display Area Latin", is the string containing Lain to be shown to the user.
	 *
	 *  As the user reads through the Literature, more and more of the Latin is added to this string. When the user resets the display, this string is cleared.
	 */
	std::string DAL;

	/**
	 *  \brief Stands for "Display Area English", is the string containing English to be shown to the user.
	 *
	 *  As the user reads through the Literature, more and more of the Latin is added to this string. When the user resets the display, this string is cleared.
	 */
	std::string DAE;

	/**
	 *  \brief Keeps track of which MeaningUnit's English the user is currently at.
	 */
	int englishCounter;

	/**
	 *  \brief Keeps track of which MeaningUnit's Latin the user is currently at.
	 */
	int latinCounter;

	unsigned int cutPercent;
	unsigned int cutLength;

	/**
	 *  \brief Constructs a Translator from a MeaningUnit array.
	 *
	 *  The text object is copied from the t parameter, DAE and DAL are set to blank (""), and englishCounter/latinCounter are set to -1.
	 */
	Translator(std::vector<MeaningUnit> t);

	Translator();

	/**
	 *  \brief Advances the Latin that the user can read.
	 *
	 *  Increments latinCounter and updates the DAL to show the next MeaningUnit's Latin (text.at(latinCounter).latin).
	 */
	void nextLatin();

	/**
	 *  \brief Advances the English that the user can read.
	 *
	 *  Increments englishCounter and updates the DAE to show the next MeaningUnit's English (text.at(englishCounter).english).
	 */
	void nextEnglish();

	void nextWCEnglish();
	void toCleanEnglish();

	void reset();

	/** \brief A method that converts the Translator into a string.
	 *
	 *  The methods creates the string by joining the result of calling the intoString() method for each MeaningUnit in the Translator.
	 *
	 *  \see std::string MeaningUnit::intoString()
	 */
	std::string intoString();
};

#endif /* SRC_TRANSLATOR_H_ */
