/*
   Name - Ansh Girdhar
   Email - agirdhar@myseneca.ca
   Student Id - 152552204
   Date - 2022-11-06
*/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include "Luxuryvan.h"

namespace sdds {
    Luxuryvan::Luxuryvan(std::istream& in) :Van(in) {
        std::string consmpSpace;
        std::getline(in, consmpSpace, '\n');

        std::string arr[1] = { consmpSpace };
        for (int i = 0; i < 1; i++) {
            if (arr[i][0] != ' ' && arr[i][arr[i].length() - 1] != ' ') {
            }
            else if (arr[i][0] == ' ' && arr[i][arr[i].length() - 1] == ' ') {
                int fNrepPos = -1;
                for (unsigned int i2 = 0; i2 < arr[i].length(); i2++) {
                    if (arr[i][i2] != ' ') {
                        fNrepPos = i2;
                        i2 = arr[i].length();
                    };
                };
                arr[i].erase(0, fNrepPos);

                int firstSpacePos = -1;
                for (unsigned int i2 = 0; i2 < arr[i].length(); i2++) {
                    if (arr[i][i2] == ' ') {
                        if (i2 + 1 < arr[i].length()) {
                            if (arr[i][i2 + 1] == ' ') {
                                firstSpacePos = i2;
                                i2 = arr[i].length();
                            };

                        }
                        else {
                            firstSpacePos = i2;
                            i2 = arr[i].length();
                        };
                    };
                };
                arr[i].erase(firstSpacePos);


            }
            else if (arr[i][0] == ' ') {
                int firstNrepPos = -1;
                for (unsigned int i2 = 0; i2 < arr[i].length(); i2++) {
                    if (arr[i][i2] != ' ') {
                        firstNrepPos = i2;
                        i2 = arr[i].length();
                    };
                };
                arr[i].erase(0, firstNrepPos);
            }
            else {
                int firstSpacePos = -1;
                for (unsigned int i2 = 0; i2 < arr[i].length(); i2++) {
                    if (arr[i][i2] == ' ') {
                        if (i2 + 1 < arr[i].length()) {
                            if (arr[i][i2 + 1] == ' ') {
                                firstSpacePos = i2;
                                i2 = arr[i].length();
                            };

                        }
                        else {
                            firstSpacePos = i2;
                            i2 = arr[i].length();
                        };
                    };
                };
                arr[i].erase(firstSpacePos);

            };

        };


        if (arr[0] == "e") {
            m_consumption = arr[0];

        }
        else {
            // Invalid
            throw "Invalid record!";
        };



    };

    void Luxuryvan::display(std::ostream& out) const {
        Van::display(out);
        out << " electric van  *";

    };

    std::string Luxuryvan::consumption() const {
        std::string returnVal;
        if (m_consumption == "e") {

            returnVal = "electric";
        };
        return returnVal;
    };

}