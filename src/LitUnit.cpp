/*
 * LitUnit.cpp
 *
 *  Created on: Nov 17, 2017
 *      Author: s105308
 */

#include "LitUnit.h"

LitUnit::LitUnit(std::vector<PoeticDevice> d, std::string a, std::string m, Translator t)
{
	devices = d;
	author = a;
	meter = m;
	translator = t;
}
