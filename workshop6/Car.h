/*
   Name - Ansh Girdhar
   Email - agirdhar@myseneca.ca
   Student Id - 152552204
   Date - 2022-11-06
*/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef CAR_H
#define CAR_H
#include "Vehicle.h"
#include <iostream>
namespace sdds {
    class Car : public Vehicle {
        std::string carMaker{ "" };
        char carCondition{ '\0' };
        double carTopSpeed{ 0 };

    public:
        Car(std::istream& is);
        std::string condition() const;
        double topSpeed() const;
        void display(std::ostream& out) const;
    };



}

#endif