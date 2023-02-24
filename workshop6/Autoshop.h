/*
   Name - Ansh Girdhar
   Email - agirdhar@myseneca.ca
   Student Id - 152552204
   Date - 2022-11-06
*/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef AUTOSHOP_H
#define AUTOSHOP_H
#include <iostream>
#include <vector>
#include <list>
#include "Vehicle.h"



namespace sdds {
    class Autoshop {
        std::vector<Vehicle*> m_vehicles;
    public:
        Autoshop& operator+=(Vehicle* theVehicle);
        void display(std::ostream& out) const;
        template <typename T>
        void select(T test, std::list<const Vehicle*>& vehicles);
        ~Autoshop();

    };

    template <typename T>
    void Autoshop::select(T test, std::list<const Vehicle*>& vehicles) {
        for (auto i = m_vehicles.begin(); i != m_vehicles.end(); i++) {
            if (test(*i)) {
                vehicles.push_back(*i);

            };


        };

    };


}

#endif