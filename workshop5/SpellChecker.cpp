/*
	==================================================
	Workshop 02: OOP345ZCC
	==================================================
	Name   : Ansh GirdhAR
	ID     : 152552204
	Email  : agirdhar@myseneca.ca
	Section: ZCC
*/
#include <fstream>
#include <iomanip>
#include "SpellChecker.h"


namespace sdds
{
	SpellChecker::SpellChecker() {
		for (size_t i = 0; i < 6; i++) {
			m_bad[i] = "";
			m_good[i] = "";
			m_repl[i] = 0;
		}
	}
	SpellChecker::SpellChecker(const char* filename)
	{
		std::ifstream file(filename);

		if (!file)
			throw "Bad file name!";
		else
		{
			for (size_t i = 0; i < 6; i++)
			{
				file >> m_bad[i];
				file >> m_good[i];
			}
		}
	}

	void SpellChecker::operator()(std::string& text)
	{
		for (size_t i = 0; i < 6; i++)
		{
			size_t index = text.find(m_bad[i]);
			while (index != std::string::npos)
			{
				m_repl[i]++;
				text.replace(index, m_bad[i].length(), m_good[i]);
				index = text.find(m_bad[i]);
			}
		}
	}

	void SpellChecker::showStatistics(std::ostream& out) const
	{
		out << "Spellchecker Statistics" << std::endl;
		for (size_t i = 0; i < 6; i++)
		{
			out << std::setw(15) << m_bad[i] << ": " << m_repl[i] << " replacements" << std::endl;
		}

	}
}