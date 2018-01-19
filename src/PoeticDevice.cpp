/*
 * PoeticDevice.cpp
 *
 *  Created on: Nov 17, 2017
 *      Author: s105308
 */

#include "PoeticDevice.h"

PoeticDevice::PoeticDevice(int c, std::string t, std::string d = "") : count(c), type(t), description(d) {}

std::string PoeticDevice::intoString()
{
	std::string s = "";

	std::string temp = "";
	temp = std::to_string(count);

	s += temp + "\n" + type + "\n" + description + "\n";
	return s;
}
