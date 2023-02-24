/*
   Name - Ansh Girdhar
   Email - agirdhar@myseneca.ca
   Student Id - 152552204
   Date - 2022-11-06
*/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef RACECAR_H
#define RACECAR_H
#include "Car.h"
#include <iostream>
namespace sdds {
    class Racecar :public Car {
        double m_booster{ 0.0 };

    public:
        Racecar(std::istream& in);
        void display(std::ostream& out) const;
        double topSpeed() const;


    };



}

#endif
