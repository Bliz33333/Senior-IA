/** \file StartUpCommands.h
 *  \brief The header file for the code that contains several commands used by the driver during program startup.
 *
 */

/** \file PoeticDevice.cpp
 *  \brief The source code file that contains several commands used by the driver during program startup.
 *
 *  \see PoeticDevice
 */

#ifndef SRC_STARTUPCOMMANDS_H_
#define SRC_STARTUPCOMMANDS_H_

#include "LitUnit.h"
#include <fstream>
#include <map>


void startupLit(std::map<std::string, class LitUnit>&, std::map<std::string, class LitUnit>&);
void startupStages();
std::vector<MeaningUnit> readInLines(std::string, std::ifstream&, int);
std::vector<PoeticDevice> readInDevices(std::string);


#endif /* SRC_STARTUPCOMMANDS_H_ */
