#include "Senior-IA-Driver.h"
#include "LitUnit.h"
#include "MeaningUnit.h"
#include "PoeticDevice.h"
#include "Translator.h"
#include <iostream>
#include <fstream>
#include <map>
#include <vector>

bool startupLit();
bool startupStages();
std::vector<MeaningUnit> readInLines(std::string, std::ifstream);

int main()
{
	if(!startupLit())
	{
		return -1;
	}

	if(!startupStages())
	{
		return -2;
	}

	return 0;
}

bool startupLit()			//todo make the error bool work
{
	int numIB = 0;
	int numAP = 0;

	std::ifstream infile;
	std::string line;

	infile.open("data\\LitNames.txt", std::ios::out);

	if (infile.is_open())
	{
		getline(infile, line);
		numIB = std::stoi(line);
		getline(infile, line);
		numAP = std::stoi(line);
	}

	std::map<std::string, class LitUnit> IBmap;
	std::map<std::string, class LitUnit> APmap;

	for(int i = 0; i < numIB; i++)
	{
		getline(infile, line);

		std::ifstream litfile;
		std::string litline;

		std::string title = line;
		litfile.open("data\\" + title +".txt", std::ios::out);

		getline(litfile, litline);
		getline(litfile, litline);
		std::string author = litline;
		getline(litfile, litline);
		std::string meter = litline;
	}

	return true;
}

bool startupStages()
{
	return true;
}

std::vector<MeaningUnit> readInLines(std::string meter, std::ifstream litfile)
{
	std::vector<MeaningUnit> units;
	std::string litline;

	getline(litfile, litline);
	getline(litfile, litline);
	if(meter == "ElegiacCouplet")
	{
		std::string english;
		std::string latin;

		getline(litfile, litline);
		latin += litline;
		getline(litfile, litline);
		latin += litline;

		getline(litfile, litline);
		english += litline;
		getline(litfile, litline);
		english += litline;

		MeaningUnit m = MeaningUnit(latin, english);
		units.push_back(m);
	}

	return units;
}
