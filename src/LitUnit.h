/*
 * LitUnit.h
 *
 *  Created on: Nov 17, 2017
 *      Author: s105308
 */

#ifndef SRC_LITUNIT_H_
#define SRC_LITUNIT_H_

#include <string>
#include "PoeticDevice.h"
#include <vector>
#include "Translator.h"

class LitUnit
{
public:
	Translator translator = Translator();
	std::vector<PoeticDevice> devices = std::vector<PoeticDevice>();
	std::string author, meter;
	LitUnit(std::vector<PoeticDevice> d, std::string a, std::string m, Translator t);
};

#endif /* SRC_LITUNIT_H_ */
