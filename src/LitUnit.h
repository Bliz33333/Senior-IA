/** \file LitUnit.h
 *  \brief The header file for the LitUnit class.
 *
 *	\see LitUnit
 */

/** \file LitUnit.cpp
 *  \brief The source code file for the LitUnit class.
 *
 *  \see LitUnit
 */

#ifndef SRC_LITUNIT_H_
#define SRC_LITUNIT_H_

#include "PoeticDevice.h"

#include "Translator.h"

/** \brief The object that holds information for a single piece of literature.
 *
 *  This class is the highest level class for the literature section of this program. It stores all the information and methods needed to display the literature on the screen: author, meter, the Latin, its English, and poetic devices.
 *  There is one LitUnit per literature.
 */
class LitUnit
{
public:

	/** \brief A vector of PoeticDevices to hold the poetic devices of this section.
	 *
	 *  The devices object holds each poetic device and where it appears in this section. They are stored in order of appearance.
	 *
	 */
	std::vector<PoeticDevice> devices;

	/** \brief A string that holds the author of this literature section.
	 *
	 */
	std::string author;

	/** \brief A string that holds the meter of this literature section.
	 *
	 *  If the literature is poetry, this string holds what meter the poetry is in. If it is prose, this string holds "prose".
	 */
	std::string meter;

	/** \brief A Translator that stores and tracks the Latin and English of the section.
	 *
	 *  The translator object stores all of the Latin as well as its translated English. It also tracks at what point in the section the user is reading at, and updates a string to show what the user needs to see.
	 *  \see Translator.h
	 *  \see Translator
	 */
	Translator translator;

	/** \brief The constructor that makes a LitUnit.
	 *
	 *  This constructor does not do anything other than copy the given objects to the corresponding member objects of the LitUnit.
	 *
	 *  \param d The vector<PoeticDevices> that is copied to the devices object.
	 *  \param a The string that is copied to author.
	 *  \param m The string that is copied to meter.
	 *  \param t The Translator for that is copied to translator.
	 *
	 *  \see devices
	 *  \see author
	 *  \see meter
	 *  \see translator
	 */
	LitUnit(std::vector<PoeticDevice> d, std::string a, std::string m,
			Translator t);

	/** \brief A method that converts the LitUnit into a string.
	 *
	 *  The author and meter are written to the first two lines of the string, the next line is blank, then the PoeticDevices are written to the next lines, then the Translator is written. The PoeticDevices and Translator are converted to strings by their own intoString() method.
	 *
	 *  \see std::string Translator::intoString()
	 *  \see std::string PoeticDevice::intoString()
	 */
	std::string intoString();
};

#endif /* SRC_LITUNIT_H_ */
