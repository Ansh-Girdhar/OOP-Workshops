/*
    ==================================================
    Workshop 02: OOP435ZCC
    ==================================================
    Name   : Ansh GirdhAR
    ID     : 152552204
    Email  : agirdhar@myseneca.ca
    Section: ZCC
*/

#ifndef TENNISLOG_H
#define TENNISLOG_H
#include <iostream>
namespace sdds {


    struct TennisMatch {
        std::string tID{ "" };
        std::string tName{ "" };
        unsigned int matchID{ 0 };
        std::string wMatch{ "" };
        std::string lMatch{ "" };
    };



    class TennisLog {
        TennisMatch* allTennisMatches{ nullptr };
        unsigned int totalMatches{ 0 };

    public:
        
        TennisLog();
       
        TennisLog(const char* fName);

        TennisMatch operator[](size_t);
        operator size_t() const;
        void addMatch(const TennisMatch& toAdd);

        TennisLog findMatches(std::string name);

        
        ~TennisLog();

        TennisLog& operator=(const TennisLog& src);

    
        TennisLog(const TennisLog& src);

      
        TennisLog& operator=(TennisLog&& src);

        TennisLog(TennisLog&& src);


    };




    // Overloading the insertion operator
    std::ostream& operator<<(std::ostream& os, const TennisMatch& src);


};

#endif
