/*
 * PoeticDevice.h
 *
 *  Created on: Nov 17, 2017
 *      Author: s105308
 */

#ifndef SRC_POETICDEVICE_H_
#define SRC_POETICDEVICE_H_

#include <string>

class PoeticDevice
{
public:
	int count;
	std::string type, description;
	PoeticDevice(int c, std::string t, std::string d);
	std::string intoString();
};

#endif /* SRC_POETICDEVICE_H_ */
