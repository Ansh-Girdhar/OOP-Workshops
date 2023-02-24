/*
    Name   : Ansh Girdhar
    ID     : 15255204
    Email  : agirdhar@myseneca.ca
    Section: ZCC
*/
#ifndef SDDS_GENERATINGLIST_H
#define SDDS_GENERATINGLIST_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <memory>
#include <utility>
#include <fstream>

namespace sdds {
	template<typename T>
	class GeneratingList {

		std::vector<T> list;
	public:

		GeneratingList(){}
		GeneratingList(const char* f) {
			std::ifstream file(f);
			if (!file)
				throw std::string("*** Failed to open file ") + std::string(f) + std::string(" ***");

			while (file) {
				T t;
				if (t.load(file))
					list.push_back(T(t));
			}
		}

		size_t size() const { return list.size(); }
		const T& operator[](size_t i) const { return list[i]; }

		//TODO: Implement the Luhn Algorithm to check the 
		//      valadity of SIN No's

		bool checkSin(const std::string& sin) const{
			bool returnValue ; 
			size_t sum1 = 0 ; 
			for(int i = sin.length() - 2; i >= 0 ; i -= 2){
				size_t digit = sin[i] - '0' ;
				size_t dDigit = 2 * digit ; 
				if(dDigit >= 10){	
					size_t sumDDigit = (dDigit % 10) + (dDigit / 10) ; 
					sum1 += sumDDigit ;  
				}else{
					sum1 += dDigit ; 
				} ; 

			} ; 

			size_t sum2 = 0 ; 

			for(int i = sin.length() - 1 ; i >= 0 ; i-= 2){
				size_t digit = sin[i] - '0' ;
				sum2 += digit ; 

			} ; 

			size_t totalSum = sum1 + sum2 ; 
			if(totalSum % 10 == 0){
				returnValue = true ;
			}else{
				returnValue = false ;
			} ; 

		return returnValue ; 

		} ; 

		//TODO: Overload the += operator with a smart pointer
		// as a second operand.

		void operator+=(std::unique_ptr<T>ptr_obj){
			list.push_back(*ptr_obj);

		} ; 
		

		//TODO: Overload the += operator with a raw pointer
		// as a second operand.
		
		void operator+=(T* ptr_obj){
			list.push_back(*ptr_obj);
			// If object dynamically allocated, deallocating the memory.
			delete ptr_obj; 

		} ; 
		
		void print(std::ostream& os) const {
			os << std::fixed << std::setprecision(2);
			for (auto& e : list)
				e.print(os);
		}
	};

	template<typename T>
	std::ostream& operator<<(std::ostream& os, const GeneratingList<T>& rd) {
		rd.print(os);
		return os;
	}
}
#endif 
