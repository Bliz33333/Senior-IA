/*
 * MeaningUnit.h
 *
 *  Created on: Nov 9, 2017
 *      Author: s105308
 */

#ifndef SRC_MEANINGUNIT_H_
#define SRC_MEANINGUNIT_H_


class MeaningUnit
{
public:
	std::string latin, english;
	bool latinActive, englishActive;
	MeaningUnit(std::string latinInput, std::string englishInput);
	std::string intoString();
};



#endif /* SRC_MEANINGUNIT_H_ */
