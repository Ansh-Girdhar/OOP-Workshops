/*
    ==================================================
    Workshop 01: OOP435ZCC
    ==================================================
    Name   : Ansh GirdhAR
    ID     : 152552204
    Email  : agirdhar@myseneca.ca
    Section: ZCC
*/

#ifndef __SDDS_CARADS_H__
#define __SDDS_CARADS_H__

#include <iostream>
#include <string.h>
#include <string>
#include <iomanip>

extern double g_taxrate;
extern double g_discount;

namespace sdds
{

    class Cars
    {
    public:
        Cars();
        Cars(const Cars& carPassed);

        void display(bool reset);
        char getStatus();
        void read(std::istream& in);
        operator bool();
        Cars& operator=(const Cars& carPassed);
        ~Cars();
    private:

        double price;
        char status;
        char* brand;
        char model[15];
        bool discount;
        int year;

    };
    std::istream& operator>>(std::istream& is, Cars& car);
    void operator>>(const Cars& car1, Cars& car2);
    void listArgs(int argc, char* argv[]);
}
#endif