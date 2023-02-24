/*
    Name   : Ansh Girdhar
    ID     : 15255204
    Email  : agirdhar@myseneca.ca
    Section: ZCC
*/
#include "GeneratingList.h"
#include "EmpProfile.h"
#include "WritingRecord.h"

using namespace std;

namespace sdds {
	GeneratingList<EmployeeWage> writeRaw(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
		GeneratingList<EmployeeWage> activeEmp;
		// TODO: Add your code here to build a list of employees
		//         using raw pointers

		for(size_t i = 0 ; i < emp.size() ; i++){
			for(size_t i2 =0 ; i2 < sal.size() ; i2++){
				if(emp[i].id == sal[i2].id){
					
					EmployeeWage* empWage = new EmployeeWage(emp[i].name,sal[i2].salary);
					
					try{
						empWage->rangeValidator(); 

					}catch(...){
						delete empWage ; 
						throw ; 

					} ;

					bool sinValid = emp.checkSin(emp[i].id);
					if(!sinValid){
						delete empWage ; 
						std::string msg = "SIN Not valid" ; 
						throw msg ; 
					} ; 	

					activeEmp += empWage ; 

					i2 = sal.size() ;
				} ; 


			} ; 


		} ;
		
		return activeEmp;
	}

	GeneratingList<EmployeeWage> writeSmart(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
		GeneratingList<EmployeeWage> activeEmp;
		// TODO: Add your code here to build a list of employees
		//         using smart pointers

		for(size_t i = 0 ; i < emp.size() ; i++){
			for(size_t i2 =0 ; i2 < sal.size() ; i2++){
				if(emp[i].id == sal[i2].id){
					// It is an active employee.
					// Creating an object of type 'EmployeeWage'
					std::unique_ptr<EmployeeWage>empWage(new EmployeeWage(emp[i].name,sal[i2].salary));
					
					empWage->rangeValidator();

					bool sinValid = emp.checkSin(emp[i].id);
					if(!sinValid){
						std::string msg = "SIN Not valid" ; 
						throw msg ; 
					} ; 	
					
					activeEmp += std::move(empWage);

					i2 = sal.size() ;
				} ; 


			} ; 


		} ;
		
		return activeEmp;
	}
}