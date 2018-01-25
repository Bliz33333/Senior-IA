/** \file PoeticDevice.h
 *  \brief The header file for the PoeticDevice class.
 *
 *	\see PoeticDevice
 */

/** \file PoeticDevice.cpp
 *  \brief The source code file for the PoeticDevice class.
 *
 *  \see PoeticDevice
 */

#ifndef SRC_POETICDEVICE_H_
#define SRC_POETICDEVICE_H_

#include <string>

/**
 *  \brief The class that stores a poetic device of a literature
 *
 *  Each PoetcDevice object holds one poetic device, each device is defined by where it is, its type, and its description. Each literature has an array of PoeticDevices.
 */
class PoeticDevice
{
public:
	/**
	 *  \brief An integer that stores the count of the MeaningUnit this PoeticDevice appears in.
	 */
	int count;

	/**
	 *  \brief This string stores the type of the poetic device (ex. metaphor, allusion, etc.)
	 */
	std::string type;

	/**
	 *  \brief This string stores a description of the poetic device.
	 */
	std::string description;

	/** \brief The constructor that makes a PoeticDevice.
	 *
	 *  This constructor does not do anything other than copy the given objects to the corresponding member objects of the PoeticDevice.
	 *
	 *  \param c The int that is copied to count.
	 *  \param t The string that is copied to type.
	 *  \param d The string that is copied to description.
	 *
	 *  \see devices
	 *  \see author
	 *  \see meter
	 *  \see translator
	 */
	PoeticDevice(int c, std::string t, std::string d);

	/** \brief A method that converts the PoeticDevice into a string.
	 *
	 *  The methods creates the string by joining the count, a blank line, the type string, a blank line, the description string, and another blank line.
	 */
	std::string intoString();
};

#endif /* SRC_POETICDEVICE_H_ */
