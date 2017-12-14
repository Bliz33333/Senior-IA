/** \file LitUnit.h
 *  \brief The header file for the LitUnit class.
 *
 */

/** \file LitUnit.cpp
 *  \brief The source code file for the LitUnit class.
 *
 */

#ifndef SRC_LITUNIT_H_
#define SRC_LITUNIT_H_

/**
 *
 */
#include <string>

/**
 *
 */
#include "PoeticDevice.h"

/**
 *
 */
#include <vector>

/*
 *
 */
#include "Translator.h"

/** \brief The object that holds information for a single piece of literature.
 *
 *  This class is the highest level class for the literature section of this program. It stores all the information and methods needed to display the literature on the screen.
 */
class LitUnit
{
public:
	/**
	 *
	 */
	Translator translator = Translator();

	/**
	 *
	 */
	std::vector<PoeticDevice> devices = std::vector<PoeticDevice>();

	/**
	 *
	 */
	std::string author, meter;

	/**
	 *
	 */
	LitUnit(std::vector<PoeticDevice> d, std::string a, std::string m, Translator t);

	/**
	 *
	 */
	std::string intoString();
};

#endif /* SRC_LITUNIT_H_ */
