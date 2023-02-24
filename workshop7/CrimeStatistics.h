/*
    Name   : Ansh Girdhar
    ID     : 15255204
    Email  : agirdhar@myseneca.ca
    Section: ZCC
*/
#ifndef CRIMESTATISTICS_H
#define CRIMESTATISTICS_H
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <list>
#include <numeric>
#include <iomanip>
namespace sdds {

    struct Crime {
        std::string province;
        std::string district;
        std::string crime;
        unsigned int noCases;
        unsigned int year;
        unsigned int m_resolved;

    };

    class CrimeStatistics {
        std::vector <Crime> crimeCollection;

    public:
        CrimeStatistics(const char* fName);

        void display(std::ostream& out) const;

        void sort(std::string fieldName);

        void cleanList();

        bool inCollection(std::string crimeType) const;

        std::list<Crime> getListForProvince(std::string provinceName) const;


    };

  
    std::ostream& operator<<(std::ostream& out, const Crime& theCrime);



}


#endif