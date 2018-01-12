/*
 * StartUpCommands.cpp
 *
 *  Created on: Dec 6, 2017
 *      Author: s105308
 */

#include "StartUpCommands.h"

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
			english = "";
			latin = "";

			getline(litfile, litline);
			latin += litline;
			getline(litfile, litline);
			latin += "\n" + litline;

			getline(litfile, litline);
			english += litline;
			getline(litfile, litline);
			english += +"\n" + litline;
			getline(litfile, litline);
			MeaningUnit m = MeaningUnit(latin, english);

			units.push_back(m);
		}

	}

	if (meter == "Prose")
	{
		std::string english;
		std::string latin;
		for (int i = 0; i < numUnits; i++)
		{
			english = "";
			latin = "";

			getline(litfile, litline);
			latin += litline;

			getline(litfile, litline);
			english += litline;

			getline(litfile, litline);
			MeaningUnit m = MeaningUnit(latin, english);

			units.push_back(m);
		}

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
		count = stoi(devline);

		getline(devfile, devline);
		type = devline;

		getline(devfile, devline);
		description = devline;

		p.push_back(PoeticDevice(count, type, description));
	}

	return p;
}

void startupLit(std::map<std::string, class LitUnit>& IBmap,
		std::map<std::string, class LitUnit>& APmap)
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

		APmap.insert(
				{ title, LitUnit(readInDevices(title), author, meter,
						Translator(readInLines(meter, litfile, numUnits))) });
	}
}

void startupStages() //todo finish
{}

