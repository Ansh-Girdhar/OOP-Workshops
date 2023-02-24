/*
    ==================================================
    Workshop 01: OOP435ZCC
    ==================================================
    Name   : Ansh GirdhAR
    ID     : 152552204
    Email  : agirdhar@myseneca.ca
    Section: ZCC
*/


#include "carads.h"

using namespace std;

double g_taxrate = 0.13;
double g_discount = 0.05;
namespace sdds
{


    Cars::Cars()
    {
        price = 0;
        status = '\0';
        model[0] = '\0';
        year = 0;
        discount = false;
        brand = nullptr;
    }
    Cars::Cars(const Cars& carPassed)
    {
        if (carPassed.brand == nullptr)
        {
            brand = nullptr;
        }
        else
        {
            brand = new char[strlen(carPassed.brand) + 1];
            strcpy(brand, carPassed.brand);
        }
        status = carPassed.status;
        year = carPassed.year;
        discount = carPassed.discount;
        price = carPassed.price;
        strcpy(model, carPassed.model);
    }

    Cars& Cars::operator=(const Cars& carPassed)
    {
        if (this != &carPassed)
        {
            if (brand == nullptr)
            {
                brand = nullptr;
            }
            else
            {
                delete[] brand;
                brand = nullptr;
            }
            if (carPassed.brand != nullptr)
            {
                brand = new char[strlen(carPassed.brand) + 1];
                strcpy(brand, carPassed.brand);
            }
            strcpy(model, carPassed.model);
            price = carPassed.price;
            status = carPassed.status;
            discount = carPassed.discount;
            year = carPassed.year;
        }
        return *this;
    }

    Cars::~Cars()
    {
        if (brand != nullptr)
            delete[] brand;
        brand = nullptr;
    }

    void Cars::read(istream& in)
    {
        if (!in.good())
        {
            return;
        }
        else
        {

            if (brand != nullptr)
            {
                delete[] brand;
            }
            brand = nullptr;
            string line;
            in >> status;
            in.ignore(1000, ',');
            getline(in, line, ',');
            brand = new char[strlen(line.c_str()) + 1];
            strcpy(brand, line.c_str());
            in.getline(model, 15, ',');
            in >> year;
            in.ignore(1000, ',');
            in >> price;
            in.ignore(1000, ',');

            char discountT;
            in >> discountT;
            if (in.peek() == '\n')
                in.ignore();

            if (discountT == 'Y')
                discount = true;
            else
                discount = false;
        }
    }

    void Cars::display(bool reset)
    {
        static int countFlag = 0;
        if (reset)
        {
            countFlag = 0;
        }
        countFlag++;
        cout << setw(2) << left << countFlag << ". ";
        if (brand[0] != '\0')
        {
            double priceT = price * (1 + g_taxrate);
            double discountT = priceT * (1 - g_discount);
            cout << setw(10) << left << brand << "| ";
            cout << setw(15) << left << model << "| ";
            cout << setw(4) << right << year << " |";
            cout << setw(12) << right << fixed << setprecision(2) << priceT << "|";
            if (discount)
            {
                cout << setw(12) << right << fixed << setprecision(2) << discountT;
            }
            cout << endl;
        }
        else
        {
            cout << "No Car" << endl;
        }
    }

    char Cars::getStatus()
    {
        return status;
    }
    Cars::operator bool()
    {
        return status == 'N';

    }

    istream& operator>>(istream& is, Cars& car)
    {
        car.read(is);
        return is;
    }
    void operator>>(const Cars& carA, Cars& carB)
    {
        carB = carA;
    }

    void listArgs(int argc, char* argv[])
    {
        cout << "Command Line:\n";
        cout << "--------------------------\n";
        for (int i = 0; i < argc; i++)
        {
            cout << setw(3)
                << i + 1 << ": "
                << argv[i] << endl;
        }
        cout << "--------------------------\n\n";
    }
}





