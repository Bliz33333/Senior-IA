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

/**
 *
 */
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

	/**
	 *
	 */
	std::string intoString();
};

#endif /* SRC_POETICDEVICE_H_ */
