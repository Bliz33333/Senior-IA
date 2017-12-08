/*
 * StartUpCommands.h
 *
 *  Created on: Dec 6, 2017
 *      Author: s105308
 */

#ifndef SRC_STARTUPCOMMANDS_H_
#define SRC_STARTUPCOMMANDS_H_

#include "Senior-IA-Driver.h"
#include "LitUnit.h"
#include "MeaningUnit.h"
#include "PoeticDevice.h"
#include "Translator.h"
#include <iostream>
#include <fstream>
#include <map>
#include <vector>


bool startupLit(std::map<std::string, class LitUnit>&, std::map<std::string, class LitUnit>&);
bool startupStages();
std::vector<MeaningUnit> readInLines(std::string, std::ifstream&, int);
std::vector<PoeticDevice> readInDevices(std::string);


#endif /* SRC_STARTUPCOMMANDS_H_ */
