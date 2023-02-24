
/*
    Name   : Ansh Girdhar
    ID     : 15255204
    Email  : agirdhar@myseneca.ca
    Section: ZCC
*/

#include <iostream>
#include <fstream>
#include <string>
#include "TreasureMap.h"
#include <thread>
#include <functional>
#include <future>
using namespace std::placeholders ; 
namespace sdds{

    size_t digForTreasure(const std::string& str, char mark){
        size_t cont = 0;
        for (auto& x : str){
            if (x == mark){
                cont++;
            }
        }
        return cont;
    }

    TreasureMap::TreasureMap(const char* filename){
        std::fstream fin(filename);
        if (fin){
            fin >> rows;
            fin.ignore();
            map = new std::string[rows];
            size_t idx = 0;
            while(fin){
                getline(fin, map[idx]);
                idx++;
            }
            colSize = map[0].length();
        }
        else {
            throw std::string(filename) + " cannot be opened";
        }
    }

    TreasureMap::~TreasureMap(){
        delete [] map;
    }

    std::ostream& TreasureMap::display(std::ostream& os) const{
        if (map){
            for (size_t x = 0; x < rows; ++x){
                os << map[x] << std::endl;
            }
        }
        else 
            os << "The map is empty!" << std::endl;
        return os;
    }

    void TreasureMap::enscribe(const char* filename){
        
        if (map){
           
            std::ofstream f(filename,std::ios::out | std::ios::binary | std::ios::trunc) ;
            if(f.is_open()){
            if(f){
                
                f.write(reinterpret_cast<char*>(&rows),sizeof(rows)) ;
             
                f.write(reinterpret_cast<char*>(&colSize), sizeof(colSize)) ;
           
                for(size_t x = 0; x < rows ; x++){
                    
                    f.write(&map[x][0], map[x].size());
                    
                } ; 
                f.close() ; 
            } ; 
         
            }else{
                throw "Cannot open the file.";
            } ; 
        }
        else{
            throw std::string("Treasure map is empty!");
        }
    }

    void TreasureMap::recall(const char* filename){
       
        std::ifstream f(filename, std::ios::in | std::ios::binary); 
        if(f.is_open()){
       
        f.read(reinterpret_cast<char*>(&rows), sizeof(size_t)) ;
      
        f.read(reinterpret_cast<char*>(&colSize), sizeof(size_t)) ;
 
        map = new std::string[rows];
        
        for(size_t x = 0 ; x < rows ; x++){
            map[x].resize(colSize) ; 
            f.read(&map[x][0], colSize) ;
        } ;
        f.close();
    
        }else{
            throw "File cannot be opened." ;
        } ; 

        
    }

    void TreasureMap::clear(){
        delete [] map;
        map = nullptr;
        rows = 0;
        colSize = 0;
    }

    size_t TreasureMap::findTreasure(char mark){
        size_t count = 0;

       
     
       std::string totDat = "" ; 
       for(size_t x = 0; x < rows ; x++){
            totDat += map[x] ; 
       } ; 
     
       auto p = std::bind(digForTreasure, _1, _2) ; 

   
       std::packaged_task <size_t(const std::string& , char)> pt1(p) ; 
       std::packaged_task <size_t(const std::string& , char)> pt2(p) ; 
       std::packaged_task <size_t(const std::string& , char)> pt3(p) ; 
       std::packaged_task <size_t(const std::string& , char)> pt4(p) ; 

       auto f1 = pt1.get_future() ; 
       auto f2 = pt2.get_future() ; 
       auto f3 = pt3.get_future() ; 
       auto f4 = pt4.get_future() ; 

       
       size_t equal4 = totDat.size()/4 ; 
       
       std::thread th1(std::move(pt1),totDat.substr(0,equal4) ,mark) ; 
       std::thread th2(std::move(pt2),totDat.substr(equal4,equal4) , mark) ; 
       std::thread th3(std::move(pt3),totDat.substr(2*equal4,equal4 ) ,mark) ; 
       std::thread th4(std::move(pt4),totDat.substr(3 * equal4,equal4) ,mark) ; 

       
       th1.join() ;
       th2.join() ;
       th3.join() ;
       th4.join() ;

    
       count = f1.get() + f2.get() + f3.get() + f4.get() ; 

        return count;
    }
}