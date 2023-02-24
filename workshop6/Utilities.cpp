/*
   Name - Ansh Girdhar
   Email - agirdhar@myseneca.ca
   Student Id - 152552204
   Date - 2022-11-06
*/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include "Utilities.h"
namespace sdds {
    Vehicle* createInstance(std::istream& in) {
        Vehicle* ptr;
        if (in.peek() != EOF) {
            std::string str;
            getline(in, str, '\n');
            std::string str2 = str;
            str2 += '\n';
            std::stringstream ss(str2);
            int pos_f_comma = str.find(',');
            std::string tag_Space = str.substr(0, pos_f_comma);

            std::string arr[1] = { tag_Space };


            for (int i = 0; i < 1; i++) {
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



            char tag = arr[0].at(0);

            if (tag == 'c' || tag == 'C') {
                ptr = new Car(ss);

            }
            else if (tag == 'v' || tag == 'V') {
                ptr = new Van(ss);

            }
            else if (tag == 'r' || tag == 'R') {
                ptr = new Racecar(ss);

            }
            else if (tag == 'l' || tag == 'L') {
                ptr = new Luxuryvan(ss);

            }
            else {
                throw tag;

            };



        }
        else {
            in.get();
            ptr = nullptr;

        };
        return ptr;
    };


}