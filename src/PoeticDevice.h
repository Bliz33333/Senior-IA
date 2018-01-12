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

class PoeticDevice
{
public:
	/**
	 *
	 */
	int count;

	/**
	 *
	 */
	std::string type, description;

	/**
	 *
	 */
	PoeticDevice(int c, std::string t, std::string d);

	/** \brief A method that converts the PoeticDevice into a string.
	 *
	 *  The methods creates the string by joining the count, a newline, the type string, a newline, the description string, and another newline.
	 */
	std::string intoString();
};

#endif /* SRC_POETICDEVICE_H_ */
