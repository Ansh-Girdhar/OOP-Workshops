/*
   Name - Ansh Girdhar
   Email - agirdhar@myseneca.ca
   Student Id - 152552204
   Date - 2022-11-06
*/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef VAN_H
#define VAN_H
#include "Vehicle.h"
#include <iostream>
namespace sdds {
    class Van :public Vehicle {
        std::string vanMaker{ "" };
        char vanType{ '\0' };
        char vanCondition{ '\0' };
        char vanPurpose{ '\0' };
        double vanTopSpeed{ 0 };

    public:
        Van(std::istream& is);
        std::string condition() const;
        double topSpeed() const;
        std::string type() const;
        std::string usage() const;
        void display(std::ostream& out) const;

    };



}

#endif