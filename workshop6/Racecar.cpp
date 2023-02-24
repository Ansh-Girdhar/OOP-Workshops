/*
   Name - Ansh Girdhar
   Email - agirdhar@myseneca.ca
   Student Id - 152552204
   Date - 2022-11-06
*/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include "Racecar.h"

namespace sdds {
    Racecar::Racecar(std::istream& in) :Car(in) {

        in >> m_booster;


    };

    void Racecar::display(std::ostream& out) const {
        Car::display(out);
        out << "*";

    };

    double Racecar::topSpeed() const {
        return  (Car::topSpeed() + (Car::topSpeed() * m_booster));

    };


}