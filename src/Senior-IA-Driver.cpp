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
std::vector<MeaningUnit> readInLines(std::string, std::ifstream&, int);
std::vector<PoeticDevice> readInDevices(std::string);

std::map<std::string, class LitUnit> IBmap;
std::map<std::string, class LitUnit> APmap;

int main()
{
	if (!startupLit())
	{
		return -1;
	}

	if (!startupStages())
	{
		return -2;
	}

	//std::cout << IBmap.find("Heroides1")->second.intoString();

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

	std::cout << numIB << "\n"; //todo remove
	std::cout << numAP << "\n"; //todo remove

	for (int i = 0; i < numIB; i++)
	{
		getline(infile, line);

		std::ifstream litfile;
		std::string litline;

		std::string title = line;
		litfile.open("data\\" + title + ".txt", std::ios::out);

		getline(litfile, litline);
		getline(litfile, litline);
		std::string author = litline;
		getline(litfile, litline);
		std::string meter = litline;
		getline(litfile, litline);
		int numUnits = std::stoi(litline);

//		std::vector<MeaningUnit> units = readInLines(meter, litfile, numUnits);
//		Translator t = Translator(readInLines(meter, litfile, numUnits));
		IBmap.insert(
				{ title, LitUnit(readInDevices(title), author, meter,
						Translator(readInLines(meter, litfile, numUnits))) });
	}
	for (int i = 0; i < numAP; i++)
	{
		getline(infile, line);

		std::ifstream litfile;
		std::string litline;

		std::string title = line;
		litfile.open("data\\" + title + ".txt", std::ios::out);

		getline(litfile, litline);
		getline(litfile, litline);
		std::string author = litline;
		getline(litfile, litline);
		std::string meter = litline;
		getline(litfile, litline);
		int numUnits = std::stoi(litline);

		//		std::vector<MeaningUnit> units = readInLines(meter, litfile, numUnits);
		//		Translator t = Translator(readInLines(meter, litfile, numUnits));
		APmap.insert(
				{ title, LitUnit(readInDevices(title), author, meter,
						Translator(readInLines(meter, litfile, numUnits))) });
	}
	return true;
}

bool startupStages()
{
	return true;
}

std::vector<MeaningUnit> readInLines(std::string meter, std::ifstream& litfile, //todo other meters
		int numUnits)
{
	std::vector<MeaningUnit> units;
	std::string litline;

	getline(litfile, litline);
	if (meter == "ElegiacCouplet")
	{
		std::string english;
		std::string latin;
		for (int i = 0; i < numUnits; i++)
		{
			getline(litfile, litline);
			latin += litline;
			getline(litfile, litline);
			latin += litline;

			getline(litfile, litline);
			english += litline;
			getline(litfile, litline);
			english += litline;
			getline(litfile, litline);
			MeaningUnit m = MeaningUnit(latin, english);

			units.push_back(m);
		}

	}

	for(unsigned int i = 0; i < units.size(); i++) //todo remove
	{
		std::cout << units.at(i).intoString() + "\n";
	}

	return units;
}

std::vector<PoeticDevice> readInDevices(std::string title)
{
	std::vector<PoeticDevice> p;

	std::ifstream devfile;
	std::string devline;

	devfile.open("data\\" + title + "PD.txt", std::ios::out);

	getline(devfile, devline);
	int numDevices = std::stoi(devline);

	for (int i = 0; i < numDevices; i++)
	{
		int count = 0;
		std::string type = "";
		std::string description = "";

		getline(devfile, devline);
		count = std::stoi(devline);

		getline(devfile, devline);
		type = devline;

		getline(devfile, devline);
		description = devline;

		p.push_back(PoeticDevice(count, type, description));
	}

	return p;
}
