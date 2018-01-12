/** \file StartUpCommands.h
 *  \brief The header file for the code that contains methods used by the driver during program startup.
 *
 */

/** \file StartUpCommands.cpp
 *  \brief The source code file that contains methods used by the driver during program startup.
 *
 */

/** \file Senior-IA-Driver.cpp
 *  \brief The driver that creates the UI, starts up the program, and acts as the main loop.
 */

/** \file [title].txt
 *  \verbinclude [title].txt
 *  \brief The file that contains information about the literature names title.
 *
 *  Each literature his its own [title].txt file with the [title] replaced by the title of the file. The file contains the title (again) in the first line, the author in the second, the meter in the third, and the number of MeaningUnits in the fourth. After a blank line, the first MeaningUnit starts with the Latin, then the English. There is then another blank line before the second MeaningUnit; this pattern continues till the end.
 */

/** \file [title]PD.txt
 *  \verbinclude [title]PD.txt
 *  \brief The file that contain literary devices for a piece of literature.
 *
 *  Each literature his its own [title]PD.txt file with the [title] replaced by the title of the file. The file contains the number of poetic devices in the first line, and then the poetic device information. Each poetic device takes up 3 lines in the file: it has the number of the MeaningUnit where it appears in the first line, the type of poetic device it is in the second line, and the description in the third line. There are no blank spaces.
 *
 */

/** \file LitNames.txt
 *  \verbinclude LitNames.txt
 *  \brief The file that contains how many and the names of the Literatures.
 *
 *  This file contains the number of IB literatures in the first line, the number of AP literatures in the seconds, then each IB literature title in its own line, and finally all the AP literature titles each in their own line. Each title corresponds to the name two files ([title].txt and [title]PD.txt) that contain info for the literature.
 *
 *  \see [title].txt
 *  \see [title]PD.txt
 */

#ifndef SRC_STARTUPCOMMANDS_H_
#define SRC_STARTUPCOMMANDS_H_


#include "LitUnit.h"

#include <fstream>

#include <map>

/** \brief The startup method that loads all of the literature data into the program from files.
 *
 *  This method is given two blank maps, one for IB literature and one for AP literature, and then reads in the data from files in the data folder. It starts by opening the LitNames.txt file, which contains the number of IB and AP literatures as well as the name of each literature. For each piece of literature, a LitUnit is constructed by reading in from [title].txt and [title]PD.txt. This LitUnit is then mapped to its title in the correct map.
 *  \see LitNames.txt
 *  \see LitUnit
 *  \param IBmap The map that holds all the IB literatures
 *  \param APmap The map that holds all the AP literatures
 */
void startupLit(std::map<std::string, class LitUnit>& IBmap, std::map<std::string, class LitUnit>& APmap);

/* todo finish
 *
 */
void startupStages();


#endif /* SRC_STARTUPCOMMANDS_H_ */
