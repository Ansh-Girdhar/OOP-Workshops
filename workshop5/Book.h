/*
    ==================================================
    Workshop 02: OOP345ZCC
    ==================================================
    Name   : Ansh GirdhAR
    ID     : 152552204
    Email  : agirdhar@myseneca.ca
    Section: ZCC
*/
#ifndef SDDS_BOOK_H_
#define SDDS_BOOK_H_
#include <iostream>
#include <string>

namespace sdds
{
    class Book
    {
    private:
        std::string m_author{};
        std::string m_title{};
        std::string m_country{};
        size_t m_year{};
        double m_price{};
        std::string m_desc{};

    public:
        Book();
        Book(const std::string& strBook);
        virtual ~Book() = default;
        const std::string& title() const;
        const std::string& country() const;
        const size_t& year() const;
        double& price();
        friend std::ostream& operator<<(std::ostream& os, const Book& book);
        template <typename T>
        void fixSpelling(T& spellChecker)
        {
            spellChecker(m_desc);
        }
    };

}
#endif