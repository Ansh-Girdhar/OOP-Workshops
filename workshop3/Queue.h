/*
    ==================================================
    Workshop 03: OOP435ZCC
    ==================================================
    Name   : Ansh GirdhAR
    ID     : 152552204
    Email  : agirdhar@myseneca.ca
    Section: ZCC
*/
#ifndef SDDS_QUEUE_H_
#define SDDS_QUEUE_H_
#include <iostream>
#include "Dictionary.h"

namespace sdds
{
    template <typename T, size_t CAPACITY>
    class Queue
    {
        T m_data[CAPACITY]{};
        size_t m_filled{};
        static T m_default;

    public:
        Queue() = default;
        virtual ~Queue() = default;
        virtual bool push(const T& item);
        T pop();
        size_t size() const;
        std::ostream& display(std::ostream& os = std::cout) const;
        T operator[](size_t index) const;
    };

    template <typename T, size_t CAPACITY>
    T Queue<T, CAPACITY>::m_default{};
    template <>
    Dictionary Queue<Dictionary, 100u>::m_default{ "Empty Term", "Empty Substitute" };

    template <typename T, size_t CAPACITY>
    bool Queue<T, CAPACITY>::push(const T& item)
    {

        bool result = false;
        if (m_filled < CAPACITY)
        {
            m_data[m_filled] = item;
            m_filled++;
            result = true;
        }
        return result;
    }

    template <typename T, size_t CAPACITY>
    size_t Queue<T, CAPACITY>::size() const
    {
        return m_filled;
    }

    template <typename T, size_t CAPACITY>
    std::ostream& Queue<T, CAPACITY>::display(std::ostream& os) const
    {
        std::cout << "----------------------\n"
            << "| Dictionary Content |\n----------------------\n";
        for (size_t i = 0; i < m_filled; i++)
        {
            os << m_data[i] << std::endl;
        }
        std::cout << "----------------------\n";
        return os;
    }

    template <typename T, size_t CAPACITY>
    T Queue<T, CAPACITY>::operator[](size_t index) const
    {
        return index < m_filled&& index >= 0 ? m_data[index] : m_default;
    }

    template <typename T, size_t CAPACITY>
    T Queue<T, CAPACITY>::pop()
    {
        T result{};
        if (m_filled > 0)
        {
            result = m_data[0];
            for (size_t i = 0; i < m_filled - 1; i++)
            {
                m_data[i] = m_data[i + 1];
            }
            m_filled--;
        }
        return result;
    }
}

#endif