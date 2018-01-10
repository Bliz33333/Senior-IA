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

/** Inclusion of the PoeticDevice class because LitUnit stores and displays poetic devices.
 *  \see devices
 *  \see PoeticDevice.h
 */
#include "PoeticDevice.h"

/** Inclusion of the Translator class because Translator stores the Latin and its corresponding English.
 *  \see translator
 *  \see Translator.h
 */
#include "Translator.h"

/** \brief The object that holds information for a single piece of literature.
 *
 *  This class is the highest level class for the literature section of this program. It stores all the information and methods needed to display the literature on the screen: author, meter, the Latin, its English, and poetic devices.
 *  There is one LitUnit per literature.
 */
class LitUnit
{
public:
	/** A Translator that stores and tracks the Latin and English of the section.
	 *
	 *  The translator object stores all of the Latin as well as its translated English. It also tracks at what point in the section the user is reading at, and updates a string to show what the user needs to see.
	 *  \see Translator.h
	 *  \see Translator
	 */
	Translator translator = Translator();

	/** A vector of PoeticDevices to hold the poetic devices of this section.
	 *
	 *  The devices object holds each poetic device and where it appears in this section. They are stored in order of appearance.
	 *
	 */
	std::vector<PoeticDevice> devices = std::vector<PoeticDevice>();

	/** A string that holds the author of this literature section.
	 *
	 */
	std::string author;

	/** A string that holds the meter of this literature section.
	 *
	 *  If the literature is poetry, this string holds what meter the poetry is in. If it is prose, this string holds "prose".
	 */
	std::string meter;

	/** The constructor that makes a LitUnit.
	 *
	 *  This constructor does not do anything other than copy the given objects to the corresponding member objects of the LitUnit.
	 *
	 *  \param d The vector<PoeticDevices> that is used to create the devices object.
	 *  \param a The string that holds the author.
	 *  \param m The string that holds the meter.
	 *  \param t The Translator for this section.
	 *
	 *  \see devices
	 *  \see author
	 *  \see meter
	 *  \see translator
	 */
	LitUnit(std::vector<PoeticDevice> d, std::string a, std::string m, Translator t);

	/** A method that converts the LitUnit into string.
	 *
	 *  The author and meter are saved on the first two lines of the string, then the PoeticDevices are saved to the next lines, then the Translator is saved. The PoeticDevices and Translator are converted to strings by thier own intoString() method.
	 *
	 *  \see Translator::intoString()
	 *  \see PoeticDevice::intoString()
	 */
	std::string intoString();
};

#endif /* SRC_LITUNIT_H_ */
