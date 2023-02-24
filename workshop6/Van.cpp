/*
   Name - Ansh Girdhar
   Email - agirdhar@myseneca.ca
   Student Id - 152552204
   Date - 2022-11-06
*/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include "Van.h"

namespace sdds {

    Van::Van(std::istream& is) {

        std::string tag_Space;
        std::getline(is, tag_Space, ',');
        std::string maker_Space;
        std::getline(is, maker_Space, ',');
        std::string type_Space;
        std::getline(is, type_Space, ',');

        std::string purpose_Space;
        std::getline(is, purpose_Space, ',');

        std::string condition_Space;
        getline(is, condition_Space, ',');

        is >> vanTopSpeed;
        is.ignore();
        std::string arr[5] = { tag_Space,maker_Space,type_Space ,purpose_Space ,condition_Space };

        for (int i = 0; i < 5; i++) {
            if (arr[i][0] != ' ' && arr[i][arr[i].length() - 1] != ' ') {
            }
            else if (arr[i][0] == ' ' && arr[i][arr[i].length() - 1] == ' ') {
                int firstNrepPos = -1;
                for (unsigned int i2 = 0; i2 < arr[i].length(); i2++) {
                    if (arr[i][i2] != ' ') {
                        firstNrepPos = i2;
                        i2 = arr[i].length();
                    };
                };
                arr[i].erase(0, firstNrepPos);

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

        vanMaker = arr[1];
        vanType = arr[2].at(0);
        vanPurpose = arr[3].at(0);
        if (arr[4].length() == 0) {
            vanCondition = 'n';
        }
        else {
            vanCondition = arr[4].at(0);
        };



        if (vanType == 'p' || vanType == 'm' || vanType == 'c') {
            if (vanPurpose == 'd' || vanPurpose == 'p' || vanPurpose == 'c') {
                if (vanCondition == 'n' || vanCondition == 'b' || vanCondition == 'u') {


                }
                else {
                    // Invalid condition
                    throw "Invalid record!";
                };

            }
            else {
                // Invalid purpose
                throw "Invalid record!";
            };

        }
        else {
            // Invalid type
            throw "Invalid record!";
        };




    };

    // Returning the condition of the van
    std::string Van::condition() const {
        std::string returnVal;
        if (vanCondition == 'n') {
            // New
            returnVal = "new";
        }
        else if (vanCondition == 'u') {
            // Used
            returnVal = "used";
        }
        else {
            // broken
            returnVal = "broken";
        };


        return returnVal;
    };

    // Returning the top speed of the van
    double Van::topSpeed() const {

        return vanTopSpeed;
    };

    // Returning the type of the van
    std::string Van::type() const {
        std::string returnVal;
        if (vanType == 'p') {
            returnVal = "pickup";

        }
        else if (vanType == 'm') {
            returnVal = "mini-bus";
        }
        else {
            returnVal = "camper";
        };
        return returnVal;
    };


    // Returning the usage of the van
    std::string Van::usage() const {
        std::string returnVal;
        if (vanPurpose == 'd') {

            returnVal = "delivery";
        }
        else if (vanPurpose == 'p') {
            returnVal = "passenger";
        }
        else {
            returnVal = "camping";
        };
        return returnVal;
    };

    // Outputting the van to the console.
    void Van::display(std::ostream& out) const {
        out << "| ";
        out.width(8);
        out.setf(std::ios::right);
        out << vanMaker;
        out.unsetf(std::ios::right);
        out << " | ";
        out.width(12);
        out.setf(std::ios::left);
        out << (*this).type();
        out.unsetf(std::ios::left);
        out << " | ";
        out.width(12);
        out.setf(std::ios::left);
        out << (*this).usage();
        out.unsetf(std::ios::left);
        out << " | ";
        out.width(6);
        out.setf(std::ios::left);
        out << (*this).condition();
        out.unsetf(std::ios::left);
        out << " | ";
        out.width(6);
        out.setf(std::ios::fixed);
        out << vanTopSpeed;
        out.unsetf(std::ios::fixed);
        out << " |";
    };




}

