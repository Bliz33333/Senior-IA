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

/**
 *
 */
class Translator
{
public:
	/**
	 *  An object that stores all of the Latin and English of this Literature in order in the form of MeaningUnits.
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
	 *  Keeps track of which MeaningUnit's English the user is currently at.
	 */
	int englishCounter;

	/**
	 *  Keeps track of which MeaningUnit's Latin the user is currently at.
	 */
	int latinCounter;

	/**
	 *  \brief Constructs a Translator from a MeaningUnit array.
	 *
	 *  The text objects is copies from the t parameter, DAE and DAL are set to blank (""), and englishCounter/latinCounter are set to -1.
	 */
	Translator(std::vector<MeaningUnit> t);

	/**
	 *
	 */
	void nextLatin();

	/**
	 *
	 */
	void draw();

	/**
	 *
	 */
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
