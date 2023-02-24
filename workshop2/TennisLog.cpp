/*
    ==================================================
    Workshop 02: OOP435ZCC
    ==================================================
    Name   : Ansh GirdhAR
    ID     : 152552204
    Email  : agirdhar@myseneca.ca
    Section: ZCC
*/

#include "TennisLog.h"
#include <fstream>
#include <cstring>
namespace sdds {


    TennisLog::TennisLog() {

    };

   

    TennisLog::TennisLog(const char* fName) {
        std::ifstream is(fName);

        

        unsigned int noMatches = -1;
        bool keepReading = true;
        while (keepReading) {
            if (is.peek() == EOF) {
                keepReading = false;
            }
            else {
                noMatches += 1;
                std::string str;
                getline(is, str);
            };

        };

        is.close();

        allTennisMatches = new TennisMatch[noMatches];
        totalMatches = noMatches;



        std::ifstream is2(fName);
        std::string ig;
       
        getline(is2, ig);


        keepReading = true;
        int currentMtach = 0;
        while (keepReading) {
            if (is2.peek() == EOF) {
                keepReading = false;
            }
            else {
                // Reading one record at a time.
                // TID
                getline(is2, allTennisMatches[currentMtach].tID, ',');
                //TNAME
                getline(is2, allTennisMatches[currentMtach].tName, ',');

                // MID
                is2 >> allTennisMatches[currentMtach].matchID;
                is2.ignore();

                // WNAME
                getline(is2, allTennisMatches[currentMtach].wMatch, ',');


                // LNAME
                getline(is2, allTennisMatches[currentMtach].lMatch, '\n');
                currentMtach++;

            };



        };


        is2.close();



    };


    // Overloading the insertion operator
    std::ostream& operator<<(std::ostream& os, const TennisMatch& src) {
        if (src.tID.length() > 0) {
            // not an empty state.
            os.fill('.');

            // Formatting label
            os.width(20);
            os.setf(std::ios::right);
            os << "Tourney ID";
            os.unsetf(std::ios::right);
            os << " : ";
            // Formatting value.
            os.width(30);
            os.setf(std::ios::left);
            os << src.tID << std::endl;
            os.unsetf(std::ios::left);

            // Formatting label
            os.width(20);
            os.setf(std::ios::right);
            os << "Match ID";
            os.unsetf(std::ios::right);
            os << " : ";
            // Formatting value.
            os.width(30);
            os.setf(std::ios::left);
            os << src.matchID << std::endl;
            os.unsetf(std::ios::left);

            // Formatting label
            os.width(20);
            os.setf(std::ios::right);
            os << "Tourney";
            os.unsetf(std::ios::right);
            os << " : ";
            // Formatting value.
            os.width(30);
            os.setf(std::ios::left);
            os << src.tName << std::endl;
            os.unsetf(std::ios::left);

            // Formatting label
            os.width(20);
            os.setf(std::ios::right);
            os << "Winner";
            os.unsetf(std::ios::right);
            os << " : ";
            // Formatting value.
            os.width(30);
            os.setf(std::ios::left);
            os << src.wMatch << std::endl;
            os.unsetf(std::ios::left);

            // Formatting label
            os.width(20);
            os.setf(std::ios::right);
            os << "Loser";
            os.unsetf(std::ios::right);
            os << " : ";
            // Formatting value.
            os.width(30);
            os.setf(std::ios::left);
            os << src.lMatch << std::endl;
            os.unsetf(std::ios::left);
            os.fill(' ');

        }
        else {
            // An emty state.
            os << "Empty Match";
        };

        return os;

    };

  
    void TennisLog::addMatch(const TennisMatch& toAdd) {
        
        TennisMatch* tempAll = new TennisMatch[totalMatches + 1];
     
        for (unsigned int count = 0; count < totalMatches; count++) {
            tempAll[count] = allTennisMatches[count];

        };

        // Deleting the previous array.
        delete[] allTennisMatches;
        // Setting it to the new address.
        allTennisMatches = tempAll;
       
        allTennisMatches[totalMatches] = toAdd;
        totalMatches++;

    };





    // Overloading the '[]' operator
    TennisMatch TennisLog::operator[](size_t index) {

        if (allTennisMatches != nullptr && index < totalMatches) {
            return allTennisMatches[index];
        }
        else {
            TennisMatch temp;
            return temp;
        };
    };

    TennisLog::operator size_t() const {
        return totalMatches;

    };


    TennisLog TennisLog::findMatches(std::string name) {
        // Creating a tennis log object.
        TennisLog playersWithMatch;

        for (unsigned int i = 0; i < totalMatches; i++) {
            if (allTennisMatches[i].wMatch == name || allTennisMatches[i].lMatch == name) {
                playersWithMatch.addMatch(allTennisMatches[i]);
            };

        };

        return playersWithMatch;

    };

    // Rule of 5

    // Destructor.

    TennisLog::~TennisLog() {
        delete[] allTennisMatches;

    };



    // Copy assignment operator
    TennisLog& TennisLog::operator=(const TennisLog& src) {
        delete[] allTennisMatches;
        totalMatches = 0;
        if (this != &src) {
            allTennisMatches = new TennisMatch[src.totalMatches];
            for (unsigned int i = 0; i < src.totalMatches; i++) {
                allTennisMatches[i] = src.allTennisMatches[i];


            };
            totalMatches = src.totalMatches;
        }
        else {
            allTennisMatches = nullptr;

        };
        return *this;

    };

    // Copy Constructor.
    TennisLog::TennisLog(const TennisLog& src) {
        (*this) = src;
    };

    // Move assignment operator
    TennisLog& TennisLog::operator=(TennisLog&& src) {
        delete[] allTennisMatches;
        if (this != &src) {
            totalMatches = size_t(src);
            allTennisMatches = src.allTennisMatches;
            src.allTennisMatches = nullptr;
            src.totalMatches = 0;
        }
        else {
            allTennisMatches = nullptr;
            totalMatches = 0;
        };
        return *this;
    };

    // Move constructor
    TennisLog::TennisLog(TennisLog&& src) {

        (*this) = std::move(src);

    };


}
