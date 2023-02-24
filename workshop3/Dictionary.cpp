/*
    ==================================================
    Workshop 03: OOP435ZCC
    ==================================================
    Name   : Ansh GirdhAR
    ID     : 152552204
    Email  : agirdhar@myseneca.ca
    Section: ZCC
*/
#include "Dictionary.h"
namespace sdds
{
    std::ostream& operator<<(std::ostream& os, const Dictionary& d)
    {
        os.width(20);
        os.setf(std::ios::right);
        os << d.getTerm() << ": " << d.getDefinition();
        return os;
    }
    bool operator==(const Dictionary& left, const Dictionary& right)
    {
        return left.getTerm() == right.getTerm();
    }
}