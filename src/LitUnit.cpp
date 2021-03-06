#include "LitUnit.h"


LitUnit::LitUnit(std::vector<PoeticDevice> d, std::string a, std::string m,
		Translator t) :
		devices(d), author(a), meter(m), translator(t)
{
}

LitUnit::LitUnit() : author("This should never appear. it means the default litunit constructor was used")
{
	assert(0 == 1);
}

std::string LitUnit::intoString()
{
	std::string s = "";

	s += author + "\n" + meter + "\n" +"\n";
	for (unsigned int i = 0; i < devices.size(); i++)
	{
		s += devices.at(i).intoString() + "\n";
	}

	s += translator.intoString() + "\n";

	return s;
}
