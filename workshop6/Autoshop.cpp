/*
   Name - Ansh Girdhar
   Email - agirdhar@myseneca.ca
   Student Id - 152552204
   Date - 2022-11-06
*/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include "Autoshop.h"

namespace sdds {
    Autoshop& Autoshop::operator+=(Vehicle* theVehicle) {
        m_vehicles.push_back(theVehicle);
        return (*this);
    };

    void Autoshop::display(std::ostream& out) const {
        std::vector<Vehicle*>::const_iterator it;

        for (it = m_vehicles.begin(); it != m_vehicles.end(); it++) {
            (*it)->display(out);
            std::cout << std::endl;
        };

    };

    Autoshop::~Autoshop() {
        for (auto i = m_vehicles.begin(); i != m_vehicles.end(); i++) {
            delete (*i);

        };
    };


}