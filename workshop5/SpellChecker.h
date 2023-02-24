#/*
    ==================================================
    Workshop 02: OOP345ZCC
    ==================================================
    Name   : Ansh GirdhAR
    ID     : 152552204
    Email  : agirdhar@myseneca.ca
    Section: ZCC
*/
#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H

#include <string>
namespace sdds
{
	class SpellChecker
	{
		std::string m_bad[6]{};
		std::string m_good[6]{};
		size_t m_repl[6]{};

	public:
		SpellChecker();
		SpellChecker(const char* filename);
		void operator()(std::string& text);
		void showStatistics(std::ostream& out) const;
	};

}
#endif